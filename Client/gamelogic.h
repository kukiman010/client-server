#ifndef GAMELOGIC_H
#define GAMELOGIC_H


#include <iostream>
#include "command.h"

class GameLogic
{
    std::vector<QString> field;
public:
    GameLogic(){ init_game(); }

    void init_game();
    void show_field();
};

#endif // GAMELOGIC_H
