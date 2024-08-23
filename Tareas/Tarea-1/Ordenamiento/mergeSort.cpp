#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
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
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//fuente: https://www.geeksforgeeks.org/merge-sort/
int main()
{
    int N = 100; //largo de arreglos y rango de numeros
    cout << "Mergesort en arreglos de largo: " << N << endl << endl;


    //Caso array ordenado
    vector<int> array1;
    for(int i=0;i<N;i++){
        array1.push_back(i);
    }
    auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
    mergeSort(array1, 0, N - 1);
    auto stop = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration = duration_cast<microseconds>(stop - start); // Calcula la duración
    cout << "Tiempo del arreglo ordenado: " << duration.count() << " microsegundos" << endl;


    //Caso array aleatorio con numeros entre 0 y N
    vector<int> array2;
    std::random_device rd;  // Fuente de entropía para la semilla
    std::mt19937 gen(rd()); // Motor de generación de números aleatorios
    std::uniform_int_distribution<> distrib(0, N-1); // Distribución uniforme en el rango [0, N]
    for(int i=0;i<N;i++){
        array2.push_back(distrib(gen));
    }
    auto start2 = high_resolution_clock::now(); // Captura el tiempo de inicio
    mergeSort(array2, 0, N - 1);
    auto stop2 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration2 = duration_cast<microseconds>(stop2 - start2); // Calcula la duración
    cout << "Tiempo del arreglo aleatorio: " << duration2.count() << " microsegundos" <<endl;


    //Caso array aleatorio con numeros entre 0 y N sin repetir numeros 
    vector<int> array3;
    for (int i = 0; i < N; i++) {
        array3.push_back(i);
    }
    std::random_device rd3;  // Fuente de entropía para la semilla
    std::mt19937 gen3(rd3()); // Motor de generación de números aleatorios
    std::shuffle(array3.begin(), array3.end(), gen3);// Desordenar el vector aleatoriamente
    auto start3 = high_resolution_clock::now(); // Captura el tiempo de inicio
    mergeSort(array3, 0, N - 1);
    auto stop3 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration3 = duration_cast<microseconds>(stop3 - start3); // Calcula la duración
    cout << "Tiempo del arreglo aleatorio sin repetir numeros: " << duration3.count() << " microsegundos" <<endl;

    return 0;
}