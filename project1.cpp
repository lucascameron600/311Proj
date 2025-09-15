#include <iostream>
#include <string>
#include <vector>
#include <fstream>

bool isSorted(const std::vector<int> &v){
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        } 
    }
    return true;
}


int main(){
    

    return 0;
}
