#include "stdafx.h"
#include "MonteCalroAlgorithm.h"


CMonteCalroAlgorithm::CMonteCalroAlgorithm(size_t iterationsCount, size_t threadsCount)
	: m_iterationsCount(iterationsCount)
	, m_pointsInCircle(0)
	, m_threadsCount(threadsCount)
{
}

double CMonteCalroAlgorithm::GetPiNumber() const
{
	return m_pi;
}

void CMonteCalroAlgorithm::Run()
{
	m_pi = SinglethreadedAlgorithm();
}

double CMonteCalroAlgorithm::SinglethreadedAlgorithm()
{
	m_pointsInCircle = 0;
	
	std::srand(std::time(0));
	for (size_t i = 0; i < m_iterationsCount; ++i)
	{
		double x = (double)(rand()) / RAND_MAX * (MAX_COORDINATE - MIN_COORDINATE) + MIN_COORDINATE;
		double y = (double)(rand()) / RAND_MAX * (MAX_COORDINATE - MIN_COORDINATE) + MIN_COORDINATE;

		if (PointInCircle(x, y))
		{
			++m_pointsInCircle;
		}
	}

	return 4 * (double)m_pointsInCircle / m_iterationsCount;
}

bool CMonteCalroAlgorithm::PointInCircle(double x, double y)
{
	return (pow(x, 2) + pow(y, 2)) <= 1;
}
