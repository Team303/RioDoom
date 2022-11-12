// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

#include "subsystems/DoomSubsystem.h"

class Robot : public frc::TimedRobot
{
public:
	void RobotInit() override;
	void RobotPeriodic() override;
	void DisabledInit() override;
	void TeleopInit() override;
	void SimulationInit() override;
	
	static DoomSubsystem m_doomSubsystem;

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.

	void ConfigureButtonBindings();
};
