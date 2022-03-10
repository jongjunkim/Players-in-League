#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(std::string first, std::string last, int number, std::string nickname){

    firstname = first;
    lastname = last;
    jerseyNumber = number;
    teamNick = nickname;
}

Player::~Player(){
    delete [] career;
}


Player& Player::operator=(const Player& other){

    if(this != &other){
        if(other.getTeamnick() == ""){
            firstname = other.firstname;
            lastname = other.lastname;
            teamNick = "";
            jerseyNumber = other.jerseyNumber;
        }else{
            firstname = other.firstname;
            lastname = other.lastname;
            teamNick = other.teamNick;
            jerseyNumber = other.jerseyNumber;
        }   
    }

    return *this;

}

Player::Player(){
    firstname = "";
    lastname = "";
    jerseyNumber = -1;
    teamNick = "";
    num_career = 0;
}

void Player::print(){
    
    cout << lastname << ", " << firstname << " " << "(#" << jerseyNumber 
    <<") "<< " " << endl;

}

string Player::getFirstname(){
    return firstname;
}

string Player::getLastname()const{
    return lastname;
}

string Player::getTeamnick()const{
    return teamNick;
}

int Player::getJerseyNumber()const{
    return jerseyNumber;
}

void Player::setJerseyNumber(int number){
    jerseyNumber = number;
}

void Player::setTeamnick(std::string nickname){
    teamNick = nickname;
}

void Player::addCareer(Player &player){

    string tname = player.getTeamnick();
    int jnumber = player.getJerseyNumber();
    Career c1 = Career(jnumber, tname);
    
    if(tname == ""){
        
    }else{
        if(num_career == capacity){
        Career *doubling = new Career[capacity + 1];
        for(int i = 0; i<capacity; i++){
            doubling[i] = career[i];
        }
        delete [] career;
        career = doubling;
        capacity = capacity + 1;
    }
    career[num_career] = c1;
    num_career++;
    }    
   
}

void Player::showCareer(){

    for(int i = 0; i<num_career; i++){
        career[i].careerShow();
    }
}