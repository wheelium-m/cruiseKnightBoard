#set(ALL_HEADERS KnightBoard/KnightBoard.h)

set(KNIGHT_BOARD_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/KnightBoard/KnightBoard.h PARENT_SCOPE)
set(ALL_HEADERS ${ALL_HEADERS} ${KNIGHT_BOARD_HEADERS} PARENT_SCOPE)

set(SQUARE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/Square/Square.h PARENT_SCOPE)
set(ALL_HEADERS ${ALL_HEADERS} ${SQUARE_HEADERS} PARENT_SCOPE)

set(ALL_HEADERS ${ALL_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/fullKnightBoard.h PARENT_SCOPE)