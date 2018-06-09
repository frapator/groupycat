cmake_minimum_required(VERSION 2.6)
project(groupycat)

set(MySources main.cpp src/common/Common.cpp src/uci/Uci.cpp src/uci/UciParser.cpp src/board/Board.cpp src/board/Board_passedpawn.cpp src/board/Board_fork.cpp src/board/Board_pin.cpp src/board/AMove.cpp src/engine/Engine.cpp)

add_executable(groupycat  ${MySources})

find_package (Threads)
target_link_libraries (groupycat ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS groupycat RUNTIME DESTINATION groupycat)
