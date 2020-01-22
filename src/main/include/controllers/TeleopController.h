#ifndef ROBOT_TELEOPCONTROLLER
#define ROBOT_TELEOPCONTROLLER

#include "subsystems/Drivetrain.h"
#include "OI.h"

class TeleopController {
public:
	TeleopController();

	void Init();
	void Execute();
private:
	Drivetrain* mDrivetrain;
	OI* mOI;
};

#endif