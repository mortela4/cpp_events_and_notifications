#ifndef TESTWORKER_H_
#define TESTWORKER_H_

#include <iostream>
#include <functional>
#include <string>


namespace monitor_ex
{

	class TestWorker
	{
	private:
		const std::string _name;
	public:
	    int myCap = 0;
		bool isRunning = false;
		std::function<void(const std::string&)> _notifier;

		explicit TestWorker(const std::string& name);
		virtual ~TestWorker();
		void Run(void);
		void Stop(void);
		void SetCapacity(int newCapacity);
		std::string GetName(void);
	};

} /* namespace worker_ex */

#endif /* TESTWORKER_H_ */
