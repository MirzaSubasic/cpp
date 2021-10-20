#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <map>

using namespace std;

void arrayInput(int sizeOfArray) {
    srand (time(NULL));
    int arr[sizeOfArray];
    clock_t start = clock();
    for(int i=0;i<sizeOfArray;i++) {
        arr[i]=rand();
    }
    clock_t stop = clock();
    double elapsedTime = double(stop - start);
    cout<<"elapsed time for array is "<< elapsedTime<<" milliseconds"<<endl;
}

void mapInput(int sizeOfMap) {
    srand (time(NULL));
    map<int,int> m;
    clock_t start = clock();
    for(int i=0;i<sizeOfMap;i++){
        m[i]=(rand());
    }
    clock_t stop = clock();
    double elapsedTime = double(stop - start);
    cout<<"elapsed time for map is "<< elapsedTime<<" milliseconds"<<endl;
}


int main() {
    int size1;
    size1=200000;

    arrayInput(size1);
    mapInput(size1);

    return 0;
}
