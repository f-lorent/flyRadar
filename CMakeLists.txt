cmake_minimum_required(VERSION 3.31)
project(flyRadar C)

set(CMAKE_C_STANDARD 11)

add_executable(flyRadar src/main.c
        src/logic.c
        src/parse.c
        src/requestAPI.c
        include/requestAPI.h
        include/logic.h
        include/parse.h
        librairies/cJSON.c
)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(flyRadar ${CURL_LIBRARIES})

