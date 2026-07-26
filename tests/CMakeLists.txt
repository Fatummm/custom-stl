set(TEST_MODULES
    search
)

foreach(module ${TEST_MODULES})
    set(target_name "stl_${module}_tests")

    add_executable(${target_name} "test_${module}.cpp")

    target_link_libraries(${target_name} PRIVATE custom_stl)

    string(SUBSTRING ${module} 0 1 FIRST_LETTER)
    string(TOUPPER ${FIRST_LETTER} FIRST_LETTER_UPPER)
    string(SUBSTRING ${module} 1 -1 REST_LETTERS)
    add_test(NAME "${FIRST_LETTER_UPPER}${REST_LETTERS}Tests" COMMAND ${target_name})
endforeach()