//============================================================================
// Name        : delegator.cpp
// Author      : ml
// Version     :
// Copyright   : 
// Description : Dynamically (Re-)partition capacity among multiple 'workers' using delegates.
//============================================================================

#include "TestWorker.h"
#include "WorkerMonitor.h"

//#include <iostream>
//#include <functional>
//#include <vector>

using namespace std;



int main()
{
	auto monitor = monitor_ex::WorkerMonitor();

	monitor.AddWorker("A");
	monitor.AddWorker("B");

	// monitor.RunAll();

	monitor.Command("run", "A");
	monitor.Command("run", "B");
	monitor.Command("stop", "A");
	monitor.Command("stop", "B");
	monitor.Command("run", "A");

	// Let's make it 3 workers ...
	monitor.AddWorker("C");
	monitor.Command("run", "C");
	monitor.Command("run", "B");
	monitor.Command("stop", "A");



	return 0;
}
