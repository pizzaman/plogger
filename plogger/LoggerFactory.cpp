//
// Created by pizzaman on 02/01/2018.
//

#include <iostream>
#include "Logger.h"
#include "LoggerFactory.h"
#include "LogUtil.h"

ILogger* DefaultLoggerFactory::getLogger(const std::string& logname) {
    return new DefaultLogger(logname);
}

DefaultLogger::DefaultLogger(const std::string &name) : AbstractLogger(name) {

}

void DefaultLogger::log(uint8_t level,const std::string &message, va_list va) {
    char logbuf[1024];
    char logdata[1024];
    int len = vsnprintf(logbuf, 1000 * 100, message.c_str(), va);
    std::string logLevel ="[" + LogLevel::toString(level) + "]";
    std::string logTime = "[" + LogUtil::getSystemTime() + "]";
    std::string tag = "[" + this->name + "]";
    std::string content = logLevel + logTime + tag;
    if (len < 0)
    {
        std::cerr << content << "log params error" << std::endl;
    }
    else
    {
        sprintf(logdata, "[%s]",logbuf);
        std::cout << content << logdata << std::endl;
    }
}
