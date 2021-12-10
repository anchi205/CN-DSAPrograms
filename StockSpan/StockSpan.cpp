#include <iostream>
using namespace std;

// #include "solution.h"
#include<stack>
int *stockSpan(int *price, int size) {
    stack<int> s;                              // Create a stack
    int *output = new int[size];               // Create an array
    s.push(0); 
    output[0] = 1;                             // Resultant array's first element is 1 bcuz it won't have any price lower than that 
    
    for(int i = 1; i < size; i++) { 
        while(!s.empty() and price[s.top()] < price[i]) {
            s.pop(); 
    	}
    	if(s.empty()){                         // if stack is empty then we have the best price
            output[i] = i + 1; 
    	} 
        else { 
            output[i] = i - s.top();           // else the span will be difference between the indices
    	}
    	s.push(i);                             // push the current index onto stack
 	} 
    return output;
}
/*
Time complexity: O(N)
Space complexity: O(N)
N - number of days
*/
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
