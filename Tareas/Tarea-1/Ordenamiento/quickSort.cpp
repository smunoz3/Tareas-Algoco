#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

/* This function takes the last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to the left of the pivot and all greater elements 
   to the right  of the pivot */
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//fuente: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
int main()
{
    int N = 100; //largo de arreglos y rango de numeros
    cout << "Quicksort en arreglos de largo: " << N << endl << endl;
    
    
    //Caso array ordenado
    vector<int> array1;
    for(int i=0;i<N;i++){
        array1.push_back(i);
    }
    auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
    quickSort(array1, 0, N - 1);
    auto stop = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration = duration_cast<microseconds>(stop - start); // Calcula la duración
    cout << "Tiempo del arreglo ordenado: " << duration.count() << " microsegundos" << endl;


    //Caso array aleatorio con numeros entre 0 y N
    vector<int> array2;
    std::random_device rd2;  // Fuente de entropía para la semilla
    std::mt19937 gen2(rd2()); // Motor de generación de números aleatorios
    std::uniform_int_distribution<> distrib(0, N-1); // Distribución uniforme en el rango [0, N]
    for(int i=0;i<N;i++){
        array2.push_back(distrib(gen2));
    }
    auto start2 = high_resolution_clock::now(); // Captura el tiempo de inicio
    quickSort(array2, 0, N - 1);
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
    quickSort(array3, 0, N - 1);
    auto stop3 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration3 = duration_cast<microseconds>(stop3 - start3); // Calcula la duración
    cout << "Tiempo del arreglo aleatorio sin repetir numeros: " << duration3.count() << " microsegundos" <<endl;

    return 0;
}