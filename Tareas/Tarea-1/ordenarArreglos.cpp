#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left,int mid, int right){ // fuente: https://www.geeksforgeeks.org/merge-sort/
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2); // Se crea vectores temporales

    // Se copia los dato a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
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

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right){ // fuente: https://www.geeksforgeeks.org/merge-sort/
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int partition(vector<int>& arr, int low, int high){ //fuente: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
    int pivot = arr[high];    // pivote
    int i = (low - 1);  // Indice del elemente menor

    for (int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;    // incrementa el indice del elemento menor
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(vector<int>& arr, int low, int high){ //fuente: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
    if (low < high){
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before
        // partition and after partition
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
    std::random_device rd;  // Fuente de entropía para la semilla
    std::mt19937 gen(rd()); // Motor de generación de números aleatorios
    std::uniform_int_distribution<> distrib(0, 99); // Distribución uniforme en el rango [0, 99]
    for(int i=0;i<N;i++){
        array.push_back(distrib(gen));
    }

    vector<int> array1=array;
    vector<int> array2=array;
    vector<int> array3=array;
    vector<int> array4=array;

    auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
    sort(array1.begin(), array1.end());
    auto stop = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration = duration_cast<microseconds>(stop - start); // Calcula la duración
    cout << "Tiempo del sort estandar: " << duration.count() << " microsegundos" <<endl;


    auto start2 = high_resolution_clock::now(); // Captura el tiempo de inicio
    mergeSort(array2, 0, N - 1);
    auto stop2 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration2 = duration_cast<microseconds>(stop2 - start2); // Calcula la duración
    cout << "Tiempo del merge sort: " << duration2.count() << " microsegundos" <<endl;

    auto start3 = high_resolution_clock::now(); // Captura el tiempo de inicio
    quickSort(array3, 0, N - 1);
    auto stop3 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration3 = duration_cast<microseconds>(stop3 - start3); // Calcula la duración
    cout << "Tiempo del quick sort: " << duration3.count() << " microsegundos" <<endl;

    auto start4 = high_resolution_clock::now(); // Captura el tiempo de inicio
    selectionSort(array4, array4.size());
    auto stop4 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration4 = duration_cast<microseconds>(stop4 - start4); // Calcula la duración
    cout << "Tiempo del selection sort: " << duration4.count() << " microsegundos" <<endl;
    return 0;
}