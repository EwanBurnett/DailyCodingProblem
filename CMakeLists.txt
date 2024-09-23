cmake_minimum_required(VERSION 3.14)
project("DailyCodingProblem")

option(ENABLE_UNIT_TESTS "Enable Unit Tests for Daily Coding Problem solutions" ON)

# Optionally enable unit tests via google test
if(ENABLE_UNIT_TESTS)
    include(FetchContent)

    FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
    )

    if(WIN32)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # Force GTest to use a Shared Runtime Library, even when built as a Static Library. 
    endif()

    FetchContent_MakeAvailable(gtest)

    enable_testing()

    add_compile_definitions(ENABLE_UNIT_TESTS=1)    # Define a macro so that projects can optionally use unit tests. 
    link_libraries(GTest::gtest)    # globally link google test
endif()

# Output sub-projects to a named subdirectory
set_property(GLOBAL PROPERTY
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}/"
)

add_subdirectory(Problems)