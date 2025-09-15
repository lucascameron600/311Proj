#include <iostream>
#include <string>
#include <vector>
#include <fstream>

bool isSorted(std::vector<int> &v){
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        } 
    }
    return true;
}

std::vector<int> bubbleSort(std::vector<int> &v){
    bool sorted = false;

    while(!sorted){
        sorted = true;

        for(int i = 0;i<v.size()-1; i++){
            if(v[i] > v[i+1]){
                std::swap(v[i-1], v[i]);
                sorted = false;
            }

        }

    }

    return v;
}

std::vector<int> insertionSort(std::vector<int> &v){
    int i = 1;

    while(i < v.size()){
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            std::swap(v[j] , v[j-1]);
        }
        i++
    }
    return v;
}

std::vector<int> selectionSort(std::vector<int> &v){
    for(int i = 0; i < v.size() -1; i++){
        int uMin = i;
        for(int j = i +1; j < v.size(); j++){
            if(v[j] < v[uMin]){
                uMin = j;

            }
        }
        std::swap(v[i], v[uMin]);



    }
    return v;
}

std::vector<int> quickSort(std::vector<int> &v){
    if (v.size() <= 1) return v;

    int pivot = v[0];

    std::vector<int> A = {};
    std::vector<int> B = {};

    for(int i = 1; i<v.size(); i++){
        if(v[i] <= pivot) A.push_back(v[i]);
        else B.push_back(v[i]);
    }
    std::vector<int> sortedA = quickSort(A);
    std::vector<int> sortedB = quickSort(B);


    sortedA.push_back(pivot);
    sortedA.insert(sortedA.end(),sortedB.begin(), sortedB.end());
    return sortedA;
}



int main(){
    

    return 0;
}
