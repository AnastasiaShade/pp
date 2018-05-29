#pragma once

class CClient
{
public:
	CClient(std::string id);
	~CClient() = default;

	std::string GetId() const;
	void LiveInRoom() const;

private:
	std::string m_id;
	static HANDLE m_mutex;
};

