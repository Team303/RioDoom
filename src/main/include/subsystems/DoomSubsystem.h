// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cstdio>
#include <thread>

#include <frc2/command/SubsystemBase.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cameraserver/CameraServer.h>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

extern "C"
{
	#include "headless_doom/i_video.h"
	#include "headless_doom/doomdef.h"

	#include "headless_doom/m_argv.h"
	#include "headless_doom/d_main.h"
}

class DoomSubsystem : public frc2::SubsystemBase
{
public:
	DoomSubsystem();

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic() override;

	void StartEngine();
	void StopEngine();
	static void OnDoomLoop();

	bool doomRunning;

private:
	cv::Mat mat;
	cs::CvSource videoStream;
	cs::CvSink cvSink;

	void UpdateMat();
	static void LaunchDoom();
};

extern "C" int IsDoomRunning();