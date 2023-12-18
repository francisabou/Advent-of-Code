#include <iostream>
#include <fstream>

int written_number_test(std::string line,int index);


int main(){

std::ifstream input("part1_input.txt");
//std::ifstream input("part2_example.txt");
std::string line;
int cascii;
int sum=0;
int wnum;

while(std::getline(input,line)){
    for(int j=0;j<line.length();j++){
        if(line.at(j)<58&&line.at(j)>47){
            sum+=10*(line.at(j)-48);
            break;
        }
        wnum=written_number_test(line,j);
        if (wnum!=-1){
            sum+=10*wnum;
            break;
        }
    }

    for(int j=line.length()-1;j>-1;j--){
        if(line.at(j)<58&&line.at(j)>47){
            sum+=line.at(j)-48;
            break;
        }
        wnum=written_number_test(line,j);
        if (wnum!=-1){
            sum+=wnum;
            break;
        }
    }
}

std::cout<<sum<<"\n";

    return 0;
}

int written_number_test(std::string line,int index){

std::string spelling[]={"one","two","three","four","five","six","seven","eight","nine"};

for(int i=0;i<sizeof(spelling)/sizeof(spelling[0]);i++){
    if(line.substr(index,line.length()-index).length()<spelling[i].length()){continue;}
    int test=line.substr(index,spelling[i].length())==spelling[i] ? i+1 : -1;
    if(test!=-1){return test;}
}

return -1;

}