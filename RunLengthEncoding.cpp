#include <bits/stdc++.h>
using namespace std;

class RunLengthEncoding
{
public:
	void encode(){
		ifstream textFile;
		ofstream compressed;
		textFile.open("rleInput.txt");
		compressed.open("rleCompressed.txt");
		char ch1, ch2;
		textFile >> ch1 >> noskipws;
		int i = 1;
		while(textFile >> ch2 >> noskipws){
			if(ch2==ch1)
				i++;
			else{
				compressed << int(ch1) << " " << i << " " ;
				i = 1;
			}
			ch1 = ch2;
		}
		compressed << int(ch2) << " " << i ;

		textFile.close();
		compressed.close();
	}

	void decode(){
		ifstream compressed;
		ofstream decompressed;

		compressed.open("rleCompressed.txt");
		decompressed.open("rleDecompressed.txt");

		int i, j;
		while(compressed >> i >> j){
			char ch = i;
			for(int k = 0; k < j; k++){
				decompressed << ch;
			}
		}

		compressed.close();
		decompressed.close();
	}
};

int main(int argc, char const *argv[])
{
	RunLengthEncoding rle;
	rle.encode();
	rle.decode();
	return 0;
}