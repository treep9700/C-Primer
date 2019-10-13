#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template <class T>
bool find(T a, T b, int c){
	while(a!=b){
		if(c==*a){
			cout << "have find" << endl;
			return true;
		}
		a++;
	}
	
	cout << "not find" << endl;
	return false;
}

int main(){
	
	/*** ≤‚ ‘vector **/ 
	vector<int> v;
	for(int i = 0; i<10; i++){
		v.push_back(i);
	}
	
	vector<int>::iterator iter = v.begin();
	find(iter,v.end(),41);
	
	/** ≤‚ ‘deque **/ 
	deque<int> d;
	for(int i = 0; i<10; i++){
		d.push_back(i);
	}
	
	deque<int>::iterator diter = d.begin();
	find(diter,d.end(),41);
	return 0;
} 
