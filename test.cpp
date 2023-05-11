#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    string m_filename = "test.log";
    string filename ="test.log1";

    if(rename(m_filename.c_str(),filename.c_str()) != 0){
        throw std::logic_error("rename log failed");
    }

    return 0;
}   
   
