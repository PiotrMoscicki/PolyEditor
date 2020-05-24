cmake_minimum_required(VERSION 3.12)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

##
# Function that generates source groups
##
function(GenerateSourceGoups Sources)
	foreach(Source ${Sources})
		get_filename_component(SourcePath "${Source}" PATH)
		if (WIN32)
			string(REPLACE "/" "\\" SourcePath "${SourcePath}")
		endif()
		source_group("${SourcePath}" FILES "${Source}")
	endforeach()
endfunction()

##
# Start
##
project(PolyEditor VERSION "1.0.0")

set(POLY_EDITOR_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(DIST_DIR "${POLY_EDITOR_ROOT_DIR}/Dist")
set(COMMON_BUILD_DIR "${POLY_EDITOR_ROOT_DIR}/CommonBuild")

# Output dirs
if (WIN32)
	set(FULL_DIST_DIR "${DIST_DIR}") # Config name is added autmatically on windows
else()
	set(FULL_DIST_DIR "${DIST_DIR}/${BUILD_CONFIG_NAME}")
endif()
	
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${FULL_DIST_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${FULL_DIST_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${FULL_DIST_DIR})

# C++ standard 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find externals
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(PolyPlugin REQUIRED)
find_package(PolyTools REQUIRED)

# Qt variables
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(AUTOUIC_SEARCH_PATHS Form)
set(Qt5_DIR $ENV{POLY_QTDIR})
list(APPEND CMAKE_PREFIX_PATH $ENV{POLY_QTDIR})

set(POLYTOOLS_TARGET PolyTools)
set(RESOURCE_SUB_EDITOR_API_TARGET ResourceSubEditorAPI)
set(RESOURCE_SUB_EDITOR_PLUGIN_TARGET ResourceSubEditorPlugin)

add_subdirectory(PolyEditor)