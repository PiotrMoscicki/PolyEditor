#################################################
# build instructions
#################################################

# Include dir
set(RESOURCE_SUB_EDITOR_API_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/src)

# Gather source files list
file(GLOB_RECURSE RESOURCE_SUB_EDITOR_API_SRCS RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    ${RESOURCE_SUB_EDITOR_API_INCLUDE}/*.cpp 
    ${RESOURCE_SUB_EDITOR_API_INCLUDE}/*.hpp 
    ${RESOURCE_SUB_EDITOR_API_INCLUDE}/*.h)
GenerateSourceGoups("${RESOURCE_SUB_EDITOR_API_SRCS}")

# add library
add_library(${RESOURCE_SUB_EDITOR_API_TARGET} INTERFACE)
add_custom_target(${RESOURCE_SUB_EDITOR_API_TARGET}_ SOURCES ${RESOURCE_SUB_EDITOR_API_SRCS})
target_include_directories(${RESOURCE_SUB_EDITOR_API_TARGET} INTERFACE
    $<BUILD_INTERFACE:${RESOURCE_SUB_EDITOR_API_INCLUDE}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# link polyPlugin
target_link_libraries(${RESOURCE_SUB_EDITOR_API_TARGET} INTERFACE PolyTools::PolyTools)
target_link_libraries(${RESOURCE_SUB_EDITOR_API_TARGET} INTERFACE Qt5::Widgets Qt5::Core)
set_target_properties (${RESOURCE_SUB_EDITOR_API_TARGET}_ PROPERTIES FOLDER "API/SubEditors")