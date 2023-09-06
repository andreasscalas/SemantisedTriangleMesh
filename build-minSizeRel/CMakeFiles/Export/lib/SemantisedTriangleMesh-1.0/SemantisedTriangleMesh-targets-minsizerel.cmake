#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SemantisedTriangleMesh" for configuration "MinSizeRel"
set_property(TARGET SemantisedTriangleMesh APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SemantisedTriangleMesh PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "Triangle-lib;DataStructures-lib"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/SemantisedTriangleMesh-1.0/libSemantisedTriangleMesh.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SemantisedTriangleMesh )
list(APPEND _IMPORT_CHECK_FILES_FOR_SemantisedTriangleMesh "${_IMPORT_PREFIX}/lib/SemantisedTriangleMesh-1.0/libSemantisedTriangleMesh.a" )

# Import target "Triangle-lib" for configuration "MinSizeRel"
set_property(TARGET Triangle-lib APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(Triangle-lib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/SemantisedTriangleMesh-1.0/libTriangle-lib.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS Triangle-lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_Triangle-lib "${_IMPORT_PREFIX}/lib/SemantisedTriangleMesh-1.0/libTriangle-lib.a" )

# Import target "DataStructures-lib" for configuration "MinSizeRel"
set_property(TARGET DataStructures-lib APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(DataStructures-lib PROPERTIES
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/SemantisedTriangleMesh-1.0/libDataStructures-lib.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS DataStructures-lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_DataStructures-lib "${_IMPORT_PREFIX}/lib/SemantisedTriangleMesh-1.0/libDataStructures-lib.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
