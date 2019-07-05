cmake_minimum_required(VERSION 3.4)
project(tgDatabase)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

## ================================================================

set(SOURCE_FILES
        DataObject.cpp DataObject.h
        DataObjectStatement.cpp DataObjectStatement.h
        Exceptions/DataObjectException.cpp Exceptions/DataObjectException.h
        DataObjectConfiguration.h
        Value.cpp Value.h
        Line.h Param.cpp Param.h)

include_directories(vendor)

## ================================================================

add_library(tgDatabase STATIC ${SOURCE_FILES})
add_library(tgDatabase_shared SHARED ${SOURCE_FILES})

target_link_libraries(tgDatabase tgTypes)
target_link_libraries(tgDatabase_shared tgTypes)