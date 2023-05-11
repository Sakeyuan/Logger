#include "logger.h"
using namespace utility;
const char* Logger::m_levels[Logger::LEVEL_COUNT]{
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"
};

//默认日志文件大小为10M
Logger::Logger():m_level(DEBUG),m_max_size(10*1024*1024),m_file_size(0){

}

Logger::~Logger(){
    this->close();
}

//C++11局部静态变量线程安全
Logger* Logger::instance(){
    static Logger m_instance;
    return &m_instance;
}

void Logger::open(const std::string& filename){
    m_filename = filename;
    m_fout.open(filename,std::ios::app);
    if(m_fout.fail()){
        throw std::logic_error("open file failed"+filename);
    }
    //获取文件大小
    m_fout.seekp(0,std::ios::end);
    m_file_size = m_fout.tellp();
}

void Logger::close(){
    m_fout.close();
}

void Logger::level(Level level){
    m_level = level;
}
/**
 * @brief 
 * 
 * @param level 日志级别
 * @param file 文件名称
 * @param line 行
 * @param format 
 * @param ... 
 */
void Logger::log(Level level, const char* file,int line,const char* format,...){
    if(m_level > level){
        return;
    }
    if(m_fout.fail()){
        throw std::logic_error("open file failed" + m_filename);
    }
    time_t ticks = time(NULL);
    struct tm* ptm = localtime(&ticks);
    char time_buf[32];
    memset(&time_buf,0,sizeof(time_buf));
    
    //格式化时间存储到time_buf中
    strftime(time_buf, sizeof(time_buf),"%Y-%m-%d %H:%M:%S", ptm);

    const char* fmt = "%s %s %s:%d ";
    //获取字符长度
    int size = snprintf(NULL,0,fmt,time_buf,m_levels[level],file,line);

    if(size > 0){
        char* buffer = new char[size+1];
        memset(buffer,0,size+1);
        snprintf(buffer,size+1,fmt,time_buf,m_levels[level],file,line);
        //std::cout << buffer << std::endl;
        m_fout << buffer;
        m_file_size += size;
        delete []buffer;
    }
    
    va_list arg_ptr;
    va_start(arg_ptr,format);
    //获取字符长度
    size = vsnprintf(NULL,0,format,arg_ptr); 
    va_end(arg_ptr);
    if(size > 0){
        char* content = new char[size+1];
        va_start(arg_ptr,format);
        vsnprintf(content,size+1,format,arg_ptr);
        va_end(arg_ptr);
        //std::cout << content << std::endl;
        m_fout << content;
        m_file_size += size;
        delete []content;
    }
    m_fout << "\n";
    //写入磁盘
    m_fout.flush();
    if(m_max_size > 0 && m_file_size > m_max_size){
        rotate();
    }
}

void Logger::set_size(int bytes){
    m_max_size = bytes;
}

void Logger::rotate(){
    //关闭以前的文件
    close();
    time_t ticks = time(NULL);
    struct tm* ptm = localtime(&ticks);
    char time_buf[32];
    memset(&time_buf,0,sizeof(time_buf));
    
    //格式化时间存储到time_buf中
    strftime(time_buf, sizeof(time_buf),"%Y_%m_%d %H_%M_%S_", ptm);
    //毫秒级别
    struct timeval tv;
    gettimeofday(&tv, NULL);
    char ms_buf[4];
    memset(ms_buf, 0, sizeof(ms_buf));
    snprintf(ms_buf, sizeof(ms_buf),"%03ld",tv.tv_usec/1000);
    strcat(time_buf,ms_buf);
    strcat(time_buf,"_log.txt");

    std::string filename = time_buf;
    std::cout << filename << std::endl;
    if(rename(m_filename.c_str(),filename.c_str()) != 0){
        std::cerr << "Error: Failed to rename log file from " << m_filename << " to " << filename << ". ";
        perror("errno");
        throw std::logic_error("rename log failed");
    }
    open(m_filename);
}