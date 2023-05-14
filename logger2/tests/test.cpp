#include <iostream>
#include "../src/log.h"
#include "../src/util.h"

int main(){
    Logger::ptr logger(new Logger);
    logger->addAppender(LogAppender::ptr(new StdoutLogAppender));
    
    FileLogAppender::ptr file_appender(new FileLogAppender("./log.txt"));
    logger->addAppender(file_appender);
    LOG_DEBUG(logger)<<"test log";
    LOG_INFO(logger)<<"test log";
    LOG_FATAL(logger)<<"test log";
    LOG_FMT_DEBUG(logger,"test %s","yjf");
    auto l = LoggerMgr::GetInstance()->getLogger("xx");
    LOG_INFO(logger)<<"XXX";
    std::cout << "hello log" << std::endl;
    return 0;
}