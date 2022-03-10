#include "Team.h"
#include <iostream>
using namespace std;



Team::Team(const string &locate, const string &nick){
    location = locate;
    nickName = nick;
}

Team::~Team(){
    delete [] player;
}



Team& Team::operator=(const Team& t){

    if(this != &t){
        location = t.location;
        nickName = t.nickName;
    }

    return *this;

}

void Team::show(){

    for(unsigned int i = 0; i<num_players; i++){
        player[i].print();
    }

}

void Team::addPlayers(Player &play){
    
    if(num_players == capacity){
        Player *doubling = new Player[capacity+ 1];
        for(int i = 0; i<capacity; i++){
            doubling[i] = player[i];
        }
        delete [] player;
        player = doubling;
        capacity = capacity + 1;
    }
    player[num_players] = play;
    player[num_players].addCareer(player[num_players]);
    num_players++;
    
}


void Team::remove(const string& lastname){
    
    int k = 0;

    for(int i = 0; i<num_players; i++){
        if(player[i].getLastname() == lastname){
            k = i; 
            Player *decrease = new Player[capacity-1];
            for(int j = k; j<capacity-1; j++){
                player[j] = player[j+1];
            }
            
            for(int j = 0; j<capacity-1; j++){
                decrease[j] = player[j];
            }
            delete[] player;
            capacity--;
            num_players--;
            player = decrease;
            
        }
    }
    
}

bool Team::getLastname(const std::string lastname){
    for(int i = 0; i<num_players; i++){
        if(player[i].getLastname() == lastname){
            return true;
        }
    }
    return false;
}


Player& Team::getPlayer(const std::string& lastname){
    
    for(int i = 0; i<num_players; i++){
        if(player[i].getLastname() == lastname){
            return player[i];
        }
    }
}




void Team::jerseynumber(Player &play){

    int jersey= play.getJerseyNumber();
    bool duplicate = true;



    for(int i = 0; i<num_players; i++){
        if(player[i].getJerseyNumber() == jersey)
            jersey = 0;
    }
    
    while(duplicate){
        
        int compare = 0;

        for(int i = 0; i<num_players; i++){
            if(player[i].getJerseyNumber() == jersey){
                jersey += 1;
            }else
                compare++;  
        }

        play.setJerseyNumber(jersey);
        
        if(compare == num_players)
            duplicate = false;
    }



}

