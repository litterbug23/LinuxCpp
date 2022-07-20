#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <filesystem>
//c++ 11
namespace fs = std::experimental::filesystem;

std::wstring GetDefaultLogFile()
{
    fs::path logPath = fs::temp_directory_path();
    logPath = logPath.parent_path().parent_path();
    logPath.append("Glodon/GGP");
    if (!fs::exists(logPath))
    {
        fs::create_directories(logPath);
    }

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    struct tm tminfo;
    localtime_s(&tminfo, &in_time_t);
    char timebuffer[80];
    std::strftime(timebuffer, 80, "GGP-%Y-%m-%d.txt", &tminfo);
    logPath.append(timebuffer);

    return logPath.c_str();
}

int main()
{
  std::wcout<<GetDefaultLogFile()<<std::endl;
  return 1;
}
