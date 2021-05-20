#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player& Virologist:: treat(City c) {
    if(cards.count(c)==0 && c!=city){throw std::invalid_argument{"you do not have the " + cityToString(c) +" card"};}
    if(board[c] == 0){throw std::invalid_argument{"illegal action: no more cubes remain in city " + cityToString(c)};}
    if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
    else{
        board[c]--;
    }
    return *this;

}