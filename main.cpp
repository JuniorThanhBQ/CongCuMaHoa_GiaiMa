#include <iostream>
#include <string>
using namespace std;

int SolveX(int &x1, int x2) {
	int ketQua = x1 % x2;
	x1 = x2;
	return ketQua;
}
int SolveY(int x1, int x2) {
	return x1 / x2;
}
int SolveB(int &b2, int &b3, int y) {
	int ketQua = b2 - (b3 * y);
	b2 = b3;
	return ketQua;
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


int AffineMaHoa(int x, int k1, int k2) {
	return (k1 * x + k2) % 26;
}

int AffineGiaiMa(int x, int k1, int k2) {
	int ketQua = SolveEuclide(26, k1) * (x - k2) % 26;
	if (ketQua >= 0)
		return ketQua;
	return 26 + ketQua;
}

string SolveAffine() {
	int k1, k2;
	bool giaiMa = true;
	string word = "";

	cout << "Nhap van ban: ";
	getline(cin, word);
	cout << "\nNhap loai bai toan (giai ma 1, ma hoa 0), k1, k2: ";
	cin >> giaiMa >> k1 >> k2;

	string ketQua = "";
	if (giaiMa) {
		for (int i = 0; i < word.size(); i++) {
			if (word[i] != ' ')
				ketQua += char(AffineGiaiMa(word[i] - 65, k1, k2) + 65);
			else
				ketQua += ' ';
		}
	}
	else {
		for (int i = 0; i < word.size(); i++) {
			if (word[i] != ' ')
				ketQua += char(AffineMaHoa(word[i] - 65, k1, k2) + 65);
			else
				ketQua += ' ';
		}
	}

	return ketQua + "\0";
}

int main() {
	//int x, a;
	//cin >> x >> a;
	//cout << SolveEuclide(x,a) << endl;
	cout << SolveAffine() << endl;
	system("pause");
	return 1;
}