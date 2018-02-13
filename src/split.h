#pragma once
//#include <iostream>
//#include <vector>
//#include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;


const std::string delim = "|";

/*split will take input and remove any of the characters from the string 'delim'
when it encounters such a character, it will cut out the string inbetween the
characters and put the substrings into a vector and then return that vector*/

vector<string> split(const string& s, const string& delim) {
	vector<string> v;
	string::size_type pos1, pos2 = 0,pos3;
	string word;
	string::size_type n;
	pos1 = s.find_first_not_of(delim, pos2);
	while (pos1 != string::npos) {
		if ((pos2 = s.find_first_of(delim, pos1+1)) == string::npos) {
			word = s.substr(pos1);
			pos1 = pos2;
		}
		else {
			if( (pos2-pos1) != 1 ){	
				word = s.substr(pos1, pos2 - pos1);
			}else{
				word =" ";
			}
			pos3 = s.find_first_of(delim, pos2+1);
			if( (pos3-pos2) != 1 ){				
				pos1 = s.find_first_not_of(delim, pos2);
			}else {
				
				pos1 = pos2;		
			}
		}
		v.push_back(word);
	}
	return v;
}