cmake_minimum_required(VERSION 3.8)
project(ament_cmake_auto_test_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()
ament_auto_add_library(${PROJECT_NAME} SHARED DIRECTORY src include)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  set(TEST_NAME ${PROJECT_NAME}_test)
  ament_auto_find_test_dependencies()
  ament_auto_add_gtest(${TEST_NAME} test/test_example.cpp)
endif()

ament_package()
