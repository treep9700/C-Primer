#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool find_word(string &s, string &s1){           //һ��Ҫ�����find_first_of�ĺ��� 
	if(s.find_first_of(s1) != string::npos){   // �õ��ʲ����Ϲ��� 
		return false;
	}
	    	
	return true;
}

void print_word(fstream &f) {
	string ascender = "bdfghjklpqty";
	string right_word;
	
	for(string str; f >> str; ) {      //���ļ��а������뵥�� 
		if(find_word(str, ascender)) {     //����з��Ϲ���ĵ��� 
		    cout << "str: " << str << "     " << "right_word:  " << right_word << endl;
			if(str.size() > right_word.size())
				right_word = str;
		} 
	}
		
	cout << right_word;
}

int main(){
	fstream f;
	f.open("word.txt");
	
	print_word(f);
	
	return 0;
} 
