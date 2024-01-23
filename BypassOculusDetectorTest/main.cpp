#include <windows.h> 
#include <iostream>
#include "../BypassOculusDetector/FakeMethods.h"

typedef ovrDetectResult(*DETECT_OCULUS)(int timeoutMilliseconds);
void showResult(ovrDetectResult ovrResult);

int main(void)
{
	HINSTANCE hinstLib;
	DETECT_OCULUS ProcAdd;
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
	ovrDetectResult ovrResult = { ovrFalse, ovrFalse };
	hinstLib = LoadLibrary(TEXT("LibOVRRT64_1.dll"));
	if (hinstLib != NULL)
	{
		ProcAdd = (DETECT_OCULUS)GetProcAddress(hinstLib, "ovr_Detect");
		if (NULL != ProcAdd)
		{
			fRunTimeLinkSuccess = TRUE;
			ovrResult = ProcAdd(500);
			showResult(ovrResult);
		}
		else
		{
			std::cout << "Function ovr_Detect not found\n";
		}
		fFreeResult = FreeLibrary(hinstLib);
	}
	else
	{
		std::cout << "LibOVRRT64_1.dll not found\n";
	}
	std::cin.get();
	return 0;
}

void showResult(ovrDetectResult ovrResult)
{
	if (ovrResult.IsOculusHMDConnected == ovrTrue)
	{
		std::cout << "Oculus HMD detected.\n";
	}
	else
	{
		std::cout << "Oculus HMD not detected.\n";
	}

	if (ovrResult.IsOculusServiceRunning == ovrTrue) {
		std::cout << "Oculus Service Running. \n";
	}
	else
	{
		std::cout << "Oculus Service Not Running. \n";
	}
}
