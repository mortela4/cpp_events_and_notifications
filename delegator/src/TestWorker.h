#ifndef TESTWORKER_H_
#define TESTWORKER_H_

#include "delegate.h"
#include "event.h"

#include <iostream>
#include <functional>
#include <string>


namespace monitor_ex
{

	class TestWorker
	{
	private:
		const std::string _name;
		Delegate<const notification_event::Event&> _notifier;		// NOTE: yes - this should be 'private'
	public:
	    int myCap = 0;
		bool isRunning = false;

		explicit TestWorker(const std::string& name);
		virtual ~TestWorker();
		void Attach(std::function<void(const notification_event::Event&)> notifyHandler);
		void Run(void);
		void Stop(void);
		void SetCapacity(int newCapacity);
		std::string GetName(void);
	};

} /* namespace worker_ex */

#endif /* TESTWORKER_H_ */
