#ifndef ROBOT_PATH
#define ROBOT_PATH

#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>

#include <units/units.h>

#include "Constants.h"

class Path {
private:
  frc::Trajectory mTraj;

  frc::Trajectory::State tCurrentState;
  frc::ChassisSpeeds tChassisSpeed;
public:
  Path(const char* name);

  frc::DifferentialDriveWheelSpeeds GetStateSpeed(double time);
  double GetTrajectoryTravelTime();
};

#endif