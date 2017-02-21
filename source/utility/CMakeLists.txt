#=============================================================================
# VizX Utility
#
# Copyright 2005-2017 William Xiao
#
# Create: 2017-02-21, William Xiao
# Modify:
#=============================================================================

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
SET(UTILITY_PROJECT_NAME "Utility")
PROJECT("${UTILITY_PROJECT_NAME}")

MESSAGE(${UTILITY_PROJECT_NAME})

#SET( INCLUDE_DIRS
#	${CMAKE_CURRENT_LIST_DIR}
#)
#MESSAGE("current path: ${INCLUDE_DIRS}")
#INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )

# ┌──────────────────────────────────────────────────────────────────┐
# │  Collect projects source files                                   │
# └──────────────────────────────────────────────────────────────────┘
FILE(GLOB PROJECT_SOURCE_FILES *.txt)
FILE(GLOB PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES}
    log/*.hpp
	log/*.cpp
    )

LINK_DIRECTORIES(${CMAKE_LIBRARY_PATH})
# STATIC or SHARED
ADD_LIBRARY(${UTILITY_PROJECT_NAME} STATIC ${PROJECT_SOURCE_FILES})
TARGET_LINK_LIBRARIES(${UTILITY_PROJECT_NAME} glfw)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects organization                                           │
# └──────────────────────────────────────────────────────────────────┘
# grouping this project into "App" folder - test only in visual studio
SET_PROPERTY(TARGET ${UTILITY_PROJECT_NAME}  PROPERTY FOLDER "Library")
FILE(GLOB_RECURSE project_headers *.hpp *.h)
FILE(GLOB_RECURSE project_cpps *.cpp)
SET(all_files ${project_headers} ${project_cpps})
SOURCE_GROUP_BY_DIR(all_files)