#include <iostream>
#include <string>
#include <vector>
#if defined (_WIN32) || defined( _WIN64)

#include <Windows.h>

std::vector<std::string> get_com_ports()
{
	std::vector< std::string> comports{};
	char lpTargetPath[5000];
	bool gotPort = false;

	for (int i = 0; i < 255; i++)
	{
		std::string str = "COM" + std::to_string(i);
		if (QueryDosDeviceA(str.c_str(), lpTargetPath, 5000) != 0)
		{
			comports.push_back(str);
			std::cout << str << ": " << lpTargetPath << std::endl;
			gotPort = true;
		}

		if (::GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
		}
	}

	return gotPort;
}
#endif


#if defined (__linux__) || defined(__APPLE__)

#endif