#include "stdafx.h"
#include "Hotel.h"
#include "ThreadHandler.h"

static const size_t ROOM_COUNT = 5;
static const size_t CLIENT_COUNT = 6;

HANDLE CHotel::m_semaphore = CreateSemaphore(NULL, ROOM_COUNT, ROOM_COUNT, NULL);
std::vector<CRoom> CHotel::m_rooms = CreateRooms();

CHotel::CHotel()
	:m_clients(CreateClients())
{
}

CHotel::~CHotel()
{
	CloseHandle(m_semaphore);
}

void CHotel::Run()
{

}

CRoom * CHotel::FindFirstVacantRoom()
{

}

std::vector<CRoom> CHotel::CreateRooms()
{
	std::vector<CRoom> rooms;

	for (size_t i = 0; i < ROOM_COUNT; ++i)
	{
		CRoom room("#" + std::to_string(i + 1));
		rooms.push_back(room);
	}

	return rooms;
}

std::vector<CClient> CHotel::CreateClients()
{
	std::vector<CClient> clients;

	for (size_t i = 0; i < CLIENT_COUNT; ++i)
	{
		CClient client("#" + std::to_string(i + 1));
		clients.push_back(client);
	}

	return clients;
}

DWORD WINAPI CHotel::SettleClient(CONST LPVOID data)
{
	CClient * client = static_cast<CClient *>(data);
	std::string clientId = client->GetId();

	std::cout << "The client " + clientId + " arrived and wants to rent a room" << std::endl;

	while (true)
	{
		try {
			client->LiveInRoom();
			break;
		}
		catch (const std::exception &exc) {
			std::cout << "Client " + clientId + ", " + exc.what() << std::endl;
			WaitForSingleObject(m_semaphore, INFINITE);
		}
	}
	ReleaseSemaphore(m_semaphore, 1, NULL);

	return 0;
}
