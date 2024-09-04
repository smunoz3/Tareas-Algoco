#include <iostream>
#include <cmath>

using namespace std;

void printMatrix(int** matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(int** A, int** B, int** C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int** A, int** B, int** C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int** A, int** B, int** C, int N) {
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = N / 2;
    int** A11 = new int*[newSize];
    int** A12 = new int*[newSize];
    int** A21 = new int*[newSize];
    int** A22 = new int*[newSize];
    int** B11 = new int*[newSize];
    int** B12 = new int*[newSize];
    int** B21 = new int*[newSize];
    int** B22 = new int*[newSize];
    int** M1 = new int*[newSize];
    int** M2 = new int*[newSize];
    int** M3 = new int*[newSize];
    int** M4 = new int*[newSize];
    int** M5 = new int*[newSize];
    int** M6 = new int*[newSize];
    int** M7 = new int*[newSize];
    int** temp1 = new int*[newSize];
    int** temp2 = new int*[newSize];
    int** C11 = new int*[newSize];
    int** C12 = new int*[newSize];
    int** C21 = new int*[newSize];
    int** C22 = new int*[newSize];

    for (int i = 0; i < newSize; ++i) {
        A11[i] = new int[newSize];
        A12[i] = new int[newSize];
        A21[i] = new int[newSize];
        A22[i] = new int[newSize];
        B11[i] = new int[newSize];
        B12[i] = new int[newSize];
        B21[i] = new int[newSize];
        B22[i] = new int[newSize];
        M1[i] = new int[newSize];
        M2[i] = new int[newSize];
        M3[i] = new int[newSize];
        M4[i] = new int[newSize];
        M5[i] = new int[newSize];
        M6[i] = new int[newSize];
        M7[i] = new int[newSize];
        temp1[i] = new int[newSize];
        temp2[i] = new int[newSize];
        C11[i] = new int[newSize];
        C12[i] = new int[newSize];
        C21[i] = new int[newSize];
        C22[i] = new int[newSize];
    }

    // Dividir matrices A y B en submatrices
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
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

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrices(A11, A22, temp1, newSize);
    addMatrices(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);

    // M2 = (A21 + A22) * B11
    addMatrices(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtractMatrices(B12, B22, temp1, newSize);
    strassen(A11, temp1, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtractMatrices(B21, B11, temp1, newSize);
    strassen(A22, temp1, M4, newSize);

    // M5 = (A11 + A12) * B22
    addMatrices(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrices(A21, A11, temp1, newSize);
    addMatrices(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrices(A12, A22, temp1, newSize);
    addMatrices(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);

    // C11 = M1 + M4 - M5 + M7
    addMatrices(M1, M4, temp1, newSize);
    subtractMatrices(temp1, M5, temp2, newSize);
    addMatrices(temp2, M7, C11, newSize);

    // C12 = M3 + M5
    addMatrices(M3, M5, C12, newSize);

    // C21 = M2 + M4
    addMatrices(M2, M4, C21, newSize);

    // C22 = M1 - M2 + M3 + M6
    subtractMatrices(M1, M2, temp1, newSize);
    addMatrices(temp1, M3, temp2, newSize);
    addMatrices(temp2, M6, C22, newSize);

    // Reconstruir la matriz C
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Liberar memoria
    for (int i = 0; i < newSize; ++i) {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] M1[i];
        delete[] M2[i];
        delete[] M3[i];
        delete[] M4[i];
        delete[] M5[i];
        delete[] M6[i];
        delete[] M7[i];
        delete[] temp1[i];
        delete[] temp2[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
    }

    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] M1;
    delete[] M2;
    delete[] M3;
    delete[] M4;
    delete[] M5;
    delete[] M6;
    delete[] M7;
    delete[] temp1;
    delete[] temp2;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;
}

int main() {
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

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A, n);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(B, n);

    strassen(A, B, C, n);

    std::cout << "Matrix C (result of A * B):" << std::endl;
    printMatrix(C, n);

    // Liberar memoria
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
