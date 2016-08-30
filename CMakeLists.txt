cmake_minimum_required(VERSION 3.0)
project(iot_sample)

# Version numbers
set(${CMAKE_PROJECT_NAME}_VERSION_MAJOR 1)
set(${CMAKE_PROJECT_NAME}_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code
configure_file(
	"${PROJECT_SOURCE_DIR}/inc/iot_sample.h.in"
	"${PROJECT_BINARY_DIR}/iot_sample.h"
)
# Add the binary tree to the search path for include files so we can find iot_sample.h
include_directories("${PROJECT_BINARY_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/inc)

set(iot_sample_c_files
	src/main.cpp
	src/iothub_sample.cpp
)

set(iot_sample_h_files
)

add_executable(
	${CMAKE_PROJECT_NAME}
	${iot_sample_c_files}
	${iot_sample_h_files}
)

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Os -Wno-unused-variable")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Og")

# Link in our external submodule lib sources
add_subdirectory(${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(${CMAKE_PROJECT_NAME}
	iothub_client
	iothub_client_amqp_transport
)

linkSharedUtil(${CMAKE_PROJECT_NAME})
linkUAMQP(${CMAKE_PROJECT_NAME})