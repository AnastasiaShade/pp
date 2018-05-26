#pragma once
#include "Room.h"

class CHotel
{
public:
	CHotel();
	~CHotel() = default;

	HANDLE GetSemaphore();

private:
	void CreateRooms();

	HANDLE m_semaphore;
	std::vector<CRoom> m_rooms;
};

