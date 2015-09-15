add_executable(KnightBoardTest KnightBoard/KnightBoardTest.cpp ${ALL_HEADERS})
target_link_libraries(KnightBoardTest KnightBoard Square)
add_test(KnightBoardTestTarget KnightBoardTest 0)