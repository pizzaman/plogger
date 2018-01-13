//
//  PLog.cpp
//  log
//
//  Created by pizzaman on 02/01/2018.
//

#include <map>
#include "PLog.h"

PLog *PLog::_instance = new PLog();

PLog *PLog::getInstance() {
    return _instance;
}

PLog::PLog() {
    _factory = 0;
}

PLog::~PLog() {
    cache.clear();
}

void PLog::setFactory(ILoggerFactory *value) {
    delete _factory;
    _factory = value;
}

ILogger *PLog::getLogger(const std::string& logname) {
    ILogger* log = cache[logname];
    if (log) {
        return log;
    } else {
        if (_factory == 0) {
            _factory = new DefaultLoggerFactory();
        }
        ILogger *log = _factory->getLogger(logname);
        cache[logname] = log;
        return log;
    }
}






