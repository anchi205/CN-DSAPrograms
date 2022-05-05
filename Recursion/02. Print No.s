Print numbers from 1 to n in increasing order recursively.
----------------------------------------------------------

TC:  O(n)
SC:  O(n)

#include<iostream>
using namespace std;

void print(int n){
    if(n == 1){
        cout << n << " ";
        return;
    }
    
    print(n - 1);
    cout << n << " ";
}

int main(){
    int n;
    cin >> n;
  
    print(n);
}
