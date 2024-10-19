
#include <iostream>

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
        int l_digit(){
            return last_digit;
        };
        //Setters
        int findf_digit(){
            int i=0;
            while((line.at(i)<48)&&(line.at(i)>57)){
                i++;
            };
            return line.at(i)-48;
        }
        int findl_digit(){
            int i=line.length();
            while((line.at(i)<48)&&(line.at(i)>57)){
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

 Line line1("1abc2");

std::cout << line1.sline() << "\n";
std::cout << line1.f_dig() << "\n";
std::cout << line1.f_dig() << "\n";

return 0;
}