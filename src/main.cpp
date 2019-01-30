#include "MMCore.h"

int main() {
  CMMCore mmcore;
  mmcore.loadDevice("tutorial", "RPiV4L2", "RPiV4L2");
  mmcore.initializeAllDevices();

  return 0;
}
