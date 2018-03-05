#pragma once
#include "RandomPoint.h"

class CMonteCalroAlgorithm
{
public:
	CMonteCalroAlgorithm(unsigned int iterationsCount, size_t threadsCount);
	~CMonteCalroAlgorithm() = default;
	void Run();
	double GetPiNumber() const;

private:
	double SinglethreadedAlgorithm();
	bool PointInCircle(CRandomPoint & rndPoint);

	unsigned int m_pointsInCircle;
	unsigned int m_iterationsCount;
	size_t m_threadsCount;
	double m_pi;
};

