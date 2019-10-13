#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int main(){
	list<string> l;
	string value;
	list<string>::iterator  
	//string serchvalue("hehao");
	
	while(cin >> value)
		l.push_back(value);
	
	
	list<string>::iterator iter = find(l.begin(), l.end(), "hehao");
	if(iter != l.end())
		l.erase(iter);
		
	return 0;
}
