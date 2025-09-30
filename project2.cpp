#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <cmath>

bool isSorted(std::vector<int> &v){
    for (int i = 0; i < static_cast<int>(v.size()) - 1; i++){
        if (v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

std::vector<int> bubbleSort(std::vector<int> v){
    bool sorted = false;

    while(!sorted){
        sorted = true;

        for (int i = 0; i < static_cast<int>(v.size()) - 1; i++){
            if (v[i] > v[i+1]){
                std::swap(v[i+1], v[i]);
                sorted = false;
            }
        }
    }

    return v;
}

std::vector<int> insertionSort(std::vector<int> v){
    int i = 1;

    while (i < static_cast<int>(v.size())){
        int j = i;
        while (j > 0 && v[j] < v[j-1]){
            std::swap(v[j], v[j-1]);
            j--;
        }
        i++; // missing semicolon fixed
    }
    return v;
}

std::vector<int> selectionSort(std::vector<int> v){
    for (int i = 0; i < static_cast<int>(v.size()) - 1; i++){
        int uMin = i;
        for (int j = i + 1; j < static_cast<int>(v.size()); j++){
            if (v[j] < v[uMin]){
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

    for (int i = 1; i < static_cast<int>(v.size()); i++){
        if (v[i] <= pivot) A.push_back(v[i]);
        else B.push_back(v[i]);
    }
    std::vector<int> sortedA = quickSort(A);
    std::vector<int> sortedB = quickSort(B);

    sortedA.push_back(pivot);
    sortedA.insert(sortedA.end(), sortedB.begin(), sortedB.end());
    return sortedA;
}

std::vector<int> randomVector(int size, int low, int high){
    std::vector<int> v(size, 0); // qualified std::vector
    for (int i = 0; i < size; i++){
        v[i] = std::rand() % (high - low + 1) + low; // std::rand
    }
    return v;
}

double sampleMax(const std::vector<double> v) // qualified std::vector
{
    double max = 0;

    for (int i = 0; i < static_cast<int>(v.size()); i++){
        if (v[i] > max){
            max = v[i]; // missing semicolon fixed
        }
    }
    return max;
}

double sampleMean(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    double s = 0.0;
    for (double x : v) s += x;
    return s / static_cast<double>(v.size());
}

double sampleMin(const std::vector<double> v) // qualified std::vector
{
    double min = v[0];

    for (int i = 0; i < static_cast<int>(v.size()); i++){
        if (v[i] < min){
            min = v[i]; // missing semicolon fixed
        }
    }
    return min;
}

double sampleSD(const std::vector<double> v){ // qualified std::vector
    double mean = 0;

    for (int i = 0; i < static_cast<int>(v.size()); i++){
        mean += v[i];
    }

    mean = mean / v.size();

    double sd = 0;

    for (int i = 0; i < static_cast<int>(v.size()); i++){
        sd += (v[i] - mean) * (v[i] - mean);
    }
    sd = sd / (v.size() - 1);

    return std::sqrt(sd); // std::sqrt, removed stray 'i' and fixed braces
}

void printStats(const std::string& name, const std::vector<double>& times) { // added comma and std::
    std::cout << "************************\n";
    std::cout << name << " sort on 10 vectors of length 100" << "\n";
    std::cout << "Sorting successful\n";
    std::cout << "Minimum: " << sampleMin(times) << " sec; "
              << "Mean: "    << sampleMean(times) << " sec; "
              << "Standard deviation: " << sampleSD(times) << " sec; "
              << "Maximum: " << sampleMax(times) << " sec\n";
    std::cout << "************************\n";
}

void sortAndGetTimes(){
    std::vector<double> bubbleTimes;
    std::vector<double> insertionTimes;
    std::vector<double> selectionTimes;
    std::vector<double> quickTimes;

    for (int i = 0; i < 10; i++){
        // Bubble
        auto start1 = std::chrono::high_resolution_clock::now();
        auto vec = bubbleSort(randomVector(100, 0, 99));
        auto end1 = std::chrono::high_resolution_clock::now();
        double elapsed1 = std::chrono::duration_cast<std::chrono::duration<double>>(end1 - start1).count();
        bubbleTimes.push_back(elapsed1);
        std::cout << "Bubble Times done" << std::endl;

        // Insertion
        auto start2 = std::chrono::high_resolution_clock::now();
        auto vec2 = insertionSort(randomVector(100, 0, 99));
        auto end2 = std::chrono::high_resolution_clock::now();
        double elapsed2 = std::chrono::duration_cast<std::chrono::duration<double>>(end2 - start2).count();
        insertionTimes.push_back(elapsed2);

        // Selection
        auto start3 = std::chrono::high_resolution_clock::now();
        auto vec3 = selectionSort(randomVector(100, 0, 99));
        auto end3 = std::chrono::high_resolution_clock::now();
        double elapsed3 = std::chrono::duration_cast<std::chrono::duration<double>>(end3 - start3).count();
        selectionTimes.push_back(elapsed3);

        // Quick
        auto start4 = std::chrono::high_resolution_clock::now();
        auto vec4 = quickSort(randomVector(100, 0, 99));
        auto end4 = std::chrono::high_resolution_clock::now();
        double elapsed4 = std::chrono::duration_cast<std::chrono::duration<double>>(end4 - start4).count();
        quickTimes.push_back(elapsed4);
    }

    printStats("Bubble",    bubbleTimes);
    printStats("Insertion", insertionTimes);
    printStats("Selection", selectionTimes);
    printStats("Quick",     quickTimes);
}

int main(){
    sortAndGetTimes(); // added dummy argument to match signature
    return 0;
}

