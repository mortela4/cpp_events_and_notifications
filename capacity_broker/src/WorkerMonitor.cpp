#include "TestWorker.h"
#include "WorkerMonitor.h"

#include <string>
#include <vector>
#include <map>
#include <functional>



namespace monitor_ex
{
	/************************************* Free Functions *****************************************/

	static TestWorker& make_worker(const std::string workerName)
	{
		auto worker = new TestWorker(workerName);

		return(*worker);
	}

	static void run_worker(WorkerMonitor& monitor, TestWorker& worker)
	{
		++monitor.numActive;

		int newCapacity = monitor.maxCap / monitor.numActive;

		if (monitor.maxCap > newCapacity)
		{
			/* Re-scale cap for other workers */
			for (auto workerRef : monitor.workers)
			{
				auto& wrk = workerRef.get();

				if (&worker != &wrk)
				{
					wrk.SetCapacity(newCapacity);	// May STOP before SET ... then RUN again!!
				}
			}
		}

		std::cout << "\nRUN action for '" << worker.GetName() << "' ...\n\n";

		worker.SetCapacity(newCapacity);

		worker.Run();
	}

	static void stop_worker(WorkerMonitor& monitor, TestWorker& worker)
	{
		std::cout << "\nSTOP action for '" << worker.GetName() << "' ...\n\n";

		worker.Stop();

		--monitor.numActive;

		// Re-distribute capacity
		int newCapacity = (0 == monitor.numActive) ? monitor.maxCap : (monitor.maxCap / monitor.numActive);

		/* Re-scale cap for other workers */
		for (auto workerRef : monitor.workers)
		{
			auto& wrk = workerRef.get();

			if (&worker != &wrk)
			{
				wrk.SetCapacity(newCapacity);	// May STOP before SET ... then RUN again!! (IF worker 'wrk' was running ...)
			}
		}
	}


	/********************************* Static Data Structures ************************************************/

	const static std::function<void(WorkerMonitor&, TestWorker&)> funcStop = &stop_worker;
	const static std::function<void(WorkerMonitor&, TestWorker&)> funcRun = &run_worker;
	// Map command-to-function for simplified parsing:
	const static std::map<const std::string, const std::function<void(WorkerMonitor&, TestWorker&)>> workerFuncs =
	{
		{"stop", funcStop},
		{"run", funcRun},
	};


	/***************************************** Class Methods *******************************************/

	WorkerMonitor::WorkerMonitor()
	{
		// TODO Auto-generated constructor stub
	}

	WorkerMonitor::~WorkerMonitor()
	{
		// TODO Auto-generated destructor stub
	}

	void WorkerMonitor::AddWorker(const std::string& workerName)
	{
		auto& workerRef = make_worker(workerName);

		workers.push_back(std::ref(workerRef));
	}

	void  WorkerMonitor::RunAll(void)
	{
		for (auto workerRef : workers)
		{
			auto worker = workerRef.get();

			worker.Run();
		}
	}

	void WorkerMonitor::Command(const std::string& cmd, const std::string& workerName)
	{
		auto commandedFunc = workerFuncs.at(cmd);

		for (auto workerRef : workers)
		{
			auto& worker = workerRef.get();

			if (workerName == worker.GetName())
			{
				commandedFunc(*this, worker);
			}
		}
	}


} /* namespace monitor_ex */
