# CMake generated Testfile for 
# Source directory: H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode
# Build directory: H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test1 "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/build/Debug/orbitalsim_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;39;add_test;H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test1 "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/build/Release/orbitalsim_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;39;add_test;H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test1 "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/build/MinSizeRel/orbitalsim_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;39;add_test;H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test1 "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/build/RelWithDebInfo/orbitalsim_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;39;add_test;H:/Todo/Escuela/2023/EDA/Level1V2/level1Eda/WarmUpStarterCode/CMakeLists.txt;0;")
else()
  add_test(test1 NOT_AVAILABLE)
endif()
