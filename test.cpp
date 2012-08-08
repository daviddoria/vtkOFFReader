// STL
#include <iostream>

// VTK
#include <vtkXMLPolyDataWriter.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>

#include "vtkOFFReader.h"

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    std::cerr << "Required parameters: InputFilename OutputFilename" << std::endl;
    return EXIT_FAILURE;
  }

  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];

  vtkSmartPointer<vtkOFFReader> offReader = vtkSmartPointer<vtkOFFReader>::New();
  offReader->SetFileName(inputFilename.c_str());
  offReader->Update();

  vtkSmartPointer<vtkXMLPolyDataWriter> polyDataWriter = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  polyDataWriter->SetFileName(outputFilename.c_str());
  polyDataWriter->SetInputData(offReader->GetOutput());
  polyDataWriter->Write();

  return EXIT_SUCCESS;
}