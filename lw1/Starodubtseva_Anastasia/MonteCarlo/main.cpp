#include "stdafx.h"
#include "MonteCalroAlgorithm.h"

static const size_t MIN_ARGUMENT_COUNT = 2;
static const size_t MAX_ARGUMENT_COUNT = 3;
static const int MAX_THREAD_COUNT = 64;
static const std::string HELP_FLAG = "--help";


static const std::string ITERATION_COUNT_INFO = "    <iterations count> - value is positive\n";
static const std::string TREAD_COUNT_INFO = "    <threads count> - optional argument, value in range from " + std::to_string(MIN_THREAD_COUNT) + " to " + std::to_string(MAX_THREAD_COUNT) + "\n";

static const std::string HELP_INFO = "  MonteCarlo.exe --help for help\n";
static const std::string RUN_INFO = "  MonteCarlo.exe <iterations count> <threads count> to run program\n" + ITERATION_COUNT_INFO + TREAD_COUNT_INFO;

static const std::string HELP_MESSAGE = "Use:\n" + HELP_INFO + RUN_INFO;
static const std::string ERROR_MESSAGE = "Invalid arguments\n" + HELP_MESSAGE;

int main(int argc, char* argv[])
{
	if (argc < MIN_ARGUMENT_COUNT || argc > MAX_ARGUMENT_COUNT)
	{
		std::cout << ERROR_MESSAGE;
		return 1;
	}

	if (argc == MIN_ARGUMENT_COUNT && argv[1] == HELP_FLAG)
	{
		std::cout << HELP_MESSAGE;
		return 0;
	}

	int iterationsCount = atoi(argv[1]);
	int threadsCount = (argc == MIN_ARGUMENT_COUNT) ? MIN_THREAD_COUNT : atoi(argv[2]);

	if (iterationsCount < MIN_ITERATION_COUNT
		|| threadsCount < MIN_THREAD_COUNT || threadsCount > MAX_THREAD_COUNT)
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
