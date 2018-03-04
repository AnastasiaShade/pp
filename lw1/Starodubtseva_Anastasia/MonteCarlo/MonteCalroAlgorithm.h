#pragma once
#include "RandomPoint.h"

class CMonteCalroAlgorithm
{
public:
	CMonteCalroAlgorithm(size_t iterationsCount, size_t threadsCount);
	~CMonteCalroAlgorithm() = default;
	void Run();
	float GetPiNumber() const;

private:
	float SinglethreadedAlgorithm();
	bool PointInCircle(CRandomPoint & rndPoint);

	size_t m_pointsInCircle;
	size_t m_iterationsCount;
	size_t m_threadsCount;
	float m_pi;
};

