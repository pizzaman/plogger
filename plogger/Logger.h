//
// Created by pizzaman on 02/01/2018.
//

#ifndef SLG_SERVER_LOGGER_H
#define SLG_SERVER_LOGGER_H

#include <string>

class LogLevel
{
public:
    static const uint8_t LOG_DEBUG = 1;
    static const uint8_t LOG_INFO = 2;
    static const uint8_t LOG_WARN = 3;
    static const uint8_t LOG_ERROR = 4;
    static const uint8_t LOG_FATAL = 5;
    static std::string toString(uint8_t level);
};

class ILogger {
public:
    virtual void debug(const std::string &message, ...) = 0;
    virtual void info(const std::string &message, ...) = 0;
    virtual void warn(const std::string &message, ...) = 0;
    virtual void error(const std::string &message, ...) = 0;
    virtual void fatal(const std::string &message, ...) = 0;

};

class AbstractLogger : public ILogger {
public:
    explicit AbstractLogger(const std::string &value);
    void debug(const std::string &message, ...) override;
    void info(const std::string &message, ...) override;
    void warn(const std::string &message, ...) override;
    void error(const std::string &message, ...) override;
    void fatal(const std::string &message, ...) override;
protected:
    std::string name;
    virtual void log(uint8_t level, const std::string &message, va_list va) = 0;
};


class DefaultLogger : public AbstractLogger {
public:
    explicit DefaultLogger(const std::string &name);
protected:
    void log(uint8_t level, const std::string &message, va_list va) final;
};


#endif //SLG_SERVER_LOGGER_H
