cmake_minimum_required(VERSION 3.8)
project(simple_plugin)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
# pluginlib が必要
find_package(pluginlib REQUIRED)
find_package(simple_plugin_base REQUIRED)

add_library(${PROJECT_NAME} SHARED src/simple_plugin.cpp)
ament_target_dependencies(${PROJECT_NAME} pluginlib simple_plugin_base)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(simple_plugin_base)

# pluginlib_export_plugin_description_file でプラグインの存在を ament に登録する 第 2
# 引数にはプラグイン記述 XML ファイル名をいれる
pluginlib_export_plugin_description_file(
  simple_plugin_base plugins_description.xml)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  LIBRARY DESTINATION lib)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights comment the
  # line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo) comment the line
  # when this package is in a git repo and when a copyright and license is added
  # to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
