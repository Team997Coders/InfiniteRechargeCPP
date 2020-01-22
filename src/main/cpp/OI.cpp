#include "OI.h"

OI::OI() {
	gamepad1 = new frc::XboxController(0);
	gamepad2 = new frc::XboxController(1);
}

OI::~OI() {
	delete gamepad1;
	delete gamepad2;
}

frc::XboxController& OI::GetDriver() {
	return *gamepad1;
}

frc::XboxController& OI::GetOperator() {
	return *gamepad2;
}