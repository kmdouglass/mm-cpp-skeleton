#include <iostream>

#include "MMCore.h"

int main() {
  CMMCore mmcore;
  mmcore.loadDevice("camera", "RPiV4L2", "RPiV4L2");
  mmcore.setProperty("camera", "Video Device", "/dev/video0");
  mmcore.initializeAllDevices();

  std::cout << "Video device: " << mmcore.getProperty("camera", "Video Device") << std::endl;
  std::cout << "Format: " << mmcore.getProperty("camera", "Format Description") << std::endl;
  std::cout << " Flags: " << mmcore.getProperty("camera", "Format Flags") << std::endl;
  std::cout << " Width: " << mmcore.getProperty("camera", "Width") << std::endl;
  std::cout << " Height: " << mmcore.getProperty("camera", "Height") << std::endl;
  std::cout << " Field: " << mmcore.getProperty("camera", "Field") << std::endl;


  std::cout << std::endl << "The camera device is: " << mmcore.getCameraDevice() << std::endl;

  // Print info from the core API
  std::cout << std::endl << std::endl;
  std::cout << "Image buffer size: " << mmcore.getImageBufferSize() << std::endl;
  std::cout << "Height: " << mmcore.getImageHeight() << std::endl;
  std::cout << "Width: " << mmcore.getImageWidth() << std::endl;

  // Snap an image and display the first 8 bytes
  unsigned char* image;
  mmcore.snapImage();
  image = static_cast <unsigned char*> ( mmcore.getImage() );

  std::cout << std::hex << std::setiosflags(std::ios::showbase);
  for (int i = 0; i < 8; i++) {
    std::cout << std::hex << (int) image[i] << " ";
  }
  std::cout << std::resetiosflags(std::ios::showbase) << std::endl;
  std::cout << "Image buffer size: " << mmcore.getImageBufferSize() << std::endl;

  return 0;
}
