#include <string.h>
#include <iostream>
#include <frc/Filesystem.h>

#include "Deployment.h"

void GetDeployDir(char* output) {
	std::string dir = frc::filesystem::GetDeployDirectory();
	strcpy(output, dir.c_str());
}