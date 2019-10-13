#include <iostream>
#include <list>
#include <vector>
#include <deque>
 
using namespace std;
int main(){
	list<int> l;
	deque<int> d;
	vector<int> v;
		
	int ia[] = {1,2,3,4,4,5,6,6,7,8,9,10,11};
	v.assign(ia, ia+11);
	
    vector<int>::iterator vi = v .begin();
	while(vi != v.end()){ 
	 if ( 0 == *vi % 2){
	 	 cout << *vi << " ";
	 	 cout << *v.erase(vi) << " ";
         cout << *vi << endl;
	 }
      ++vi;
	}	
	
	return 0;
}
