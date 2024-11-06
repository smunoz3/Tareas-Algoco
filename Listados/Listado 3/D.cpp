#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int siguientePermutacion(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i < 0) {
        reverse(nums.begin(), nums.end());
        return -1;
    }
    int j = nums.size() - 1;
    while (nums[j] <= nums[i]) {
        j--;
    }
    swap(nums[i], nums[j]);
    reverse(nums.begin() + i + 1, nums.end());
     return 0;
}

int main() {
    int x;
    cin>>x;
    int n =x;
    int siguienteNum;
    while(1){ 
        vector<int> digitos;
        while (x > 0) {
            digitos.push_back(x % 10);
            x /= 10;
        }
        reverse(digitos.begin(), digitos.end());


        if(siguientePermutacion(digitos)==-1){
            siguienteNum=0;
            break;
        }
        else{
            siguienteNum = 0;
            for (int d : digitos) {
                siguienteNum = siguienteNum * 10 + d;
            }
            if(siguienteNum>n){
                break;
            }
            else{
                x=siguienteNum;
            }
        }
    }
    cout<<siguienteNum<<endl;
    return 0;
}