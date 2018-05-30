#include "stdafx.h"
#include "Logger.h"

HANDLE CLogger::m_mutex = CreateMutex(NULL, false, NULL);

void CLogger::PrintMessage(std::string message)
{
	WaitForSingleObject(m_mutex, INFINITE);
	std::cout << message << std::endl;
	ReleaseMutex(m_mutex);
}
