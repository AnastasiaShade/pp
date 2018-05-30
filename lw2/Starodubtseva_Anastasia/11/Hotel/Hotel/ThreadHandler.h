#pragma once
class CThreadHandler
{
public:
	void AddThread(LPVOID data, LPTHREAD_START_ROUTINE function);
	void Wait();
	void CloseAll();

private:
	std::vector<HANDLE> m_threads;
};

