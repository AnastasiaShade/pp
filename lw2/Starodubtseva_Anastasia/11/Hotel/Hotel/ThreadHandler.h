#pragma once
class CThreadHandler
{
public:
	CThreadHandler() = default;
	~CThreadHandler() = default;

	void AddThread(LPVOID data, LPTHREAD_START_ROUTINE function);
	void Wait();
	void CloseAll();

private:
	std::vector<HANDLE> m_threads;
};

