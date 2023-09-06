file(REMOVE_RECURSE
  "libDataStructures-lib.a"
  "libDataStructures-lib.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/DataStructures-lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
