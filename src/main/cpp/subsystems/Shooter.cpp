#include "subsystems/Shooter.h"

Shooter::Shooter() {
	mMotor1 = new rev::CANSparkMax(Constants::Ports::SHOOTER_MOTOR_1, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
	mMotor2 = new rev::CANSparkMax(Constants::Ports::SHOOTER_MOTOR_2, rev::CANSparkMaxLowLevel::MotorType::kBrushless);

	mMotor1->RestoreFactoryDefaults();
	mMotor2->RestoreFactoryDefaults();

	mMotor2->Follow(*mMotor1);

	mEncoder = new rev::CANEncoder(*mMotor1);
	mController = new rev::CANPIDController(*mMotor1);

	mController->SetP(Constants::Values::SHOOTER_VELOCITY_GAINS.P);
	mController->SetI(Constants::Values::SHOOTER_VELOCITY_GAINS.I);
	mController->SetD(Constants::Values::SHOOTER_VELOCITY_GAINS.D);
	mController->SetFF(Constants::Values::SHOOTER_VELOCITY_GAINS.F);
}

Shooter::~Shooter() {
	delete mMotor1;
	delete mMotor2;
	delete mEncoder;
	delete mController;
}

double Shooter::GetRPM() {
	return mEncoder->GetVelocity();
}

void Shooter::SetRPM(double targetRPM) {
	mController->SetReference(targetRPM, rev::ControlType::kVelocity);
}