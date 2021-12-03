#include <iostream>
using namespace std;

// #include "solution.h"
#include <queue>
void reverseQueue(queue<int> &q) {
    if(q.size()<=1){
        return;
    }
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}
// Time Complexity O(n)
// Space Complexity O(n)    
// n - size of input queue
int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}