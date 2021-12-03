#include <iostream>
#include <stack>
using namespace std;

// #include "solution.h"
void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()<=1){
        return;
    }
    int lastElement = input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){        // smaller part copied to extra
        int top = input.top();
        input.pop();
        extra.push(top);
    }
    
    input.push(lastElement);     // adding the topmost element into stack
    
    while(!extra.empty()){       // copying back to input
        int top = extra.top();
        extra.pop();
        input.push(top);
    }
}
/* Time Complexity: O(N^2)
   Space Complexity: O(N)
   N - size of input stack
*/
int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}