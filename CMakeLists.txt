cmake_minimum_required( VERSION 2.6 )

project( sudoku_projekt )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package( SDL2 REQUIRED )


include_directories(/usr/local/Cellar/sdl2/2.26.4/include /usr/local/Cellar/sdl2_ttf/2.20.2/include /usr/local/Cellar/sdl2/2.26.4/include/SDL2)
link_directories(/usr/local/Cellar/sdl2/2.26.4/lib /usr/local/Cellar/sdl2_ttf/2.20.2/lib)



set(CMAKE_CXX_STANDARD 11)

if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()

link_libraries (
  SDL2
  SDL2_ttf
)

add_library( graphics graphics.cpp )


add_executable( test_graphics main.cpp )
target_link_libraries( test_graphics graphics pthread)

add_executable( helloworld helloworld.cpp number_widget.cpp widget.cpp menu_widget.cpp string_widget.cpp sudoku_grafika.cpp sudoku_game.cpp)
target_link_libraries( helloworld graphics)


