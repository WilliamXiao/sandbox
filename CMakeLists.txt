#=============================================================================
# VizX sandbox
#
# Copyright 2005-2017 William Xiao
#
# Create: 2017-02-21, William Xiao
# Modify:
#=============================================================================

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
SET(PROJECT_NAME "VizX")
PROJECT (${PROJECT_NAME})

# common project setting utility to grouping projects
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
MACRO(SOURCE_GROUP_BY_DIR SOURCE_FILES)
    IF(MSVC)
        SET(SGBD_CUR_DIR ${CMAKE_CURRENT_SOURCE_DIR})
        FOREACH(SGBD_FILE ${${SOURCE_FILES}})
            STRING(REGEX REPLACE ${SGBD_CUR_DIR}/\(.*\) \\1 SGBD_FPATH ${SGBD_FILE})
            STRING(REGEX REPLACE "\(.*\)/.*" \\1 SGBD_GROUP_NAME ${SGBD_FPATH})
            STRING(COMPARE EQUAL ${SGBD_FPATH} ${SGBD_GROUP_NAME} SGBD_NOGROUP)
            STRING(REPLACE "/" "\\" SGBD_GROUP_NAME ${SGBD_GROUP_NAME})
			
            IF(SGBD_NOGROUP)
                SET(SGBD_GROUP_NAME "\\")
            ENDIF(SGBD_NOGROUP)
            SOURCE_GROUP(${SGBD_GROUP_NAME} FILES ${SGBD_FILE})
        ENDFOREACH(SGBD_FILE)
    ENDIF(MSVC)
ENDMACRO(SOURCE_GROUP_BY_DIR)
#end of grouping utility block

# ┌──────────────────────────────────────────────────────────────────┐
# │  Compilation flags                                               │
# └──────────────────────────────────────────────────────────────────┘
LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11")
ADD_DEFINITIONS(-Wall)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Load libraries - common to overall solution                     │
# └──────────────────────────────────────────────────────────────────┘
# glfw
#SET(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
SET(GLFW_BUILD_EXAMPLES ON CACHE STRING "" FORCE)
SET(GLFW_BUILD_TESTS    ON CACHE STRING "" FORCE)
SET(GLFW_INSTALL        OFF CACHE STRING "" FORCE)
ADD_SUBDIRECTORY(third_party/glfw)
INCLUDE_DIRECTORIES(third_party/glfw/include)

# glew
ADD_DEFINITIONS(-DGLEW_STATIC)
OPTION(glew-cmake_BUILD_SHARED "" OFF)
ADD_SUBDIRECTORY(third_party/glew)
INCLUDE_DIRECTORIES(third_party/glew/include third_party/glew/src)

# glm
# fatal error C1189: #error:  "GLM: GLM_GTX_matrix_operation is an
# experimental extension and may change in the future."
ADD_DEFINITIONS(-DGLM_ENABLE_EXPERIMENTAL)

INCLUDE_DIRECTORIES(third_party/glm)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects organization                                           │
# └──────────────────────────────────────────────────────────────────┘

ADD_SUBDIRECTORY(source/application)
ADD_SUBDIRECTORY(source/utility)
