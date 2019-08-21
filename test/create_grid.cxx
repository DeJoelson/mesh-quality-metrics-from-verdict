// Example 1: very simple VTK-m program.
// Read data set, write it out.
//
#include <vtkm/io/reader/VTKDataSetReader.h>
#include <vtkm/io/writer/VTKDataSetWriter.h>
#include <vtkm/filter/MeshQuality.h>
#include <vtkm/cont/DataSetBuilderExplicit.h>

vtkm::cont::DataSet createDataSet()
{

      std::cout << "Creating explicit grid iteratively." << std::endl;
      vtkm::cont::DataSetBuilderExplicitIterative dataSetBuilder;

      dataSetBuilder.AddPoint(1.1, 0.0, 0.0); //0
      dataSetBuilder.AddPoint(0.2, 0.4, 0.0); //1
      dataSetBuilder.AddPoint(0.9, 0.6, 0.0); //2
      dataSetBuilder.AddPoint(1.4, 0.5, 0.0); //3
      dataSetBuilder.AddPoint(1.8, 0.3, 0.0); //4
      dataSetBuilder.AddPoint(0.4, 1.0, 0.0); //5
      dataSetBuilder.AddPoint(1.0, 1.2, 0.0); //6
      dataSetBuilder.AddPoint(1.5, 0.9, 0.0); //7
      dataSetBuilder.AddPoint(0.0, 0.0, 0.0); //8
      dataSetBuilder.AddPoint(1.0, 0.0, 0.0); //9
      dataSetBuilder.AddPoint(0.0, 1.0, 0.0); //10
      dataSetBuilder.AddPoint(0.0, 0.0, 1.0); //11
      

      dataSetBuilder.AddCell(vtkm::CELL_SHAPE_TRIANGLE);
      dataSetBuilder.AddCellPoint(0);
      dataSetBuilder.AddCellPoint(2);
      dataSetBuilder.AddCellPoint(1);

      dataSetBuilder.AddCell(vtkm::CELL_SHAPE_QUAD);
      dataSetBuilder.AddCellPoint(0);
      dataSetBuilder.AddCellPoint(4);
      dataSetBuilder.AddCellPoint(3);
      dataSetBuilder.AddCellPoint(2);

      dataSetBuilder.AddCell(vtkm::CELL_SHAPE_TRIANGLE);
      dataSetBuilder.AddCellPoint(1);
      dataSetBuilder.AddCellPoint(2);
      dataSetBuilder.AddCellPoint(5);

      dataSetBuilder.AddCell(vtkm::CELL_SHAPE_POLYGON);
      dataSetBuilder.AddCellPoint(2);
      dataSetBuilder.AddCellPoint(3);
      dataSetBuilder.AddCellPoint(7);
      dataSetBuilder.AddCellPoint(6);
      dataSetBuilder.AddCellPoint(5);

      dataSetBuilder.AddCell(vtkm::CELL_SHAPE_TRIANGLE);
      dataSetBuilder.AddCellPoint(3);
      dataSetBuilder.AddCellPoint(4);
      dataSetBuilder.AddCellPoint(7);
      
      dataSetBuilder.AddCell(vtkm::CELL_SHAPE_TETRA);
      dataSetBuilder.AddCellPoint(8);
      dataSetBuilder.AddCellPoint(9);
      dataSetBuilder.AddCellPoint(10);
      dataSetBuilder.AddCellPoint(11);

      vtkm::cont::DataSet dataSet = dataSetBuilder.Create();

      return dataSet;
}

int main()
{


 

   /*
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
  vtkm::cont::DataSet ds_with_metric = mq.Execute(ds);
  */
  
  vtkm::cont::DataSet ds = createDataSet();
  std::cerr << "Writing new Mesh!" << std::endl;
  vtkm::io::writer::VTKDataSetWriter writer("../data/ugrid3.vtk");
  writer.WriteDataSet(ds_with_metric);

  return 0;
}
