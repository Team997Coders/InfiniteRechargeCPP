#include "OI.h"

OI::OI() {
  // gamepad1 = frc::XboxController(0);
  // buttonA = frc2::JoystickButton(&gamepad1, 1);
}

double OI::getAxis(int port) {
  return gamepad1.GetRawAxis(port);
}