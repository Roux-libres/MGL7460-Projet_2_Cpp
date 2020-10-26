# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER "C:/Users/1830542/Downloads/mingw/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Users/1830542/Downloads/mingw/bin/g++.exe")

project ("MGL7460_Projet_2_Cpp")

add_custom_target(Clean_Project
                  ALL
                  COMMENT "Clean the project's build directory"
                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/..
                  COMMAND rmdir /S /Q "C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out"
                  COMMAND mkdir "C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out"
                  COMMAND mkdir "C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build")

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

execute_process(COMMAND C:/Program Files/Cppcheck/cppcheck.exe --enable=all --inconclusive --xml --xml-version=2 C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp
                OUTPUT_VARIABLE cppcheck)
message("CPPCHECK RESULT : ${cppcheck}")
file(WRITE C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build/cppcheck.xml ${cppcheck})

execute_process(COMMAND C:/Users/1830542/AppData/Local/Programs/Python/Python37/Scripts/cpplint.exe --recursive --output=vs7 --counting=detailed --extensions=cpp,h --exclude=C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp/packages C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp
                RESULT_VARIABLE cpplint)
message("CPPLINT RESULT : ${cpplint}")
file(WRITE C:/Users/1830542/.jenkins/workspace/MGL7460_Projet_2_Cpp/out/build/cpplint-cppcheck-result.txt ${cpplint})

add_library(MGL7460_Projet_2_Cpp STATIC ${Sources})