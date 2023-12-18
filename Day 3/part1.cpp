#include <iostream>
#include <fstream>

int main(){

//std::ifstream Engine("part1_example.txt");
std::ifstream Engine("part1_input.txt");
std::array<std::string,3> scope;
std::string temp;
int value;
int sum_partnum=0;
bool tag=false;

std::getline(Engine,scope[1]);
std::getline(Engine,scope[2]);
scope[0].assign(scope[1].length(),'.');

do{
for(int j=0; j<scope[0].length(); j++){
    value=0;
    tag=false;
    while(scope[1].at(j)<58&&scope[1].at(j)>47){
        value=value*10+scope[1].at(j)-48;
        for(int k=-1; k<2; k++){
            if(j+k<0||j+k>scope[1].length()-1){continue;}
            for (int m=-1; m<2 ;m++){
                if (scope[1+m].at(j+k)!='.'&&(scope[1+m].at(j+k)>57||scope[1+m].at(j+k)<48)){
                    tag=true;
                }
        }
        }
        if(j==scope[1].length()-1){break;}
        j++;
    }
tag? sum_partnum+=value : -1; 
}

temp=scope[2];

scope[0]=scope[1];
scope[1]=scope[2];

}while(std::getline(Engine,scope[2]));

scope[2].assign(scope[1].length(),'.');

for(int j=0; j<scope[0].length(); j++){
    value=0;
    tag=false;
    while(scope[1].at(j)<58&&scope[1].at(j)>47){
        value=value*10+scope[1].at(j)-48;
        for(int k=-1; k<2; k++){
            if(j+k<0||j+k>scope[1].length()-1){continue;}
            for (int m=-1; m<2 ;m++){
                if (scope[1+m].at(j+k)!='.'&&(scope[1+m].at(j+k)>57||scope[1+m].at(j+k)<48)){
                    tag=true;
                }
        }
        }
        if(j==scope[1].length()-1){break;}
        j++;
    }
tag? sum_partnum+=value : -1; 
}

std::cout<<sum_partnum<<"\n";

return 0;
}