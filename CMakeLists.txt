cmake_minimum_required(VERSION 3.20)
project(MoteurM2)

set(CMAKE_CXX_STANDARD 17)

# Dites à CMake d'utiliser vcpkg
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "Vous devez passer CMAKE_TOOLCHAIN_FILE vers vcpkg")
endif()

# Chercher GLFW via vcpkg
find_package(glfw3 CONFIG REQUIRED)

# Créer l’exécutable
add_executable(MoteurM2
    src/main.cpp
)

# Lier GLFW
target_link_libraries(MoteurM2 PRIVATE glfw)
