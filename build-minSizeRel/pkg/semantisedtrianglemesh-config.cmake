# Compute installation prefix relative to this file.
get_filename_component(_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_prefix "${_dir}/../.." ABSOLUTE)

# Import the targets.
include("${_prefix}/lib/SemantisedTriangleMesh-1.0/SemantisedTriangleMesh-targets.cmake")

# Report other information.
set(SemantisedTriangleMesh_INCLUDE_DIRS "${_prefix}/include/SemantisedTriangleMesh-1.0")

file(GLOB SemantisedTriangleMesh_LIBRARIES "${_prefix}/lib/SemantisedTriangleMesh-1.0/lib*")
