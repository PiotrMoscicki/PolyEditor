# Include dir
set(RESOURCE_SUB_EDITOR_PLUGIN_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/src)

# Source files list
file(GLOB_RECURSE RESOURCE_SUB_EDITOR_PLUGIN_SRCS RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    ${RESOURCE_SUB_EDITOR_PLUGIN_INCLUDE}/*.cpp 
    ${RESOURCE_SUB_EDITOR_PLUGIN_INCLUDE}/*.hpp 
    ${RESOURCE_SUB_EDITOR_PLUGIN_INCLUDE}/*.h
    ${RESOURCE_SUB_EDITOR_PLUGIN_INCLUDE}/*.ui)
GenerateSourceGoups("${RESOURCE_SUB_EDITOR_PLUGIN_SRCS}")

add_library(${RESOURCE_SUB_EDITOR_PLUGIN_TARGET} SHARED ${RESOURCE_SUB_EDITOR_PLUGIN_SRCS} ${AUTOGEN_SOURCE_GROUP})
target_include_directories(${RESOURCE_SUB_EDITOR_PLUGIN_TARGET} PRIVATE ${RESOURCE_SUB_EDITOR_PLUGIN_INCLUDE})

target_link_libraries(${RESOURCE_SUB_EDITOR_PLUGIN_TARGET} PRIVATE ${RESOURCE_SUB_EDITOR_API_TARGET})

set_target_properties (${RESOURCE_SUB_EDITOR_PLUGIN_TARGET} PROPERTIES FOLDER "Plugins/SubEditors")