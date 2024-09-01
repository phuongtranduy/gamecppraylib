##testing CMakeLists.txt adding existing boostlib
##running in window: shibimfighter\build> cmake -G "MinGW Makefiles" .. ; cmake --build .
##running in linux: shibimfighter\build> cmake .. ; cmake --build .
cmake_minimum_required(VERSION 3.0)
project(fightergame)


include(FetchContent) # once in the project to include the module
#just download and add one folder
FetchContent_Declare(raylibs
                    ## GIT_REPOSITORY https://github.com/phuongtranduy/temporary.git ##ok
                     GIT_REPOSITORY https://github.com/raysan5/raylib.git
                     #GIT_TAG master
                     #GIT_TAG 4.6-dev ##ok
                     GIT_TAG 5.0
                     GIT_PROGRESS TRUE ##enable GIT PROGRESS
                     #SOURCE_SUBDIR  mathlib
                     #GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
                     )
FetchContent_MakeAvailable(raylibs)

add_executable(fightergame BaseSpace.cpp  Bullet.cpp  Enemy.cpp  Explosion.cpp  Fighter.cpp  main.cpp  PowerDrug.cpp)
target_include_directories(fightergame PRIVATE .)
target_link_libraries(fightergame  raylib )
add_custom_command(
    TARGET fightergame
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy_directory 
        "${CMAKE_SOURCE_DIR}/audio"
        "${CMAKE_BINARY_DIR}/audio"
        COMMENT "Copying runtime data to binary directory"
)

add_custom_command(
    TARGET fightergame
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy_directory 
        "${CMAKE_SOURCE_DIR}/texture"
        "${CMAKE_BINARY_DIR}/texture"
        COMMENT "Copying runtime data to binary directory"
)


include(CTest)
enable_testing()
add_executable(tst_basespace tst_basespace.cpp)
add_executable(tst_enemy tst_enemy.cpp)
add_test(NAME tst_basespace COMMAND tst_basespace)
add_test(NAME tst_enemy COMMAND tst_enemy)

# cmake -S. -Bbuild
# cd build
# cmake --build .
# ctest
## we have CMAKE_CTEST_COMMAND and CMAKE_COMMAND