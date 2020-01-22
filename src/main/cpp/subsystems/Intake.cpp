#include "subsystems/Intake.h"

Intake::Intake() {
	mMotor = new rev::CANSparkMax(Constants::Ports::INTAKE_MOTOR, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
	mDetector = new frc::DigitalInput(Constants::Ports::INTAKE_DETECTOR);
}

Intake::~Intake() {
	delete mMotor;
	delete mDetector;
}

void Intake::SetSpeed(double percent) {
	mMotor->Set(percent);
}

bool Intake::DetectBall() {
	return mDetector->Get();
}