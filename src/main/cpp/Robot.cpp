// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

DoomSubsystem Robot::m_doomSubsystem = DoomSubsystem();

void Robot::RobotInit()
{
	ConfigureButtonBindings();
}

void Robot::ConfigureButtonBindings()
{
	// TODO - Pass Button Presses to DoomSubsystem
}

void Robot::TeleopInit()
{
	Robot::m_doomSubsystem.StartEngine();
}

void Robot::SimulationInit()
{
	Robot::m_doomSubsystem.StartEngine();
}

bool firstStart = true;

void Robot::DisabledInit()
{
	if (firstStart) {
		firstStart = false;
		return;
	}

	Robot::m_doomSubsystem.StopEngine();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic()
{
	frc2::CommandScheduler::GetInstance().Run();
}

int main()
{
	return frc::StartRobot<Robot>();
}
