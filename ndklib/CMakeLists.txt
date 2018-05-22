cmake_minimum_required(VERSION 3.4.1)

#设置生成的so动态库最后输出的路径
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})


add_library(hello-lib
            SHARED
            src/main/cpp/hello-lib.c )

find_library(log-lib
             log )

target_link_libraries(hello-lib
                      ${log-lib} )