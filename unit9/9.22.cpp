#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> iv;
	int v[] = {1, 1, 2, 1};
	iv.assign(v, v + 4);
	int some_val = 1;
	
	vector<int>::iterator iter = iv.begin();
	int org_size = iv.size(), new_ele = 0;
	
	while(iter != (iv.begin() + org_size / 2 + new_ele))
		if(*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
		    //iv.insert(iter, 2 * some_val);        //vector���ݵ�ʱ�����ж������ݣ����·���һ���ڴ棬����д������ɵ�����ʧЧ 
			new_ele++;
			iter += 2;
		} else iter++;
		
	for(iter = iv.begin(); iter != iv.end(); iter++)
		cout << *iter << endl;
		
	return 0;	
}
