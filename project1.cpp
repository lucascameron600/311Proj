#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

bool isSorted(std::vector<int> &v){
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        } 
    }
    return true;
}

std::vector<int> bubbleSort(std::vector<int> v){
    bool sorted = false;

    while(!sorted){
        sorted = true;

        for(int i = 0;i<v.size()-1; i++){
            if(v[i] > v[i+1]){
                std::swap(v[i+1], v[i]);
                sorted = false;
            }

        }

    }

    return v;
}

std::vector<int> insertionSort(std::vector<int> v){
    int i = 1;

    while(i < v.size()){
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            std::swap(v[j] , v[j-1]);
            j--;
        }
        i++
    }
    return v;
}

std::vector<int> selectionSort(std::vector<int> v){
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

std::vector<int> quickSort(std::vector<int> v){
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

std::vector<int> randomVector(int size, int low, int high){
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++){
    v[i] = rand() % (high - low +1) + low;
    }
return v;
}

double sampleMax(const vector<double> v)
{
    double max = 0;

    for(int i  = 0; i < v.size(); i++){
        if(v[i] > max){
            max = v[i]
        }


    }
    return max;

}


double sampleMean(const vector<double>& v) {
    if (v.empty()) return 0.0;
    double s = 0.0;
    for (double x : v) s += x;
    return s / static_cast<double>(v.size());
}

double sampleMin(const vector<double> v)
{
    double min = 0;

    for(int i  = 0; i < v.size(); i++){
        if(v[i] < min){
            min = v[i]
        }


    }
    return min;

}

double sampleSD(const vector<double> v){
    double mean = 0;
    
    for (int i = 0; i < v.size(); i++){
        mean += v[i];
    }

    mean = mean / v.size();
    
    double sd = 0;

    for (int i = 0; i < v.size(); i++){
        sd += (v[i]-mean)*(v[i]-mean);
    }
    sd = sd / (v.size()-1);
    
    return sqrt(sd);i}


void printStats(const std::string& name const vector<double>& times) {
    cout << "************************\n";
    cout << name << " sort on 10 vectors of length 100" << "\n";
    cout << "Sorting successful\n";
    cout << "Minimum: " << sampleMin(times) << " sec; "
         << "Mean: "    << sampleMean(times) << " sec; "
         << "Standard deviation: " << sampleSD(times) << " sec; "
         << "Maximum: " << sampleMax(times) << " sec\n";
    cout << "************************\n";
}


void sortAndGetTimes(std::string indicator){
    

    std::vector<double> bubbleTimes;
    std::vector<double> insertionTimes;
    std::vector<double> selectionTimes;
    std::vector<double> quickTimes;
    
    for(int i = 0; i < 10; i++){
        chrono::high_resolution_clock::time_point start;
        chrono::high_resolution_clock::time_point end;
        auto start = chrono::high_resolution_clock::now();

        auto vec = bubbleSort(randomVector(100, 0, 99));
        
        auto end = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration_cast<chrono::duration<double>>(end-start).count();

        //updateStats(elapsed, arr[0], bubblemax);
        bubbleTimes.push_back(elapsed);

        cout << "Bubble Times done" << std::endl;


        chrono::high_resolution_clock::time_point start;
        chrono::high_resolution_clock::time_point end;
        auto start = chrono::high_resolution_clock::now();

        auto vec2 = insertionSort(randomVector(100, 0, 99));
        
        auto end = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration_cast<chrono::duration<double>>(end-start).count();

        //updateStats(elapsed, arr[0], bubblemax);
        insertionTimes.push_back(elapsed);

        

        chrono::high_resolution_clock::time_point start;
        chrono::high_resolution_clock::time_point end;
        auto start = chrono::high_resolution_clock::now();

        auto vec3 = selectionSort(randomVector(100, 0, 99));
        
        auto end = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration_cast<chrono::duration<double>>(end-start).count();

        //updateStats(elapsed, arr[0], bubblemax);
        selectionTimes.push_back(elapsed);
        


        

        chrono::high_resolution_clock::time_point start;
        chrono::high_resolution_clock::time_point end;
        auto start = chrono::high_resolution_clock::now();

        auto vec4 = quickSort(randomVector(100, 0, 99));
        
        auto end = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration_cast<chrono::duration<double>>(end-start).count();

        //updateStats(elapsed, arr[0], bubblemax);
        quickTimes.push_back(elapsed);
    }

    printStats("Bubble",    bubbleTimes);
    printStats("Insertion", insertionTimes);
    printStats("Selection", selectionTimes);
    printStats("Quick",     quickTimes);
}
    
int main(){
    
    sortAndGetTimes();

    return 0;
}
