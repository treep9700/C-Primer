#include <iostream>
#include <string>

using namespace std;

void add_name(string &s1, const string &s2, const string &s3) {
	s1.insert(s1.begin(), 1, ' ');
	s1.insert(0, s2);
	//s1.insert(s1.begin(), s2.begin(), s2.end());
	
	s1.append(" ");
	//s1.append(s3);   
	s1.insert(s1.size(), s3);
	
} 

int main(){
	string s1 = {"he hao"};
	string s2 = {"Mr."};
	string s3 = {"III"};
	
	add_name(s1, s2, s3);
	
	cout << s1;
	
	return 0;	
} 
