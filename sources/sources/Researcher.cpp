#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

const int NUM_CARDS = 5;

Player& Researcher:: discover_cure(Color c){
    if(!board.cureDiscoverd(c)){
        int countCards=0;
        for(const auto& card: cards){
            if(Board::getColor(card) == c){
                countCards++;
            }
        }

        if(countCards < NUM_CARDS){throw std::invalid_argument{"Illegal action: you need 5 cards in color "+colorToString(c)};}
        auto it= cards.begin();
        while(it != cards.end() && countCards > 0){
            if(Board::getColor(*it) == c){ 
            it=cards.erase(it);
            countCards--;
            }
            else{
            it++;
            }
            
        }
        board.insertCures(c);
    }
    return *this;
}