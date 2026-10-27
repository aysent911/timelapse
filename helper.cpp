#include "helper.h"

#include <ctime>
#include <filesystem>

namespace timelapse {
    string generateOutputFilename(const string& name,
                                  const string& output_path) {
        const std::time_t now = std::time(nullptr);
        std::tm local_time{};
        localtime_r(&now, &local_time);

        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp),
                      "%Y-%m-%d_%H-%M-%S", &local_time);

        std::filesystem::path directory =
            std::filesystem::path(output_path) / "timelapse";
        std::filesystem::create_directories(directory);

        return (directory / (name + "-" + timestamp + ".mp4")).string();
    }
}
