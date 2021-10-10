#include "gamelogic.h"



void GameLogic::init_game()
{
    std::vector<QString> type_row {"A","B","C","D","E", "F","G","H","I","J"};

    for(uint i=1; i<= type_row.size(); ++i)
        for(uint j=1; j<= type_row.size(); ++j)
        {
            field.push_back(type_row[j-1] + QString::number(i));
        }
}

void GameLogic::show_field()
{
    QString cache ="";
    int row =1;
    for(auto i : field)
    {
        if(row == 10)
        {
            qDebug() << cache;
            cache ="";
            row =0;
        }
        else
            cache += i + " ";

        ++row;
    }
}
