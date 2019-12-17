#include "Classes.h"
SDK::ACameraa::ACameraa()
{
}

Vector3 SDK::ACameraa::GetPositiona()
{
	Vector3 position = this->ReadVirtualMemory<Vector3>(this->getimagebase() + this->Camera_Posiion1);
	return position;
}

Vector3 SDK::ACameraa::GetRotationa()
{
	Vector3 Camera;
	unsigned __int64 ptr = this->ReadVirtualMemory<unsigned __int64>(this->LocalPlayerPtr + this->Pitch_offset1);    // PITCH PTR

	Camera.x = this->ReadVirtualMemory<float>(ptr + this->Pitch_offset2);								 // PITCH FLOAT
	Camera.y = this->ReadVirtualMemory<float>(this->RootComponent + this->Yaw_offset1);                   // YAW
	Camera.z = 0.f;                                                                                      // ROLL

	float test = asin(Camera.y);
	float degrees = test * (180.0 / 3.14159265358979323846f);
	Camera.y = degrees;

	if (Camera.x < 0)
		Camera.x = 360 + Camera.x;


	return Camera;
}

float SDK::ACameraa::GetFova()
{
	this->Zoom_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->LocalPlayerPtr + this->ZoomBase1);
	float zoom = this->ReadVirtualMemory<float>(this->Zoom_ptr + this->ZoomOffset1);
	float fov = 80.f;
	return ((float)fov / (zoom / 1.19f));

}	
bool SDK::ACameraa::WriteAnglesa(Vector3 angles)
{
	return this->WriteVirtualMemory(this->LocalPlayerPtr + 0x418, angles);
}
