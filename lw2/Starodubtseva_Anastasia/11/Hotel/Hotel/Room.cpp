#include "stdafx.h"
#include "Room.h"

CRoom::CRoom(size_t id)
	:m_id(id)
	,m_isVacant(true)
{
}

void CRoom::SetState(bool state)
{
	m_isVacant = state;
}

bool CRoom::IsVacant()
{
	return m_isVacant;
}
