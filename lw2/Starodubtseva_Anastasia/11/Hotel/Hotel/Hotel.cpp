#include "stdafx.h"
#include "Hotel.h"

static const size_t ROOM_COUNT = 5;

CHotel::CHotel()
	:m_semaphore(CreateSemaphore(NULL, ROOM_COUNT, ROOM_COUNT, NULL))
{
	CreateRooms();
}

HANDLE CHotel::GetSemaphore()
{
	return m_semaphore;
}

void CHotel::CreateRooms()
{
	for (size_t i = 0; i < ROOM_COUNT; ++i)
	{
		m_rooms.push_back(CRoom(i));
	}
}
