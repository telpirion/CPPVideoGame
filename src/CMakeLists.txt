message("Building src folder ...")

file(GLOB_RECURSE LIB_SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_library(src STATIC ${LIB_SOURCES})
