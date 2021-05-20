#include "Player.hpp"

using namespace std;
using namespace pandemic;
const int NUM_CARDS = 5;

Player& Player:: drive(City c){
    if(city == c){throw std::invalid_argument{"Illegal action: you can not fly to the city you are already in"};}
    if(!Board::isConnected(city, c)){throw std::invalid_argument{"Illegal action: "+ cityToString(city)+" is not connected to"+cityToString(c)};}
    city=c;
    return *this;
}

Player& Player:: fly_direct(City c){
    if(city == c){throw std::invalid_argument{"Illegal action: you can not fly to the city you are already in"};}
    if(cards.count(c) == 0){
        throw std::invalid_argument{"illegal action: you do not have the card of "+cityToString(c)};
    }
    
    city=c;
    cards.erase(c);
    return *this;
}
Player& Player::fly_charter(City c){
    if(city == c){throw std::invalid_argument{"Illegal action: you can not fly to the city you are already in"};}
    if(cards.count(city)==0){throw std::invalid_argument{"illegal action: you do not have the card of "+cityToString(city)};}
    cards.erase(city);
    city=c;
    return *this;
}
Player& Player::fly_shuttle(City c){
    if(!(board.isResearchStation(city) && board.isResearchStation(c))){
        throw std::invalid_argument{"Illegal action: " + cityToString(city) + " and " + cityToString(c) + " must both have research station."};
    }
    if(city == c){throw std::invalid_argument{"Illegal action: you can not fly to the city you are already in"};}
    city=c;
    return *this;
}
Player& Player::build(){
    if(cards.count(city)==0){throw std::invalid_argument{"Illegal action: you do not have the card of "+cityToString(city)};}
    if(!board.isResearchStation(city)){
        board.buildStation(city);
        cards.erase(city);
    }
    return *this;
}

Player& Player:: discover_cure(Color c){
    if(!board.cureDiscoverd(c)){
        if(!board.isResearchStation(city)){throw std::invalid_argument{"Illegal action: "+cityToString(city)+"have not research station"};}
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

Player& Player:: treat(City c){
    if(city != c){ throw std::invalid_argument{"illegal action: you are not in city " + cityToString(c)};}
    if(board[c] == 0){  throw std::invalid_argument{"illegal action: no more cubes remain in city " + cityToString(c)};}
    if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
    else{
        board[c]--;
    }
    return *this;
}

Player& Player::take_card(City c){
    cards.insert(c);
    return *this;
}