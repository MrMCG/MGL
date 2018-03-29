#pragma once

#include <iostream>

#define FILENAME_ONLY (strrchr(__FILE__, '\\') + 1)

#define LOGE(x) (std::cerr << "ERR " << FILENAME_ONLY << " " << __LINE__ << " " << x << std::endl);
#define LOGI(x) (std::cout << "INF " << FILENAME_ONLY << " " << __LINE__ << " " << x << std::endl);

#ifdef _DEBUG
	#define LOGD(x) (std::cout << "DBG " << FILENAME_ONLY << " " << __LINE__ << " " << x << std::endl);
#else
	#define LOGD(x) ;
#endif