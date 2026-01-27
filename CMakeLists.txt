cmake_minimum_required(VERSION 3.20)
project(MoteurM2)
set(CMAKE_CXX_STANDARD 17)

# Dites à CMake d'utiliser vcpkg
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "Vous devez passer CMAKE_TOOLCHAIN_FILE vers vcpkg")
endif()

# Chercher GLFW via vcpkg
find_package(glfw3 CONFIG REQUIRED)

# Chercher OpenGL (nécessaire pour ImGui)
find_package(OpenGL REQUIRED)

# ===== Configuration ImGui =====
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/dependencies/IMGUI/imgui)

# Fichiers sources ImGui
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    # Backends pour GLFW + OpenGL3
    ${IMGUI_DIR}/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/imgui_impl_opengl3.cpp
)

# Créer l'exécutable
add_executable(MoteurM2
    src/main.cpp
    ${IMGUI_SOURCES}
)

# Inclure les headers ImGui
target_include_directories(MoteurM2 PRIVATE
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# Lier les bibliothèques
target_link_libraries(MoteurM2 PRIVATE 
    glfw
    OpenGL::GL
)