cmake_minimum_required(VERSION 3.10)
project(FinalProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(game_logic STATIC
    src/autopsy.cpp
    src/choice.cpp 
    src/clue.cpp
    src/day.cpp
    src/dialogue.cpp
    src/ending.cpp
    src/gameLoader.cpp
    src/gameLoop.cpp
    src/interface.cpp
    src/interview.cpp
    src/printer.cpp
    src/item.cpp
    src/location.cpp
    src/person.cpp
    src/player.cpp
    src/printer.cpp
)

target_include_directories(game_logic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(FinalProject src/main.cpp)

target_link_libraries(FinalProject game_logic)

add_subdirectory(googletest)

add_executable(run_tests
    src/testItemClass.cpp  
    src/testInterview.cpp
    src/testPlayer.cpp  
    src/testAutopsy.cpp
    src/testClues.cpp 
    src/testGameLoader.cpp 
    src/testLocation.cpp 
    src/testPersonClass.cpp
)

target_link_libraries(run_tests
    game_logic
    GTest::gtest_main
)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/game_text_files/"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/game_text_files/"
)

include(CTest)
add_test(NAME MyAllTests COMMAND run_tests)
