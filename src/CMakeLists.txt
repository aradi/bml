add_subdirectory(Fortran-interface)
add_subdirectory(C-interface)

add_library(bml
  $<TARGET_OBJECTS:bml-c>
  $<TARGET_OBJECTS:bml-dense-double_complex>
  $<TARGET_OBJECTS:bml-dense-double_real>
  $<TARGET_OBJECTS:bml-dense-single_complex>
  $<TARGET_OBJECTS:bml-dense-single_real>
  $<TARGET_OBJECTS:bml-dense>
  $<TARGET_OBJECTS:bml-ellpack-double_complex>
  $<TARGET_OBJECTS:bml-ellpack-double_real>
  $<TARGET_OBJECTS:bml-ellpack-single_complex>
  $<TARGET_OBJECTS:bml-ellpack-single_real>
  $<TARGET_OBJECTS:bml-ellpack>
  $<TARGET_OBJECTS:bml-fortran>)

install(TARGETS bml
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
