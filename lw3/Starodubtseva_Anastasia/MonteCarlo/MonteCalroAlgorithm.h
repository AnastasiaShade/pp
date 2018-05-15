#pragma once
#include "RandomPoint.h"

class CMonteCalroAlgorithm
{
public:
	CMonteCalroAlgorithm(size_t iterationsCount);
	~CMonteCalroAlgorithm() = default;
	void Run();
	double GetPiNumber() const;

private:
	static bool IsPointInCircle(CRandomPoint& rndPoint);

	static size_t m_pointsInCircleCount;
	size_t m_iterationCount;
	double m_pi;
};
