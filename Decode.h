#include <iostream>
#include <fstream>
using namespace std;

//UPDATED 4/28/2014!!!!
class Decode{
private:
	int check;
public:
	ofstream output;
	int counter;
	void Decoding(string code, int length, string decoded, int times){
		//checks to see if Invalid exists in the decoded string
		//if it exists then the code does not execute and will just output “Invalid Morse Code”
		string decodedtemp = decoded;
		string tempcode = code;
		times++;
		counter++;
		if(length > 1){
			//checks to see how large the length is and does the corresponding code set
			if(length > 5){
				for(int u = 0; u < 5; u++){
					tempcode = code.substr(0,u+1);
					decodedtemp = decoded + Morse(tempcode);
					if((u+1) == 5 && code.length() != 5) counter--;
					Decoding(code.substr(u+1), code.length() - tempcode.length(), decodedtemp, times);
				}
			}
			else{
				for(int u = 0; u < length; u++){
					tempcode = code.substr(0,u+1);
					decodedtemp = decoded + Morse(tempcode);
					if((u+1) < length) Decoding(code.substr(u+1), code.length() - tempcode.length(), decodedtemp, times);
				}
			}
		}
		else{
			tempcode = code.substr(0,1);
			decodedtemp = decoded + Morse(tempcode);
		}
		
		size_t exist = decodedtemp.find("Invalid");
		if(exist == string::npos) {
			if(check != 5 && decodedtemp.length() == 1);
			else output << decodedtemp << endl;
		}
	}
	string Morse(string code){
		//here we will try and find the corresponding letter from the given morse code
		//I was having some problems with 
		if(code.at(0) == 'O'){
			if(code.length() == 1) return "E";
			else{
				code = code.substr(1);
				if(code.at(0) == 'O'){
					if(code.length() == 1) return "I";
					else{
						code = code.substr(1);
						if(code.at(0) == 'O'){
							if(code.length() == 1) return "S";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "H";
									else{
										code = code.substr(1);
										if(code.at(0) == 'O') return "5";
										else if(code.at(0) == 'A') return "4";
									}
								}
								else if(code.at(0) == 'A'){
									if(code.length() == 1) return "V";
									else{
										code = code.substr(1);
										if(code.at(0) == 'A') return "3";
									}
								}
							}
						}
						else if(code.at(0) == 'A'){
							if(code.length() == 1) return "U";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "F";
								}
								else if(code.at(0) == 'A'){
									if(code.length() == 1) return "Invalid";
									else{
										code = code.substr(1);
										if(code.at(0) == 'A') return "2";
									}
								}
							}
						}
					}
				}
				else if(code.at(0) == 'A'){
					if(code.length() == 1) return "A";
					else{
						code = code.substr(1);
						if(code.at(0) == 'O'){
							if(code.length() == 1) return "R";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "L";
								}
							}
						}
						else if(code.at(0) == 'A'){
							if(code.length() == 1) return "W";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "P";
								}
								else if(code.at(0) == 'A'){
									if(code.length() == 1) return "J";
									else{
										code = code.substr(1);
										if(code.at(0) == 'A') return "1";
									}
								}
							}
						}
					}
				}
			}
		}
		else if(code.at(0) == 'A'){
			if(code.length() == 1) return "T";
			else{
				code = code.substr(1);
				if(code.at(0) == 'O'){
					if(code.length() == 1) return "N";
					else{
						code = code.substr(1);
						if(code.at(0) == 'O'){
							if(code.length() == 1) return "D";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "B";
									else{
										code = code.substr(1);
										if(code.at(0) == 'O')return "6";
									}
								}
								else if(code.at(0) == 'A'){
									if(code.length() == 1) return "X";
								}
							}
						}
						else if(code.at(0) == 'A'){
							if(code.length() == 1) return "K";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "C";
								}
								else if(code.at(0) == 'A'){
									if(code.length() == 1) return "Y";
								}
							}
						}
					}
				}
				else if(code.at(0) == 'A'){
					if(code.length() == 1) return "M";
					else{
						code = code.substr(1);
						if(code.at(0) == 'O'){
							if(code.length() == 1) return "G";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "Z";
									else{
										code = code.substr(1);
										if(code.at(0) == 'O') return "7";
									}
								}
								else if(code.at(0) == 'A'){
									if(code.length() == 1) return "Q";
								}
							}
						}
						else if(code.at(0) == 'A'){
							if(code.length() == 1) return "O";
							else{
								code = code.substr(1);
								if(code.at(0) == 'O'){
									if(code.length() == 1) return "Invalid";
									else{
										code = code.substr(1);
										if(code.at(0) == 'O') return "8";
									}
								}
								else if(code.at(0) == 'A'){
									if(code.length() == 1) return "Invalid";
									else{
										code = code.substr(1);
										if(code.at(0) == 'O') return "9";
										else if(code.at(0) == 'A') return "0";
									}
								}
							}
						}
					}
				}
			}
		}
		return "Invalid";
	}
	Decode(string name){
		check = name.length();
		output.open(name+".txt");
		counter = 0;
	}
	~Decode(){
		output.close();
	}
};