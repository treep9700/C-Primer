#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool find_word(string &s, string &s1){           //一定要搞清楚find_first_of的含义 
	if(s.find_first_of(s1) != string::npos){   // 该单词不符合规则 
		return false;
	}
	    	
	return true;
}

void print_word(fstream &f) {
	string ascender = "bdfghjklpqty";
	string right_word;
	
	for(string str; f >> str; ) {      //从文件中挨个读入单词 
		if(find_word(str, ascender)) {     //如果有符合规则的单词 
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
