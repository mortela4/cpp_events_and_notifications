#include "TestWorker.h"

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

	void TestWorker::Run(void)
	{
		std::cout << _name << ": RUNning: my capacity is now = " << myCap << std::endl;
		isRunning = true;
	}

	void TestWorker::Stop(void)
	{
		std::cout << _name << ": STOPped: last capacity SET is = " << myCap << std::endl;
		isRunning = false;
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
