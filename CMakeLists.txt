cmake_minimum_required(VERSION 3.5.1)
project(UDPServerClientChat)

#Header directory
include_directories(include)

#find_package(Threads REQUIRED)


#Adding own libraries
file( GLOB LIB_SOURCES libs/*c)
file( GLOB LIB_HEADERS libs/*h)

add_library(netconf ${LIB_SOURCES} ${LIB_HEADERS} )


#manually adding sources
set(SOURCES src/mainApp.c)
set(CMAKE_C_FLAGS "-O0")
#add_compile_options("-lpthread")



#can also use the file glob
#file(GLOB SOURCES "src/*.c")

add_executable(mainApp ${SOURCES})
#add_executable(stdin2ethernet ${SOURCES})
TARGET_LINK_LIBRARIES(mainApp netconf pthread)