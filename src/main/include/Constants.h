/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

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
    DRIVE_RIGHT_2 = 2;

}

namespace Values {

  static const double

    DRIVE_WHEELBASE = 2.1; // Feet

  static const Gains

    DRIVE_VELOCITY_GAINS = Gains(0.13, 0.0, 3.0, 1023.0 / 19990.0);

}

}