
cmake_minimum_required(VERSION 3.15)
project(Soundshelf VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# всички .cpp-та в src/, БЕЗ main.cpp - ще ни трябват за двете цели
# като добавям нови .сpp ги хваща автоматично при следващия cmake --build build
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
list(REMOVE_ITEM ALL_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# основното приложение
add_executable(soundshelf src/main.cpp ${ALL_SOURCES})


# всеки .cpp в tests/ става СВОЯ executable цел (защото всеки има свой main())
file(GLOB TEST_SOURCES "tests/*.cpp")
foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${ALL_SOURCES} ${test_src})
endforeach()