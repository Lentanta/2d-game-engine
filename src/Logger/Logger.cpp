#include "Logger.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

std::vector<LogEntry> Logger::message;

std::string getCurrentDateString() {
  // Using C lib to get time
  std::time_t now = std::time(nullptr);
  std::tm *local = std::localtime(&now);

  // Transform put_time output to string
  std::ostringstream oss;
  oss << std::put_time(local, "%Y-%b-%d %H:%M:%S");
  return oss.str();
};

// ANSI color codes
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

void Logger::Log(const std::string &msg) {
  LogEntry logEntry;
  logEntry.type = INFO;
  logEntry.msg = msg;
  message.push_back(logEntry);

  std::cout << GREEN                          //
            << "[LOG] "                       //
            << getCurrentDateString() + " - " //
            << logEntry.msg                   //
            << RESET                          //
            << std::endl;
};

void Logger::Err(const std::string &msg) {
  LogEntry logEntry;
  logEntry.type = ERROR;
  logEntry.msg = msg;
  message.push_back(logEntry);

  std::cout << RED                            //
            << "[ERR] "                       //
            << getCurrentDateString() + " - " //
            << logEntry.msg                   //
            << RESET                          //
            << std::endl;
};
