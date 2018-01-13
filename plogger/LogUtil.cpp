//
// Created by pizzaman on 10/01/2018.
//

#include "LogUtil.h"
#include <string>
#include <time.h>

std::string LogUtil::getSystemTime() {
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp),"%Y-%m-%d %H:%M:%S",localtime(&timep));
    return tmp;
}