#include <iostream>
#include "logger.h"
using namespace utility;

int main(){
    Logger::instance()->open("log.txt");
    debug("name is %s","log system");
    info("name is %s","log system");
    warn("name is %s","log system");
    error("name is %s","log system");
    fatal("name is %s","log system");
    
    debug("log system");
    info("log system");
    warn("log system");
    error("log system");
    fatal("log system");
    return 0;
}

