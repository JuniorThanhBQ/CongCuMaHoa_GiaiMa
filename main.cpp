#include <iostream>
#include <string>
using namespace std;

int SolveX(int &x1, int x2) {
	int output = x1 % x2;
	x1 = x2;
	return output;
}
int SolveY(int x1, int x2) {
	return x1 / x2;
}
int SolveB(int &b2, int &b3, int y) {
	int output = b2 - (b3 * y);
	b2 = b3;
	return output;
}
int SolveEuclide(int x, int a) {
	int b = 1, b2 = 0, y = 0;

	while (a > 1){
		y = SolveY(x, a);
		b = SolveB(b2, b, y);
		a = SolveX(x, a);
	}

	if (b < 0)
		b = (b + 26) % 26;
	return b;
}
int AffineDecoding_Encoding(int x, int k1, int k2, bool type) {
	int output = 0;
	if (type) {
		output = SolveEuclide(26, k1) * (x - k2) % 26;

		if (output >= 0)
			return output;

		return 26 + output;
	}
	else
		return (k1 * x + k2) % 26;
}
string SolveAffine() {
	int k1, k2;
	bool decoding = true;
	string word = "";

	cout << "Input word: ";
	getline(cin, word);
	cout << "\nType of Affine (0 for decoding, 1 for encoding), k1, k2: ";
	cin >> decoding >> k1 >> k2;

	string output = "";
	for (int i = 0; i < word.size(); i++) {
		if (word[i] != ' ')
			output += char(AffineDecoding_Encoding(word[i] - 65, k1, k2, decoding) + 65);
		else
			output += ' ';
	}


	return output;
}

int mod(int a, int m) {
	return (a % m + m) % m;
}

string CeasarDecoding_Encoding(string x, int k, bool type) {
	string output = "";
	for (int i = 0; i < x.size(); i++) {
		if(type)
			output += mod((int(x[i]) - 65 - k), 26) + 65;
		else
			output += mod((int(x[i]) - 65 + k), 26) + 65;
	}
	return output;
}
string SolveCeasar() {
	int k = 0;
	bool decoding = true;
	string word = "";

	cout << "Input word: ";
	cin.ignore();
	getline(cin, word);
	cout << "\nType of Ceasar (0 for decoding, 1 for encoding) and k: ";
	cin >> decoding >> k;

	return CeasarDecoding_Encoding(word, k, decoding);
}

string VigenereDecoding_Encoding(string x, string k, bool type) {
	string output = "";
	int countCurrentK = 0;

	for (int i = 0; i < x.size(); i++) {
		if(type)
			output += mod((int(x[i]) - int(k[countCurrentK++]) - 65 * 2), 26) + 65;
		else
			output += mod((int(x[i]) + int(k[countCurrentK++]) - 65 * 2), 26) + 65;

		if (countCurrentK >= k.size())
			countCurrentK = 0;
	}
	return output;
}
string SolveVigenere() {
	string k = "", word = "";
	bool decoding = true;

	cout << "Input word: ";
	cin.ignore();
	getline(cin, word);

	cout << "\nType of Vigenere (0 for decoding, 1 for encoding) and k: ";
	cin >> decoding;
	cin.ignore();
	getline(cin, k);

	return VigenereDecoding_Encoding(word, k, decoding);
}

/*void Initialize_PlayFairTable(string k, int(&arr)[50][50]) {
	
}

string PlayfairDecoding(string x, int arr[50][50]) {
	string output = "";

	return output + "\0";
}
string PlayfairEncoding(string x, int arr[50][50]) {
	string output = "";
	
	return output + "\0";
}

string SolvePlayFair() {
	string k = "";
	bool decoding = true;
	string word = "";

	cout << "Input word: ";
	cin.ignore();
	getline(cin, word);
	cout << "\nType of Playfair (1 for decoding, 0 for encoding) and k: ";
	cin >> decoding;
	cin.ignore();
	getline(cin, k);

	int arr[50][50];
	Initialize_PlayFairTable(k, arr);

	if (decoding) {
		word = PlayfairDecoding(word, arr);
	}
	else {
		word = PlayfairEncoding(word, arr);
	}
	return word;
}


*/


const string listTemlate = "\
=========== Menu tool ==========\n\
1. Ceasar tool\n\
2. Vigenere tool\n\
3. Playfair tool\n\
4. Affair tool\n\
5. Ecluid tool\n\
6. Hill tool\n\
7. Diffie-Hellman\n\
0. Exit \n\
================================\n\
";

void ToolsMenu() {
	char selection = -1;
	while (selection != '0') {
		cout << listTemlate << endl;
		cout << "Input your choice [0-7]: "; cin >> selection;
		switch (selection)
		{
			case '1':
			{
				cout << SolveCeasar() << endl;
				break;
			}
			case '2':
			{
				cout << SolveVigenere() << endl;
				break;
			}
			case '3':
			{
				cout << "Not available" << endl;
				break;
			}
			case '4':
			{
				cout << SolveAffine() << endl;
				break;
			}
			case '5':
			{
				int x = 0, a = 0;
				cout << "Input x, a: "; cin >> x >> a;
				cout << SolveEuclide(x,a)<< endl;
				break;
			}
			case '6':
			{
				cout << "Not available" << endl;
				break;
			}
			case '7':
			{
				cout << "Not available" << endl;
				break;
			}
			default:
				if(selection != '0')
					cout << "Input is invalid!" << endl;
		}
	}
}

int main() {
	ToolsMenu();
	system("pause");
	return 1;
}