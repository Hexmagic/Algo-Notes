project(Algo-Notes)
cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(OpenCV REQUIRED)
find_package(absl)
include_directories(
    /usr/local/include
    include
)
file(GLOB NOTES note/*.cpp)

foreach(FILEPATH ${NOTES} )
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" BASENAME ${FILEPATH})
    message(${BASENAME})
    add_executable(${BASENAME} ${FILEPATH})
    target_link_libraries(${BASENAME} absl::time)
endforeach( )

add_executable(rect src/rect.cpp)
target_link_libraries(rect ${OpenCV_LIBS})