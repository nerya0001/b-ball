// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "league.hpp"
#include "team.hpp"
#include "schedule.hpp"
#include "game.hpp"

using namespace basketball;

TEST_CASE ("Good")
{
    SUBCASE("random league") {
        League league = League();
    
        CHECK_NOTHROW(Schedule schedule = Schedule(league));

        CHECK_NOTHROW(league.computeScoreTable());
        int teamsWithPoints;
        CHECK_NOTHROW(teamsWithPoints = league.getTeamsWithPoints());

        std::vector<Team*> topTeams;
        CHECK_NOTHROW(topTeams = league.getTopTeams(5));
        CHECK_NOTHROW(topTeams = league.getTopTeams(3));
        CHECK_NOTHROW(topTeams = league.getTopTeams(9));
        CHECK_NOTHROW(topTeams = league.getTopTeams(12));

        Team* largestWinStreak;
        CHECK_NOTHROW(largestWinStreak = league.getLargestWinStreak());
        Team* largestLossStreak;
        CHECK_NOTHROW(largestLossStreak = league.getLargestLossStreak());
    }

    SUBCASE("league with teams") {
        std::vector<Team*> teams;

        Team team1 = Team("miami", 0.6);
        Team team2 = Team("cleve", 0.8);
        Team team3 = Team("boston", 0.9);
        Team team4 = Team("toronto", 0.7);
        Team team5 = Team("philade", 0.5);
        Team team6 = Team("chicago", 0.4);
        Team team7 = Team("detroit", 0.3);
        Team team8 = Team("orlando", 0.2);
        Team team9 = Team("york", 0.1);
        Team team10 = Team("san", 0.8);
        Team team11 = Team("seattle", 0.9);
        Team team12 = Team("dallas", 0.7);
        Team team13 = Team("antonio", 0.5);
        Team team14 = Team("houston", 0.4);
        Team team15 = Team("london", 0.3);
        Team team16 = Team("paris", 0.2);
        Team team17 = Team("tokyo", 0.1);
        Team team18 = Team("milan", 0.8);
        Team team19 = Team("madrid", 0.9);
        Team team20 = Team("essen", 0.7);

        teams.push_back(&team1);
        teams.push_back(&team2);
        teams.push_back(&team3);
        teams.push_back(&team4);
        teams.push_back(&team5);
        teams.push_back(&team6);
        teams.push_back(&team7);
        teams.push_back(&team8);
        teams.push_back(&team9);
        teams.push_back(&team10);
        teams.push_back(&team11);
        teams.push_back(&team12);
        teams.push_back(&team13);
        teams.push_back(&team14);
        teams.push_back(&team15);
        teams.push_back(&team16);
        teams.push_back(&team17);
        teams.push_back(&team18);
        teams.push_back(&team19);
        teams.push_back(&team20);

        League league2 = League(teams);

        CHECK_NOTHROW(Schedule schedule2 = Schedule(league2));

        CHECK_NOTHROW(league2.computeScoreTable());
        int teamsWithPoints;
        CHECK_NOTHROW(teamsWithPoints = league2.getTeamsWithPoints());

        std::vector<Team*> topTeams;
        CHECK_NOTHROW(topTeams = league2.getTopTeams(5));
        CHECK_NOTHROW(topTeams = league2.getTopTeams(3));
        CHECK_NOTHROW(topTeams = league2.getTopTeams(9));
        CHECK_NOTHROW(topTeams = league2.getTopTeams(12));

        Team* largestWinStreak;
        CHECK_NOTHROW(largestWinStreak = league2.getLargestWinStreak());
        Team* largestLossStreak;
        CHECK_NOTHROW(largestLossStreak = league2.getLargestLossStreak());

    }
}

TEST_CASE ("Bad")
{
    SUBCASE("empty league") {
        League league = League();
    
        CHECK_THROWS(Schedule schedule = Schedule());

        CHECK_THROWS(Team team1 = Team("", 0.6));
        CHECK_THROWS(Team team2 = Team("cleve", -0.8));
        CHECK_THROWS(Team team3 = Team("boston", 20.5));
        CHECK_THROWS(Team team4 = Team("", -4.3));
        
        // add more than 20 teams to the league
        Team team1 = Team("miami", 0.6);
        Team team2 = Team("cleve", 0.8);
        Team team3 = Team("boston", 0.9);
        Team team4 = Team("toronto", 0.7);
        Team team5 = Team("philade", 0.5);
        Team team6 = Team("chicago", 0.4);
        Team team7 = Team("detroit", 0.3);
        Team team8 = Team("orlando", 0.2);
        Team team9 = Team("york", 0.1);
        Team team10 = Team("san", 0.8);
        Team team11 = Team("seattle", 0.9);
        Team team12 = Team("dallas", 0.7);
        Team team13 = Team("antonio", 0.5);
        Team team14 = Team("houston", 0.4);
        Team team15 = Team("london", 0.3);
        Team team16 = Team("paris", 0.2);
        Team team17 = Team("tokyo", 0.1);
        Team team18 = Team("milan", 0.8);
        Team team19 = Team("madrid", 0.9);
        Team team20 = Team("essen", 0.7);
        Team team21 = Team("miami", 0.6);
        Team team22 = Team("cleve", 0.8);
        Team team23 = Team("boston", 0.9);

        std::vector<Team*> teams;
        teams.push_back(&team1);
        teams.push_back(&team2);
        teams.push_back(&team3);
        teams.push_back(&team4);
        teams.push_back(&team5);
        teams.push_back(&team6);
        teams.push_back(&team7);
        teams.push_back(&team8);
        teams.push_back(&team9);
        teams.push_back(&team10);
        teams.push_back(&team11);
        teams.push_back(&team12);
        teams.push_back(&team13);
        teams.push_back(&team14);
        teams.push_back(&team15);
        teams.push_back(&team16);
        teams.push_back(&team17);
        teams.push_back(&team18);
        teams.push_back(&team19);
        teams.push_back(&team20);
        teams.push_back(&team21);
        teams.push_back(&team22);
        teams.push_back(&team23);

        CHECK_THROWS(League league2 = League(teams));
    }
}
