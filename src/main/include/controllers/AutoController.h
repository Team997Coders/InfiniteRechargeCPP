#ifndef ROBOT_AUTOCONTROLLER
#define ROBOT_AUTOCONTROLLER

#include "subsystems/Drivetrain.h"
#include "subsystems/Hopper.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"

class AutoController {
private:
	AutoController();

	Drivetrain* mDrivetrain;
	Intake* mIntake;
	Hopper* mHopper;
	Shooter* mShooter;
public:
	void Init();
	void Execute();

	enum AutoRoutine {
		None = -1,
		SickOm0de = 0
	};

	AutoRoutine mSelectedAuto;

	static AutoController& GetInstance() {
		static AutoController instance;
		return instance;
	}
};

#endif