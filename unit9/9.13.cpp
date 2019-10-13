#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template <class T1, class T2>
T1 find(T1 a, T1 b, T2 c){
	while(a!=b){
		if(c==*a){
			cout << "have find" << endl;
			return a;
		}
		a++;
	}
	
	cout << "not find" << endl;
	return --b;
}

int main(){
	
	/*** ²âÊÔvector **/ 
	//int c = 12;
	vector<int> v;
	for(int i = 0; i<10; i++){
		v.push_back(i);
	}
	
	vector<int>::iterator iter = v.begin();
	cout << *(find(iter,v.end(),12));
	
	/** ²âÊÔdeque **/ 
//	deque<int> d;
//	for(int i = 0; i<10; i++){
//		d.push_back(i);
//	}
//	
//	deque<int>::iterator diter = d.begin();
//	find(diter,d.end(),41);
	return 0;
} 
