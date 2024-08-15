cmake_minimum_required(VERSION 3.10)

# Project name
project(Zappy_Server)

set(CMAKE_CXX_STANDARD 20)

# Conan
include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(unit-tests
  src/main.cpp
  src/Utils.cpp
  src/TestClient.cpp
  src/TestCore.cpp
  src/TestGame.cpp
  src/TestInventory.cpp
  src/TestMap.cpp
  src/TestServer.cpp
  src/TestTeams.cpp
  src/TestTrantorian.cpp
  src/TestParseParams.cpp
  src/TestGUIProtocol.cpp
  src/TestGUIEvent.cpp
  src/TestUtils.cpp
  src/TestDefaultProtocol.cpp

  ../server/src/manage_struct/manage_client.c
  ../server/src/manage_struct/manage_core.c
  ../server/src/manage_struct/manage_game.c
  ../server/src/manage_struct/manage_inventory.c
  ../server/src/manage_struct/manage_map.c
  ../server/src/manage_struct/manage_server.c
  ../server/src/manage_struct/manage_team.c
  ../server/src/manage_struct/manage_trantorian.c
  ../server/src/utils/parse_params.c
  ../server/src/utils/set_fds.c
  ../server/src/server_handling/server_handling.c
  ../server/src/server_handling/start_server.c
  ../server/src/client_handling/client_update.c
  ../server/src/client_handling/client_def_exec_command.c
  ../server/src/client_handling/default_commands/forward.c
  ../server/src/client_handling/default_commands/right.c
  ../server/src/client_handling/default_commands/left.c
  ../server/src/client_handling/default_commands/look.c
  ../server/src/client_handling/default_commands/inventory.c
  ../server/src/client_handling/default_commands/broadcast.c
  ../server/src/client_handling/default_commands/connect_nbr.c
  ../server/src/client_handling/default_commands/fork.c
  ../server/src/client_handling/default_commands/eject.c
  ../server/src/client_handling/default_commands/take.c
  ../server/src/client_handling/default_commands/set.c
  ../server/src/client_handling/default_commands/incantation.c
  ../server/src/client_handling/default_commands/death.c
  ../server/src/utils/command_utils.c
  ../server/src/utils/is_uuid.c
  ../server/src/client_handling/client_command_utils.c
  ../server/src/client_handling/gui_commands/msz.c
  ../server/src/client_handling/gui_commands/bct.c
  ../server/src/client_handling/gui_commands/mct.c
  ../server/src/client_handling/gui_commands/tna.c
  ../server/src/client_handling/gui_commands/ppo.c
  ../server/src/client_handling/gui_commands/plv.c
  ../server/src/client_handling/gui_commands/pin.c
  ../server/src/client_handling/gui_commands/sgt.c
  ../server/src/client_handling/gui_commands/sst.c
  ../server/src/client_handling/gui_commands/pnw.c
  ../server/src/client_handling/gui_commands/pex.c
  ../server/src/client_handling/gui_commands/pbc.c
  ../server/src/client_handling/gui_commands/pic.c
  ../server/src/client_handling/gui_commands/pie.c
  ../server/src/client_handling/gui_commands/pfk.c
  ../server/src/client_handling/gui_commands/pdr.c
  ../server/src/client_handling/gui_commands/pgt.c
  ../server/src/client_handling/gui_commands/pdi.c
  ../server/src/client_handling/gui_commands/enw.c
  ../server/src/client_handling/gui_commands/eht.c
  ../server/src/client_handling/gui_commands/ebo.c
  ../server/src/client_handling/gui_commands/edi.c
  ../server/src/client_handling/gui_commands/seg.c
  ../server/src/client_handling/gui_commands/smg.c
  ../server/src/client_handling/gui_commands/suc.c
  ../server/src/client_handling/gui_commands/sbp.c
  ../server/src/client_handling/client_define_type.c
  ../server/src/client_handling/client_gui_exec_command.c
  ../server/src/game_handling/game_utils/game_calc.c
  ../server/src/game_handling/game_utils/game_utils.c
  ../server/src/game_handling/game_update.c
  ../server/src/game_handling/game_update_handler.c
  ../server/src/game_handling/game_update_trantorians.c
  ../server/src/game_handling/game_utils/game_calc_sound_dir.c
  ../server/src/game_handling/game_update_map.c
  ../server/src/game_handling/game_utils/game_map_utils.c
  ../server/src/game_handling/game_utils/game_look_utils.c
  ../server/src/game_handling/game_utils/game_look_utils_2.c
  ../server/src/game_handling/game_utils/trantorian_utils.c
  ../server/src/client_handling/clients_update_delete.c
  ../server/src/manage_struct/manage_incantation.c
  ../server/src/game_handling/game_update_incantations.c
  ../server/src/utils/parse_params_2.c
)

target_include_directories(unit-tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/../server/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/../include/
)

target_link_directories(unit-tests
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../libs
)

target_link_libraries(unit-tests
  PRIVATE
  list
  nlib
  uuid
)
target_link_libraries(unit-tests PRIVATE m)
target_link_libraries(unit-tests PRIVATE ${CONAN_LIBS})
target_link_libraries(unit-tests PRIVATE ${CMAKE_DL_LIBS})

ENABLE_TESTING()
ADD_TEST(tests bin/unit-tests)
