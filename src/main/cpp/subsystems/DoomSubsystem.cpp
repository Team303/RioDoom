// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/DoomSubsystem.h"
#include "Robot.h"

DoomSubsystem::DoomSubsystem()
{
	this->mat = cv::Mat(SCREEN_HEIGHT, SCREEN_WIDTH, CV_8UC3);
	this->doomRunning = false;
}

void DoomSubsystem::Periodic()
{
	static int periods = 0;

	// TODO - collect joystick movements

	frc::SmartDashboard::PutNumber("periods", ++periods);
}

void DoomSubsystem::StartEngine()
{
	printf("Starting DOOM Engine\n");

	this->doomRunning = true;

	frc::CameraServer::AddServer("test_server");

	this->cvSink = frc::CameraServer::GetVideo();
	this->videoStream = frc::CameraServer::PutVideo("doom", SCREEN_WIDTH, SCREEN_HEIGHT);

	std::thread doomThread(LaunchDoom);
	doomThread.detach();
}

void DoomSubsystem::StopEngine()
{
	printf("Stopping DOOM Engine\n");

	this->doomRunning = false;
}

void DoomSubsystem::LaunchDoom()
{
	D_SetLoopHook(&DoomSubsystem::OnDoomLoop);

	myargc = 0;
	myargv = {};

	D_DoomMain();
}

void DoomSubsystem::OnDoomLoop()
{

	// printf("Loop hook called!\n");
	// Update the screen
	Robot::m_doomSubsystem.UpdateMat();

	

	// TODO Send joystick inputs to the engine
}

void DoomSubsystem::UpdateMat()
{	
	// Get the current screen buffer
	byte palette[256 * 3];
	byte screen[SCREEN_WIDTH * SCREEN_HEIGHT];

	I_ReadPalette(palette);
	I_ReadScreen(screen);

	// Iterate through the pixels in the Mat
	for (int y = 0; y < mat.rows; y++)
	{
		for (int x = 0; x < mat.cols; x++)
		{
			// Calculate index into color palette
			int imgIndex = y * SCREEN_WIDTH + x;

			int paletteIndex = screen[imgIndex];

			// Get pixel
			cv::Vec3b &color = mat.at<cv::Vec3b>(y, x);

			// Copy the values from the screen buffer (BGR order bc ¯\_(ツ)_/¯)
			color[0] = palette[paletteIndex * 3 + 2];
			color[1] = palette[paletteIndex * 3 + 1];
			color[2] = palette[paletteIndex * 3 + 0];

			// Set pixel
			mat.at<cv::Vec3b>(cv::Point(x, y)) = color;
		}
	}

	// Send the updated Mat to the video stream
	this->videoStream.PutFrame(this->mat);
}

int IsDoomRunning()
{
	return Robot::m_doomSubsystem.doomRunning;
}