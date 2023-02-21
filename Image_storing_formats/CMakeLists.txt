cmake_minimum_required(VERSION 2.8)
project( Image_storing_formats )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Image_storing_formats main.cpp )
target_link_libraries( Image_storing_formats ${OpenCV_LIBS} )

