#include "stdafx.h"
#include "MonteCalroAlgorithm.h"
#include "ProgressBar.h"

static const size_t PI_COEFICIENT = 4;
static const size_t EXPONENT = 2;

size_t CMonteCalroAlgorithm::m_pointsInCircleCount = 0;

CMonteCalroAlgorithm::CMonteCalroAlgorithm(size_t iterationCount)
	: m_iterationCount(iterationCount)
{
}

double CMonteCalroAlgorithm::GetPiNumber() const
{
	return m_pi;
}

void CMonteCalroAlgorithm::Run()
{
	std::srand(time(0));
	auto & instance = CProgressBar::GetInstance();
	instance.SetTotal(m_iterationCount);

	for (size_t i = 0; i < m_iterationCount; ++i)
	{
		CRandomPoint rndPoint;

		if (IsPointInCircle(rndPoint))
		{
			++m_pointsInCircleCount;
		}
		instance.Update();
	}

	m_pi = PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationCount;
	
}


bool CMonteCalroAlgorithm::IsPointInCircle(CRandomPoint& rndPoint)
{
	return (pow(rndPoint.GetX(), EXPONENT) + pow(rndPoint.GetY(), EXPONENT)) <= CIRCLE_RADIUS;
}
