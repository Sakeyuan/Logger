cmake_minimum_required(VERSION 2.8)
project(log)

#设置输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置编译参数
# -rdynamic：生成动态链接符号表，允许在程序运行时通过dlopen()函数加载动态链接库。
# -O3：启用最高级别的优化，以尽可能提高代码执行速度。
# -g：生成调试信息，以便在调试程序时进行符号级别的跟踪和分析。
# -std=c++11：使用C++11标准进行编译。
# -Wall：启用所有警告。
# -Wno-deprecated：禁止显示有关已弃用函数或特性的警告。
# -Werror：将所有警告视为错误，导致编译过程中出现警告时终止编译。
# -Wno-unused-function：禁止显示未使用函数的警告。
# -DCMAKE_VERBOSE_MAKEFILE=ON：在生成Makefile时产生详细输出，显示构建过程的详细信息

set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -DCMAKE_VERBOSE_MAKEFILE=ON " )
set(LIB_SRC src/log.cpp src/util.cpp)
add_library(log SHARED ${LIB_SRC})
add_executable(test tests/test.cpp)
add_dependencies(test log)
target_link_libraries(test log)
