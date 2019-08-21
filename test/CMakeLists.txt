cmake_minimum_required(VERSION 3.10)
project(VTKm_tut)

SET(VTKm_DIR ../vtk-m/lib/cmake/vtkm-1.4/)
find_package(VTKm REQUIRED)

#add_executable(volume volume.cxx)
#target_link_libraries(volume vtkm_cont vtkm_filter)

add_executable(aspect_ratio aspect_ratio.cxx)
target_link_libraries(aspect_ratio vtkm_cont vtkm_filter)

add_executable(metric_test metric_test.cxx)
target_link_libraries(metric_test vtkm_cont vtkm_filter)


