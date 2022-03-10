#include "League.h"
#include <iostream>
using namespace std;


League::~League(){
    delete[] team;
}

void League::displayTeams(){

    for(int i = 0; i<num_teams; i++){
        cout << team[i].getLocation() << " " << team[i].getNick() 
            << " (" << team[i].getNum_player() << " players)" << endl;

    } 
    cout << endl;

}

int League::displayTeam(const string &t){   

    for(int i = 0; i<num_teams; i++)
        if(team[i].getNick() == t){
            cout << team[i].getLocation() << " " << team[i].getNick() << endl;
            return 1;
        }
    
    cout << "Could not find team with nickname of " << t <<endl;
               
}

void League::displayPlayer(const string &nickname){

   
    for(int i = 0; i<num_teams; i++){
        if(team[i].getNick() == nickname){
            cout << "Players: " << endl;
            team[i].show();
            
        }
    }
    cout << endl;
}

 void League::displayAgent(){
     free.show();
  }


int League::addTeams(const string &location, const string &nickname){

    for(int i = 0; i<num_teams; i++){
        if(team[i].getNick() == nickname){
            cout << "Could not add team " << location << " " << nickname << endl;
            return -1;
        }
    }
    
    if(num_teams == capacity){
        Team *doubling = new Team[capacity + 1];
        for(int i = 0; i<capacity; i++){
            doubling[i] = team[i];
        }
        delete [] team;
        team = doubling;
        capacity = capacity + 1;
    }

    team[num_teams] =  Team(location, nickname);
    num_teams++;
    cout << "Team " << location << " " << nickname << " added to the League" << endl; 
   
    
}




int League::addFreeAgent(Player &play){   
    
    free.addPlayers(play);
    
    return 1;


}

int League::addPlayer(Player &play, const string &nickname){

    
    for(int i = 0; i<num_teams; i++){
        if(team[i].getNick() == nickname){
            team[i].jerseynumber(play);
            team[i].addPlayers(play);
            cout << "Player " << play.getFirstname() << " " << play.getLastname() << " added to " << nickname << endl; 
            return 1;
        }
    }
    cout << "Could not add the player to team " << nickname << endl;
    return -1;


}


bool League::release(const std::string &lastName, const std::string &nickname){

    bool both_condition = false;
    bool team_exist = false;
    Player p1;


    for(int i = 0; i< num_teams; i++){
        if(team[i].getNick() == nickname)
            team_exist = true;
    }

    if(team_exist == false){
        cout << "Team " << nickname << " does not exist" << endl;
        return false;
    }
    
    for(int i = 0; i<num_teams; i++){
        if(team[i].getNick() == nickname && team[i].getLastname(lastName)){
            both_condition = true;
            p1= team[i].getPlayer(lastName);
        }
    }

    if(both_condition == false){
        cout << "Player " << lastName << " is not currently on team " << nickname << endl;
        return false;
    }
        
   
    for(int i = 0; i<num_teams; i++){
        if(team[i].getNick() == nickname){
            cout << "Release " << lastName << " from " << nickname << endl; 
            addFreeAgent(team[i].getPlayer(lastName));
            team[i].remove(lastName);
            return true;
        }
    }



}

bool League::signing(const std::string &lastName, const std::string &nickname){

    
     Player p1;
    bool exist_lastName = false;
    bool team_exist = false;

    
    if(free.getLastname(lastName)){
        exist_lastName = true;
    
    }

    if(exist_lastName == false){
        cout << "Player " << lastName << " is not a free agent" << endl;
        return false;
    }

    for(int i = 0; i< num_teams; i++){
        if(team[i].getNick() == nickname)
            team_exist = true;
    }

    if(team_exist == false){
        cout << "Team " << nickname << " does not exist" << endl;
        return false;
    }


    
    if(free.getLastname(lastName)){
        p1 = free.getPlayer(lastName);
        p1.setTeamnick(nickname);
        addPlayer(p1, nickname);
        free.remove(lastName);
    }
}

int League::career(const std::string &lastName){

   

      if(free.getLastname(lastName)){
        free.getPlayer(lastName).showCareer();
        return 1;
    }
    
    for(int i = 0; i<num_teams; i++){
        if(team[i].getLastname(lastName)){
            team[i].getPlayer(lastName).showCareer();
            return 1;
        }
    }
    
    cout << "Could not find player with last name of " << lastName << endl;

}