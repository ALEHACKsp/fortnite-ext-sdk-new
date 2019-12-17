#include "Classes.h"
SDK::LocalPlayer::LocalPlayer()
{

	this->LocalPlayerList = this->ReadVirtualMemory<std::uintptr_t>(this->GameInstance_ptr + this->LocalPlayer_List);
	this->LocalPlayerPtr = this->ReadVirtualMemory<std::uintptr_t>(this->LocalPlayerList + this->LocalPlayer_offset);
}

unsigned __int64 SDK::LocalPlayer::getPtr()
{
	this->LocalPlayerList = this->ReadVirtualMemory<std::uintptr_t>(this->GameInstance_ptr + this->LocalPlayer_List);
	this->LocalPlayerPtr = this->ReadVirtualMemory<std::uintptr_t>(this->LocalPlayerList + this->LocalPlayer_offset);
	return this->LocalPlayerPtr;
}
Vector3 SDK::LocalPlayer::GetPosition()
{
	return this->ReadVirtualMemory<Vector3>(this->LocalPlayerPtr + this->Local_Player_Position);
}