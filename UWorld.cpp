#include "Classes.h"
using namespace std;
SDK::World::World()
{
	this->world_ptr = this->ReadVirtualMemory<unsigned __int64>(SDK::base + 0x6C0A9F8);
}
void SDK::World::UpdateWorld()
{
	this->world_ptr = this->ReadVirtualMemory<unsigned __int64>(SDK::base + 0x6C0A9F8);

}

SDK::GameInstanceClass::GameInstanceClass()
{
	this->GameInstance_ptr = this->ReadVirtualMemory<unsigned __int64>(this->world_ptr + this->GameInstance_offset);
}
void SDK::GameInstanceClass::UpdateGMC()
{
	this->GameInstance_ptr = this->ReadVirtualMemory<unsigned __int64>(this->world_ptr + this->GameInstance_offset);

}