#include <iostream>
#include <vector>
using namespace std;

int main() {
	// vector<int> * vp = new vector<int>(); Dynamically -- Delete yourself
	vector<int> v; // statically

	for (int i = 0; i < 100; i++) {
		cout << "cap:" << v.capacity() << endl; // current capacity -- doubles when it exhausts
		cout << "size:" << v.size() << endl;
		v.push_back(i + 1);
	}

	v.push_back(10); // to empty vector
	v.push_back(20); // to 10
	v.push_back(30); // to 20

	v[1] = 100;
    /* 
    v[3] = 1002;
	v[4] = 1234;
    --> push_back func checks current size, if space is available or not, should the size be doubled 
	--> dont use [] for inserting elements -- it won't increase size
	--> use it for getting or updating an element
    */
	v.push_back(23);
	v.push_back(33);
	v.pop_back(); // Deletes last element

	/*
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	cout << v[3] << endl;
	cout << v[4] << endl;
	cout << v[5] << endl;
	cout << v[6] << endl;

	cout << "Size: " << v.size() << endl; --> 5
	cout << v.at(2) << endl; --> 30
	cout << v.at(6) << endl; --> terminating with uncaught exception of type std::out_of_range:vector
    .at() func is safe
	*/
}