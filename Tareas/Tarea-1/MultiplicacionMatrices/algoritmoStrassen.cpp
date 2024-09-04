#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace std;
using namespace std::chrono;

void add(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void traditionalMultiply(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else if (n % 2 != 0) {
        // Si n no es potencia de 2, utilizamos multiplicación tradicional
        traditionalMultiply(A, B, C, n);
    } else {
        int newSize = n / 2;

        int** A11 = new int*[newSize];
        int** A12 = new int*[newSize];
        int** A21 = new int*[newSize];
        int** A22 = new int*[newSize];
        int** B11 = new int*[newSize];
        int** B12 = new int*[newSize];
        int** B21 = new int*[newSize];
        int** B22 = new int*[newSize];
        int** C11 = new int*[newSize];
        int** C12 = new int*[newSize];
        int** C21 = new int*[newSize];
        int** C22 = new int*[newSize];
        int** M1 = new int*[newSize];
        int** M2 = new int*[newSize];
        int** M3 = new int*[newSize];
        int** M4 = new int*[newSize];
        int** M5 = new int*[newSize];
        int** M6 = new int*[newSize];
        int** M7 = new int*[newSize];
        int** tempA = new int*[newSize];
        int** tempB = new int*[newSize];

        for (int i = 0; i < newSize; i++) {
            A11[i] = new int[newSize];
            A12[i] = new int[newSize];
            A21[i] = new int[newSize];
            A22[i] = new int[newSize];
            B11[i] = new int[newSize];
            B12[i] = new int[newSize];
            B21[i] = new int[newSize];
            B22[i] = new int[newSize];
            C11[i] = new int[newSize];
            C12[i] = new int[newSize];
            C21[i] = new int[newSize];
            C22[i] = new int[newSize];
            M1[i] = new int[newSize];
            M2[i] = new int[newSize];
            M3[i] = new int[newSize];
            M4[i] = new int[newSize];
            M5[i] = new int[newSize];
            M6[i] = new int[newSize];
            M7[i] = new int[newSize];
            tempA[i] = new int[newSize];
            tempB[i] = new int[newSize];
        }

        // Dividiendo las matrices A y B en submatrices
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        // Calculando M1 = (A11 + A22) * (B11 + B22)
        add(A11, A22, tempA, newSize);
        add(B11, B22, tempB, newSize);
        multiply(tempA, tempB, M1, newSize);

        // Calculando M2 = (A21 + A22) * B11
        add(A21, A22, tempA, newSize);
        multiply(tempA, B11, M2, newSize);

        // Calculando M3 = A11 * (B12 - B22)
        subtract(B12, B22, tempB, newSize);
        multiply(A11, tempB, M3, newSize);

        // Calculando M4 = A22 * (B21 - B11)
        subtract(B21, B11, tempB, newSize);
        multiply(A22, tempB, M4, newSize);

        // Calculando M5 = (A11 + A12) * B22
        add(A11, A12, tempA, newSize);
        multiply(tempA, B22, M5, newSize);

        // Calculando M6 = (A21 - A11) * (B11 + B12)
        subtract(A21, A11, tempA, newSize);
        add(B11, B12, tempB, newSize);
        multiply(tempA, tempB, M6, newSize);

        // Calculando M7 = (A12 - A22) * (B21 + B22)
        subtract(A12, A22, tempA, newSize);
        add(B21, B22, tempB, newSize);
        multiply(tempA, tempB, M7, newSize);

        // Calculando C11 = M1 + M4 - M5 + M7
        add(M1, M4, tempA, newSize);
        subtract(tempA, M5, tempB, newSize);
        add(tempB, M7, C11, newSize);

        // Calculando C12 = M3 + M5
        add(M3, M5, C12, newSize);

        // Calculando C21 = M2 + M4
        add(M2, M4, C21, newSize);

        // Calculando C22 = M1 - M2 + M3 + M6
        subtract(M1, M2, tempA, newSize);
        add(tempA, M3, tempB, newSize);
        add(tempB, M6, C22, newSize);

        // Combinando las submatrices en la matriz resultante C
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }

        // Liberando la memoria
        for (int i = 0; i < newSize; i++) {
            delete[] A11[i];
            delete[] A12[i];
            delete[] A21[i];
            delete[] A22[i];
            delete[] B11[i];
            delete[] B12[i];
            delete[] B21[i];
            delete[] B22[i];
            delete[] C11[i];
            delete[] C12[i];
            delete[] C21[i];
            delete[] C22[i];
            delete[] M1[i];
            delete[] M2[i];
            delete[] M3[i];
            delete[] M4[i];
            delete[] M5[i];
            delete[] M6[i];
            delete[] M7[i];
            delete[] tempA[i];
            delete[] tempB[i];
        }

        delete[] A11;
        delete[] A12;
        delete[] A21;
        delete[] A22;
        delete[] B11;
        delete[] B12;
        delete[] B21;
        delete[] B22;
        delete[] C11;
        delete[] C12;
        delete[] C21;
        delete[] C22;
        delete[] M1;
        delete[] M2;
        delete[] M3;
        delete[] M4;
        delete[] M5;
        delete[] M6;
        delete[] M7;
        delete[] tempA;
        delete[] tempB;
    }
}


int main() {
    int n;
    cout << "Ingrese el tamaño de las matrices y luego las 2 matrices: ";
    cin >> n;

    // Inicializar la semilla para el generador de números aleatorios
    std::srand(std::time(0));

    // Creando matrices A y B
    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    } 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j]=std::rand() % 100;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B[i][j]=std::rand() % 100;
        }
    }

    
    auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
    multiply(A, B, C, n); // Multiplicando matrices usando el algoritmo de Strassen o la multiplicación tradicional
    auto stop = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration = duration_cast<microseconds>(stop - start); // Calcula la duración
    cout << "Tiempo del arreglo ordenado: " << duration.count() << " microsegundos" << endl;

    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
