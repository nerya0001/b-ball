#ifndef TEAM_HPP
#define TEAM_HPP

#include <stdexcept>
#include <string>

namespace basketball {
    class Team {
    private:
        std::string name;
        double strength;
        int pointsWon;
        int pointsLost;
        int wins;
        int losses;
        int maxWinStreak;
        int maxLossStreak;
        int currentWinStreak;
        int currentLossStreak;
    public:
        Team();
        Team(std::string name, double strength);
        ~Team(){}

        std::string getName(){ return this->name; }
        double getStrength(){ return this->strength; }
        int getPointsWon(){ return this->pointsWon; }
        int getPointsLost(){ return this->pointsLost; }
        int getWins(){ return this->wins; }
        int getLosses(){ return this->losses; }
        int getMaxWinStreak(){ return this->maxWinStreak; }
        int getMaxLossStreak(){ return this->maxLossStreak; }
        int getCurrentWinStreak(){ return this->currentWinStreak; }
        int getCurrentLossStreak(){ return this->currentLossStreak; }

        void setName(std::string name){ this->name = name; }
        void setStrength(double strength){ this->strength = strength; }
        void setPointsWon(int pointsWon){ this->pointsWon = pointsWon; }
        void setPointsLost(int pointsLost){ this->pointsLost = pointsLost; }
        void setWins(int wins){ this->wins = wins; }
        void setLosses(int losses){ this->losses = losses; }
        void setMaxWinStreak(int maxWinStreak){ this->maxWinStreak = maxWinStreak; }
        void setMaxLossStreak(int maxLossStreak){ this->maxLossStreak = maxLossStreak; }
        void setCurrentWinStreak(int currentWinStreak){ this->currentWinStreak = currentWinStreak; }
        void setCurrentLossStreak(int currentLossStreak){ this->currentLossStreak = currentLossStreak; } 
    };
}

#endif
        
