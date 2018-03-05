#pragma once
class CProgressBar
{
public:
	CProgressBar(unsigned int total);
	~CProgressBar() = default;
	void Update();

private:
	unsigned int m_current;
	unsigned int m_total;
};

