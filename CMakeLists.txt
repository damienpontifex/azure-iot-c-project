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

include_directories(inc)

set(iot_sample_c_files
	main.cpp
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

# azure-iot-sdk options and linking
set(skip_unittests ON CACHE BOOL "Skip azure-iot-sdks unit tests")
set(use_http OFF CACHE BOOL "Dont use http")
set(use_mqtt OFF CACHE BOOL "Dont use mqtt")
set(build_samples OFF CACHE BOOL "Dont build iot hub samples")
set(build_service_client OFF CACHE BOOL "Dont build iot hub service client")
set(dont_use_uploadtoblob ON CACHE BOOL "Not using upload to blob at this stage")

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
