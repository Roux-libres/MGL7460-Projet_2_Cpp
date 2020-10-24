# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER "C:/Users/1830542/Downloads/mingw/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Users/1830542/Downloads/mingw/bin/g++.exe")

project ("MGL7460_Projet_2_Cpp")

# Incluez les sous-projets.
add_subdirectory ("MGL7460_Projet_2_Cpp_CMake")
