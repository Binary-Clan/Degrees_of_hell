#ifndef DEGREES_H
#define DEGREES_H

#include <vector>
#include <memory>
#include "CPlayer.h"
#include "CSpace.h"

class CDegrees {
public:
    using SpaceVector = std::vector<std::unique_ptr<CSpace>>;
    using PlayerList = std::vector<CPlayer>;

private:
    SpaceVector mSpaces;
    PlayerList mPlayers;

public:
    CDegrees() = default;
    void ReadSpaces(const std::string& filename);
    void AddPlayer(const std::string& name);
    void SimulatePlayerTurn(CPlayer& currentPlayer);
    void Run();
};

#endif // DEGREES_H
