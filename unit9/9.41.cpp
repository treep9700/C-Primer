#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<char> v = {'hello string !!!'};
	
	//const char *v = {"hello string !!!"};
	
	string s(v+6, 5);
	
	return 0;
} 
