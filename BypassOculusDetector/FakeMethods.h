#pragma once

#ifdef BYPASS_OCULUS_EXPORTS
#define BYPASS_OCULUS_API __declspec(dllexport)
#else
#define BYPASS_OCULUS_API __declspec(dllimport)
#endif

//LibOVR defines
#define OVR_ALIGNAS(n) __declspec(align(n))
#define OVR_UNUSED_STRUCT_PAD(padName, size) char padName[size];
typedef char ovrBool; ///< Boolean type
#define ovrFalse 0 ///< ovrBool value of false.
#define ovrTrue 1 ///< ovrBool value of true.

typedef struct OVR_ALIGNAS(8) ovrDetectResult_ {
    ovrBool IsOculusServiceRunning;
	ovrBool IsOculusHMDConnected;
	OVR_UNUSED_STRUCT_PAD(pad0, 6) ///< \internal struct padding
} ovrDetectResult;

extern "C" BYPASS_OCULUS_API ovrDetectResult ovr_Detect(int millisecondsWaited);
