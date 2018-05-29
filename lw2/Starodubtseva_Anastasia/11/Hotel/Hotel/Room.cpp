#include "stdafx.h"
#include "Room.h"

CRoom::CRoom(std::string id)
	:m_id(id)
	,m_isVacant(true)
{
}

void CRoom::SetVacantState(bool state)
{
	m_isVacant = state;
}

bool CRoom::IsVacant() const
{
	return m_isVacant;
}

std::string CRoom::GetId() const
{
	return m_id;
}
