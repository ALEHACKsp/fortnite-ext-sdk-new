#pragma once
#include "MemoryReader.hpp"

#include "UWorld.h"
#include "LocalPlayer.h"
#include "ULevel.h"
#include "ACamera.h"
#include "APawn.h"

namespace SDK
{
#define __BASE static constexpr unsigned __int64
#define __OFFSET static constexpr unsigned __int64
	static unsigned __int64 base;
	class World : public MemoryTools::MemoryManager
	{
	public:
		World();
		void UpdateWorld();
	private:
		__BASE world_offset = 0x6C0A9F8;
	};





	class GameInstanceClass : public World
	{
	public:
		GameInstanceClass();
		void UpdateGMC();
	private:
		__OFFSET GameInstance_offset = 0x170;
	};
	class ULevel : public World
	{
	public:
		ULevel();
		void LevelUpdate();
		virtual signed __int32 GetCount();
		virtual unsigned __int64 GetList();


	private:
		__OFFSET ULevel_offset = 0x30;
		__OFFSET ULevelList_offset = 0x98;
		__OFFSET ULevelCount_offset = 0xA0;
	};

	class LocalPlayer : public World
	{
	public:
		LocalPlayer();
		virtual unsigned __int64 getPtr();

		Vector3 GetPosition();

	private:
		std::uintptr_t LocalPlayerList;
		__OFFSET LocalPlayer_List = 0x38;
		__OFFSET LocalPlayer_offset = 0x0;
		__OFFSET Local_Player_Position = 0x88;
	};




	class APawn : public World
	{
	public:
		APawn();
		virtual float GetZoom();
		virtual unsigned __int64 GetRootCmp();
		virtual unsigned __int64 GetPawnPtr();
		virtual unsigned __int64 GetController();


	private:



		__OFFSET Controller_offset = 0x0030;
		__OFFSET APawn_Offset = 0x0248;
		__OFFSET ZoomBase = 0xB0;
		__OFFSET ZoomOffset = 0x500;
		__OFFSET rootcmp_offset = 0x130;

	};
	class ACameraa : public World
	{
	public:
		ACameraa();
		Vector3 GetPositiona();
		Vector3 GetRotationa();
		float GetFova();
		bool WriteAnglesa(Vector3 angles);
	private:


		__OFFSET Camera_Posiion1 = 0x6BE5070;

		__OFFSET Pitch_offset1 = 0xb0; // localplayer
		__OFFSET Pitch_offset2 = 0x678; // localplayer + pitch_offset1

		__OFFSET Yaw_offset1 = 0x12C; //RootCMP

		__OFFSET ZoomBase1 = 0xB0;
		__OFFSET ZoomOffset1 = 0x500;

	};



}

struct Global
{
	 SDK::World* World;
	 SDK::ULevel* Level;
	 SDK::GameInstanceClass* GameInstance;
	 SDK::LocalPlayer* LocalPlayer;
	 SDK::APawn* Pawn;
	 SDK::ACameraa* Camera;

	 Vector3 m_World_LocalCamera;
	 Vector3 CameraPos;
	 Vector3 LocalPlayerPos;

	 unsigned __int64 p_LocalPlayerList;

	 unsigned __int64 p_LocalPlayer;
	 unsigned __int64 p_LocalPlayerController;
	 unsigned __int64 p_LocalPlayerRootComp;
	 unsigned __int64 p_ActorsList;
	 signed __int32 m_ActorsCount;

};