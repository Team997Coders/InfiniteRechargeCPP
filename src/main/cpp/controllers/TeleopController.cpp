#include "controllers/TeleopController.h"

TeleopController::TeleopController() {
	mDrivetrain = &Drivetrain::GetInstance();
	mOI = &OI::
}

void TeleopController::Init() {
	mDrivetrain->SetNeutralMode(NeutralMode::Brake);
}

void TeleopController::Execute() {
	
}