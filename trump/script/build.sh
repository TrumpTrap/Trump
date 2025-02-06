###
 # @Author: Mass
 # @Date: 2022-02-15 23:14:19
 # @LastEditors: Mass
 # @LastEditTime: 2022-07-11 15:27:03
 # @FilePath: /trump/script/build.sh
### 

#! /bin/sh

set -x

SOURCE_DIR=`pwd/..`
BUILD_DIR=${BUILD_DIR:-build}
BUILD_TYPE=${BUILD_TYPE:-debug}
INSTALL_DIR=${INSTALL_DIR:-${BUILD_TYPE}-install-cpp11}
CXX=${CXX:-g++}

# ln -sf $BUILD_DIR/$BUILD_TYPE-cpp11/compile_commands.json

cd ..

mkdir -p $BUILD_DIR/$BUILD_TYPE-cpp11 \
  && cd $BUILD_DIR/$BUILD_TYPE-cpp11 \
  && cmake ../..\
           -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
           -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
           -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
           $SOURCE_DIR \
  && make $* \
  && ctest . \
  && make install


# Use the following command to run all the unit tests
# at the dir $BUILD_DIR/$BUILD_TYPE :
# CTEST_OUTPUT_ON_FAILURE=TRUE make test

# cd $SOURCE_DIR && doxygen