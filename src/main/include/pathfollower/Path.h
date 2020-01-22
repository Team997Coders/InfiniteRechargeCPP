#ifndef ROBOT_PATH
#define ROBOT_PATH

#include <string>

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
  Path(std::string name);

  frc::DifferentialDriveWheelSpeeds GetStateSpeed(double time);
  double GetTrajectoryTravelTime();
};

#endif