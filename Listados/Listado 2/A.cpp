#include <iostream>
#include <vector>

using namespace std;

int contador=0;

int partition(vector<int>& arr, int low, int high){ 
    int pivot = arr[low];
    int i = (low - 1);

    for (int j = low+1; j <= high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
            contador++;//test 1
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(vector<int>& arr, int low, int high){ 
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cin>>n;

    int k;
    vector<int> numeros(21);
    while(n){
        contador=0;
        for (int i = 0; i < 21; ++i){
            cin >> numeros[i];
        }
        k=numeros[0];
        vector<int> restonum(numeros.begin() + 1, numeros.end());

        quickSort(restonum,0,19);

        cout<<k<<" "<<contador<<endl;

        n--;
    }

    return 0;
}