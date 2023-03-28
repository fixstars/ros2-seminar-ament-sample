cmake_minimum_required(VERSION 3.5)

project(simple_ament_cmake_extension NONE)

find_package(ament_cmake_core REQUIRED)

install(DIRECTORY cmake DESTINATION share/${PROJECT_NAME})

ament_package(CONFIG_EXTRAS "simple_ament_cmake_function_extras.cmake")
