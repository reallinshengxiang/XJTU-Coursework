set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -g -std=gnu++11")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
*.cpp
*.cc
*.c++
*.c
*.C)

add_executable(test_executor ${SOURCES})

target_include_directories(test_executor 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} 
            ${PROJECT_SOURCE_DIR}/deps 
            ${PROJECT_SOURCE_DIR}/src 
            ${PROJECT_SOURCE_DIR}/thirdparty/googletest/include)

target_link_libraries(test_executor PRIVATE executor gtest_main)

target_compile_definitions(test_executor PRIVATE CUSTOMER_LOG)
