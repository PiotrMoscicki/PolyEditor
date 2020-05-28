#################################################
# build instructions
#################################################

# Include dir
set(WINDOWS_MANAGER_API_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/src)

# Gather source files list
file(GLOB_RECURSE WINDOWS_MANAGER_API_SRCS RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    ${WINDOWS_MANAGER_API_INCLUDE}/*.cpp 
    ${WINDOWS_MANAGER_API_INCLUDE}/*.hpp 
    ${WINDOWS_MANAGER_API_INCLUDE}/*.h)
GenerateSourceGoups("${WINDOWS_MANAGER_API_SRCS}")

# add library
add_library(${WINDOWS_MANAGER_API_TARGET} INTERFACE)
add_custom_target(${WINDOWS_MANAGER_API_TARGET}_ SOURCES ${WINDOWS_MANAGER_API_SRCS})
target_include_directories(${WINDOWS_MANAGER_API_TARGET} INTERFACE
    $<BUILD_INTERFACE:${WINDOWS_MANAGER_API_INCLUDE}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# link polyPlugin
target_link_libraries(${WINDOWS_MANAGER_API_TARGET} INTERFACE PolyTools::PolyTools)
target_link_libraries(${WINDOWS_MANAGER_API_TARGET} INTERFACE Qt5::Widgets Qt5::Core)
set_target_properties (${WINDOWS_MANAGER_API_TARGET}_ PROPERTIES FOLDER "API/Managers")