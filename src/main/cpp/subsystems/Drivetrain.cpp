#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {

  l1.ConfigFactoryDefault(10);
  l2.ConfigFactoryDefault(10);
  r1.ConfigFactoryDefault(10);
  r2.ConfigFactoryDefault(10);

  l1.SetInverted(true);
  l2.SetInverted(true);
  r1.SetInverted(false);
  r2.SetInverted(false);

  l2.Follow(l1);
  r2.Follow(r1);

  l1.ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor, 0, 10);
  l1.SetSelectedSensorPosition(0, 0, 10);
  r1.ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor, 0, 10);
  r1.SetSelectedSensorPosition(0, 0, 10);

  l1.ConfigPeakOutputForward(1, 10);
  l1.ConfigPeakOutputReverse(-1, 10);
  r1.ConfigPeakOutputForward(1, 10);
  r1.ConfigPeakOutputReverse(-1, 10);

  l1.Config_kP(0, Constants::Values::DRIVE_VELOCITY_GAINS.P, 10);
  l1.Config_kI(0, Constants::Values::DRIVE_VELOCITY_GAINS.I, 10);
  l1.Config_kD(0, Constants::Values::DRIVE_VELOCITY_GAINS.D, 10);
  l1.Config_kF(0, Constants::Values::DRIVE_VELOCITY_GAINS.F, 10);

  r1.Config_kP(0, Constants::Values::DRIVE_VELOCITY_GAINS.P, 10);
  r1.Config_kI(0, Constants::Values::DRIVE_VELOCITY_GAINS.I, 10);
  r1.Config_kD(0, Constants::Values::DRIVE_VELOCITY_GAINS.D, 10);
  r1.Config_kF(0, Constants::Values::DRIVE_VELOCITY_GAINS.F, 10);
}

void Drivetrain::SetPercentOutput(double left, double right) {
  l1.Set(ControlMode::PercentOutput, left);
  r1.Set(ControlMode::PercentOutput, right);
}

void Drivetrain::SetVelocityOutput(double left, double right) {
  l1.Set(ControlMode::Velocity, left);
  r1.Set(ControlMode::Velocity, right);
}