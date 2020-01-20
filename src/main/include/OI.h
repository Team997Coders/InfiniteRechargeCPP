#ifndef ROBOT_OI
#define ROBOT_OI

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

class OI {
private:
  frc::XboxController gamepad1 = frc::XboxController(0);
public:
  OI();
  ~OI();

  double getAxis(int port);
};

#endif