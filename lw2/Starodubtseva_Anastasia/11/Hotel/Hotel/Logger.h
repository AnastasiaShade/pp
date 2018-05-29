#pragma once

class CLogger
{
public:
	CLogger() = default;
	~CLogger() = default;
	static void PrintMessage(std::string message);
};

