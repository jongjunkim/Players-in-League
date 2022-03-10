#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Career.h"


class Player{

        private:
                std::string firstname;
                std::string lastname;
                std::string teamNick;
                int jerseyNumber;
                int capacity = 1;
                int num_career = 0;
                Career *career = new Career[1];


               
                


       public:
                Player();
                Player(std::string first, std::string last, int number, std::string name);
                ~Player();
                Player& operator=(const Player& other);
                void print();
                std::string getFirstname();
                std::string getLastname() const;
                std::string getTeamnick()const;
                int getJerseyNumber()const;
                void setJerseyNumber(int number);
                void setTeamnick(std::string nickname);
                void addCareer(Player& player);
                void showCareer();
                void deleteCareer();
               
        



};

#endif
