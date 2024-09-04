    #include <iostream>
    #include <chrono>

    using namespace std;
    using namespace std::chrono;

    // Transpone la matriz B
    void transposeMatrix(int** B, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Intercambiar elementos (i, j) y (j, i)
                std::swap(B[i][j], B[j][i]);
            }
        }
    }


    void multiplyMatrices(int** A, int** B, int** C, int n) {
        transposeMatrix(B,n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[j][k];
                }
            }
        }
    }

    int main() {
        int n;

        cout << "Ingrese el tamaño de las matrices y luego las 2 matrices: ";
        cin >> n;

        int** A = new int*[n];
        int** B = new int*[n]; 
        int** C = new int*[n];

        for (int i = 0; i < n; i++) {
            A[i] = new int[n];
            B[i] = new int[n];
            C[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> A[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> B[i][j];
            }
        }

        auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
        multiplyMatrices(A, B, C, n); // Multiplicar matrices
        auto stop = high_resolution_clock::now(); // Captura el tiempo de finalización
        auto duration = duration_cast<microseconds>(stop - start); // Calcula la duración
        cout << "Tiempo del arreglo ordenado: " << duration.count() << " microsegundos" << endl;

        // Liberar memoria
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
