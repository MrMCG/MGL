#include <fstream>
#include <sstream>

#include "FileSystem.hpp"
#include "Logger.hpp"

namespace MGL {

	std::string GetFileAsString(std::string filePath) {
		LOGD("Opening file: " << filePath);
		std::ifstream file(filePath);
		if (!file.good()) {
			LOGE("File: " << filePath << " is bad");
			return {};
		}

		std::ostringstream sstream;
		sstream << file.rdbuf();
		return sstream.str();
	}

} // MGL
