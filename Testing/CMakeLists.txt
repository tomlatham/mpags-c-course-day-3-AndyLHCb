# - Build sub-script for the MPAGSCipher library unit tests


add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Most basic tests
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# First catch-based test
add_executable(testCatch testCatch.cpp)
add_test(NAME test-catch COMMAND testCatch)

# Testing transformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher)
add_test(NAME test-transformchar COMMAND testTransformChar)

# Testing CaesarCipher
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)

# Testing processCommandLine
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine MPAGSCipher)
add_test(NAME test-processcommandline COMMAND testProcessCommandLine)
