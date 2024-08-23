#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int> myVector, int sizeOfVect)//vector<int> sizeOfVector)
{
    for (unsigned int i = 0; i < sizeOfVect - 1; i++)
    {
        int vectMin = i;
        for (int j = i + 1; j < sizeOfVect; j++)
        {
            if(myVector[j] < myVector[vectMin])
            {
                vectMin = j;
            }
        }
        int temp = myVector[i];
        myVector[i] = myVector[vectMin];
        myVector[vectMin] = temp;
    }
}


//funte: https://cplusplus.com/forum/beginner/245026/
int main()
{   

    int N = 100; //largo de arreglos y rango de numeros
    cout << "Sort Estandar en arreglos de largo: " << N << endl << endl;
    

    //Caso array ordenado
    vector<int> array1;
    for(int i=0;i<N;i++){
        array1.push_back(i);
    }
    auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
    selectionSort(array1, array1.size());
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
    selectionSort(array2, array2.size());
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
    selectionSort(array3, array3.size());
    auto stop3 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration3 = duration_cast<microseconds>(stop3 - start3); // Calcula la duración
    cout << "Tiempo del arreglo aleatorio sin repetir numeros: " << duration3.count() << " microsegundos" <<endl;

    return 0;
}