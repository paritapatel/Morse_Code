#include <iostream>
#include <string>
#include "Decode.h"
using namespace std;

void main(){
	string sequence;

	cout << "Enter your Morse Code sequence: ";
	cin >> sequence;
	cout << endl;

	Decode decoder(sequence);

	decoder.Decoding(sequence,sequence.length(),"",0);

	decoder.output << decoder.counter << endl;
}