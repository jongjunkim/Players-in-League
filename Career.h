#ifndef CAREER_H
#define CAREER_H
#include <string>

class Career{

    private:
        int jerseyNumber;
        std::string teamNickname;

    public:
        Career(int number, std::string name);
        Career();
        int getCareerNumber();
        std::string getCareerTeam();
        void careerShow();
        Career& operator=(const Career& other);





};

#endif