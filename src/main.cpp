
#include "PrisonerSimulator.hpp"
#include "PluginLoader.hpp"

int main(int argc, char* argv[])
{
    loadPlugin("./librandomstrategy.so");
    InputData data {argc, argv};
    PrisonerSimulator simulator {data};

    simulator.run();

    return 0;
}
