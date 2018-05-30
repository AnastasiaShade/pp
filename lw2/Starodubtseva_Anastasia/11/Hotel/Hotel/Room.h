#pragma once

class CRoom
{
public:
	CRoom(const std::string & id);

	void SetVacantState(bool state);
	bool IsVacant() const;
	std::string GetId() const;

private:
	std::string m_id;
	bool m_isVacant;
};
