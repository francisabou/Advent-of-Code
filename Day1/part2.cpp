#include <iostream>
#include <fstream>

class Code {
    private:
        //Attributes
        std::string line;
        int f_digit;
        int l_digit;
        //methods
        
        int findf_digit(){
            int i[] = {std::numeric_limits<int>::max(),-1}; 
            int j[]= {0,-1}; 
            int k = 0;          
            int found;
            std::string nums[]={"one","two","three","four","five","six","seven","eight","nine"};
            for(const std::string &num : nums){
                k++;
                found=line.find(num);
                if(found!=std::string::npos&&found<i[0]){
                    i[0]=found;
                    i[1]=k;
                }
            }
            while(j[0]<line.size()&&(line.at(j[0])<48||line.at(j[0])>57)){
                j[0]++;
                if (j[0]==line.size()){
                    j[0]=std::numeric_limits<int>::max();
                };
            }
            return (i[0]<j[0])? i[1] : line.at(j[0])-48 ; 
        }
        int findl_digit(){
            int i[] = {std::numeric_limits<int>::min(),-1}; 
            int j[]= {0,-1};
            int k=0;
            int found;
            j[0]=line.size()-1;
            std::string nums[]={"one","two","three","four","five","six","seven","eight","nine"};
            for(const std::string &num : nums){
                k++;
                found=line.rfind(num);
                if(found!=std::string::npos&&found>i[0]){
                    i[0]=found;
                    i[1]=k;
                }
            }
            while(j[0]>-1&&(line.at(j[0])<48||line.at(j[0])>57)){
                j[0]--;
                if(j[0]==-1){
                    j[0]=std::numeric_limits<int>::min();
                }
            }
            return (i[0]<j[0])?  line.at(j[0])-48 : i[1] ; 
        }
    public:
        //Getters
        std::string getline(){
            return line;
        }
        int getf_digit(){
            return f_digit;
        }
        int getl_digit(){
            return l_digit;
        }
        //Setters
        void setline(std::string line){
            this->line=line;
            f_digit=findf_digit();
            l_digit=findl_digit();
        }
};

int main(){

    Code code;
    int calib_val = 0;
    std::string temp_line;

    std::ifstream file("part2.txt");

    if(!file.is_open()){
        std::cout << "\n" << "File didn't open" << "\n" << "\n";
        return 1;
    }

    while(std::getline(file,temp_line)){
        code.setline(temp_line);
        calib_val+=code.getf_digit()*10+code.getl_digit();
    }

    //single string test code
    //code.setline("eightwothree");
    //calib_val+=code.getf_digit()*10+code.getl_digit();
    //std::cout << "\n" << code.getf_digit() << "\n" << "\n";
    //std::cout << "\n" << code.getl_digit() << "\n" << "\n";

    std::cout << "\n" << calib_val << "\n" << "\n";
    return 0;
}