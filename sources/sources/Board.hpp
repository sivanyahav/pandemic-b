#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic{
    class Board{

        static std :: map<City, std::set<City>> connections;
        std :: map<City, int> diseasCubes; //Indicates the level of disease in each city
        std::set<City> research_stations; //Marks the cities that have research stations
        std::set <Color> cured;

        public:
            Board(){}

            int& operator[] (City c);
            bool is_clean();
            void remove_cures(){cured.clear();};
            void remove_stations(){research_stations.clear();};
            friend std::ostream& operator<<(std::ostream& os, const Board& b);

            //////////Help functions////////////////
            static bool isConnected(City& c1, City&c2);
            void buildStation(City c);
            bool isResearchStation(City c);
            void insertCures(Color c);
            bool cureDiscoverd(Color c);
            static Color getColor(City c);

    };
}