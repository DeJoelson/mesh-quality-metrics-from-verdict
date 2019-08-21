// Example 1: very simple VTK-m program.
// Read data set, write it out.
//
#include <vtkm/io/reader/VTKDataSetReader.h>
#include <vtkm/io/writer/VTKDataSetWriter.h>
#include <vtkm/filter/MeshQuality.h>

int main()
{
  const char *input = "../data/ugrid.vtk";
  vtkm::io::reader::VTKDataSetReader reader(input);
  vtkm::cont::DataSet ds = reader.ReadDataSet();

  vtkm::UInt8 celltypes[8] = { vtkm::CELL_SHAPE_TETRA,
                               vtkm::CELL_SHAPE_HEXAHEDRON,
                               vtkm::CELL_SHAPE_WEDGE,
                               vtkm::CELL_SHAPE_PYRAMID,
                               vtkm::CELL_SHAPE_POLYGON,
                               vtkm::CELL_SHAPE_LINE,
                               vtkm::CELL_SHAPE_QUAD,
                               vtkm::CELL_SHAPE_TRIANGLE };
  
  std::vector<vtkm::Pair<vtkm::UInt8, vtkm::filter::CellMetric> > vals;
  for (int i = 0 ; i < 8 ; i++)
  {
     vtkm::Pair<vtkm::UInt8, vtkm::filter::CellMetric> val(celltypes[i], vtkm::filter::CellMetric::ASPECT_RATIO);
     vals.push_back(val);
  }

  vtkm::filter::MeshQuality mq(vals);
  vtkm::cont::DataSet ds_with_vol = mq.Execute(ds);

  std::cerr << "Writing new file!" << std::endl;
  vtkm::io::writer::VTKDataSetWriter writer("ugrid_w_aspect_ratio.vtk");
  writer.WriteDataSet(ds_with_vol);

  return 0;
}
