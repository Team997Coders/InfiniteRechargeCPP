#ifndef ROBOT_TELEOPCONTROLLER
#define ROBOT_TELEOPCONTROLLER

#include "subsystems/Drivetrain.h"
#include "subsystems/Hopper.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "OI.h"

class TeleopController {
private:
	TeleopController();

	Drivetrain* mDrivetrain;
	Intake* mIntake;
	Hopper* mHopper;
	Shooter* mShooter;
	OI* mOI;
public:
	void Init();
	void Execute();

	static TeleopController& GetInstance() {
		static TeleopController instance;
		return instance;
	}
};

#endif