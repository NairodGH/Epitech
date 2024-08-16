################# CONFIG ##################

cmake_minimum_required(VERSION 3.16)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Project name
project(kidiot LANGUAGES C)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-fdiagnostics-color=always)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fcolor-diagnostics)
endif()

################## BUILD ##################

set(EXEC_NAME
  kidiot
)

set(INC
  include/
)

set(SRC
  src/game/init_game.c
  src/game/map_utils.c
  src/game/game_loop.c
  src/game/move_players.c
  src/game/clock_gest.c
  src/game/clock_gest_split.c
  src/game/map_utils_other.c
  src/game/end_screen.c
  src/game/load_map.c
  src/game/init_game_split.c
  src/game/gest_mult_obs.c
  src/display/draw.c
  src/display/draw_map.c
  src/display/draw_entity.c
)

set(CMAKE_EXE_LINKER_FLAGS -fexceptions)

add_executable(${EXEC_NAME}
  ${SRC}
  src/main.c
)

target_include_directories(${EXEC_NAME} PUBLIC
  ${INC}
)

# link with libs
find_package(raylib REQUIRED)
target_link_libraries(${EXEC_NAME} PUBLIC raylib)
################## MISC ###################

add_custom_command(
  TARGET ${EXEC_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_BINARY_DIR}/${EXEC_NAME}
    ${CMAKE_CURRENT_BINARY_DIR}/../${EXEC_NAME}
)