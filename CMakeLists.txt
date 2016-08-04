cmake_minimum_required(VERSION 2.8.11)
project(iot_sample)

# Version numbers
set(iot_sample_VERSION_MAJOR 1)
set(iot_sample_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code
configure_file(
	"${PROJECT_SOURCE_DIR}/iot_sample.h.in"
	"${PROJECT_BINARY_DIR}/iot_sample.h"
)
# Add the binary tree to the search path for include files so we can find iot_sample.h
include_directories("${PROJECT_BINARY_DIR}")

include_directories(.)

set(iot_sample_c_files
	main.cpp
)

set(iot_sample_h_files
)

add_executable(
	${CMAKE_PROJECT_NAME}
	${iot_sample_c_files}
	${iot_sample_h_files}
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(skip_unittests ON)

option(skip_unittests "" ON)
add_subdirectory(lib/azure-iot-sdks/c)
include_directories(lib/azure-iot-sdks/c/iothub_client/inc)
include_directories(lib/azure-iot-sdks/c/azure-c-shared-utility/inc)

target_link_libraries(${CMAKE_PROJECT_NAME}
	iothub_client
	iothub_client_amqp_transport
	aziotsharedutil
	uamqp
	pthread
	curl
	ssl
	crypto
)

linkSharedUtil(${CMAKE_PROJECT_NAME})
linkUAMQP(${CMAKE_PROJECT_NAME})
