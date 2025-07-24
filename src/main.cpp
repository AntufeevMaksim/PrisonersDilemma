
#include "PrisonerSimulator.hpp"

int main(int argc, char* argv[])
{
    InputData data {argc, argv};
    PrisonerSimulator simulator {data};

    simulator.run();

    return 0;
}
