#ifndef HELPER_H
#define HELPER_H

#include <string>

using string = std::string;

namespace timelapse {

    string generateOutputFilename(const string& name,
                                  const string& output_path);
}

#endif
