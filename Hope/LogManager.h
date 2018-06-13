#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H
#include <string>


class LogManager
{
private:
	std::string log;

public:
	LogManager();
	~LogManager();

	void writeLog(std::string _log) { log += _log; };

	void errorExit();
};
#endif

