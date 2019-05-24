cmake_minimum_required(VERSION 2.8)

project(chatClient)

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_COMPONENTS
    asio
    thread
    chrono)

set(SOURCE_MODEL chatClientModel.cpp)
set(SOURCE_VIEW chatClientView.cpp)
set(SOURCE_CONTROLLER chatClientController.cpp)
set(HEADER_MODEL chatClientModel.h)
set(HEADER_VIEW chatClientView.h)
set(HEADER_CONTROLLER chatClientController.h)

find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED_FILES)
include_directories(${Boost_INCLUDE_DIRS})

add_library(controller STATIC ${SOURCE_CONTROLLER} ${HEADER_CONTROLLER})
add_library(model STATIC ${SOURCE_MODEL} ${HEADER_MODEL})
add_library(view STATIC ${SOURCE_VIEW} ${HEADER_VIEW})

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} controller model view Boost::thread Boost::chrono)
