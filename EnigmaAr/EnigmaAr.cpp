#include<iostream>

using namespace std;

const char input[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char R1[26][26] = { {"AE"}, {"BK"},{"CM"},{"DF"},{"EL"},{"FG"},{"GD"},{"HQ"},{"IV"},{"JZ"},{"KN"},{"LT"},{"MO"},{"NW"},{"OY"},{"PH"},{"QX"},{"RU"},{"SS"},{"TP"},{"UA"},{"VI"},{"WB"},{"XR"},{"YC"},{"ZJ"}, };
char R2[26][26] = { {"AA"}, {"BJ"},{"CD"},{"DK"},{"ES"},{"FI"},{"GR"},{"HU"},{"IX"},{"JB"},{"KL"},{"LH"},{"MW"},{"NT"},{"OM"},{"PC"},{"QQ"},{"RG"},{"SZ"},{"TN"},{"UP"},{"VY"},{"WF"},{"XV"},{"YO"},{"ZE"}, };
char R3[26][26] = { {"AB"}, {"BD"},{"CF"},{"DH"},{"EJ"},{"FL"},{"GC"},{"HP"},{"IR"},{"JT"},{"KX"},{"LV"},{"MZ"},{"NN"},{"OY"},{"PE"},{"QI"},{"RW"},{"SG"},{"TA"},{"UK"},{"VM"},{"WU"},{"XS"},{"YQ"},{"ZO"}, };
string stop;

void Forward(char arr[26][26]) {

	char temp[2] = { arr[0][0], arr[0][1] };

	for (size_t i = 0; i < 26; i++)
	{
		arr[i][0] = arr[i + 1][0];
		arr[i][1] = arr[i + 1][1];

	}
	arr[25][0] = temp[0];
	arr[25][1] = temp[1];




}
void Set() {
	for (size_t i = 0; i < 26; i++)
	{
		if (R1[0][0] == 'A') break;
		Forward(R1);
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (R2[0][0] == 'A') break;
		Forward(R2);
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (R3[0][0] == 'A') break;
		Forward(R3);
	}
}

void Show() {
	for (size_t i = 0; i < 26; i++)
	{
		cout << R1[i] << ' ';
	}
	cout << "\n\n";
	for (size_t i = 0; i < 26; i++)
	{
		cout << R2[i] << ' ';

	}
	cout << "\n\n";
	for (size_t i = 0; i < 26; i++)
	{
		cout << R3[i] << ' ';

	}
	cout << "\n";
	cout << "\n";


}
int GetNum(char arr[26][26], char tofind, bool way) {
	if (way) {

		for (size_t i = 0; i < 26; i++) {

			if (arr[i][0] == tofind) {
				return i;
			}
		}
	}
	else {

		for (size_t i = 0; i < 26; i++) {

			if (arr[i][1] == tofind) {
				return i;
			}
		}
	}


	return -1;
}

int FindPair(int a) {

	switch (a) {

	case 0: return 24; break;
	case 1: return 17; break;
	case 2: return 20; break;
	case 3: return 7; break;
	case 4: return 16; break;
	case 5: return 18; break;
	case 6: return 11; break;
	case 7: return 3; break;
	case 8: return 15; break;
	case 9: return 23; break;
	case 10: return 13; break;
	case 11: return 6; break;
	case 12: return 14; break;
	case 13: return 10; break;
	case 14: return 12; break;
	case 15: return 8; break;
	case 16: return 4; break;
	case 17: return 1; break;
	case 18: return 5; break;
	case 19: return 25; break;
	case 20: return 2; break;
	case 21: return 22; break;
	case 22: return 21; break;
	case 23: return 9; break;
	case 24: return 0; break;
	case 25: return 19; break;
	}

}
char Encode(int inp) {

	Forward(R1);
	if (R1[25][0] == 'Q') {
		Forward(R2);
	}

	if (R2[25][0] == 'E') {
		Forward(R3);
	}

	//Show();
	int a = GetNum(R1, R1[inp][1], true);

	a = GetNum(R2, R2[a][1], true);
	a = GetNum(R3, R3[a][1], true);
	a = FindPair(a);
	a = GetNum(R3, R3[a][0], false);
	a = GetNum(R2, R2[a][0], false);
	a = GetNum(R1, R1[a][0], false);
	//cout << input[a];








	return input[a];
}


void RPos(int a, int num) {

	switch (a) {

	case 1:
		for (int i = 0; i < num; i++) {
			Forward(R1);
		}
		break;
	case 2:
		for (int i = 0; i < num; i++) {
			Forward(R2);
		}
		break;
	case 3:
		for (int i = 0; i < num; i++) {
			Forward(R3);
		}
		break;
	}
}

int GetAlNum(char a) {

	for (size_t i = 0; i < 26; i++)
	{
		if (input[i] == a) return i;

	}
}

#include<vector>;
#include <conio.h>
int main() {
	setlocale(LC_ALL, "Russian");

	string msg = "";
	int r1, r2, r3;
	cout << "Установите значение первого ротора: ";
	cin >> r1;
	cout << "\nУстановите значение второго ротора: ";
	cin >> r2;
	cout << "\nУстановите значение третьего ротора: ";
	cin >> r3;

	RPos(1, r1);
	RPos(2, r2);
	RPos(3, r3);

	while (true) {
		system("CLS");
		cout << "Наберите текст: \n";
		cout << msg << "\n";
		char inp = _getch();
		inp = toupper(inp);
		//cin >> inp;
		char temp = Encode(GetAlNum(inp));
		msg += temp;

	}
}