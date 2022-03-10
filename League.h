#ifndef LEAGUE_H
#define LEAGUE_H
#include <string.h>
#include "Team.h"
#include "Player.h"

class League{

    private:
        int num_teams = 0;
        int num_free = 0;
        int capacity = 1;

        Team *team = new Team[1];
        Team free;
        std::string location;
        std::string nickname;
        
    
    public:
        League(){};
        ~League();
        int addTeams(const std::string &location, const std::string &nickname);
        int addPlayer(Player &play, const std::string &nickname);
        int addFreeAgent(Player &play);
        void displayAgent();
        void displayTeams();
        int displayTeam(const std::string &t);
        void displayPlayer(const std::string &nickname);
        bool release(const std::string &lastName, const std::string &nickname);
        bool signing(const std::string &lastName, const std::string &nickname);
        int career(const std::string &lastName);





};

#endif