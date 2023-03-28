cmake_minimum_required(VERSION 3.5)

project(ament_cmake_extension_caller NONE)

find_package(ament_cmake_core REQUIRED)
find_package(simple_ament_cmake_extension REQUIRED)

install(DIRECTORY cmake DESTINATION share/${PROJECT_NAME})

ament_package(CONFIG_EXTRAS "ament_cmake_extension_caller.cmake")
