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
    //��־����
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

    void max(int bytes);

private:
    Logger();

    ~Logger();

    void rotate();

private:
    //�ļ���
    std::string m_filename;
    
    //�����
    std::ofstream m_fout;    
    
    //������־�ȼ�
    static const char* m_levels[LEVEL_COUNT];

    //��־�ȼ�
    Level m_level;

    //��־�ļ���С
    int m_file_size;

    //������־��С
    int m_max_size;
};
      
} 
