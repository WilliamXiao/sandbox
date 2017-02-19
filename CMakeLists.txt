# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
cmake_minimum_required (VERSION 2.8)
SET(PROJECT_NAME "VizX")
project (${PROJECT_NAME})

# ┌──────────────────────────────────────────────────────────────────┐
# │  Compilation flags                                               │
# └──────────────────────────────────────────────────────────────────┘
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
add_definitions(-Wall)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Load libraries                                                  │
# └──────────────────────────────────────────────────────────────────┘
# glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE STRING "" FORCE)
set(GLFW_INSTALL        OFF CACHE STRING "" FORCE)
add_subdirectory(third_party/glfw)
include_directories(third_party/glfw/include)

# glew
add_definitions(-DGLEW_STATIC)
option(glew-cmake_BUILD_SHARED "" OFF)
add_subdirectory(third_party/glew)
include_directories(third_party/glew/include third_party/glew/src)

# glm
# fatal error C1189: #error:  "GLM: GLM_GTX_matrix_operation is an
# experimental extension and may change in the future."
add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

include_directories(third_party/glm)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Build executable                                                │
# └──────────────────────────────────────────────────────────────────┘
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/source/*)
add_executable(${PROJECT_NAME} ${source_files})
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} libglew_static)
