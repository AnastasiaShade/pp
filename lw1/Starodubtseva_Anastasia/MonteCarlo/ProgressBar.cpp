#include "stdafx.h"
#include "ProgressBar.h"


CProgressBar::CProgressBar(unsigned int total)
	: m_current(0)
	, m_total(total)
{
	std::cout << "\r" << std::to_string(m_current) << "/" << std::to_string(m_total);
}

void CProgressBar::Update()
{
	++m_current;
	std::cout << "\r" << std::to_string(m_current) << "/" << std::to_string(m_total);
}