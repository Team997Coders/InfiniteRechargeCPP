#ifndef ROBOT_OI
#define ROBOT_OI

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

class OI {
private:
  frc::XboxController gamepad1;
public:
  OI();

  double getAxis(int port);

  static OI& GetInstance() {
    static OI instance;
    return instance;
  }
};

#endif