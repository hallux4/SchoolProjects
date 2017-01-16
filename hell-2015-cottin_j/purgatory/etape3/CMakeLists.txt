project (Etape3.1)

set (EXECUTABLE_OUTPUT_PATH ..)

# add the executable
add_executable(test_dynamic_fsa  main.cpp Edge.hpp FSA.hpp State.hpp Matcher.hpp)
