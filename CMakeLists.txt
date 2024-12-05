cmake_minimum_required(VERSION 3.28)

project(sysmon VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

include_directories("../libbpl_sys/libbpl_sys/include")

add_executable(sysmon src/sysmon.cpp)

target_link_libraries(sysmon PRIVATE bpl_sys)

install(TARGETS sysmon DESTINATION bin)
