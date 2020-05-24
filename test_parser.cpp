#include "tiny_csv_parser.h"

struct Format1
{
	std::string file;
	float x;
	float y;
	float w;
	float h;
};

Format1 parse_format1_line(const std::string& space_seperated_line)
{
	std::stringstream ss(space_seperated_line);
	Format1 val;
	ss >> val.file >> val.x >> val.y >> val.w >> val.h;
	return val;
}

int main(int, char**)
{
	std::string file = "test_format1.csv";
	std::vector<Format1> entries;
	parse_csv_file(file, parse_format1_line, entries);

	return 0;
}

