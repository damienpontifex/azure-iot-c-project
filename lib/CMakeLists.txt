# azure-iot-sdk options and linking
set(skip_unittests ON CACHE BOOL "Skip azure-iot-sdks unit tests")
set(use_http OFF CACHE BOOL "Dont use http")
set(use_mqtt OFF CACHE BOOL "Dont use mqtt")
set(build_samples OFF CACHE BOOL "Dont build iot hub samples")
set(build_service_client OFF CACHE BOOL "Dont build iot hub service client")
set(dont_use_uploadtoblob ON CACHE BOOL "Not using upload to blob at this stage")

add_subdirectory(azure-iot-sdks/c)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE azure-iot-sdks/c/iothub_client/inc)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE azure-iot-sdks/c/azure-c-shared-utility/inc)