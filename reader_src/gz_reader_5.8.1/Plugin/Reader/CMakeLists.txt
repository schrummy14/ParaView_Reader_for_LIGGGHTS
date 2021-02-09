set(classes
  liggghts_reader_gz)

vtk_module_add_module(liggghts_reader_gz_mod
  CLASSES ${classes}
  SOURCES liggghts_reader_gz.cxx)

paraview_add_server_manager_xmls(
  XMLS  liggghts_reader_gz.xml)
