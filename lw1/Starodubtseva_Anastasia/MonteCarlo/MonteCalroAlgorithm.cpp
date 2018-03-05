#include "stdafx.h"
#include "MonteCalroAlgorithm.h"
#include "ProgressBar.h"

CMonteCalroAlgorithm::CMonteCalroAlgorithm(unsigned int iterationsCount, size_t threadsCount)
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
	CProgressBar progressBar(m_iterationsCount);

	std::srand(time(0));
	for (size_t i = 0; i < m_iterationsCount; ++i)
	{
		CRandomPoint rndPoint;

		if (PointInCircle(rndPoint))
		{
			++m_pointsInCircle;
		}
		progressBar.Update();
	}

	std::cout << std::endl;
	return 4 * (double)m_pointsInCircle / m_iterationsCount;
}

bool CMonteCalroAlgorithm::PointInCircle(CRandomPoint & rndPoint)
{
	return (pow(rndPoint.GetX(), 2) + pow(rndPoint.GetY(), 2)) <= 1;
}
