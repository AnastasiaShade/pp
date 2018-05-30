#include "stdafx.h"
#include "Client.h"
#include "Room.h"
#include "Hotel.h"
#include "Logger.h"

static const size_t SLEEPING_TIME = 2000;

CClient::CClient(const std::string & id)
	: m_id(id)
{
}

std::string CClient::GetId() const
{
	return m_id;
}

void CClient::LiveInRoom() const
{
	WaitForSingleObject(CHotel::mutex, INFINITE);
	CRoom & room = CHotel::FindFirstVacantRoom();
	room.SetVacantState(false);
	ReleaseMutex(CHotel::mutex);
	
	std::string roomId = room.GetId();
	CLogger::PrintMessage("The client " + m_id + " moved into the room " + roomId);
	Sleep(SLEEPING_TIME);
	room.SetVacantState(true);
	CLogger::PrintMessage("The client " + m_id + " released the room " + roomId);
}
