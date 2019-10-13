#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s1;
	vector<string> v(5);
	vector<string>::iterator iter;
	iter = v.begin();
	
	while(cin >> s1){
		*iter = s1;
		iter++;
	}

	iter = v.begin();
	while(iter != v.end()){
		cout << *iter << " "; 
		iter++;
	}
		
	
	return 0;
}
