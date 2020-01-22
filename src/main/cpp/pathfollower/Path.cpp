#include "pathfollower/Path.h"

Path::Path(std::string name) {
	mTraj = frc::TrajectoryUtil::FromPathweaverJson("/home/lvuser/deploy/paths/output/" + name + ".wpilib.json");
}

frc::DifferentialDriveWheelSpeeds Path::GetStateSpeed(double time) {
	static frc::DifferentialDriveKinematics diffDriveKin = frc::DifferentialDriveKinematics(
		units::meter_t(Constants::Operations::f2m(Constants::Values::DRIVE_WHEELBASE))
	);

	tCurrentState = mTraj.Sample(units::time::second_t(time));
	tChassisSpeed = {
		tChassisSpeed.vx = tCurrentState.velocity,
		tChassisSpeed.vy = units::velocity::meters_per_second_t(0.0),
		tChassisSpeed.omega = tCurrentState.curvature * tCurrentState.velocity
	};
	return diffDriveKin.ToWheelSpeeds(tChassisSpeed);
}

double Path::GetTrajectoryTravelTime() {
	return mTraj.TotalTime().value();
}