include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

set(TEST_MODULES
    search
)

foreach(module ${TEST_MODULES})
    set(target_name "stl_${module}_tests")

    add_executable(${target_name} "test_${module}.cpp")

    target_link_libraries(${target_name} PRIVATE 
        custom_stl
        Catch2::Catch2WithMain
    )

    string(SUBSTRING ${module} 0 1 FIRST_LETTER)
    string(TOUPPER ${FIRST_LETTER} FIRST_LETTER_UPPER)
    string(SUBSTRING ${module} 1 -1 REST_LETTERS)
    catch_discover_tests(${target_name})
endforeach()