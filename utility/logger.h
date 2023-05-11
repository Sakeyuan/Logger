#pragma once
#include <string>
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdexcept>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <sys/time.h>

#define debug(format,...)\
    Logger::instance()->log(Logger::DEBUG,__FILE__,__LINE__,format,##__VA_ARGS__);

#define info(format,...)\
    Logger::instance()->log(Logger::INFO,__FILE__,__LINE__,format,##__VA_ARGS__);

#define warn(format,...)\
    Logger::instance()->log(Logger::WARN,__FILE__,__LINE__,format,##__VA_ARGS__);

#define error(format,...)\
    Logger::instance()->log(Logger::ERROR,__FILE__,__LINE__,format,##__VA_ARGS__);

#define fatal(format,...)\
    Logger::instance()->log(Logger::FATAL,__FILE__,__LINE__,format,##__VA_ARGS__);

namespace utility
{
class Logger{
public:
    //日志级别
    enum Level{
        DEBUG = 0,
        INFO,
        WARN,
        ERROR,
        FATAL,
        LEVEL_COUNT
    };

    void log(Level level, const char* file,int line,const char* format,...);
    
    static Logger* instance();
    
    void open(const std::string& filename);
    
    void close();

    void level(Level level);

    void set_size(int bytes);

private:
    Logger();

    ~Logger();

    void rotate();

private:
    //文件名
    std::string m_filename;
    
    //输出流
    std::ofstream m_fout;    
    
    //保存日志等级
    static const char* m_levels[LEVEL_COUNT];

    //日志等级
    Level m_level;

    //日志文件大小
    int m_file_size;

    //单个日志大小
    int m_max_size;

};
      
} 
