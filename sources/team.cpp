#include "team.hpp"

#include <random>

namespace basketball {
    Team::Team() {
        // set a random unique name for 20 teams
        std::string names[] = {"team1", "team2", "team3", "team4", "team5", "team6", "team7", "team8", "team9", "team10", "team11", "team12", "team13", "team14", "team15", "team16", "team17", "team18", "team19", "team20"};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 19);
        int randomIndex = dis(gen);
        this->name = names[randomIndex];

        // set a random strength between 0 and 1
        std::uniform_real_distribution<> dis2(0, 1);
        this->strength = dis2(gen);
        
        pointsWon = 0;
        pointsLost = 0;
        wins = 0;
        losses = 0;
        maxWinStreak = 0;
        maxLossStreak = 0;
        currentWinStreak = 0;
        currentLossStreak = 0;
    }


    Team::Team(std::string name, double strength) {
        // check if name is empty, if so, throw exception
        if (name.empty()) {
            throw std::invalid_argument("Team name cannot be empty");
        }
        // check if strength is between 0 and 1, if not, throw exception
        if (strength < 0 || strength > 1) {
            throw std::invalid_argument("Team strength must be between 0 and 1");
        }
        this->name = name;
        this->strength = strength;
        pointsWon = 0;
        pointsLost = 0;
        wins = 0;
        losses = 0;
        maxWinStreak = 0;
        maxLossStreak = 0;
        currentWinStreak = 0;
        currentLossStreak = 0;
    }

}

