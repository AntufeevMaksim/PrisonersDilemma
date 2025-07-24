#include "Strategy.hpp"

#include "Kind.hpp"
#include "Traitor.hpp"

#include <stdexcept>

std::unique_ptr<Strategy> Strategy::create(const std::string& name)
{
    if (name == "Kind")
    {
        return std::unique_ptr<Strategy> { new Kind{}};
    }
    else if (name == "Traitor")
    {
        return std::unique_ptr<Strategy> { new Traitor{}};
    }
    else
    {
        throw std::runtime_error("incorrect strategy name");
    }
}
