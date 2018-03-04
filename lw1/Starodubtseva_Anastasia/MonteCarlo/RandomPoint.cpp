#include "stdafx.h"
#include "RandomPoint.h"

CRandomPoint::CRandomPoint()
	: m_x(GetRandomNumber())
	, m_y(GetRandomNumber())
{
}

float CRandomPoint::GetX() const
{
	return m_x;
}

float CRandomPoint::GetY() const
{
	return m_y;
}

float CRandomPoint::GetRandomNumber() const
{
	return (float)(rand()) / RAND_MAX * (MAX_COORDINATE - MIN_COORDINATE) + MIN_COORDINATE;
}
