cmake_minimum_required (VERSION 3.10)

set(PROJECT_NAME    rena_i18n)
project (${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB CPP_SOURCES 
    ./src/*.cpp
)

# 设置文件路径
set(INCLUDE_DIRS
    ./include
)

# link_directories(libOpenXLSX.a)
add_subdirectory(./lib/OpenXLSX)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})
target_link_libraries(${PROJECT_NAME} OpenXLSX)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})



install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
)
