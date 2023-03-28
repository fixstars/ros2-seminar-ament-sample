cmake_minimum_required(VERSION 3.8)
project(simple_library)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(${PROJECT_NAME} SHARED src/simple.cpp
                                   include/simple_library/simple.hpp)
target_include_directories(
  ${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

set_target_properties(
  ${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/simple_library/simple.hpp)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-config
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})
install(EXPORT ${PROJECT_NAME}-config DESTINATION lib/cmake/${PROJECT_NAME})
