#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>

enum LogType { INFO, WARNING, ERROR };

struct LogEntry {
  LogType type;
  std::string msg;
};

class Logger {
public:
  static std::vector<LogEntry> message;
  static void Log(const std::string &msg);
  static void Err(const std::string &msg);
};

#endif
