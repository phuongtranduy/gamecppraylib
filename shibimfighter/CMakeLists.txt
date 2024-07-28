##tsting CMakeLists.txt adding existing boostlib
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
                     #SOURCE_SUBDIR  mathlib
                     #GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
                     )
FetchContent_MakeAvailable(raylibs)

add_executable(fightergame BaseSpace.cpp  Bullet.cpp  Enemy.cpp  Explosion.cpp  Fighter.cpp  main.cpp  PowerDrug.cpp)
target_include_directories(fightergame PRIVATE .)
target_link_libraries(fightergame  raylib GL m pthread dl rt X11)
