#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player& Medic::treat(City c) {
    if(city != c){ throw std::invalid_argument{"illegal action: you are not in city " + cityToString(c)};}
    if(board[c] == 0){  throw std::invalid_argument{"illegal action: no more cubes remain in city " + cityToString(c)};}
    board[c]=0;
    return *this;
}
Player& Medic::drive(City c){
    Player::drive(c);
    if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
    return *this;

}
Player& Medic::fly_direct(City c) {
    Player::fly_direct(c);
    if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
    return *this;

}
Player& Medic::fly_charter(City c){
    Player::fly_charter(c);
    if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
    return *this;
}
Player& Medic::fly_shuttle(City c){
    Player::fly_shuttle(c);
    if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
    return *this;
}
