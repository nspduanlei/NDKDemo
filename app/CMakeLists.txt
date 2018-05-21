cmake_minimum_required(VERSION 3.4.1)

add_library(hello-lib
            SHARED
            src/main/cpp/hello-lib.c )

find_library(log-lib
             log )

target_link_libraries(hello-lib
                      ${log-lib} )