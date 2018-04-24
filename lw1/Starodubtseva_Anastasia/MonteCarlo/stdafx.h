#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include "windows.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

static const size_t MIN_ARGUMENT_COUNT = 2;
static const size_t MAX_ARGUMENT_COUNT = 3;

static const int MIN_THREAD_COUNT = 1;
static const int MAX_THREAD_COUNT = 64;

static const int MIN_ITERATION_COUNT = 0;

static const size_t CIRCLE_RADIUS = 1;
static const size_t DIAMETER = 2 * CIRCLE_RADIUS;
static const size_t EXPONENT = 2;
static const size_t PI_COEFICIENT = 4;

static const std::string ITERATION_COUNT_INFO = "    <iterations count> - value is positive\n";
static const std::string TREAD_COUNT_INFO = "    <threads count> - optional argument, value in range from " + std::to_string(MIN_THREAD_COUNT) + " to " + std::to_string(MAX_THREAD_COUNT) + "\n";

static const std::string HELP_INFO = "  MonteCarlo.exe --help for help\n";
static const std::string RUN_INFO = "  MonteCarlo.exe <iterations count> <threads count> to run program\n" + ITERATION_COUNT_INFO + TREAD_COUNT_INFO;

static const std::string HELP_MESSAGE = "Use:\n" + HELP_INFO + RUN_INFO;
static const std::string ERROR_MESSAGE = "Invalid arguments\n" + HELP_MESSAGE;

static const std::string HELP_FLAG = "--help";
