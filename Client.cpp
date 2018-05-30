#include "stdafx.h"
#include "Client.h"
#include "Room.h"
#include "Hotel.h"
#include "Logger.h"

static const size_t MAX_SLEEPING_TIME = 1000;
static const size_t MIN_SLEEPING_TIME = 200;

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
	CLogger::PrintMessage("The client #" + m_id + " moved into the room #" + roomId);

	size_t sleepingTime = (rand() % MAX_SLEEPING_TIME + MIN_SLEEPING_TIME) * stoi(m_id);
	CLogger::PrintMessage(std::to_string(sleepingTime));
	Sleep(sleepingTime);

	room.SetVacantState(true);
	CLogger::PrintMessage("The client #" + m_id + " released the room #" + roomId);
}
