#include "StrategyFactory.hpp"


StrategyFactory& StrategyFactory::instance()
{
    static StrategyFactory factory;
    return factory;
}

void StrategyFactory::register_strategy(const std::string& name, FactoryFunc func)
{
    registry[name] = func;
}

std::unique_ptr<IStrategy> StrategyFactory::create(const std::string& name)
{
    auto it = registry.find(name);
    if (it == registry.end())
        throw std::runtime_error("Unknown strategy: " + name);
    return (it->second)();
}
