#include "league.hpp"
#include <iostream>

namespace basketball {
    // empty constructor, add 20 unique teams to the league
    League::League() {
        // while loop to add 20 unique teams to the league
        while (teams.size() < 20) {
            bool exists = false;
            Team *team = new Team();
            // check if the vector already contains the team name, insert it if not, otherwise delete the team
            for (auto t : teams) {
                if (t->getName() == team->getName()) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                teams.push_back(team);
            } else {
                delete team;
            }
        }
            
    }

    // constructor with teams
    League::League(std::vector<Team*> inputTeams) {
        // check if the input teams vector is larger than 20, if so, throw exception
        if (inputTeams.size() > 20) {
            throw std::invalid_argument("League cannot have more than 20 teams");
        }

        //copy the teams from the input vector to the league vector only up to 20 teams
        for (auto t : inputTeams) {
            // check if the vector already contains the team name, insert it if not
            for (auto t2 : teams) {
                if (t2->getName() == t->getName()) {
                    throw std::invalid_argument("League cannot have duplicate teams");
                }
            }
            this->teams.push_back(t);
            if (this->teams.size() == 20) {
                break;
            }
        }
        // check if there are 20 teams in the vector, if not, add teams until there are 20
        while (this->teams.size() < 20) {
            // check if the vector already contains the team name, insert it if not
            bool exists = false;
            Team *team = new Team();
            for (auto t : teams) {
                if (t->getName() == team->getName()) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                this->teams.push_back(team);
            } else {
                delete team;
            }
        }
    }


    // compute the score table for the league
    void League::computeScoreTable() {
        // for each team in the league, create a new vector of ints to store the winnings, losses, and points difference
        for (auto t : teams) {
            std::vector<int> scores;
            scores.push_back(t->getWins());
            scores.push_back(t->getLosses());
            scores.push_back(t->getPointsWon() - t->getPointsLost());
            scoreTable.insert(std::make_pair(t, scores));
        }
    }

    // get the league winner (the team with the most points)
    Team* League::getLeagueWinner() {
        // get the team with the best winnings/losses difference
        Team *winner = teams[0];
        for (auto t : teams) {
            if (t->getPointsWon() - t->getPointsLost() > winner->getPointsWon() - winner->getPointsLost()) {
                winner = t;
            }
        }
        return winner;
    }

    // get the league loser (the team with the least points)
    Team* League::getLeagueLoser() {
        // get the team with the worst winnings/losses difference
    
        Team *loser = teams[0];
        for (auto t : teams) {
            if (t->getPointsWon() - t->getPointsLost() < loser->getPointsWon() - loser->getPointsLost()) {
                loser = t;
            }
        }
        return loser;
    }

    // print the score table for the league
    void League::printScoreTable() {
        // print the header
        std::cout << "Team Name" << "\t" << "Wins" << "\t" << "Losses" << "\t" << "Points Difference" << std::endl;
        // print the score table
        for (auto t : teams) {
            std::cout << "----------------------------------------------------" << std::endl;
            std::cout << t->getName() << "\t\t" << scoreTable[t][0] << "\t" << scoreTable[t][1] << "\t" << scoreTable[t][2] << std::endl;
        }
        std::cout << "----------------------------------------------------" << std::endl;
    }

    // get the x top teams in the league
    std::vector<Team*> League::getTopTeams(int x) {
        // create a deap copy of the teams vector
        std::vector<Team*> teamsCopy(this->teams);
        
        std::vector<Team*> topTeams;
        while (topTeams.size() < x) {
            // get the team with the best winnings/losses ratio, and with the best points difference
            Team *bestTeam = teamsCopy[0];
            for (auto t : teamsCopy) {
                if (t->getWins() - t->getLosses() > bestTeam->getWins() - bestTeam->getLosses() && t->getPointsWon() - t->getPointsLost() > bestTeam->getPointsWon() - bestTeam->getPointsLost()) {
                    bestTeam = t;
                }
            }
            topTeams.push_back(bestTeam);

            // remove the best team from the vector
            teamsCopy.erase(std::remove(teamsCopy.begin(), teamsCopy.end(), bestTeam), teamsCopy.end());
        }
        return topTeams;
    }

    Team* League::getLargestWinStreak() {
        // get the team with the longest win streak
        Team *longestStreak = teams[0];
        for (auto t : teams) {
            if (t->getMaxWinStreak() > longestStreak->getMaxWinStreak()) {
                longestStreak = t;
            }
        }
        return longestStreak;
    }


    Team* League::getLargestLossStreak() {
        // get the team with the longest loss streak
        Team *longestStreak = teams[0];
        for (auto t : teams) {
            if (t->getMaxLossStreak() > longestStreak->getMaxLossStreak()) {
                longestStreak = t;
            }
        }
        return longestStreak;
    }


    int League::getTeamsWithPoints() {
        // get the number of teams with points won - lost > 0
        int teamsWithPoints = 0;
        for (auto t : teams) {
            if (t->getPointsWon() - t->getPointsLost() > 0) {
                teamsWithPoints++;
            }
        }
        return teamsWithPoints;
    }

}

