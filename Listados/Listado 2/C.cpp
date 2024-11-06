#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
map<string,unsigned long> m;
vector<string> v;


bool myfunction (string a, string b) {
    unsigned long al = m[a];
    unsigned long bl = m[b];
    if(al != bl){
        return (m[a]>m[b]);
    } else {
        return a.compare(b) < 0;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        v.clear();
        m.clear();
        int n;
        cin >> n;

        for(int j = 0; j < n; ++j){
            string name;
            cin >> name;
            name = name.substr(0,name.length()-1);
            string class_string;
            cin >> class_string;
            string clase;      
            cin >> clase;

            string class_valor = "";    
            istringstream ss(class_string);
            string token;
            while(std::getline(ss, token, '-')) {   
                if(token.compare("upper") == 0){
                    class_valor.push_back('3');         
                } else if(token.compare("middle") == 0){
                    class_valor.push_back('2');
                } else if(token.compare("lower") == 0){
                    class_valor.push_back('1');
                }
            }
            class_valor = string(class_valor.rbegin(), class_valor.rend()); 
            while(class_valor.length() != 10) {
                class_valor.push_back('2');   
            }

            unsigned long valor = 0;
            for(auto it = class_valor.begin(); it != class_valor.end();++it){
                valor *= 10;
                valor += *it-'0';
            }

            m[name] = valor;
            v.push_back(name);
        }

        sort(v.begin(),v.end(),myfunction);

        for(auto it = v.begin(); it != v.end(); ++it){
            cout << *it << endl;
        }
        cout << "==============================" << endl;
    }
    return 0;
}