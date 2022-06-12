#ifndef GAME_HPP
#define GAME_HPP

#include <random>
#include <algorithm>
#include "team.hpp"

namespace basketball {
    class Game {
        private:
            Team *home;
            Team *guest;

        public:
            Game(Team *home, Team *guest);
            ~Game();


            // getters
            Team *getHome(){return this->home;}
            Team *getGuest(){return this->guest;}

    };
}

#endif