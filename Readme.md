## Bypass Oculus Detector
Windows Library that simulates not having the Oculus service running and having the VR Headsets disconnected. It is useful for programs like Automobilista 2 that force the execution in Oculus mode if they detect them, making impossible the execution of the game in OpenXR runtime.

## How to use
### Prerequisites
-  [OpenXR Toolkit](https://mbucchia.github.io/OpenXR-Toolkit)
-  [OpenComposite](https://gitlab.com/znixian/OpenOVR) and replaced openvr_api.dll
### Steps
- Download `LibOVRRT64_1.dll` (64-bit) or `LibOVRRT32_1.dll` (32-bit) from [Releases](https://github.com/rodolZ80/bypass-oculus-detector/releases).
- Copy the dll file to the root folder of game:  
Example:  ```[Drive]:\SteamLibrary\steamapps\common\Automobilista 2\```
- Set Oculus as active OpenXR runtime.
- Start the game in SteamVR mode.

## Tested
- Windows 11 Pro 23H2
- Oculus App Version 60.0.0.162.352 
- Oculus Quest Pro Headsets
- 64-bit
- Games: 
     - Automobilista 2: **OpenXR runtime [OK]**
     - Project Cars 2: **OpenXR runtime [OK]**
     - Elite Dangerous: **OpenXR runtime [OK]**  
       Copy dll to ``[Drive]:\SteamLibrary\steamapps\common\Elite Dangerous\Products\elite-dangerous-odyssey-64`` 
