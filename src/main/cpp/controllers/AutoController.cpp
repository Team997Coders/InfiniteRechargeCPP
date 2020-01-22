#include "controllers/AutoController.h"

AutoController::AutoController() {
	mDrivetrain = &Drivetrain::GetInstance();
	mIntake = &Intake::GetInstance();
	mHopper = &Hopper::GetInstance();
	mShooter = &Shooter::GetInstance();
}

void AutoController::Init() {
	mDrivetrain->SetNeutralMode(NeutralMode::Brake);
}

void AutoController::Execute() {
	
}