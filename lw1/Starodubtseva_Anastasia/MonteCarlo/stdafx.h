#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <ctime>
#include <string>

static const size_t MIN_ARGUMENTS_COUNT = 2;
static const size_t MAX_ARGUMENTS_COUNT = 3;

static const size_t MIN_THREADS_COUNT = 1;
static const size_t MAX_THREADS_COUNT = 20;

static const unsigned int MIN_ITERATIONS_COUNT = 0;
static const unsigned int MAX_ITERATIONS_COUNT = INT_MAX;

static const float MIN_COORDINATE = -1;
static const float MAX_COORDINATE = 1;


static const std::string ITERATIONS_COUNT_INFO = "    <iterations count> - " + std::to_string(MIN_ITERATIONS_COUNT) + " - " + std::to_string(MAX_ITERATIONS_COUNT) + "\n";
static const std::string TREADS_COUNT_INFO = "    <threads count> - " + std::to_string(MIN_THREADS_COUNT) + " - " + std::to_string(MAX_THREADS_COUNT) + "\n";

static const std::string HELP_INFO = "  MonteCarlo.exe --help for help\n";
static const std::string RUN_INFO = "  MonteCarlo.exe <iterations count> <threads count> to run program\n" + ITERATIONS_COUNT_INFO + TREADS_COUNT_INFO;

static const std::string HELP_MESSAGE = "Use:\n" + HELP_INFO + RUN_INFO;
static const std::string ERROR_MESSAGE = "Invalid arguments\n" + HELP_MESSAGE;

static const std::string HELP_FLAG = "--help";