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
            int i = std::string::npos; 
            int j= 0;           
            int found;
            std::string nums[]={"one","two","three","four","five","six","seven","eight","nine"};
            for(std::string num : nums){
                found=line.find(num);
                if(found!=std::string::npos&&found<i){
                    i=found;
                }
            }
            while(j<line.size()&&line.at(j)<48&&line.at(j)>57){
                j++;
            }
            return (i<j)? i : j ; 
        }
        int findl_digit(){
            int i = std::string::npos;
            int j=line.size()-1;
            int found;
            std::string nums[]={"one","two","three","four","five","six","seven","eight","nine"};
            for(std::string num : nums){
                found=line.rfind(num);
                if(found!=std::string::npos&&found>i){
                    i=found;
                }
            }
            while(j>-1&&line.at(j)<48&&line.at(j)>57){
                j--;
            }
            return (i<j)? j : i ; 
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
    





}