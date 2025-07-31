#pragma once
#include <string>
#include <stdexcept>
#include <dlfcn.h>

inline void loadPlugin(const std::string& path) {
    void* handle = dlopen(path.c_str(), RTLD_NOW | RTLD_GLOBAL);
    if (!handle) throw std::runtime_error(dlerror());

    using RegisterFunc = void (*)();
    auto registerFunc = (RegisterFunc)dlsym(handle, "registerStrategies");
    if (!registerFunc) throw std::runtime_error("Missing registerStrategies()");

    registerFunc();
}