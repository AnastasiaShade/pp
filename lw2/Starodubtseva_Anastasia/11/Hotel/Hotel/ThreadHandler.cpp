#include "stdafx.h"
#include "ThreadHandler.h"

void CThreadHandler::AddThread(LPVOID data, LPTHREAD_START_ROUTINE function)
{
	HANDLE thread = CreateThread(NULL, 0, function, data, 0, NULL);
	if (thread != NULL)
	{
		m_threads.push_back(thread);
	}
	else
	{
		std::cout << "Cant create thread" << std::endl;
	}
}

void CThreadHandler::Wait()
{
	WaitForMultipleObjects(m_threads.size(), m_threads.data(), TRUE, INFINITE);
}

void CThreadHandler::CloseAll()
{
	for (HANDLE thread : m_threads)
	{
		CloseHandle(thread);
	}
}
