# CMake generated Testfile for 
# Source directory: C:/Users/tim11/lab1
# Build directory: C:/Users/tim11/lab1/build/default-windows
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[lab1_run]=] "C:/Users/tim11/lab1/build/default-windows/Debug/lab1.exe")
  set_tests_properties([=[lab1_run]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tim11/lab1/CMakeLists.txt;10;add_test;C:/Users/tim11/lab1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[lab1_run]=] "C:/Users/tim11/lab1/build/default-windows/Release/lab1.exe")
  set_tests_properties([=[lab1_run]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tim11/lab1/CMakeLists.txt;10;add_test;C:/Users/tim11/lab1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[lab1_run]=] "C:/Users/tim11/lab1/build/default-windows/MinSizeRel/lab1.exe")
  set_tests_properties([=[lab1_run]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tim11/lab1/CMakeLists.txt;10;add_test;C:/Users/tim11/lab1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[lab1_run]=] "C:/Users/tim11/lab1/build/default-windows/RelWithDebInfo/lab1.exe")
  set_tests_properties([=[lab1_run]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tim11/lab1/CMakeLists.txt;10;add_test;C:/Users/tim11/lab1/CMakeLists.txt;0;")
else()
  add_test([=[lab1_run]=] NOT_AVAILABLE)
endif()
