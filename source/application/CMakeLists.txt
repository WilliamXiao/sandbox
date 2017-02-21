#=============================================================================
# VizX Application
#
# Copyright 2005-2017 William Xiao
#
# Create: 2017-02-21, William Xiao
# Modify:
#=============================================================================

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
SET(UTILITY_PROJECT_NAME "Application")
PROJECT("${UTILITY_PROJECT_NAME}")

MESSAGE(${UTILITY_PROJECT_NAME})

# ┌──────────────────────────────────────────────────────────────────┐
# │  Collect projects source files                                   │
# └──────────────────────────────────────────────────────────────────┘
SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}
)
MESSAGE("current path: ${INCLUDE_DIRS}")

INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )

FILE(GLOB PROJECT_SOURCE_FILES *.txt)
FILE(GLOB PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES}
    ./*.hpp
	./*.h
    ./*.cpp
	graphics/*.hpp
    graphics/*.cpp
	system/*.hpp
    system/*.cpp
    utils/*.hpp
	utils/*.cpp
    )

# ┌──────────────────────────────────────────────────────────────────┐
# │  Build Target and library link                                   │
# └──────────────────────────────────────────────────────────────────┘
ADD_EXECUTABLE(${UTILITY_PROJECT_NAME} ${PROJECT_SOURCE_FILES})
TARGET_LINK_LIBRARIES(${UTILITY_PROJECT_NAME} glfw ${GLFW_LIBRARIES} libglew_static)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects organization                                           │
# └──────────────────────────────────────────────────────────────────┘
# grouping this project into "App" folder - test only in visual studio
SET_PROPERTY(TARGET ${UTILITY_PROJECT_NAME}  PROPERTY FOLDER "App")
FILE(GLOB_RECURSE project_headers *.hpp *.h)
FILE(GLOB_RECURSE project_cpps *.cpp)
SET(all_files ${project_headers} ${project_cpps})
SOURCE_GROUP_BY_DIR(all_files)