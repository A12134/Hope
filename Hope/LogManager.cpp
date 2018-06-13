#include "LogManager.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "psapi.h"
#pragma comment(lib, "user32.lib")


LogManager::LogManager()
{
	this->log = "";
}


LogManager::~LogManager()
{
	std::time_t t = time(0);	// get current time
	struct tm  now;
	localtime_s(&now,&t);

	// generate log info
	std::string filename = "Log-" + std::to_string(now.tm_year + 1900) + "-" + std::to_string(now.tm_mon + 1) + "-" + std::to_string(now.tm_mday) + "-" + std::to_string(t) + ".txt";

	std::ofstream outputFile;
	outputFile.open(filename);

	std::ostringstream ostream;

	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);

	// Total virtual memory
	ostream << memInfo.ullTotalPageFile;
	std::string totalVirtualMem = ostream.str();

	// clear stream
	ostream.str("");
	ostream.clear();

	// Total virtual memory used
	ostream << memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
	std::string virtualMemUsed = ostream.str();

	// clear stream
	ostream.str("");
	ostream.clear();

	// Total virtual memory available
	ostream << memInfo.ullAvailPageFile;
	std::string virtualMemAvail = ostream.str();

	// clear stream
	ostream.str("");
	ostream.clear();

	std::stringstream stream;

	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	
	// Virtual Memory used by engine
	stream << pmc.PrivateUsage;
	std::string virtualMemUsedByEngine = stream.str();

	// clear stream
	stream.str("");
	stream.clear();

	// Total Physical Memory
	ostream << memInfo.ullTotalPhys;
	std::string totalPhysMem = ostream.str();

	// clear stream
	ostream.str("");
	ostream.clear();

	// Total Physical Memory used
	ostream << memInfo.ullTotalPhys - memInfo.ullAvailPhys;
	std::string physMemUsed = ostream.str();

	// clear stream
	ostream.str("");
	ostream.clear();
	
	// Total Physical Memory Available
	ostream << memInfo.ullAvailPhys;
	std::string physMemAvail = ostream.str();

	// clear stream
	ostream.str("");
	ostream.clear();

	// Total Physical Memory used by Engine
	stream << pmc.WorkingSetSize;
	std::string physMemUsedByEngine = stream.str();

	// clear stream
	stream.str("");
	stream.clear();


	outputFile << std::to_string(now.tm_year + 1900) + "-" + std::to_string(now.tm_mon + 1) + "-" + std::to_string(now.tm_mday) << "\n";
	outputFile << "Total virtual Memory: " << totalVirtualMem << "	virtual Memory used: " << virtualMemUsed << "	engine used: " << virtualMemUsedByEngine << "	virtual Memory Left: " << virtualMemAvail << "\n";
	outputFile << "Total physical Memory: " << totalPhysMem << "	physical Memory used: " << physMemUsed << "		engine used: " << physMemUsedByEngine << "	physical Mmeory Left: " << physMemAvail << "\n";
	outputFile << "--------------------------------------------\n";

	outputFile << this->log;

	outputFile << "\n";
	outputFile << "--------------------------------------------\n";
	outputFile << "Log Ended.\n";

	outputFile.close();
}

void LogManager::errorExit()
{
	delete this;
	exit(-1);
}
