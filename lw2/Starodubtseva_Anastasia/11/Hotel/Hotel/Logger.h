#pragma once

class CLogger
{
public:
	static void PrintMessage(std::string message);
private:
	static HANDLE m_mutex;
};

