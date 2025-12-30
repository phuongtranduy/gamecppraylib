##testing CMakeLists.txt adding existing boostlib
##running in window: shibimfighter\build> cmake -G "MinGW Makefiles" .. ; cmake --build .
##running in linux: shibimfighter\build> cmake .. ; cmake --build .

#https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-To-Write-Platform-Checks
# Platform Variables
# CMake sets certain variables to true depending on the current platform and toolchain in use. These always describe the target platform.  In older versions of CMake, these were the only way of detecting the current platform.
# UNIX : is TRUE on all UNIX-like OS's, including Apple OS X and CygWin
# WIN32 : is TRUE on Windows. Prior to 2.8.4 this included CygWin
# APPLE : is TRUE on Apple systems. Note this does not imply the
# system is Mac OS X, only that APPLE is #defined in C/C++
# header files.
# MINGW : is TRUE when using the MinGW compiler in Windows
# MSYS : is TRUE when using the MSYS developer environment in Windows
# CYGWIN : is TRUE on Windows when using the CygWin version of cmake

cmake_minimum_required(VERSION 3.0) ## Compatibility with CMake < 3.5 will be removed from a future version of CMake.
project(fightergame)

if(WIN32)
    ##Hide console
    set(CMAKE_CXX_FLAGS "-mwindows") ##hide console open when openning game
    set(CMAKE_CXX_FLAGS_DEBUG "-mwindows") ##Add -mwindows to the compile flags.
    set(CMAKE_CXX_FLAGS_RELEASE "-mwindows")
endif()

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
#set(CMAKE_EXE_LINKER_FLAGS "-static" CACHE STRING "Linker flags to create a static executable")

add_executable(cropdemo cropdemo.cpp)
target_include_directories(cropdemo PRIVATE .)
target_link_libraries(cropdemo  raylib )
add_executable(fightergame BaseSpace.cpp  Bullet.cpp  Enemy.cpp  Explosion.cpp  Fighter.cpp  main.cpp  PowerDrug.cpp LoadedImage.cpp)
target_include_directories(fightergame PRIVATE .)
target_link_libraries(fightergame  raylib )
#target_compile_definitions(Fightergame PRIVATE "-mwindows")
#add_compile_options("-mwindows")
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