#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
	deque<string> d;
	string value;
	while(cin >> value){
		d.push_back(value);
	}
	
	deque<string>::iterator iter = d.begin();
	while(iter != d.end()){
		cout << *iter << " ";
	    iter++;
	}
	
	return 0; 
}
