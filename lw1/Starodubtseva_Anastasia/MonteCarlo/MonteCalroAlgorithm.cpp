#include "stdafx.h"
#include "MonteCalroAlgorithm.h"

CMonteCalroAlgorithm::CMonteCalroAlgorithm(size_t iterationsCount, size_t threadsCount)
	: m_iterationsCount(iterationsCount)
	, m_pointsInCircle(0)
	, m_threadsCount(threadsCount)
{
}

float CMonteCalroAlgorithm::GetPiNumber() const
{
	return m_pi;
}

void CMonteCalroAlgorithm::Run()
{
	m_pi = SinglethreadedAlgorithm();
}

float CMonteCalroAlgorithm::SinglethreadedAlgorithm()
{
	m_pointsInCircle = 0;
	
	std::srand(time(0));
	for (size_t i = 0; i < m_iterationsCount; ++i)
	{
		CRandomPoint rndPoint;

		if (PointInCircle(rndPoint))
		{
			++m_pointsInCircle;
		}
	}

	return 4 * (float)m_pointsInCircle / m_iterationsCount;
}

bool CMonteCalroAlgorithm::PointInCircle(CRandomPoint & rndPoint)
{
	return (pow(rndPoint.GetX(), 2) + pow(rndPoint.GetY(), 2)) <= 1;
}
