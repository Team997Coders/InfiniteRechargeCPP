#include "controllers/TeleopController.h"

TeleopController::TeleopController() {
	mDrivetrain = &Drivetrain::GetInstance();
	mIntake = &Intake::GetInstance();
	mHopper = &Hopper::GetInstance();
	mShooter = &Shooter::GetInstance();
	mOI = &OI::GetInstance();
}

void TeleopController::Init() {
	mDrivetrain->SetNeutralMode(NeutralMode::Brake);
}

void TeleopController::Execute() {

	// Drivetrain

	static double forward, turn;
	forward = -mOI->GetDriver().GetRawAxis((int)frc::XboxController::Axis::kLeftY);
	turn = mOI->GetDriver().GetRawAxis((int)frc::XboxController::Axis::kRightX);

	mDrivetrain->SetSpeed(forward + turn, forward - turn);

	// Intake & Primary Hopper

	if (mOI->GetDriver().GetAButton()) {

	}

}