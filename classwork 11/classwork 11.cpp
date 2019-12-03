#include <iostream>

#include<windows.h>

#include <conio.h>

#include <fstream>

using namespace std;



int main()

{

	cout << "Variant 1\n";

	char m[1000];

	ifstream f("text.txt");

	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);



	char c = 0; int i = 0, j = 0;

	int l = 0;

	while (c != 13) {



		c = _getch();

		system("cls");

		i = 0; l = 0;

		while (!f.eof()) {

			f.getline(m, 1000);

			if (l == 1)

			{

				cout << m << ' ' << endl;

				if (m[strlen(m) - 1] == '.' || m[strlen(m) - 1] == '!' || m[strlen(m) - 1] == '?') {

					i++;

				}

			}

			else {

				if (m[strlen(m) - 1] == '.' || m[strlen(m) - 1] == '!' || m[strlen(m) - 1] == '?') {

					i++;

					if (i == j) {

						cout << " (" << m << ") " << endl;

						l = 1;

					}

					else {

						cout << m << ' ' << endl;



					}

				}

				else

					cout << m << ' ' << endl;

			}

		}

		j++;

		cout << "\nThere are " << i << " sentences.\n";

		if (i < j)

			j = 1;

		f.seekg(0, ios::beg);



	}

	f.close();

	return 0;

}