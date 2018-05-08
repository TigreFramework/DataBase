cmake_minimum_required(VERSION 3.4)
project(tgDatabase)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

## ================================================================

set(SOURCE_FILES
        Database.cpp Database.h
        Value.cpp Value.h
        Line.h)

include_directories(vendor)

## ================================================================

add_library(tgDatabase STATIC ${SOURCE_FILES})
add_library(tgDatabase_shared SHARED ${SOURCE_FILES})