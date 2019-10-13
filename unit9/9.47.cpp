#include <iostream>
#include <string>

using namespace std;

int main(){
	string s1 = "ab2c3d7R4E6";
	//string number1 = "123456789";
	string number1 = "y";
	string number2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string::size_type pos = 0;

	while((pos = s1.find_first_of(number1, pos)) != string::npos) {   //理解find_first_of()函数的作用 
		cout << "found number at index: " << pos << "element is " << s1[pos] << endl;
		++pos;
	}
	cout << endl;
	
	pos = 0;
	while((pos = s1.find_first_not_of(number1, pos)) != string::npos) {   //理解find_first_of()函数的作用 
		cout << "found number at index: " << pos << "element is " << s1[pos] << endl;
		++pos;
	}

	return 0;
}
