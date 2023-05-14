cmake_minimum_required(VERSION 2.8)
project(log)

#设置输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#输出详细的构建过程信息
set(CMAKE_VERBOSE_MAKEFILE NO)
#设置编译参数
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -DCMAKE_VERBOSE_MAKEFILE=ON " )
set(LIB_SRC src/log.cpp src/util.cpp)
add_library(log SHARED ${LIB_SRC})
add_executable(test tests/test.cpp)
add_dependencies(test log)
target_link_libraries(test log)
