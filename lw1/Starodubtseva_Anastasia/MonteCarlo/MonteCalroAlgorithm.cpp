#include "stdafx.h"
#include "MonteCalroAlgorithm.h"
#include "ThreadHandler.h"

size_t CMonteCalroAlgorithm::m_pointsInCircleCount = 0;

CMonteCalroAlgorithm::CMonteCalroAlgorithm(size_t iterationsCount, size_t threadsCount)
	: m_iterationsCount(iterationsCount)
	, m_threadsCount(threadsCount)
{
}

double CMonteCalroAlgorithm::GetPiNumber() const
{
	return m_pi;
}

void CMonteCalroAlgorithm::Run()
{
	m_pi = (m_threadsCount == MIN_THREADS_COUNT) ? SinglethreadedAlgorithm() : MultithreadedAlgorithm();
}

double CMonteCalroAlgorithm::SinglethreadedAlgorithm()
{
	std::srand(time(0));
	for (size_t i = 0; i < m_iterationsCount; ++i)
	{
		CRandomPoint rndPoint;

		if (IsPointInCircle(rndPoint))
		{
			++m_pointsInCircleCount;
		}
	}

	return PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationsCount;
}

double CMonteCalroAlgorithm::MultithreadedAlgorithm()
{
	CThreadHandler handler;
	std::vector<HANDLE> threads = handler.MakeThreads(m_threadsCount, m_iterationsCount, CalculatePointsInCircle);
	handler.CloseAll(threads);

	return PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationsCount;
}

bool CMonteCalroAlgorithm::IsPointInCircle(CRandomPoint& rndPoint)
{
	return (pow(rndPoint.GetX(), EXPONENT) + pow(rndPoint.GetY(), EXPONENT)) <= CIRCLE_RADIUS;
}

DWORD WINAPI CMonteCalroAlgorithm::CalculatePointsInCircle(LPVOID data)
{
	std::srand(time(0));
	size_t* iterations = static_cast<size_t*>(data);

	for (size_t i = 0; i < *iterations; ++i)
	{
		CRandomPoint rndPoint;

		if (IsPointInCircle(rndPoint))
		{
			InterlockedIncrement(&m_pointsInCircleCount);
		}
	}

	return 0;
}
