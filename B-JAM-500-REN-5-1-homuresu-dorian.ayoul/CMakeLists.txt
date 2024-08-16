# ############### CONFIG ##################

# init Cmake
cmake_minimum_required(VERSION 3.22)
project(Homuresu LANGUAGES C VERSION 1.0)

# set flags
if(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++20 -Ofast")
else()
    set(CMAKE_CXX_FLAGS "/std:c++20 /Ox /EHsc")
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(WIN32)
    set(BUILD_SHARED_LIBS OFF)
else()
    set(BUILD_SHARED_LIBS ON)
endif()

# include fetchcontent
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# ################# FETCH DEPENDENCIES ##################
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.2.0.tar.gz
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(raylib)

# ################# BLIB ##################

# set library name
set(BLIB BLIB)

# set root path
set(BLIB_ROOT lib/linked_list)

# fetch include paths
set(BLIB_INC
    ${BLIB_ROOT}/include
)

# fetch source files
set(BLIB_SRC
    ${BLIB_ROOT}/src/manage_list.c
    ${BLIB_ROOT}/src/manage_node.c
    ${BLIB_ROOT}/src/print_list.c
    ${BLIB_ROOT}/src/push_node.c
    ${BLIB_ROOT}/src/remove_node.c
)

# set include paths
include_directories(
    ${BLIB_INC}
)

# set source files (create library/executable)
add_library(${BLIB} ${BLIB_SRC})

# ################# CLIENT ##################

# set executable name
set(CLIENT homuresu)

# set root path
set(CLIENT_ROOT src/client)

# fetch include paths
set(CLIENT_INC
    ${CLIENT_ROOT}/include
)

if (UNIX)
set(CLIENT_UNIX_SRC
    ${CLIENT_ROOT}/network/get_packet.c
    ${CLIENT_ROOT}/network/init_client.c
    ${CLIENT_ROOT}/network/send_packet.c
    ${CLIENT_ROOT}/memory.c
    ${CLIENT_ROOT}/manage.c
    ${CLIENT_ROOT}/client.c
    ${CLIENT_ROOT}/action.c
)
else()
set(CLIENT_WINDOWS_SRC
    ${CLIENT_ROOT}/anticheat.c
)
endif()

# fetch source files
set(CLIENT_SRC
    ${CLIENT_UNIX_SRC}
    ${CLIENT_WINDOWS_SRC}
    ${CLIENT_ROOT}/main.c
    ${CLIENT_ROOT}/selection_menu.c
    ${CLIENT_ROOT}/menu.c

    ${CLIENT_ROOT}/init/initProjectile.c
    ${CLIENT_ROOT}/init/initCamera.c
    ${CLIENT_ROOT}/init/initWall.c
    ${CLIENT_ROOT}/init/initWindow.c
    ${CLIENT_ROOT}/init/initSounds.c
    ${CLIENT_ROOT}/init/initMusic.c
    ${CLIENT_ROOT}/init/initModels.c
    ${CLIENT_ROOT}/init/initGame.c
    ${CLIENT_ROOT}/init/initSprite.c
    ${CLIENT_ROOT}/init/initMenu.c
    ${CLIENT_ROOT}/init/initStat.c
    ${CLIENT_ROOT}/init/initItem.c
    ${CLIENT_ROOT}/init/initPlayer.c

    ${CLIENT_ROOT}/draw/drawProjectile.c
    ${CLIENT_ROOT}/draw/drawPlayer.c
    ${CLIENT_ROOT}/draw/drawCube.c
    ${CLIENT_ROOT}/draw/drawGame.c
    ${CLIENT_ROOT}/draw/drawTwoD.c

    ${CLIENT_ROOT}/manage/manageProjectile.c
    ${CLIENT_ROOT}/manage/manageSounds.c
    ${CLIENT_ROOT}/manage/managePlayer.c
    ${CLIENT_ROOT}/manage/manageSprite.c

    ${CLIENT_ROOT}/update/updateKeyboard.c
    ${CLIENT_ROOT}/update/updateMouse.c
    ${CLIENT_ROOT}/update/updateProjectile.c
    ${CLIENT_ROOT}/update/updateCollision.c
    ${CLIENT_ROOT}/update/updateEvent.c
    ${CLIENT_ROOT}/update/updateGame.c
    
    ${CLIENT_ROOT}/main.c
)

# set include paths
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CLIENT_INC}
)

# set source files (create library/executable)
add_executable(${CLIENT} ${CLIENT_SRC})

# link library/executable with deps
target_link_libraries(${CLIENT} PUBLIC raylib)
target_link_libraries(${CLIENT} PUBLIC ${BLIB})
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

if (UNIX)
# ################# SERVER ###################

# set executable name
set(SERVER homureserver)

# set root path
set(SERVER_ROOT src/server)

# fetch include paths
set(SERVER_INC
    ${SERVER_ROOT}/include
)

# fetch source files
set(SERVER_SRC
    ${SERVER_ROOT}/main.c
    ${SERVER_ROOT}/manage.c
    ${SERVER_ROOT}/server.c
    ${SERVER_ROOT}/cli_accept.c
    ${SERVER_ROOT}/action.c
    ${SERVER_ROOT}/network/add_client.c
    ${SERVER_ROOT}/network/get_packet.c
    ${SERVER_ROOT}/network/init_srv.c
    ${SERVER_ROOT}/network/send_packet.c
    ${SERVER_ROOT}/network/rm_client.c
    ${SERVER_ROOT}/network/srv_struct.c
)

# set include paths
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SERVER_INC}
)

# set source files (create library/executable)
add_executable(${SERVER} ${SERVER_SRC})

# link library/executable with deps
target_link_libraries(${SERVER} PUBLIC raylib)
target_link_libraries(${SERVER} PUBLIC ${BLIB})
set_target_properties(${SERVER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set_target_properties(${SERVER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})
endif()