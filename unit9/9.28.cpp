#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void oper(forward_list<string> &f, const string s1, const string s2){     //´´ÒıÓÃ 
	
	auto prev = f.before_begin();
	auto curr = f.begin();
	bool insert_flag = false; 
	
	while(curr != f.end()) {
		if(*curr == s1){
			curr = f.insert_after(curr, s2);
			insert_flag = true;
		}	
		
		prev++;
		curr++;
	}
	
	if(!insert_flag)
		f.insert_after(prev, s2);
	
}


int main(){
	forward_list<string> f = {"one", "two", "three", "four", "five"};
	
	auto iter = f.begin();

	string s1("two");
	string s2("two_three");
	
	oper(f, s1, s2);
	
	iter = f.begin();
	while(iter != f.end()){
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
	
	oper(f, "six", "six");

	iter = f.begin();	
	while(iter != f.end()){
		cout << *iter << " ";
		iter++;
	}
	
	return 0;
}
 
