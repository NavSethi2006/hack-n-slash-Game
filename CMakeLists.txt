cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 1.0)

include(CTest)
enable_testing()


file(GLOB TARGET_SRC "./src/*.c")
file(GLOB ENTITY_SRC "./src/entities/*.c")
file(GLOB PHYSICS_SRC "./src/physics/*.c")


add_executable(main ${TARGET_SRC} ${ENTITY_SRC} ${PHYSICS_SRC})
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include/)  

find_package(ZLIB)
find_package(LibXml2 REQUIRED)

target_link_libraries(main -lm
                            ${CMAKE_SOURCE_DIR}/lib/libraylib.so
                           ${CMAKE_SOURCE_DIR}/lib/libraylib-tmx.a
                           /usr/local/lib/libtmx.a)

target_link_libraries(main ZLIB::ZLIB)
target_link_libraries(main LibXml2::LibXml2)
 
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/includes/)

