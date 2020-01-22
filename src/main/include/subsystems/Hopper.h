#ifndef ROBOT_HOPPER
#define ROBOT_HOPPER

#include <ctre/Phoenix.h>

#include "Constants.h"

class Hopper {
private:
	Hopper();
	~Hopper();

	VictorSPX *mMotor1, *mMotor2;
public:
	void SetPrimarySpeed(double speed);
	void SetSecondarySpeed(double speed);

	static Hopper& GetInstance() {
		static Hopper instance;
		return instance;
	}
};

#endif