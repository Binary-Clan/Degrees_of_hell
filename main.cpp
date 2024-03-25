#include "CDegrees.h"

int main()
{
    CDegrees game;

    game.ReadSpaces("degrees.txt");
    game.AddPlayer("Vyvyan");
    game.AddPlayer("Rick");
    game.AddPlayer("Neil");
    game.AddPlayer("Mike");

    game.Run();

    return 0;
}
