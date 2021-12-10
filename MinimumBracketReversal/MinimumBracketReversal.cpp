#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"
#include <stack>
int countBracketReversals(string input) {
	stack <char> s;
    int count = 0;
    int i = input.size();
    if(i%2!=0){
        return -1;
    }
    for(int j=0;j<i;j++){
        if(input[j]=='{')
            s.push(input[j]);
        else if(s.empty() && input[j]=='}')
            s.push(input[j]);
        else if(!s.empty() && input[j]=='}')
            if(s.top()=='{')
                s.pop();
            else
                s.push(input[j]);
    }
    while(!s.empty()){
        char c1 = s.top();
        s.pop();
        char c2 = s.top();
        s.pop();
        if(c1==c2)
            count++;
        else
            count+=2;
    }
    return count;
}
int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}