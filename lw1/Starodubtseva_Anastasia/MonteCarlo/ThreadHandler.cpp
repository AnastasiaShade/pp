#include "stdafx.h"
#include "ThreadHandler.h"


CThreadHandler::CThreadHandler()
{
}

std::vector<HANDLE> CThreadHandler::MakeThreads(size_t threadsCount, size_t totalIterationscount, LPTHREAD_START_ROUTINE function)
{
	std::vector<HANDLE> threads;
	std::vector<size_t> dataInThread;

	size_t iterationsInThread = totalIterationscount / threadsCount;
	size_t additionalIterations = totalIterationscount % threadsCount;
	size_t resultIterations = 0;

	for (size_t i = 0; i < threadsCount; ++i)
	{
		resultIterations = (i < additionalIterations) ? iterationsInThread +1 : iterationsInThread;
		
		if (resultIterations == MIN_ITERATIONS_COUNT)
		{
			break;
		}

		dataInThread.push_back(resultIterations);
	}

	for (auto& data : dataInThread)
	{
		HANDLE thread = CreateThread(NULL, 0, function, &data, 0, NULL);
		if (thread != NULL)
		{
			threads.push_back(thread);
		}
		else
		{
			std::cout << "Cant create thread" << std::endl;
		}
	}

	WaitForMultipleObjects(threads.size(), threads.data(), TRUE, INFINITE);
	return threads;
}

void CThreadHandler::CloseAll(std::vector<HANDLE>& threads)
{
	for (HANDLE thread : threads)
	{
		CloseHandle(thread);
	}
}
