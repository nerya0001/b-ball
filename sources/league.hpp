#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include <random>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "team.hpp"

namespace basketball {
    class League {
        private:
        std::vector<Team*> teams;
        // score table for the league winnings/losses, points difference
        // team : numOfWins | numOfLosses | PointsDifference
        std::unordered_map<Team*, std::vector<int>> scoreTable;


        public:
        // empty constructor
        League();
        // constructor with teams
        League(std::vector<Team*> inputTeams);

        ~League(){}

        Team* getLeagueWinner();
        Team* getLeagueLoser();

        // compute the score table for the league
        void computeScoreTable();
        // get the x top teams in the league
        std::vector<Team*> getTopTeams(int x);
        //get the largest streak of wins
        Team* getLargestWinStreak();
        //get the largest streak of losses
        Team* getLargestLossStreak();

        // get the number of teams with points difference greater than 0
        int getTeamsWithPoints();

        void printScoreTable();


        // getters
        std::vector<Team*> getTeams() { return this->teams; }
      
        // setters
        void setTeams(std::vector<Team*> teams) { this->teams = teams; }
     
    };
}

#endif