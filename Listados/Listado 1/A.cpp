#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int ninos, throw_;
    cin >> ninos >> throw_;
    
    int curr = 0;
    int i = 0;
    int temp = 0;
    vector<int> stack;

    cin.ignore();  // Ignorar el salto de línea después de leer throw_
    string entrada;
    getline(cin, entrada);

    vector<string> entradas;
    string palabra = "";
    for (char c : entrada) {
        if (c == ' ') {
            entradas.push_back(palabra);
            palabra = "";
        } else {
            palabra += c;
        }
    }
    entradas.push_back(palabra);  // Agregar la última palabra

    while (throw_ > 0) {
        if (entradas[i] == "undo") {
            i++;
            temp = stoi(entradas[i]);
            while (temp > 0) {
                stack.pop_back();
                temp--;
            }
            curr = stack.back();
        } else {
            temp = stoi(entradas[i]);
            if (temp >= 0) {
                curr += temp;
                curr = curr % ninos;
            } else {
                temp = ((stoi(entradas[i]) * -1) % ninos);
                curr -= temp;
                if (curr < 0) {
                    curr += ninos;
                }
            }
            stack.push_back(curr);
        }
        i++;
        throw_--;
    }
    
    cout << curr << endl;
    
    return 0;
}
