cmake_minimum_required(VERSION 3.15)
project(StudioX LANGUAGES CXX)

# =================================================
# Standard C++
# =================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =================================================
# Racines externes
# =================================================
get_filename_component(DEV_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)

set(IMGUI_ROOT         "${DEV_ROOT}/imgui")
set(IMGUI_BACKEND_ROOT "${IMGUI_ROOT}/backends")
set(GLFW_ROOT          "${DEV_ROOT}/glfw")

# Vérifications
if(NOT EXISTS "${IMGUI_ROOT}")
    message(FATAL_ERROR "ImGui introuvable : ${IMGUI_ROOT}")
endif()

if(NOT EXISTS "${GLFW_ROOT}")
    message(FATAL_ERROR "GLFW introuvable : ${GLFW_ROOT}")
endif()

# =================================================
# GLFW
# =================================================
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)

add_subdirectory("${GLFW_ROOT}" glfw_build)

# =================================================
# ImGui (lib statique)
# =================================================
file(GLOB IMGUI_CORE
    "${IMGUI_ROOT}/*.cpp"
)

set(IMGUI_BACKENDS
    "${IMGUI_BACKEND_ROOT}/imgui_impl_glfw.cpp"
    "${IMGUI_BACKEND_ROOT}/imgui_impl_opengl3.cpp"
)

add_library(imgui STATIC
    ${IMGUI_CORE}
    ${IMGUI_BACKENDS}
)

target_include_directories(imgui PUBLIC
    "${IMGUI_ROOT}"
    "${IMGUI_BACKEND_ROOT}"
    "${GLFW_ROOT}/include"
)

# =================================================
# Sources du projet (AUTOMATIQUE)
# =================================================
file(GLOB_RECURSE PROJECT_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${IMGUI_ROOT}"
        "${IMGUI_BACKEND_ROOT}"
        "${GLFW_ROOT}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        imgui
        glfw
        opengl32
)

# =================================================
# Organisation Visual Studio (optionnel mais propre)
# =================================================
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src
             PREFIX "Source"
             FILES ${PROJECT_SOURCES})