cmake_minimum_required(VERSION 3.15)
project(StudioX LANGUAGES CXX)

# -------------------------------------------------
# Options du compilateur
# -------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------------------------
# Localisation des sources externes (chemins robustes)
# -------------------------------------------------
# Ce CMakeLists.txt se trouve dans MyImGuiApp
# Remonter d'un niveau pour atteindre le répertoire parent "dev"
get_filename_component(DEV_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)   # => C:/.../dev

# Chemins vers les dépôts
set(IMGUI_ROOT           "${DEV_ROOT}/imgui")          # C:/.../dev/imgui
set(IMGUI_BACKEND_ROOT   "${IMGUI_ROOT}/backends")     # C:/.../dev/imgui/backends
set(GLFW_ROOT            "${DEV_ROOT}/glfw")           # C:/.../dev/glfw

# -------------------------------------------------
# Vérifications rapides
# -------------------------------------------------
if(NOT EXISTS "${IMGUI_ROOT}")
    message(FATAL_ERROR "Impossible de trouver ImGui à ${IMGUI_ROOT}")
endif()
if(NOT EXISTS "${IMGUI_BACKEND_ROOT}")
    message(FATAL_ERROR "Impossible de trouver le dossier backends d'ImGui à ${IMGUI_BACKEND_ROOT}")
endif()
if(NOT EXISTS "${GLFW_ROOT}")
    message(FATAL_ERROR "Impossible de trouver GLFW à ${GLFW_ROOT}")
endif()

# -------------------------------------------------
# GLFW (déjà fourni avec son propre CMakeLists.txt)
# -------------------------------------------------
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
add_subdirectory("${GLFW_ROOT}" glfw_build)

# -------------------------------------------------
# ImGui – créer une bibliothèque statique incluant les back‑ends
# -------------------------------------------------
# Sources du cœur d’ImGui
file(GLOB IMGUI_CORE_SOURCES "${IMGUI_ROOT}/*.cpp")

# Back‑ends que nous voulons (GLFW + OpenGL3)
set(IMGUI_BACKEND_SOURCES
    "${IMGUI_BACKEND_ROOT}/imgui_impl_glfw.cpp"
    "${IMGUI_BACKEND_ROOT}/imgui_impl_opengl3.cpp"
)

add_library(imgui STATIC
    ${IMGUI_CORE_SOURCES}
    ${IMGUI_BACKEND_SOURCES}
)

# ----------- NOUVEAU : inclure les headers de GLFW pour la cible imgui -----------
target_include_directories(imgui PUBLIC
    "${IMGUI_ROOT}"                # imgui.h, etc.
    "${IMGUI_BACKEND_ROOT}"        # imgui_impl_*.h
    "${GLFW_ROOT}/include"         # <-- nécessaire pour GLFW/glfw3.h
)

# -------------------------------------------------
# Ton exécutable
# -------------------------------------------------
add_executable(${PROJECT_NAME}
    src/main.cpp          # ton code applicatif
    # src/gui.cpp        # (optionnel) si tu as un fichier séparé
)

# Inclure les headers pour le compilateur de l'exécutable
target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${IMGUI_ROOT}"
        "${IMGUI_BACKEND_ROOT}"
        "${GLFW_ROOT}/include"
        src                 # pour gui.h éventuel
)

# Lier les bibliothèques
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        imgui          # notre lib ImGui (core + back‑ends)
        glfw           # GLFW (déjà construit via add_subdirectory)
        opengl32       # OpenGL fourni par Windows
)

# -------------------------------------------------
# Copie de la DLL GLFW si tu utilises MinGW (facultatif)
# -------------------------------------------------
if (WIN32 AND NOT MSVC)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:glfw>"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()