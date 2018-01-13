//
//  main.cpp
//  PLogger
//
//  Created by pizzaman on 27/12/2017.
//  Copyright © 2017 pizzaman. All rights reserved.
//

#include <iostream>
#include "PLog.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    ILogger *log = PLog::getInstance()->getLogger("main");
    log->info("abc %s  %s  %s","efg","high","npc");
    log->debug("abc %s  %s  %s","efg","high","npc");
    log->error("abc %s  %s  %s","efg","high","npc");
    return 0;
}
