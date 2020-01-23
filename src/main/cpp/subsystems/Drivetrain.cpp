#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {

  mLeft1 = new TalonFX(Constants::Ports::DRIVE_LEFT_1);
  mLeft2 = new TalonFX(Constants::Ports::DRIVE_LEFT_2);
  mRight1 = new TalonFX(Constants::Ports::DRIVE_RIGHT_1);
  mRight2 = new TalonFX(Constants::Ports::DRIVE_RIGHT_2);

  mLeft1->ConfigFactoryDefault(10);
  mLeft2->ConfigFactoryDefault(10);
  mRight1->ConfigFactoryDefault(10);
  mRight2->ConfigFactoryDefault(10);

  mLeft1->ConfigFactoryDefault(10);
  mLeft2->ConfigFactoryDefault(10);
  mRight1->ConfigFactoryDefault(10);
  mRight2->ConfigFactoryDefault(10);

  mLeft1->SetInverted(true);
  mLeft2->SetInverted(true);
  mRight1->SetInverted(false);
  mRight2->SetInverted(false);

  mLeft2->Follow(*mLeft1);
  mRight2->Follow(*mRight1);

  mLeft1->ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor, 0, 10);
  mLeft1->SetSelectedSensorPosition(0, 0, 10);
  mRight1->ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor, 0, 10);
  mRight1->SetSelectedSensorPosition(0, 0, 10);

  mLeft1->ConfigPeakOutputForward(1, 10);
  mLeft1->ConfigPeakOutputReverse(-1, 10);
  mRight1->ConfigPeakOutputForward(1, 10);
  mRight1->ConfigPeakOutputReverse(-1, 10);

  mLeft1->Config_kP(0, Constants::Values::DRIVE_VELOCITY_GAINS.P, 10);
  mLeft1->Config_kI(0, Constants::Values::DRIVE_VELOCITY_GAINS.I, 10);
  mLeft1->Config_kD(0, Constants::Values::DRIVE_VELOCITY_GAINS.D, 10);
  mLeft1->Config_kF(0, Constants::Values::DRIVE_VELOCITY_GAINS.F, 10);

  mRight1->Config_kP(0, Constants::Values::DRIVE_VELOCITY_GAINS.P, 10);
  mRight1->Config_kI(0, Constants::Values::DRIVE_VELOCITY_GAINS.I, 10);
  mRight1->Config_kD(0, Constants::Values::DRIVE_VELOCITY_GAINS.D, 10);
  mRight1->Config_kF(0, Constants::Values::DRIVE_VELOCITY_GAINS.F, 10);
}

Drivetrain::~Drivetrain() {
  delete mLeft1;
  delete mLeft2;
  delete mRight1;
  delete mRight2;
}

void Drivetrain::SetSpeed(double left, double right) {
  mLeft1->Set(ControlMode::PercentOutput, left);
  mRight1->Set(ControlMode::PercentOutput, right);
}

void Drivetrain::SetVelocity(double left, double right, bool nativeUnits) {
  if (nativeUnits) {
    mLeft1->Set(ControlMode::Velocity, left);
    mRight1->Set(ControlMode::Velocity, right);
  }
  else {
    mLeft1->Set(ControlMode::Velocity, left / Constants::Values::DRIVE_VEL_2_FEET);
    mRight1->Set(ControlMode::Velocity, right / Constants::Values::DRIVE_VEL_2_FEET);
  }
}

void Drivetrain::SetNeutralMode(NeutralMode&& mode) {
  mLeft1->SetNeutralMode(mode);
  mRight1->SetNeutralMode(mode);
}