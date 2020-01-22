#include "subsystems/Hopper.h"

Hopper::Hopper() {
	mMotor1 = new VictorSPX(Constants::Ports::HOPPER_MOTOR_1);
	mMotor2 = new VictorSPX(Constants::Ports::HOPPER_MOTOR_2);
}

Hopper::~Hopper() {
	delete mMotor1;
	delete mMotor2;
}

void Hopper::SetPrimarySpeed(double speed) {
	mMotor1->Set(ControlMode::PercentOutput, speed);
}

void Hopper::SetSecondarySpeed(double speed) {
	mMotor2->Set(ControlMode::PercentOutput, speed);
}