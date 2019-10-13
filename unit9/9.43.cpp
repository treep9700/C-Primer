#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
void replace_string(string &s, const string &oldVal, const string &newVal) {   //使用引用和const
	auto l = oldVal.size();
	if(!l)
		return;

	auto iter = s.begin();

	while(iter <= s.end() - l) {           //迭代至最后s字符串末尾长度小于l的地方，注意 s.end()指向结尾元素的下一个位置 
	                                       //bug: iter != s.end() - l, 因为后面执行 iter += newVal.size()后跳不出循环 
	auto iter1 = iter;
	auto iter2 = oldVal.begin();

	while(*iter1 == *iter2 && iter2 != oldVal.end() ){       //从s.begin()位置开始查找oldVal，注意不要存储容器的 end() 迭代器，容易失效 
		iter1++;
		iter2++;
	}

//	if(iter2 == oldVal.end()){                         //在s中找到了oldVal
//		iter = s.erase(iter, iter1);             //删除 两个迭代器 之间的元素，即oldVal的值 
//		if(newVal.size()) {                      //将string 类比为 vector<char> 
//			iter2 = newVal.end();
//			do {
//				iter2--;
//				iter = s.insert(iter, *iter2);     //insert用法 1. 若想通过迭代器插入，只能一个字符一个字符的插入 
//			} while (iter2 > newVal.begin());      //           2. 可以通过，整个字符串的插入 
//		}
//        iter += newVal.size();
//	}else iter++;

	if(iter2 == oldVal.end()){                         //在s中找到了oldVal
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
