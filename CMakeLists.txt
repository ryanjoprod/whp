# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.23)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (
	whp
	VERSION 1.0
	DESCRIPTION "World History Project"
	LANGUAGES CXX
)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list(APPEND CMAKE_PREFIX_PATH "C:/msys64/mingw64")

set(
	CMAKE_RUNTIME_OUTPUT_DIRECTORY
	"${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
)

set(
	CMAKE_LIBRARY_OUTPUT_DIRECTORY
	"${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
)

add_executable(
	whp
	src/main.cpp
)

if(APPLE)
	set_target_properties(whp PROPERTIES
		INSTALL_RPATH "@executable_path;@loader_path"
		BUILD_WITH_INSTALL_RPATH TRUE
		MACOSX_RPATH TRUE
	)
elseif(UNIX)
	set_target_properties(whp PROPERTIES
		INSTALL_RPATH "$ORIGIN"
		BUILD_WITH_INSTALL_RPATH TRUE
	)
endif()

# Specify that we want to build with SDL_TTFs dependencies
set(SDLTTF_VENDORED ON)

# Set a variable for our vendor directory
set(VENDOR_DIR "${PROJECT_SOURCE_DIR}/vendor")

# Add the SDL libraries from our submodules
add_subdirectory(${VENDOR_DIR}/SDL)
add_subdirectory(${VENDOR_DIR}/SDL_image)
add_subdirectory(${VENDOR_DIR}/SDL_ttf)

target_link_libraries(whp
	SDL3::SDL3
	SDL3_image::SDL3_image
	SDL3_ttf::SDL3_ttf
)