#include "Strategy.hpp"

#include "Kind.hpp"

#include <stdexcept>

std::unique_ptr<Strategy> Strategy::create(const std::string& name)
{
    if (name == "Kind")
    {
        return std::unique_ptr<Strategy> { new Kind{}};
    }
    else
    {
        throw std::runtime_error("incorrect strategy name");
    }
}
