#include <ctime>
#include <string>
#include <iostream>
#include "spdlog/spdlog.h"

std::string get_greet(const std::string &who)
{
	return "Hello " + who;
}

void print_localtime()
{
	std::time_t result = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&result));
}

int main(int argc, char **argv)
{
	spdlog::set_level(spdlog::level::debug);
	spdlog::debug("starting lash");
	std::string who = "world";
	if (argc > 1)
	{
		who = argv[1];
	}
	std::cout << get_greet(who) << std::endl;
	print_localtime();
	return 0;
}
