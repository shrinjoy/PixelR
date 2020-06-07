#include "PixelR.h"
std::string Utility::ReadFile(std::string path)
{
	std::ifstream fs(path);
	std::string line;
	std::string outputdata;
	while (std::getline(fs,line))
	{
		if (line.empty())
		{
			;;
		}
		else
		{
			outputdata.append(line + "\n");
		}
		}
	fs.close();
	return outputdata;
}