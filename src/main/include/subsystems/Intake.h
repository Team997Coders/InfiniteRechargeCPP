#ifndef ROBOT_INTAKE
#define ROBOT_INTAKE

#include <frc/DigitalInput.h>

#include "rev/CANSparkMax.h"

#include "Constants.h"

class Intake {
private:
	Intake();
	~Intake();

	rev::CANSparkMax *mMotor;
	frc::DigitalInput *mDetector;
public:
	void SetSpeed(double percent);

	bool DetectBall();

	static Intake& GetInstance() {
		static Intake instance;
		return instance;
	}
};

#endif