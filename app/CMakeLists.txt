set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)



# Add external third party libraries

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(
    ALL_LIBS
    ${OPENGL_LIBRARY}
    ${GLUT_LIBRARY}
)



# Debugging folders and dependencies

message(STATUS "CMake source dir is: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMake current source dir is: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMake project source dir is: ${PROJECT_SOURCE_DIR}")
message(STATUS "Sources is set to ${SOURCES}")
message(STATUS "ALL_LIBS is set to ${ALL_LIBS}")
message(STATUS "Prefix path is ${CMAKE_PREFIX_PATH}")



# Build executable

add_definitions(
    -DGL_SILENCE_DEPRECATION
)

add_executable(${BINARY} ${SOURCES})

include_directories(
    ${OPENGL_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    LINK_PUBLIC
    src
    ${ALL_LIBS}
)