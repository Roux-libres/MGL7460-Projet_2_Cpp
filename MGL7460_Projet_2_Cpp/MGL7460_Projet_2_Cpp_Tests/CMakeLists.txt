set(This Tests)
set(Sources 
	test.cpp
)

message("TEST MESSAGE CMAKE LOOOL")
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest
	gtest_main
	MGL7460_Projet_2_Cpp
)

add_test(
	NAME ${This}
	COMMAND ${This}
)

add_custom_command(
     TARGET ${This}
     COMMENT "Run tests"
     POST_BUILD 
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
     COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failures -T Test --no-compress-output
)

