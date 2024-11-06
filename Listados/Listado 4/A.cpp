#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int m;
    int contador;
    cin>>n,m;
    vector<int> tasks(n);
    vector<int> time(m);
    
    for (int i = 0; i < n; ++i) {
        cin>>tasks[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>time[i];
    }
    sort(tasks.begin(), tasks.end(), greater<int>());
    sort(time.begin(), time.end(), greater<int>());

    for(int i=m;i>=0;i--){
        if(time[i]>= tasks[-1]){
            contador +=1;
            tasks.pop_back();
        }
    }

    cout<<contador;
    return 0;
}