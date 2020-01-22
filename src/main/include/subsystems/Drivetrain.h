#ifndef ROBOT_DRIVETRAIN
#define ROBOT_DRIVETRAIN

#include <ctre/Phoenix.h>

#include "Constants.h"

class Drivetrain {
private:
  Drivetrain();

  TalonFX l1 = TalonFX(Constants::Ports::DRIVE_LEFT_1);
  TalonFX l2 = TalonFX(Constants::Ports::DRIVE_LEFT_2);
  TalonFX r1 = TalonFX(Constants::Ports::DRIVE_RIGHT_1);
  TalonFX r2 = TalonFX(Constants::Ports::DRIVE_RIGHT_2);
public:
  void SetPercentOutput(double left, double right);
  void SetVelocityOutput(double left, double right);

  void SetNeutralMode(NeutralMode&& mode);

  static Drivetrain& GetInstance() {
    static Drivetrain instance;
    return instance;
  }
};

#endif