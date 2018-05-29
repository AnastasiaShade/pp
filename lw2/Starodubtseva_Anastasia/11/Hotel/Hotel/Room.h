#pragma once

class CRoom
{
public:
	CRoom(std::string id);
	~CRoom() = default;

	void SetVacantState(bool state);
	bool IsVacant() const;
	std::string GetId() const;

private:
	std::string m_id;
	bool m_isVacant;
};
