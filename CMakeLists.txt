cmake_minimum_required(VERSION 3.5)
project(satsuma)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(DEJAVU_LOCATION ${CMAKE_SOURCE_DIR}/dejavu)

include(FetchContent)
FetchContent_Declare(dejavu
        GIT_REPOSITORY "https://github.com/markusa4/dejavu.git"
        GIT_TAG "origin/main"
        SOURCE_DIR ${DEJAVU_LOCATION})
FetchContent_MakeAvailable(dejavu)

add_compile_options("-O3")
add_compile_options("-Wall")
add_compile_options("-march=native")
# add_definitions(-g)
add_definitions(-DNDEBUG)


set(LOCAL_BOOST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/multiprecision-Boost_1_89_0/include")
if(EXISTS "${LOCAL_BOOST_DIR}/boost/multiprecision/cpp_int.hpp")
    message(STATUS "Using local Boost headers in ${LOCAL_BOOST_DIR}")
    include_directories(${LOCAL_BOOST_DIR})
else()
    message(STATUS "Fallback")
    set(BOOST_ROOT "/opt/homebrew/opt/boost")
    find_package(Boost REQUIRED)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(satsuma satsuma.cpp)

add_library(libsatsuma STATIC satsuma.cpp )
