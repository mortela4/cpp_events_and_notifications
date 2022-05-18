#include "TestWorker.h"
#include "Event.h"

#include <functional>
#include <iostream>
#include <string>


namespace monitor_ex
{

	TestWorker::TestWorker(const std::string& name) : _name(name)
	{
		// PASS
	}

	TestWorker::~TestWorker()
	{
		// TODO Auto-generated destructor stub
	}

	void TestWorker::Attach(std::function<void(const notification_event::Event&)> notifyFunc)
	{
		_notifier = notifyFunc;

		const notification_event::Event event{"TestWorker", _name, "attached!"};

		_notifier(event);
	}

	void TestWorker::Run(void)
	{
		std::cout << _name << ": RUNning: my capacity is now = " << myCap << std::endl;
		isRunning = true;
		const notification_event::Event event{"TestWorker", _name, "running!"};

		_notifier(event);
	}

	void TestWorker::Stop(void)
	{
		std::cout << _name << ": STOPped: my capacity is now = " << myCap << std::endl;
		isRunning = false;
		const notification_event::Event event{"TestWorker", _name, "stopped!"};

		_notifier(event);
	}

	void TestWorker::SetCapacity(int newCapacity)
	{
		myCap = newCapacity;
		std::cout << _name << ": FORCED: my capacity is now = " << myCap << std::endl;
	}

	std::string TestWorker::GetName(void)
	{
		return(_name);
	}


} /* namespace worker_ex */
