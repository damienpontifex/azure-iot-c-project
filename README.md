# azure-iot-c-project

Test project to integrate the azure-iot-sdks C library as a submodule. Continuing to utilise CMake for generating build system.

Updates to the azure-iot-sdks library can then be integrated by updating the submodule.

## Initialize
```bash
# Update azure-iot-sdk submodule
git submodule update --init --recursive

# If wanting to update to later release
cd lib/azure-iot-sdks
git fetch origin
git checkout <release-tag>
cd ../../
git add lib
git commit -m 'updated azure-iot-sdks'
```

## Building

```bash
mkdir build
cd build
cmake ..
make -j4
./iot_sample "<connection-string>"
```