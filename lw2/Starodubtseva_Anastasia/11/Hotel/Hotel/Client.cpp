#include "stdafx.h"
#include "Client.h"
#include "Room.h"
#include "Hotel.h"

static const size_t SLEEPING_TIME = 2000;

CClient::CClient(std::string id)
	:m_id(id)
{
}

std::string CClient::GetId() const
{
	return m_id;
}

void CClient::LiveInRoom() const
{
	WaitForSingleObject(CHotel::m_mutex, INFINITE);
	CRoom & room = CHotel::FindFirstVacantRoom();
	room.SetVacantState(false);
	ReleaseMutex(CHotel::m_mutex);
	
	std::string roomId = room.GetId();
	std::cout << "The client " + m_id + " moved into the room " + roomId << std::endl;
	Sleep(SLEEPING_TIME);
	room.SetVacantState(true);
	std::cout << "The client " + m_id + " released the room " + roomId << std::endl;
}
