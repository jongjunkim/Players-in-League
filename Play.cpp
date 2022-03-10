#include <iostream>
#include <fstream>
#include "Player.h"
#include "Team.h"
#include "League.h"
#include "Career.h"
#include "Parser.h"
#include <vector>
using namespace std;


///// don't forget to delete allocated memory
int main(){

    
    string line;
    string command;
    int int_param;
    League l1;
    Player p1;
    Team t1;


    

    while(1){

        cout << endl << "Enter a command" << endl;
        cout << "Choose from" << endl;
        cout << "   Team <location> <team-nickname>" << endl;
        cout << "   Player <firstname> <lastname> <number> [<team-nickname>]" << endl;
        cout << "   League "<< endl;
        cout << "   Roster [<team-nickname>]" << endl;
        cout << "   Release <lastname> <team-nickname>" << endl;
        cout << "   Sign <lastname> <team-nickname>" << endl;
        cout << "   Career <lastname>" << endl;
        cout << "   Trade" << endl;
        cout << "   Quit" << endl; 
        cout << ":";
        
        getline(cin, line);
        Parser command(line);
        if (command.getOperation().empty()) {
            if (std::cin.fail())
	            break;
        continue;
        }

        if (command.getOperation() == "Quit"){
            if (command.numArgs() > 0) 
                cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
            break;
        
        }else if(command.getOperation() == "Team"){
            if (command.numArgs() < 2) 
                cout << std::endl << "Can't operate with missing arguments" << endl; 
            else if(command.numArgs() > 2)
                cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            else{
                l1.addTeams(command.getArg1(), command.getArg2());
            }

        }else if(command.getOperation() == "Player"){
            if(command.numArgs() < 3)
                cout << std::endl << "Can't operate with missing arguments" << endl;
            else{
                if(Parser::isInteger(command.getArg3())) {
                    int_param = stoi(command.getArg3()); 
                        if(command.numArgs() == 3){
                            p1 = Player(command.getArg1(), command.getArg2(), int_param, " ");
                            cout << "working" << endl;
                            l1.addFreeAgent(p1);
                        }
                        else{
                            p1 = Player(command.getArg1(), command.getArg2(), int_param, command.getArg4());
                            l1.addPlayer(p1, p1.getTeamnick());
                        }
                }else
                    cout << "Error: arg2: " << command.getArg2() << " is not an integer" << endl;
                
            }
        }else if(command.getOperation() == "League"){
            l1.displayTeams();

        }else if(command.getOperation() == "Roster"){
            if(command.numArgs() == 1){
                l1.displayTeam(command.getArg1());
                l1.displayPlayer(command.getArg1());
            }else
                l1.displayAgent();

        }else if(command.getOperation() == "Release"){
            if(command.numArgs() < 2){
                cout << std::endl << "Can't operate with missing arguments" << endl;
            }else if(command.numArgs() > 2)
                cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            else
                l1.release(command.getArg1(), command.getArg2());
        
        }else if(command.getOperation() == "Sign"){
            if(command.numArgs() < 2){
                cout << std::endl << "Can't operate with missing arguments" << endl;
            }else if(command.numArgs() > 2)
                cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            else
                l1.signing(command.getArg1(), command.getArg2());  
        
        }else if(command.getOperation() == "Career"){
            if(command.numArgs() < 1){
                cout << std::endl << "Can't operate with missing arguments" << endl;
            }else if(command.numArgs() > 1){
                cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            }else{
                l1.career(command.getArg1());
            }

        
        
        }else{
            cout << std::endl << 
		    "Command not recognized. Please try again." << endl; 
        }

    }

}