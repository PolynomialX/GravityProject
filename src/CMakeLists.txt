cmake_minimum_required(VERSION 3.10)
project(NBodyDynamics VERSION 0.0.1)

# Specify C++ standard to 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Utilise a header file to pass in CMake config settings
configurefile(NBodyDynamicsConfig.h.in NBodyDynamicsConfig.h)

add_subdirectory(MathematicsLib)

add_executable(NBodyDynamics main.cpp)

target_link_libraries(NBodyDynamics PUBLIC Mathematics)
target_include_directories(NBodyDynamics PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/MathematicsLib")