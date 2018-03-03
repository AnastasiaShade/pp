#pragma once
class CMonteCalroAlgorithm
{
public:
	CMonteCalroAlgorithm(size_t iterationsCount, size_t threadsCount);
	~CMonteCalroAlgorithm() = default;
	void Run();
	double GetPiNumber() const;

private:
	double SinglethreadedAlgorithm();

	bool PointInCircle(double x, double y);

	size_t m_pointsInCircle;
	size_t m_iterationsCount;
	size_t m_threadsCount;
	double m_pi;
};

