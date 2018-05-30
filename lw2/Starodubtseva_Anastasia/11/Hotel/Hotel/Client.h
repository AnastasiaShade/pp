#pragma once

class CClient
{
public:
	CClient(const std::string & id);

	std::string GetId() const;
	void LiveInRoom() const;

private:
	std::string m_id;
};

