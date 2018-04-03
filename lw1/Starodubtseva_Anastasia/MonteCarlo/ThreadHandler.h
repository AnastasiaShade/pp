#pragma once
class CThreadHandler
{
public:
	CThreadHandler();
	~CThreadHandler() = default;
	std::vector<HANDLE> MakeThreads(size_t threadsCount, size_t totalIterationscount, LPTHREAD_START_ROUTINE function);
	void CloseAll(std::vector<HANDLE>& threads);
};

