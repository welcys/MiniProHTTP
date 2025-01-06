# CMake generated Testfile for 
# Source directory: /Users/welch/Desktop/top/MiniPro-HTTP/tests
# Build directory: /Users/welch/Desktop/top/MiniPro-HTTP/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_threadpool "/Users/welch/Desktop/top/MiniPro-HTTP/build/tests/test_threadpool")
set_tests_properties(test_threadpool PROPERTIES  _BACKTRACE_TRIPLES "/Users/welch/Desktop/top/MiniPro-HTTP/tests/CMakeLists.txt;21;add_test;/Users/welch/Desktop/top/MiniPro-HTTP/tests/CMakeLists.txt;0;")
add_test(test_log "/Users/welch/Desktop/top/MiniPro-HTTP/build/tests/test_log")
set_tests_properties(test_log PROPERTIES  _BACKTRACE_TRIPLES "/Users/welch/Desktop/top/MiniPro-HTTP/tests/CMakeLists.txt;33;add_test;/Users/welch/Desktop/top/MiniPro-HTTP/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
