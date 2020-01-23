#include "controllers/TeleopController.h"

TeleopController::TeleopController() {
	mDrivetrain = &Drivetrain::GetInstance();
	//mIntake = &Intake::GetInstance();
	//mHopper = &Hopper::GetInstance();
	//mShooter = &Shooter::GetInstance();
	mOI = &OI::GetInstance();
}

void TeleopController::Init() {
	mDrivetrain->SetNeutralMode(NeutralMode::Brake);
}

void TeleopController::Execute() {

	// Drivetrain

	static bool isFollowingPath = false;
	static bool firstPath = false;

	static auto start = std::chrono::system_clock::now();
	//static auto end = std::chrono::system_clock::now();

	if (!isFollowingPath) {

		static double forward, turn;
		forward = mOI->GetDriver().GetRawAxis((int)frc::XboxController::Axis::kRightTrigger);
		forward -= mOI->GetDriver().GetRawAxis((int)frc::XboxController::Axis::kLeftTrigger);
		turn = mOI->GetDriver().GetRawAxis((int)frc::XboxController::Axis::kLeftX);

		mDrivetrain->SetSpeed(forward + turn, forward - turn);

		if (mOI->GetDriver().GetStartButtonPressed()) {
			isFollowingPath = true;
		}

	}
	else {

		if (firstPath) {
			start = std::chrono::system_clock::now();
			firstPath = false;
		}

		static frc::DifferentialDriveWheelSpeeds wheelSpeeds;
		static double currentSeconds, leftVel, rightVel;

		std::chrono::duration<double> currentTime = std::chrono::system_clock::now() - start;
		
		currentSeconds = currentTime.count();

		wheelSpeeds = mTestPath.GetStateSpeed(currentSeconds);
		
		leftVel = Constants::Operations::f2m(wheelSpeeds.left.value());
		rightVel = Constants::Operations::f2m(wheelSpeeds.right.value());

		mDrivetrain->SetVelocity(leftVel, rightVel, false);

		auto exitProtocol = [] {
			firstPath = true;
			isFollowingPath = false;
			Drivetrain::GetInstance().SetNeutralMode(NeutralMode::Coast);
		};

		if (currentSeconds >= mTestPath.GetTrajectoryTravelTime()) {
			exitProtocol();
		}
		if (OI::GetInstance().GetDriver().GetBackButtonPressed()) {
			exitProtocol();
		}
	}

	// Intake & Primary Hopper

	/*if (mOI->GetDriver().GetAButton()) {

	}*/

}