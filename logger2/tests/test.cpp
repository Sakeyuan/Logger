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
    
    auto l = LoggerMgr::GetInstance()->getLogger("xx");
    l->addAppender(FileLogAppender::ptr(new FileLogAppender("./log.txt")));
    LOG_INFO(l)<<"yjf";
    std::cout << "hello log" << std::endl;
    return 0;
}