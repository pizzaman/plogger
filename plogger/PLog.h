//
//  PLog.hpp
//  log
//
//  Created by pizzaman on 02/01/2018.
//

#ifndef PLog_hpp
#define PLog_hpp

#include <map>
#include "Logger.h"
#include "LoggerFactory.h"

class PLog {
public:
    PLog();
    ~PLog();
    static PLog* getInstance();
    void setFactory(ILoggerFactory *value);
    ILogger* getLogger(const std::string& logname);
private:
    static PLog* _instance;
    ILoggerFactory *_factory;
    std::map<std::string, ILogger*> cache;
};

#endif /* PLog_hpp */
