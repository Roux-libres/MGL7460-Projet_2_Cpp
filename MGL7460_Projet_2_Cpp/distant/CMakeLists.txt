# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER "C:/Users/1830542/Downloads/mingw/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Users/1830542/Downloads/mingw/bin/g++.exe")

project ("MGL7460_Projet_2_Cpp")

message("Cleaning the project's build directory")
execute_process(COMMAND cmd rmdir /S /Q C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out)
execute_process(COMMAND cmd mkdir C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out)
execute_process(COMMAND cmd mkdir C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

# Incluez les sous-projets.
add_subdirectory ("MGL7460_Projet_2_Cpp")
add_subdirectory ("MGL7460_Projet_2_Cpp_Tests")
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)


set(Sources
	MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp.cpp
)

execute_process(COMMAND C:/Program Files/Cppcheck/cppcheck.exe --enable=all --inconclusive --xml --xml-version=2 C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp 2> C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build/cppcheck.xml)
#                RESULT_VARIABLE cppcheck_result
#                OUTPUT_VARIABLE cppcheck_output
#                ERROR_VARIABLE cppcheck_error)
#message("CPPCHECK RESULT : ${cppcheck_result}")
#message("CPPCHECK OUTPUT : ${cppcheck_output}")
#message("CPPCHECK ERROR : ${cppcheck_error}")
#file(WRITE C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build/cppcheck.xml ${cppcheck_error})

execute_process(COMMAND C:/Users/1830542/AppData/Local/Programs/Python/Python37/Scripts/cpplint.exe --recursive --output=vs7 --counting=detailed --extensions=cpp,h --exclude=C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp/packages C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp
                RESULT_VARIABLE cpplint_result
                OUTPUT_VARIABLE cpplint_output
                ERROR_VARIABLE cpplint_error)
#message("CPPLINT RESULT : ${cpplint_result}")
#message("CPPLINT OUTPUT : ${cpplint_output}")
#message("CPPLINT ERROR : ${cpplint_error}")
file(WRITE C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build/cpplint-cppcheck-result.txt ${cpplint_error})
file(APPEND C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build/cpplint-cppcheck-result.txt ${cpplint_output})

add_library(MGL7460_Projet_2_Cpp STATIC ${Sources})