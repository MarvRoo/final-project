# CMake generated Testfile for 
# Source directory: /home/csmajs/mrodr413/final-project-sec21-proj-group-5
# Build directory: /home/csmajs/mrodr413/final-project-sec21-proj-group-5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyAllTests "/home/csmajs/mrodr413/final-project-sec21-proj-group-5/build/run_tests")
set_tests_properties(MyAllTests PROPERTIES  _BACKTRACE_TRIPLES "/home/csmajs/mrodr413/final-project-sec21-proj-group-5/CMakeLists.txt;57;add_test;/home/csmajs/mrodr413/final-project-sec21-proj-group-5/CMakeLists.txt;0;")
subdirs("googletest")
