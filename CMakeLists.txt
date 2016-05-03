project(runningx)

cmake_minimum_required(VERSION 3.0)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

find_package(X11 REQUIRED)

add_executable(runningx src/runningx.cpp)

target_compile_features(runningx PUBLIC
    cxx_auto_type
    cxx_nullptr
)

target_link_libraries(runningx 
    PUBLIC ${X11_LIBRARIES}
)

install(TARGETS runningx
    RUNTIME DESTINATION bin
)
