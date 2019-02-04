#include <bits/stdc++.h>
using namespace std;

class LZW
{
	ifstream dict, text;
	map<string, int> encodeDict;
	map<int, string> decodeDict;
public:
	LZW(){
		dict.open("dictionary.txt");
	}

	void readDictionary(){
		encodeDict.clear();
		decodeDict.clear();
		char ch, c;
		int code;
		while(dict >> ch >> noskipws){
			dict >> c >> code;
			dict >> c;
			cout<< ch << code <<endl;
			string str;
			str += ch;
			encodeDict[str] = code;
			decodeDict[code] = str;
		}
	}

	void encode(){
		text.open("textFile.txt");
		ofstream compressed;
		compressed.open("compressed.txt");

		int code = encodeDict.size();
		char c;
		string s;
		text >> c >> noskipws;
		s = c;
		while(text >> c ){
			string tmp = s + c;
	        if(encodeDict[tmp] != 0) 
	        	s = tmp;
	        else{
	        	//cout<< c << " " <<code << " " << s << " " << encodeDict[s]<<endl;

	            compressed << encodeDict[s]<<" ";
	            encodeDict[tmp] = ++code;
	            //cout << code <<" " << encodeDict[s]<<endl;
	            s = "";
	            s += c;

			}
		} 
		compressed << encodeDict[s] << endl;

		compressed.close();
	}

	void decode(){
		ifstream compressed;
		ofstream decompressed;
		compressed.open("compressed.txt");
		decompressed.open("decompressed.txt");

		int code = decodeDict.size(), k;
		string s = "";

		while(compressed >> k){
			string entry = decodeDict[k];
			decompressed << entry;
			 if(s != ""){
			 	decodeDict[++code] = s + entry[0];
			 }
			 s = entry;
		}

		compressed.close();
		decompressed.close();
	}
	
	~LZW(){
		dict.close();
	}
};

int main(int argc, char const *argv[])
{
	LZW lz;
	lz.readDictionary();
	lz.encode();
	lz.decode();
	return 0;
}
