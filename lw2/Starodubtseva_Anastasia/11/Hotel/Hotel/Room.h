#pragma once
class CRoom
{
public:
	CRoom(size_t id);
	~CRoom() = default;

	void SetState(bool state);
	bool IsVacant();

private:
	size_t m_id;
	bool m_isVacant;
};
