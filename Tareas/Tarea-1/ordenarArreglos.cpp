#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left,int mid, int right){ // fuente: https://www.geeksforgeeks.org/merge-sort/
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& arr, int left, int right){ // fuente: https://www.geeksforgeeks.org/merge-sort/
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int partition(vector<int>& arr, int low, int high){ //fuente: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(vector<int>& arr, int low, int high){ //fuente: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void selectionSort(vector<int> myVector, int sizeOfVect){ //funte: https://cplusplus.com/forum/beginner/245026/
    for (unsigned int i = 0; i < sizeOfVect - 1; i++){
        int vectMin = i;
        for (int j = i + 1; j < sizeOfVect; j++){
            if(myVector[j] < myVector[vectMin]){
                vectMin = j;
            }
        }
        int temp = myVector[i];
        myVector[i] = myVector[vectMin];
        myVector[vectMin] = temp;
    }
}


int main(){
    int N;
    cout << "Ingrese el tamaño de los arreglos: ";
    cin>>N;

    vector<int> array;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 99);
    for(int i=0;i<N;i++){
        array.push_back(distrib(gen));
    }

    vector<int> array1=array;
    vector<int> array2=array;
    vector<int> array3=array;
    vector<int> array4=array;

    auto start = high_resolution_clock::now();
    sort(array1.begin(), array1.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo del sort estandar: " << duration.count() << " microsegundos" <<endl;


    auto start2 = high_resolution_clock::now();
    mergeSort(array2, 0, N - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Tiempo del merge sort: " << duration2.count() << " microsegundos" <<endl;

    auto start3 = high_resolution_clock::now();
    quickSort(array3, 0, N - 1);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Tiempo del quick sort: " << duration3.count() << " microsegundos" <<endl;

    auto start4 = high_resolution_clock::now();
    selectionSort(array4, array4.size());
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Tiempo del selection sort: " << duration4.count() << " microsegundos" <<endl;
    return 0;
}