
#include <iostream>
#include <fstream>

class Line {
    private:
        std::string line = " ";
        int first_digit = 0;
        int last_digit = 0;
    public:
        //Getters
        std::string sline(){
            return line;
        };
        int f_dig(){
            return first_digit;
        };
        int l_dig(){
            return last_digit;
        };
        //Setters
        int findf_digit(){
            int i=0;
            while((line.at(i)<48)||(line.at(i)>57)){
                i++;
            };
            return line.at(i)-48;
        }
        int findl_digit(){
            int i=line.length()-1;
            while((line.at(i)<48)||(line.at(i)>57)){
                i--;
            };
            return line.at(i)-48;
        }
    //constructors
    Line(std::string line){
        this->line=line;
        first_digit=findf_digit();
        last_digit=findl_digit();
    };
};

int main(){

 Line line1("treb7uchet");

return 0;
}