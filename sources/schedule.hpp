#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP


#include <iostream>
#include <algorithm>
#include <vector>
#include "team.hpp"
#include "league.hpp"
#include "game.hpp"

namespace basketball {
    // standard algorithm to create a schedule for a round-robin tournament
    class Schedule {
        private:
        std::vector<std::vector<Game*>> rounds;
        

        public:
        Schedule();
        Schedule(League newleague);
        ~Schedule(){}


        // getters
        std::vector<std::vector<Game*>> getRounds(){return this->rounds;}

        void printSchedule();

        

    };
}
#endif