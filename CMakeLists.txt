cmake_minimum_required(VERSION 3.23)

project(PoddyTidal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(Tidal SHARED)

add_compile_options(-Wall -Wextra)

if (APPLE)
add_compile_definitions("IS_MACOS")
elseif (UNIX)
add_compile_definitions("IS_LINUX")
elseif (WIN32)
add_compile_definitions("IS_WINDOWS")
endif()

target_sources(Tidal
	PUBLIC
		src/tidal.cpp
    PRIVATE
		src/backend.cpp
		src/backend.hpp
		src/interface.cpp
		src/interface.hpp
)

target_link_libraries(Tidal PRIVATE Poddy::PodMod PoddySettings PoddyTui GpodXX FindDev)
