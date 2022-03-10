#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
#include "Parser.h"
#include <string>
#include <string.h>


class Team{
    
    private:
        
        int num_players = 0; 
        int capacity = 1;
        Player *player = new Player[1];
        std::string nickName;
        std::string location;

     

    public:
        Team(){};
        ~Team();
        Team& operator=(const Team& t);
        Team(const Team& other);
        
        Team(const std::string &locate, const std::string &nick);
        void addPlayers(Player &play);
        void show();
        std::string getNick(){
            return nickName;
        }
        std::string getLocation(){
            return location;
        }
        int getNum_player(){
            return num_players;
        }
        void remove(const std::string& lastname);
        Player &getPlayer(const std::string& lastname);
        bool getLastname(const std::string lastname);
        void jerseynumber(Player &play);
       
        

};




#endif