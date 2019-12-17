#include "Classes.h"
SDK::APawn::APawn()
{

}



float SDK::APawn::GetZoom()
{
	this->Zoom_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->LocalPlayerPtr + this->ZoomBase);
	return this->ReadVirtualMemory<float>(this->Zoom_ptr + this->ZoomOffset);
}

unsigned __int64 SDK::APawn::GetRootCmp()
{
	this->LocalPawn_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->Controller_ptr + this->APawn_Offset);
	this->RootComponent = this->ReadVirtualMemory<uintptr_t>(this->LocalPawn_ptr + this->rootcmp_offset);

	return  this->RootComponent;
}

unsigned __int64 SDK::APawn::GetPawnPtr()
{
	this->LocalPawn_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->Controller_ptr + this->APawn_Offset);
	return this->LocalPawn_ptr;
}
unsigned __int64 SDK::APawn::GetController()
{
	this->Controller_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->LocalPlayerPtr + this->Controller_offset);
	return this->Controller_ptr;	
}