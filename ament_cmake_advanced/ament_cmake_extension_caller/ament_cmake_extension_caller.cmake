message("!!!!!!!!!!!TEST CALLER ament_register_extension!!!!!!!!!!!!!!!!!")

ament_register_extension(
  "simple_ament_cmake_extension" "ament_cmake_extension_caller"
  "ament_cmake_extension_caller_hook.cmake")
