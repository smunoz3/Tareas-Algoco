#include <deque>
#include <iostream>
#include <string>
 
using namespace std;
int main() {
    int n;
    cin>>n;
    deque<char> final;
    char temp;
    
    for(int i=0;i<n;i++){
        while(cin.get(temp)){
            if(temp=='<'){
                
            }
            else if(temp=='['){
                
            }
            else if(temp==']'){
                
            }
            else{
                final.push_back(temp);
            }
        }
    }

    return 0;
}