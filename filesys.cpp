
#include <iostream>
#if defined(__cpp_lib_filesystem)
#   include <filesystem>
#else
#   error "no fs"
#endif

namespace fs = std::filesystem;
int main()
{
    std::cout << "Temp directory is " << fs::temp_directory_path() << '\n';
}
