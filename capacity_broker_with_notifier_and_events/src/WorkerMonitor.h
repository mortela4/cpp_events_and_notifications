#ifndef WORKERMONITOR_H_
#define WORKERMONITOR_H_

#include "TestWorker.h"
#include "Event.h"

#include <iostream>
#include <vector>
#include <functional>
#include <string>


namespace monitor_ex
{

	class WorkerMonitor
	{
	public:
		int maxCap = 32;
		int numActive = 0;
		std::vector<std::reference_wrapper<TestWorker>> workers;

		WorkerMonitor();
		void Notify(const notification_event::Event& event);
		void Attach(TestWorker& worker);
		void AddWorker(const std::string& workerName);
		void RunAll(void);
		void Command(const std::string& cmd, const std::string& workerName);
		virtual ~WorkerMonitor();
	};

} /* namespace monitor_ex */


#endif /* WORKERMONITOR_H_ */
