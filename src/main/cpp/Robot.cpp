#include "Robot.h"

void Robot::RobotInit() {
  Drivetrain::GetInstance();

  mChooser.SetDefaultOption("None", AutoRoutine::None);
  mChooser.AddOption("SickOm0de", AutoRoutine::SickOm0de);
}

void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::DisabledInit() { }

void Robot::DisabledPeriodic() { }

void Robot::AutonomousInit() {
  mSelectedRoutine = mChooser.GetSelected();
  AutoState = 0;
}

void Robot::AutonomousPeriodic() {
  switch (mSelectedRoutine) {
    case AutoRoutine::SickOm0de :
      static Path myPath = Path("AHHH");
      if (AutoState == 0) {
        static double leftVelocity, rightVelocity;
        static 
        Drivetrain::GetInstance().SetVelocityOutput();
      }
  }
}

void Robot::TeleopInit() { }

void Robot::TeleopPeriodic() {
  
}

void Robot::TestPeriodic() { }

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
