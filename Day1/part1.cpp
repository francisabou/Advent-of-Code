
#include <iostream>
#include <fstream>

//Classes
class Line {
    private:
        std::string line;
        int first_digit;
        int last_digit;
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
    Line(){
        line=" ";
        first_digit=0;
        last_digit=0;
    };
};

//Functions Declaration
bool Testfile(std::ifstream &file);

int main(){

    std::ifstream file("part1.txt");
    std::string temp;
    int total=0;

    //Exit program when file was not found
    if (Testfile(file)){
        return 1;
    };
    
    while(!file.eof()){
        std::getline(file,temp);
        if(temp.empty()){
            continue;
        };
        Line line(temp);
        total+=line.f_dig()*10+line.l_dig();
    };

    std::cout << "\n" << "************************************************************" << "\n" << "\n";
    std::cout << total << "\n";
    std::cout << "\n" << "************************************************************" << "\n" << "\n";

    file.close();
    return 0;
}

//functions
bool Testfile(std::ifstream &file){
    if (!file.is_open()){
        std::cout << "\n" << "************************************************************" << "\n" << "\n";
        std::cout << "File not found" << "\n";
        std::cout << "\n" << "************************************************************" << "\n" << "\n";
        return 1;
    };
    return 0;
}

