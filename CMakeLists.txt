cmake_minimum_required(VERSION 2.8.11)
project(iot_sample)

include_directories(.)

set(iot_sample_c_files
	main.c
)

set(iot_sample_h_files
)

add_executable(
	${CMAKE_PROJECT_NAME}
	${iot_sample_c_files}
	${iot_sample_h_files}
)

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
