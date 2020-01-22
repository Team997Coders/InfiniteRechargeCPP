#ifndef ROBOT_OI
#define ROBOT_OI

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

class OI {
private:
  OI();
  ~OI();

  frc::XboxController* gamepad1;
  frc::XboxController* gamepad2;
public:

  frc::XboxController& GetDriver();
  frc::XboxController& GetOperator();

  static OI& GetInstance() {
    static OI instance;
    return instance;
  }
};

#endif