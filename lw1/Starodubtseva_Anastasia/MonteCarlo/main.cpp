#include "stdafx.h"
#include "MonteCalroAlgorithm.h"

int main(int argc, char* argv[])
{
	if (argc < MIN_ARGUMENTS_COUNT || argc > MAX_ARGUMENTS_COUNT)
	{
		std::cout << ERROR_MESSAGE;
		return 1;
	}

	if (argc == MIN_ARGUMENTS_COUNT && argv[1] == HELP_FLAG)
	{
		std::cout << HELP_MESSAGE;
		return 0;
	}

	int iterationsCount = atoi(argv[1]);
	int threadsCount = (argc == MIN_ARGUMENTS_COUNT) ? MIN_THREADS_COUNT : atoi(argv[2]);

	if (iterationsCount < MIN_ITERATIONS_COUNT
		|| threadsCount < MIN_THREADS_COUNT || threadsCount > MAX_THREADS_COUNT)
	{
		std::cout << ERROR_MESSAGE;
		return 1;
	}

	CMonteCalroAlgorithm monteCarlo(iterationsCount, threadsCount);
	clock_t start = clock();
	monteCarlo.Run();
	clock_t end = clock();

	std::cout << std::endl << "Pi number is " << monteCarlo.GetPiNumber() << std::endl;
	std::cout << "Calculation time = " << (float)(end - start) / CLOCKS_PER_SEC << std::endl;

	return 0;
}
