#include "Career.h"
#include <iostream>
using namespace std;


Career::Career(int number, std::string name){
    jerseyNumber = number;
    teamNickname = name;

}


Career::Career(){
    jerseyNumber = -1;
    teamNickname = "";
}

int Career::getCareerNumber(){
    return jerseyNumber;
}
string Career::getCareerTeam(){
    return teamNickname;
}

void Career::careerShow(){  
    cout << teamNickname << " (#" << jerseyNumber << ")" << endl;
}

Career& Career::operator=(const Career& other){

    if(this != &other){
        jerseyNumber = other.jerseyNumber;
        teamNickname = other.teamNickname;
    }

    return *this;
}

