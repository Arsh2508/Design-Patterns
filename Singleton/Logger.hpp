#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>

class Logger {
public:
    static Logger* getInstance();
    void log(const std::string& message);
    
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    Logger() = default;  
    static Logger* instance;
};

#endif
