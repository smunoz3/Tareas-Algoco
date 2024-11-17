#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

int costo_sub(char a, char b) {
    if (a == b) return 0;
    // Ejemplo: retorna un costo fijo de 2 si 'a' y 'b' son diferentes
    return 2;
}

int costo_ins(char b) {
    // Ejemplo: retorna un costo fijo de 1 para insertar cualquier carácter
    return 1;
}

int costo_del(char a) {
    // Ejemplo: retorna un costo fijo de 1 para eliminar cualquier carácter
    return 1;
}

int costo_trans(char a, char b) {
    // Ejemplo: retorna un costo fijo de 1 para transposición entre dos caracteres adyacentes
    return 1;
}

// Función para calcular la distancia mínima de edición entre dos cadenas
int minEditDistance(const string &S1, const string &S2) {
    int n = S1.size(), m = S2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Inicializar los casos base
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + costo_del(S1[i - 1]);
    for (int j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] + costo_ins(S2[j - 1]);

    // Llenado de la matriz con costos mínimos de edición
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int costSub = dp[i - 1][j - 1] + costo_sub(S1[i - 1], S2[j - 1]);
            int costIns = dp[i][j - 1] + costo_ins(S2[j - 1]);
            int costDel = dp[i - 1][j] + costo_del(S1[i - 1]);
            
            dp[i][j] = min({costSub, costIns, costDel});
            
            // Verificar si se puede realizar una transposición
            if (i > 1 && j > 1 && S1[i - 1] == S2[j - 2] && S1[i - 2] == S2[j - 1]) {
                int costTrans = dp[i - 2][j - 2] + costo_trans(S1[i - 1], S1[i - 2]);
                dp[i][j] = min(dp[i][j], costTrans);
            }
        }
    }

    return dp[n][m];
}

void procesarCasos(const string &filename) {
    ifstream file(filename);
    ofstream archivo_salida("resultadoDinamico.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    if (!archivo_salida) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return ;
    }

    int N;
    file >> N;
    file.ignore();

    for (int i = 0; i < N; ++i) {
        string line;
        getline(file, line);
        size_t pos = line.find('|');
        string S1 = line.substr(0, pos);
        string S2 = line.substr(pos + 1);
        int distancia = minEditDistance(S1, S2);
        archivo_salida <<"Costo mínimo entre '" << S1 << "' y '" << S2 << "': " << distancia << endl; 
    }

    file.close();
    archivo_salida.close();
}

int main() {
    string filename = "palabras.txt";
    procesarCasos(filename);
    return 0;
}
