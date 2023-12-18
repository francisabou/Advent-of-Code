#include <iostream>
#include <fstream>

std::array<int,3> getmax_game(std::string game);

int main(){

const std::array<int,3> set_game={12,13,14}; //{red,green,blue}
std::array<int,3> current_game={0,14,0};
//std::ifstream games("part1_example.txt");
std::ifstream games("part1_input.txt");
std::string game;
int sum_games_power=0;

while(std::getline(games,game)){

    current_game=getmax_game(game);
    sum_games_power+=current_game[0]*current_game[1]*current_game[2];
   

}

std::cout<<sum_games_power<<"\n";

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

