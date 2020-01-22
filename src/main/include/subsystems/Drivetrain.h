#ifndef ROBOT_DRIVETRAIN
#define ROBOT_DRIVETRAIN

#include <ctre/Phoenix.h>

#include "Constants.h"

class Drivetrain {
private:
  Drivetrain();
  ~Drivetrain();

  TalonFX *mLeft1;
  TalonFX *mLeft2;
  TalonFX *mRight1;
  TalonFX *mRight2;
public:
  void SetSpeed(double left, double right);
  void SetVelocity(double left, double right);

  void SetNeutralMode(NeutralMode&& mode);

  static Drivetrain& GetInstance() {
    static Drivetrain instance;
    return instance;
  }
};

#endif