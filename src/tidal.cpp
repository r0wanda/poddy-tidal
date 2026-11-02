#include <podmod/podmod.hpp>
#include "interface.hpp"

extern "C" PodMod *create_object(Poddy *pod) {
	return new YtdlMod(pod);
}
extern "C" void free_object(YtdlMod *mod) {
	delete mod;
}
