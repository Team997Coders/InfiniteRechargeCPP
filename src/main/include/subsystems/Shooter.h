#ifndef ROBOT_SHOOTER
#define ROBOT_SHOOTER

//#define DISABLE_SHOOTER

#include "rev/CANSparkMax.h"

#include "Constants.h"

class Shooter {
private:
	Shooter();
	~Shooter();

	rev::CANSparkMax *mMotor1, *mMotor2;
	rev::CANEncoder *mEncoder;
	rev::CANPIDController* mController;
public:
	double GetRPM();

	void SetRPM(double targetRPM);

	static Shooter& GetInstance() {
		static Shooter instance;
		return instance;
	}
};

#endif