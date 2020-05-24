#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <stdexcept>

static bool is_blank(const std::string& line)
{
	for (const unsigned char c : line) {
		if (!std::isspace(c)) {
			return false;
		}
	}
	return true;
}

template <typename T, typename F>
void parse_csv_file(const std::string& csv_file, F parser, std::vector<T>& entries)
{
	std::ifstream csv(csv_file);
	if (!csv.good()) {
		throw std::runtime_error(std::string("Failed to open ") + csv_file);
	}
	entries.clear();
	std::string line;
	while (std::getline(csv, line))
	{
		if (is_blank(line))
			continue;
		//comma --> space
		std::replace(line.begin(), line.end(), ',', ' ');
		entries.push_back(parser(line));
	}
}
