#pragma once
#include <unordered_map>
#include <memory>
#include <functional>
#include <string>
#include <stdexcept>
#include "IStrategy.hpp"

class StrategyFactory {
public:
    using FactoryFunc = std::function<std::unique_ptr<IStrategy>()>;

    static StrategyFactory& instance();
    void register_strategy(const std::string& name, FactoryFunc func);
    std::unique_ptr<IStrategy> create(const std::string& name);

private:
    std::unordered_map<std::string, FactoryFunc> registry;
};