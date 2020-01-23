#pragma once

namespace Constants {

  struct Gains {

    double P, I, D, F;
    Gains(double p, double i, double d, double f): P(p), I(i), D(d), F(f) { }

  };

  namespace Operations {

    auto f2m = [](double meters) -> double { return meters * 3.281; };
    auto m2f = [](double feet) -> double { return feet / 3.281; };

  }

  namespace Ports {

    static const int

      DRIVE_LEFT_1 = 3,
      DRIVE_LEFT_2 = 4,
      DRIVE_RIGHT_1 = 1,
      DRIVE_RIGHT_2 = 2,

      SHOOTER_MOTOR_1 = 5,
      SHOOTER_MOTOR_2 = 6,

      INTAKE_MOTOR = 7,
      INTAKE_DETECTOR = 0,

      HOPPER_MOTOR_1 = 8,
      HOPPER_MOTOR_2 = 9;

  }

  namespace Values {

    static const double

      DRIVE_WHEELBASE = 2.1, // Feet
      DRIVE_VEL_2_FEET = 10 * ((double)1 / (double)2048)
      * ((double)9 / (double)70) * ((double)5 * 3.14159) * ((double)1 / (double)12);

    static const Gains

      DRIVE_VELOCITY_GAINS = Gains(0.13, 0.0, 3.0, 1023.0 / 19990.0),
      SHOOTER_VELOCITY_GAINS = Gains(0.25, 0.0, 0.0, 1 / 4200); // Gonna have to adjust all of these

  }

}