add_executable(stl_tests
    sandbox.cpp
)

target_link_libraries(stl_tests PRIVATE custom_stl)