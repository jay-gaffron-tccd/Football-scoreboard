//Dr. Tyson McMillan a Soccer Scoreboard using 
//Object Oriented Programming in C++
//Updates 4-21-2021 - Dr_T
//Dr_T teaching Object Oriented Scoreboard in C++ 

#include <iostream>
#include <string>
#include <iomanip> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    int timeoutCount; 
    string coachName; 
    string homeCity;
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "DefaultTeamName"; 
        timeoutCount = 3; 
        coachName = "DefaultCoachName";
        homeCity = "DefaultHomeCity"; 
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setTimeoutCount(int toc) { timeoutCount = toc; }
      void setCoachName(string sCN) { coachName = sCN; }
      void setHomeCity(string sHC) { homeCity = sHC; }
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      int getTimeoutCount() const { return timeoutCount; }
      string getCoachName() const { return coachName; }
      string getHomeCity() const { return homeCity; }
};

class Scoreboard
{
  private:
    int quarter; 
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      quarter = 1; 
    }  
    void setQuarter(int q) { quarter = q; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getQuarter() const { return quarter; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[34;4m"; //blue :) 
      cout << color << "\t\t\tFootball Scoreboard" << reset << endl; 
      cout << home.getName() << setw(30) << visitor.getName() << endl; 
      cout << "\t\t" << home.getScore() << reset << setw(30) << visitor.getScore() << endl; 
      cout << home.getCoachName() << reset << setw(30) << visitor.getCoachName() << endl; 
      cout << home.getHomeCity() << setw(30) << visitor.getHomeCity() << endl;
      cout << "  Timeouts: " << home.getTimeoutCount() << setw(30) << "Timeouts: " << visitor.getTimeoutCount() << endl;
      cout << "\t\t\t Current quarter: " << getQuarter() << endl;
      for(int i = 0; i < 47; i++) { cout << color << "*"; } cout << reset << endl;
       
       //proces to show the home team status
       cout << "Home > \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << " *"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << " *"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  string newHomeCity = "";
  int timeoutUpdate = 3;
  int quarterUpdate = 0;
  int homeTeamQuestion = 0; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "\nA = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home Team's Coach Name" << endl;
      cout << "D = Update Home Team's Home City" << endl;
      cout << "E = Update Home Team's Timeout Count" << endl;
      cout << "\nF = Update Visiting Team Name" << endl; 
      cout << "G = Update Visiting Team Score" << endl; 
      cout << "H = Update Visiting Team's Coach Name" << endl;
      cout << "I = Update Visiting Team's Home City" << endl;
      cout << "J = Update Visiting Team's Timeout Count" << endl;
      cout << "\n\nT = Update Home Status" << endl;
      cout << "\nX = Exit" << endl;
      cout << "\n>"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Team Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
          cout << "\nUpdate Home Team Score Module****" << endl;
          cout << "\nPlease enter the home coach name: "; 
          cin >> newCoachName; 
          tOne.setCoachName(newCoachName); 
      }
      else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Home Team Score Module****" << endl; 
          cout << "\nPlease enter the home city name: "; 
          cin >> newHomeCity; 
          tOne.setHomeCity(newHomeCity); 
      }
      else if(userChoice == "E" || userChoice == "e")
      {
          cout << "\nUpdate Home Team Score Module****" << endl; 
          cout << "\nPlease enter the new home team timeout count: "; 
          cin >> timeoutUpdate; 
          tOne.setTimeoutCount(timeoutUpdate); 
      } 
      if(userChoice == "F" || userChoice == "f")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Visiting Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the visiting team: ";
        cin >> newName; 
        //change that visiting team's default name
        tTwo.setName(newName); //set tTwo's data to the new desired name
      }
      else if(userChoice == "G" || userChoice == "g")
      {
        cout << "****Update Visiting Team Score module*** " << endl; 
        cout << "\nPlease enter a new score for the visiting team: "; 
        cin >> newScore; 
        tTwo.setScore(newScore);  //set the new score for tTwo        
      }
      else if(userChoice == "H" || userChoice == "h")
      {
          cout << "****Update Visiting Team Score module*** " << endl; 
          cout << "\nPlease enter the visiting coach name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
      else if(userChoice == "I" || userChoice == "i")
      {
          cout << "****Update Visiting Team Score module*** " << endl; 
          cout << "\nPlease enter the visiting city name: "; 
          cin >> newHomeCity; 
          tTwo.setHomeCity(newHomeCity); 
      }
      else if(userChoice == "J" || userChoice == "j")
      {
          cout << "****Update Visiting Team Score module*** " << endl;
          cout << "\nPlease enter the new visiting team timeout count: "; 
          cin >> timeoutUpdate; 
          tTwo.setTimeoutCount(timeoutUpdate); 
      }
      else if(userChoice == "T" || userChoice == "t")
      {
        cout << "\nUpdate Home Status Module****" << endl;
        cout << "\nWho is the home team: 1 = T1, 2 = T2: ";
        homeTeamQuestion = validateInt(homeTeamQuestion);
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
      else if(userChoice == "X" || userChoice == "x")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
  
  }while(userChoice != "X" && userChoice != "x");


  return 0; 
}