#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher:: fly_direct(City c){
    if(city == c){throw std::invalid_argument{"Illegal action: you can not fly to the city you are already in"};}
    if(board.isResearchStation(city)){
        city=c;
        return *this;
    }
    return Player:: fly_direct(c);
}
