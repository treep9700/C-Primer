#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void add_family(map<string, vector<string>> &families, const string &family) {
	if (families.find(family) == families.end() )
		families[family] = vector<string> ();
} 

void add_child(map<string, vector<string>> &families, const string &family, const string &child) {
		families[family].push_back(child);
} 

int main() {
	map<string, vector<string>> families;
	
	add_family(families, "��"); 
	add_child(families, "��", "ǿ"); 
	add_child(families, "��", "��"); 
//    string surname;
//    string familyname;
//    vector<string> v;
//    
//    while (cin >> surname ) {
//    	while( cin >> familyname)
//    		v.push_back(familyname);
//    	m[surname] = v;
//	}
//	
//	while (cin >> surname) 
//		cout << m[surname][1] << endl;

    for (auto f: families) {
    	cout << f.first << "�ҵĺ��ӣ�";
		for (auto c : f.second)
			cout << c << " ";
		cout << endl; 
	}
	
	return 0;
}
