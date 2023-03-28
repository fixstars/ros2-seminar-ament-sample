message("!!!!!!!!!!!TEST!!!!!!!!!!!!!!")

if(_${PROJECT_NAME}_AMENT_PACKAGE)
  message(
    FATAL_ERROR
      "find_package(ament_lint_auto) must be called before ament_package()")
endif()

ament_register_extension("ament_package" "simple_ament_cmake_extension"
                         "simple_ament_cmake_extension_hook.cmake")
