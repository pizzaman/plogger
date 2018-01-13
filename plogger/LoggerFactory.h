//
// Created by pizzaman on 02/01/2018.
//

#ifndef SLG_SERVER_DEFAULTFACTORY_H
#define SLG_SERVER_DEFAULTFACTORY_H

#include "Logger.h"

class ILoggerFactory {
public:
    virtual ILogger* getLogger(const std::string& logname) = 0;
};

class DefaultLoggerFactory : public ILoggerFactory {
public:
    ILogger* getLogger(const std::string& logname) final;
};

#endif //SLG_SERVER_DEFAULTFACTORY_H
