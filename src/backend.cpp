#include <cstdio>
#include <string>
#include <functional>

void exec(const char* cmd, const std::function<void(std::string)> &err) {
	constexpr size_t arrSz = 128;
    char buf[arrSz];
	std::FILE *f;
	#ifdef IS_LINUX
	f = popen(cmd, "r");
	#elif IS_WINDOWS
	f = _popen(cmd, "r");
	#endif
	if (!f) {
		err("ytdl failed to open");
	}

	while (std::fgets(buf, arrSz, f) != nullptr) {
		
	}

	#ifdef IS_LINUX
	pclose(f);
	#elif IS_WINDOWS
	_pclose(f);
	#endif
}
