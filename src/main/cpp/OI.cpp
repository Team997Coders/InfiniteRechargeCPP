#include "OI.h"

OI::OI() {

}

double OI::getAxis(int port) {
  return gamepad1.GetRawAxis(port);
}