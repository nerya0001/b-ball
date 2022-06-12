#include "schedule.hpp"


namespace basketball {
    // empty constructor
    Schedule::Schedule() {
        throw std::runtime_error("Schedule::Schedule() not implemented");
    }

    // constructor with teams
    Schedule::Schedule(League newleague) {
        // the teams are paired up in a round-robin fashion
        // the first team in the league is paired with the last team in the league and so on 
        // until the last team in the league is paired with the first team in the league
        // each team plays once in each round
       
        int count = 0;
        // vector of indices to rotate through the teams 0 - 19
        std::vector<uint> indices = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
        while (this->rounds.size() < 38) {
            std::vector<Game*> round;
            for (uint i = 0, j = 19; count < 10 ; i++, j--) {
                // create a new game
                Game *game = new Game(newleague.getTeams()[indices[i]], newleague.getTeams()[indices[j]]);
                // add the game to the round
                round.push_back(game);
                
                count++;
            }
            this->rounds.push_back(round);

            // rotate the indices vector by 1
            std::rotate(indices.begin(), indices.begin() + 1, indices.end());
            count = 0;
            
        }


    }

   

    //print the schedule devided by rounds  
    void Schedule::printSchedule() {
        int count = 1;
        for (auto round : this->rounds) {
            std::cout << "---------------------------------\n" << std::endl;
            
            std::cout << "Round: " << count << std::endl;
            count++;
            for (auto game : round) {
                std::cout << game->getHome()->getName() << " vs " << game->getGuest()->getName() << std::endl;
            }
        }
    }

   
}