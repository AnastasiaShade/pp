#include "stdafx.h"
#include "MonteCalroAlgorithm.h"

static const size_t ARGUMENT_COUNT = 2;
static const std::string HELP_FLAG = "--help";

int main(int argc, char* argv[])
{
	if (argc != ARGUMENT_COUNT)
	{
		CMessenger::PrintErrorMessage();
		return 1;
	}

	if (argv[1] == HELP_FLAG)
	{
		CMessenger::PrintHelpMessage();
		return 0;
	}

	int iterationCount = atoi(argv[1]);

	if (iterationCount < MIN_ITERATION_COUNT)
	{
		CMessenger::PrintErrorMessage();
		return 1;
	}

	CMonteCalroAlgorithm monteCarlo(iterationCount);
	clock_t start = clock();
	monteCarlo.Run();
	clock_t end = clock();

	std::cout << std::endl << "Pi number is " << monteCarlo.GetPiNumber() << std::endl;
	std::cout << "Calculation time = " << (float)(end - start) / CLOCKS_PER_SEC << std::endl;

	return 0;
}
