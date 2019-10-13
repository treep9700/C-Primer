#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
void replace_string(string &s, const string &oldVal, const string &newVal) {   //ʹ�����ú�const
	auto l = oldVal.size();
	if(!l)
		return;

	auto iter = s.begin();

	while(iter <= s.end() - l) {           //���������s�ַ���ĩβ����С��l�ĵط���ע�� s.end()ָ���βԪ�ص���һ��λ�� 
	                                       //bug: iter != s.end() - l, ��Ϊ����ִ�� iter += newVal.size()��������ѭ�� 
	auto iter1 = iter;
	auto iter2 = oldVal.begin();

	while(*iter1 == *iter2 && iter2 != oldVal.end() ){       //��s.begin()λ�ÿ�ʼ����oldVal��ע�ⲻҪ�洢������ end() ������������ʧЧ 
		iter1++;
		iter2++;
	}

//	if(iter2 == oldVal.end()){                         //��s���ҵ���oldVal
//		iter = s.erase(iter, iter1);             //ɾ�� ���������� ֮���Ԫ�أ���oldVal��ֵ 
//		if(newVal.size()) {                      //��string ���Ϊ vector<char> 
//			iter2 = newVal.end();
//			do {
//				iter2--;
//				iter = s.insert(iter, *iter2);     //insert�÷� 1. ����ͨ�����������룬ֻ��һ���ַ�һ���ַ��Ĳ��� 
//			} while (iter2 > newVal.begin());      //           2. ����ͨ���������ַ����Ĳ��� 
//		}
//        iter += newVal.size();
//	}else iter++;

	if(iter2 == oldVal.end()){                         //��s���ҵ���oldVal
		s.replace(iter, iter1, newVal); 
        iter += newVal.size();
	}else iter++;
	
  }
}

int main(){
	string s = "tho thru tho!";
	replace_string(s, "thru", "through"); 
	cout << s << endl;
	
	replace_string(s, "tho", "though");
	cout << s << endl;
	
	replace_string(s, "through", " ");
	cout << s << endl; 

	return 0;
}
