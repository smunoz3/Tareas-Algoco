#include <iostream>
#include <chrono>
#include <cstdlib> 
#include <ctime>

using namespace std;
using namespace std::chrono;

void multiplicarMatricesTradicional(int** A, int** B_T, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }
}

void transponeMatriz(int** B, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int temp = B[i][j];
            B[i][j] = B[j][i];
            B[j][i] = temp;
        }
    }
}

void multiplyMatricesTranspuesta(int** A, int** B, int** C, int n) {
    transponeMatriz(B,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }
}


int main(){
    int n;
    cout << "Ingrese el tamaño de las matrices: ";
    cin >> n;
    srand(time(0));


    int** A = new int*[n];
    int** B = new int*[n]; 
    int** C = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    // Llena las matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j]=rand() % 100;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j]=rand() % 100;
        }
    }

    auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
    multiplicarMatricesTradicional(A, B, C, n); // Multiplicar matrices
    auto stop = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration = duration_cast<microseconds>(stop - start); // Calcula la duración
    cout << "Tiempo algotitmo tradicional: " << duration.count() << " microsegundos" << endl;


    auto start2 = high_resolution_clock::now(); // Captura el tiempo de inicio
    multiplyMatricesTranspuesta(A, B, C, n); // Multiplicar matrices
    auto stop2 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration2 = duration_cast<microseconds>(stop2 - start2); // Calcula la duración
    cout << "Tiempo algotitmo transponiendo la matriz: " << duration2.count() << " microsegundos" << endl;


    return 0;
}