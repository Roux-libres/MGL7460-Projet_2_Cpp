# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("MGL7460_Projet_2_Cpp")

# Incluez les sous-projets.
add_subdirectory ("MGL7460_Projet_2_Cpp")
add_subdirectory ("MGL7460_Projet_2_Cpp_Tests")

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
  BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

enable_testing()

set(Sources
	MGL7460_Projet_2_Cpp.cpp
)
