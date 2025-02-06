cmake_minimum_required(VERSION 2.8)

project(trump C CXX)

enable_testing()

set(CXX_FLAGS
 # -DVALGRIND
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64 # -D 定义一个编译器宏参数
 -Wall                  # 展示所有警告
 -Wextra                # 额外警告
 -Werror                # 警告视为错误
 -Wconversion           # 警告可能改变值的隐式转换
 -Wno-unused-parameter  # 未使用的参数不警告
 -Wold-style-cast       # 警告C-style转换
 -Woverloaded-virtual   # 警告子类函数重载声明屏蔽了基类虚函数，造成无法重写
 -Wpointer-arith        # 警告对函数指针或void*指针进行算数运算
 -Wshadow               # 警告局部变量名称遮蔽另一个局部变量或全局变量
 -Wwrite-strings        # 警告向字符串常量写入，其规定字符串类型为const char[n],将其地址赋值给non-const char*将警告
 -march=native          # 指定cpu体系结构为本地硬件结构， gcc可以进行交叉编译，生成其他架构可用的代码
 # -MMD
 -std=c++20
 -rdynamic
 )
 string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O2 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR})

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

# 配置安装目录
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/run)

# aux_source_directory(common COMMON_SRC)
# aux_source_directory(time TIME_SRC)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
  add_subdirectory(tests)
endif()