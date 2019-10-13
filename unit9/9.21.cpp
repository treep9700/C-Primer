#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<string> v;
	string word;
	vector<string>::iterator iter = v.begin();
	while(cin >> word)
	iter = v.insert(iter, word);
	
	for( ; iter != v.end(); iter++){
		cout << *iter << endl; 
	}
	
	return 0;
}
