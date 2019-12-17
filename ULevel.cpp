#include "Classes.h"
SDK::ULevel::ULevel()
{
	this->ULevel_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->world_ptr + this->ULevel_offset);

}
void SDK::ULevel::LevelUpdate()
{
	this->ULevel_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->world_ptr + this->ULevel_offset);
}
signed __int32 SDK::ULevel::GetCount()
{
	this->ULevel_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->world_ptr + this->ULevel_offset);
	return this->ReadVirtualMemory<signed __int32>(this->ULevel_ptr + this->ULevelCount_offset);
	//this->ULevelList = this->ReadVirtualMemory<unsigned __int64>(this->ULevel_ptr + this->ULevelList_offset);
}
unsigned __int64 SDK::ULevel::GetList()
{
	this->ULevel_ptr = this->ReadVirtualMemory<std::uintptr_t>(this->world_ptr + this->ULevel_offset);
	return this->ReadVirtualMemory<unsigned __int64>(this->ULevel_ptr + this->ULevelList_offset);
	//this->ULevelList = this->ReadVirtualMemory<unsigned __int64>(this->ULevel_ptr + this->ULevelList_offset);
}
	