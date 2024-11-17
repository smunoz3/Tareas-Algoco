#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <utility>

using namespace std;

// Diccionarios
unordered_map<pair<char, char>, int, pair_hash> diccionarioReplace;
unordered_map<char, int> diccionarioInsert;
unordered_map<char, int> diccionarioDelete;
unordered_map<pair<char, char>, int, pair_hash> diccionarioTranspose;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

int letra_a_numero(char letra) {
    letra = toupper(letra);
    if (letra >= 'A' && letra <= 'Z') {
        return letra - 'A';
    } else {
        throw invalid_argument("La letra debe estar entre A y Z");
    }
}

int costo_sub(char a, char b) {
    pair<char, char> clave = {a, b};
    if (diccionarioReplace.find(clave) != diccionarioReplace.end()) {
        return diccionarioReplace[clave];
    } else {
        int costo = matrizReplace[letra_a_numero(a)][letra_a_numero(b)];
        diccionarioReplace[clave] = costo; // Agregar al diccionario
        return costo;
    }
}

int costo_ins(char b) {
    if (diccionarioInsert.find(b) != diccionarioInsert.end()) {
        return diccionarioInsert[b];
    } else {
        int costo = vectorInsert[letra_a_numero(b)];
        diccionarioInsert[b] = costo; // Agregar al diccionario
        return costo;
    }
}

int costo_del(char a) {
    if (diccionarioDelete.find(a) != diccionarioDelete.end()) {
        return diccionarioDelete[a];
    } else {
        int costo = vectorDelete[letra_a_numero(a)];
        diccionarioDelete[a] = costo; // Agregar al diccionario
        return costo;
    }
}

int costo_trans(char a, char b) {
    pair<char, char> clave = {a, b};
    if (diccionarioTranspose.find(clave) != diccionarioTranspose.end()) {
        return diccionarioTranspose[clave];
    } else {
        int costo = matrizTranspose[letra_a_numero(a)][letra_a_numero(b)];
        diccionarioTranspose[clave] = costo; // Agregar al diccionario
        return costo;
    }
}

// Función para calcular la distancia mínima de edición entre dos cadenas
int minEditDistance(const string &S1, const string &S2) {
    int n = S1.size(), m = S2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Inicializar los casos base
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + costo_del(S1[i - 1]);
    for (int j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] + costo_ins(S2[j - 1]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int costSub = dp[i - 1][j - 1] + costo_sub(S1[i - 1], S2[j - 1]);
            int costIns = dp[i][j - 1] + costo_ins(S2[j - 1]);
            int costDel = dp[i - 1][j] + costo_del(S1[i - 1]);
            
            dp[i][j] = min({costSub, costIns, costDel});
            
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
        archivo_salida << "Palabras: " << linea << " Costo minimo: " << costoMin <<" Tiempo: "<< duracion.count()<<"ms"<< endl;
    }

    file.close();
    archivo_salida.close();
}

int main() {
    string filename = "palabras.txt";
    procesarCasos(filename);
    return 0;
}
