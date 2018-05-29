#pragma once
#include "Room.h"
#include "Client.h"
#include "ThreadHandler.h"

class CHotel
{
public:
	CHotel();
	~CHotel();

	void Run();
	static CRoom * FindFirstVacantRoom();

private:
	static std::vector<CRoom> CreateRooms();
	std::vector<CClient> CreateClients();
	static DWORD WINAPI SettleClient(CONST LPVOID data);

	static std::vector<CRoom> m_rooms;
	std::vector<CClient> m_clients;
	static HANDLE m_semaphore;
};
