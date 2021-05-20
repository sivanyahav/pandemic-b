#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player& Scientist:: discover_cure(Color c){
    if(!board.cureDiscoverd(c)){
        if(!board.isResearchStation(city)){throw std::invalid_argument{"Illegal action: "+cityToString(city)+"have not research station"};}
        int countCards=0;
        for(const auto& card: cards){
            if(Board::getColor(card) == c){
                countCards++;
            }
        }

        if(countCards < this->n){throw std::invalid_argument{"Illegal action: you need "+ std::to_string(this->n)+" cards in color "+ colorToString(c)};} /////// fix!!!!
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