#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor:: treat(City c) {
    if(!Board::isConnected(city,c) && city!=c){ throw std::invalid_argument{"Illegal action: "+ cityToString(city)+" is not connected to "+cityToString(c)};}
    if(board[c] == 0){  throw std::invalid_argument{"illegal action: no more cubes remain in city " + cityToString(c)};}
    if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
    else{
        board[c]--;
    }
    return *this;
}