#include "bits/stdc++.h"
#include <iostream>
using namespace std;


class Player// player class
{
    private:
        string name;
        int score;
    public:
        Player(string name, int score) : name(name), score(score) {};// constructor to initialize the name and score.
        Player(): name("new player"), score(0) {};// non parametrized constructor.
        string get_name() const { return name;}// accessors to get the name.
        int get_score() const {return score;}// accessors to get the score.
        friend ostream& operator<<(ostream& OUT, Player& p);// overloaded << to print out the object
};

ostream& operator<<(ostream& OUT, Player& p)
{
    OUT << p.name <<": " << p.score;
    return OUT;
}
int main() {
    vector<Player> players;
    bool flag = true;
    int choice;
    while(flag) 
    {
        cout << "1. Add an new player" << endl;
        cout <<"2. display the top 10 names and scores" << endl;
        cout << "3. enter players name" << endl;
        cout << "4. Quit" <<endl;
        cin >> choice;
        if(choice == 1)
        {
            string name;
            int score;
            cin >> name >> score;
            if(players.size() >= 10)// if choice equal 9 add player
            {
                if(score >= players[9].get_score())// if greater than the last digit add
                {
                    players.pop_back();// remove last object in the array
                    players.push_back(Player(name, score));// add the player
                    sort(players.begin(), players.end(), [](const Player& lhs, const Player& rhs) {
                        return lhs.get_score() > rhs.get_score();
                    });// sort the array
                }
            }else
            {
                players.push_back(Player(name, score));// add the player
                sort(players.begin(), players.end(), [](const Player& lhs, const Player& rhs) {
                    return lhs.get_score() > rhs.get_score();
                });// sort the array
            }
        }else if(choice == 2)// output the array
        {
            for(int i = 0; i < players.size(); i++)
            {
                cout << players[i] << endl;
            }
        }else if(choice == 3)// search for the players name
        {
            string name ;
            cin >> name;
            for(int i = 0; i < players.size(); i++)
            {
                if(name == players[i].get_name())
                {
                    cout << players[i].get_score() << endl;// print the score
                    break;
                }
                cout << "not found" << endl;
            }
        }else
        {
            flag = false;// quit and close the program
        }
    }
    return 0;
}
