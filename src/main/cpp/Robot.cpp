#include "Robot.h"

void Robot::RobotInit() {
  Drivetrain::GetInstance();

  mAutoController = &AutoController::GetInstance();
  mTeleopController = &TeleopController::GetInstance();

  mChooser.SetDefaultOption("None", AutoController::AutoRoutine::None);
  mChooser.AddOption("SickOm0de", AutoController::AutoRoutine::SickOm0de);
}

void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::DisabledInit() { }

void Robot::DisabledPeriodic() { }

void Robot::AutonomousInit() {
  mAutoController->mSelectedAuto = mChooser.GetSelected();
  mAutoController->Init();
}

void Robot::AutonomousPeriodic() {
  mAutoController->Execute();
}

void Robot::TeleopInit() {
  mTeleopController->Init();
}

void Robot::TeleopPeriodic() {
  mTeleopController->Execute();
}

void Robot::TestPeriodic() { }

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
