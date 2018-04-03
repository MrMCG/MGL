#pragma once

#include <iostream>
#include <iomanip>

#define FILENAME_ONLY (strrchr(__FILE__, '\\') + 1)
#define FILE_DATA std::left << std::setw(16) << FILENAME_ONLY << " | " << std::setw(4) << __LINE__ << " | "

#define LOGE(x) (std::cerr << "ERR | " << FILE_DATA << x << std::endl);
#define LOGI(x) (std::cout << "INF | " << FILE_DATA << x << std::endl);

#ifdef _DEBUG
	#define LOGD(x) (std::cout << "DBG | " << FILE_DATA << x << std::endl);
#else
	#define LOGD(x) ;
#endif