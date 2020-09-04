#include "FileControl.h"

int fileControl::GetLineString(int lineSize, std::string* lineString, std::string FileName)
{
	auto filePos = 0;
	//int lineCounter = 0;
	std::fstream fs(FileName, std::ios::in);

	if (!fs)
	{
		std::cout << "file not opened!\n" << std::endl;
		return -1;
	}
	for (int lineCounter=0; lineCounter<lineSize;lineCounter++)
	{
		auto lineSize = 0;
		getline(fs, lineString[lineCounter]);
		lineSize = static_cast<int>(lineString[lineCounter].size());
		filePos = static_cast<int>(fs.tellg());
		fs.seekp(filePos, std::ios::beg);
	}

	return 0;
}

bool fileControl::GenerateMapData(int size_x, int size_y, int * mapData, std::string FileName)
{
	std::string searchName = ".txt";
	auto it = FileName.find(searchName);
	if (it == std::string::basic_string::npos)return false;
	if (size_x <= 0 || size_y <= 0)return false;

	std::ofstream ofs(FileName);
	if (!ofs)
	{
		return false;
	}
	int idx = 0;
	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			ofs << mapData[idx] << ",";
			idx++;
		}
		ofs << "\n";
	}

	return true;

}

bool fileControl::WriteString(std::string FileName, std::list <std::string> lineString)
{

	std::string searchName = ".txt";
	auto it = FileName.find(searchName);
	if (it == std::string::basic_string::npos)return false;

	std::ofstream ofs(FileName);

	for (auto&& LineString : lineString)
	{
		ofs << LineString << std::endl;
	}


	return true;
}
