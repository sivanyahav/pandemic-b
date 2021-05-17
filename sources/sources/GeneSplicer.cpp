#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;
const int NUM_CARDS = 5;

Player& GeneSplicer:: discover_cure(Color c) {
    if(!board.cureDiscoverd(c)){
        if(!board.isResearchStation(city)){throw std::invalid_argument{"Illegal action: "+cityToString(city)+"have not research station"};}
        
        int countCards=cards.size();
        if(countCards < NUM_CARDS){throw std::invalid_argument{"Illegal action: you need 5 cards in color "+colorToString(c)};}
        auto it= cards.begin();

        int count= NUM_CARDS;
        while(it != cards.end() && count > 0){ 
            it=cards.erase(it);
            count--;
            it++; 
        }
        board.insertCures(c);
    }
    return *this;
}