#include "game.hpp"


namespace basketball {
    Game::Game(Team *home, Team *guest) {
        this->home = home;
        this->guest = guest;

        // add points randomly to the home team between 55 and 100, normally distributed with mean 80 and standard deviation 10
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dis(80, 10);
        // set the home team's points to the random number, making sure it is between 55 and 100
        int homePoints = std::max(55, std::min(100, (int)dis(gen)));
        this->home->setPointsWon(this->home->getPointsWon() + homePoints);
        // set the guest team lost points the same amount as the points the home team won
        this->guest->setPointsLost(this->guest->getPointsLost() + homePoints);
        
        // add points randomly to the guest team between 55 and 100, normally distributed with mean 80 and standard deviation 10
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::normal_distribution<> dis2(80, 10);
        // set the guest team's points to the random number, making sure it is between 50 and 100
        int guestPoints = std::max(50, std::min(100, (int)dis2(gen2)));
        this->guest->setPointsWon(this->guest->getPointsWon() + guestPoints);
        // set the home team lost points the same amount as the points the guest team won
        this->home->setPointsLost(this->home->getPointsLost() + guestPoints);

        // add up to 10 points bonus to the stronger team 
        if (this->home->getStrength() > this->guest->getStrength()) {
            this->home->setPointsWon(this->home->getPointsWon() + this->home->getStrength()*10);
        } else {
            this->guest->setPointsWon(this->guest->getPointsWon() + this->guest->getStrength()*10);
        }
        
        Team *winner;
        Team *loser;

        //check for a tie, and if so, set the winner to the stronger team
        if (homePoints == guestPoints) {
            if (this->home->getStrength() > this->guest->getStrength()) {
                winner = this->home;
                loser = this->guest;
            } else {
                winner = this->guest;
                loser = this->home;
            }
        }
        else if (homePoints > guestPoints) {
            winner = home;
            loser = guest;
        } else {
            winner = guest;
            loser = home;
        }
        // add a win to the winner
        winner->setWins(winner->getWins() + 1);
        winner->setCurrentWinStreak(winner->getCurrentWinStreak() + 1);
        winner->setMaxLossStreak(winner->getMaxLossStreak() > winner->getCurrentLossStreak() ? winner->getMaxLossStreak() : winner->getCurrentLossStreak());
        // set the winner's current loss streak to 0
        winner->setCurrentLossStreak(0);
        
        // add a loss to the loser
        loser->setLosses(loser->getLosses() + 1);
        loser->setCurrentLossStreak(loser->getCurrentLossStreak() + 1);
        loser->setMaxWinStreak(loser->getMaxWinStreak() > loser->getCurrentWinStreak() ? loser->getMaxWinStreak() : loser->getCurrentWinStreak());
        // set the loser's current win streak to 0
        loser->setCurrentWinStreak(0);
        // add the points to the winner

    }

    Game::~Game() {
        delete home;
        delete guest;
    }


}