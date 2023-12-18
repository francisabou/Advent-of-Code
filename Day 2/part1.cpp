#include <iostream>
#include <fstream>

std::array<int,3> getmax_game(std::string game);

int main(){

const std::array<int,3> set_game={12,13,14}; //{red,green,blue}
std::array<int,3> current_game={0,14,0};
//std::ifstream games("part1_example.txt");
std::ifstream games("part1_input.txt");
std::string game;
int sum_games_ID=0;
int line=1;
bool possible;

while(std::getline(games,game)){

possible=true;

    current_game=getmax_game(game);
    for(int i=0; i<set_game.size(); i++){
        if(set_game[i]<current_game[i]){
            possible=false;
            break;
        }
    }
possible? sum_games_ID+=line : -1 ;
line++;
}

std::cout<<sum_games_ID<<"\n";

return 0;
}



std::array<int,3> getmax_game(std::string game){

const std::array<std::string,3> colors={"red","green","blue"};
std::array<int,3> current_game={0,0,0};
int value;

for(int i=7; i<game.length(); i++){
    if(game.at(i)<58&&game.at(i)>47){
        value=0;
        while(game.at(i)<58&&game.at(i)>47){
            value=value*10+game.at(i)-48;
            i++;
        }     
        for(int j=0; j<3; j++){
            if(game.substr(i+1,colors[j].length())==colors[j]){
                if(current_game[j]<value){
                    current_game[j]=value;
                }
                break;
            }
        }
    }
}

return current_game;

}