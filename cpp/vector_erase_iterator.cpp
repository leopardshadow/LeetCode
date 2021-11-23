#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vec;
	for(int i = 0; i < 5; i++)
		vec.push_back(i);
	vector<int>::iterator it = vec.begin() + 2;
	cout << *it << endl;

	vec.erase(it);
	cout << *it << endl;

	it--;
	cout << *it << endl;

	return 0;
}
