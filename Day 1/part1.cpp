#include <iostream>
#include <fstream>


int main(){

std::ifstream input("part1_input.txt");
std::string line;
int cascii;
int sum=0;


while(std::getline(input,line)){
    for(int j=0;j<line.length();j++){
        if(line.at(j)<58&&line.at(j)>47){
            sum+=10*(line.at(j)-48);
            break;
        }
    }

    for(int j=line.length()-1;j>-1;j--){
        if(line.at(j)<58&&line.at(j)>47){
            sum+=line.at(j)-48;
            break;
        }
    }
}

std::cout<<sum<<"\n";

    return 0;
}