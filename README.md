# modern-cpp-demo

# Pre requisites

```
sudo apt update
sudo apt install -y ninja-build
```

# Build

```
vcpkg install

rm -rf build


cmake -S . -B build -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake

cmake --build build
```

# VCPKG

```
cd ~
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh


export VCPKG_ROOT=$HOME/vcpkg
export PATH=$VCPKG_ROOT:$PATH

```
