cmake_minimum_required(VERSION 3.20)
project(CGMA C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

set(SOURCES
        "src/vector.c"
        "src/array.c"
)

option(CGMA_BUILD_EXAMPLES "Build examples" ON)


function(cgma_add_example target sub_folder source_file)
    add_executable("${target}" "examples/${source_file}")
    target_link_libraries("${target}" "CGMA")
    set_target_properties("${target}" PROPERTIES FOLDER "${sub_folder}.dir/examples")
endfunction()

if (CGMA_BUILD_EXAMPLES)
cgma_add_example("Vector" "Vector" "vector.c")
endif ()

add_library(CGMA STATIC )

target_sources(CGMA PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ./src
        PUBLIC
        ./include
)
