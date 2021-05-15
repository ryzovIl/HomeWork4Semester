#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

void demo_status(const std::filesystem::path& p, std::filesystem::file_status s)
{
    std::cout << p;
    switch (s.type())
    {
        case std::filesystem::file_type::none: std::cout << " has `not-evaluated-yet` type"; break;
        case std::filesystem::file_type::not_found: std::cout << " does not exist"; break;
        case std::filesystem::file_type::regular: std::cout << " is a regular file"; break;
        case std::filesystem::file_type::directory: std::cout << " is a directory"; break;
        case std::filesystem::file_type::symlink: std::cout << " is a symlink"; break;
        case std::filesystem::file_type::block: std::cout << " is a block device"; break;
        case std::filesystem::file_type::character: std::cout << " is a character device"; break;
        case std::filesystem::file_type::fifo: std::cout << " is a named IPC pipe"; break;
        case std::filesystem::file_type::socket: std::cout << " is a named IPC socket"; break;
        case std::filesystem::file_type::unknown: std::cout << " has `unknown` type"; break;
        default: std::cout << " has `implementation-defined` type"; break;
    }
    std::cout << '\n';
}

void view_directory(const std::filesystem::path& path)
{
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
    {
        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            auto file_name = entry.path().filename().string();

            std::cout << file_name << std::endl;

            demo_status(entry, entry.symlink_status());

            std::filesystem::path p = std::filesystem::current_path();
            auto ftime = std::filesystem::last_write_time(p);
            std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
            std::cout << "File write time is " << std::asctime(std::localtime(&cftime)) << '\n';

        }
    }
}

int main() {
    system("chcp 1251");
    view_directory(std::filesystem::current_path());
    system("pause");

    return 0;
}