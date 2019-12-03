#include <iostream>

#include <conio.h>

#include <fstream>

using namespace std;



struct scan_info {

	char model[25];

	int price;

	double x_size;

	double y_size;

	int optr;

	int grey;

};



int main()

{

	ofstream of("scan.dat");

	char c;

	scan_info s;

	int count = 0;

	do {

		cout << "Enter model: ";

		cin.getline(s.model, 25);

		cout << "Enter price: ";

		cin >> s.price;

		cout << "Enter x and y (size): ";

		cin >> s.x_size;

		cin >> s.y_size;

		cout << "Enter optical resolution: ";

		cin >> s.optr;

		cout << "Enter counts of grey's gradations: ";

		cin >> s.grey;

		of.write((char*)&s, sizeof(scan_info));

		system("cls");

		count++;

		cout << "Do you want to enter data of another scaner?\n";

		cout << "If yes, press space button!\n";

		c = _getch();

		cin.clear();

		cin.ignore(1);

		system("cls");

	} while (c == 32);

	of.close();

	scan_info* m = new scan_info[count];



	ifstream out("scan.dat");

	for (int i = 0; i < count; ++i) {

		out.read((char*)&m[i], sizeof(scan_info));

	}

	out.close();



	ofstream in("scan.dat");

	in << count;

	for (int i = 0; i < count; ++i) {

		in.write((char*)&m[i], sizeof(scan_info));

	}

	in.close();



	ifstream output("scan.dat");

	output >> count;

	for (int i = 0; i < count; ++i) {

		output.read((char*)&m[i], sizeof(scan_info));

	}

	int cur;

	cout << "Which scaner would you prefer to see?\n";

	do {

		cin >> cur;

	} while (cur <= 0 || cur > count);

	system("cls");

	cout << "Scaner " << cur << ": \n";

	cout << "Model: " << m[cur - 1].model << endl;

	cout << "Price: " << m[cur - 1].price << endl;

	cout << "Size: " << "x = " << m[cur - 1].x_size << "; " << "y = " << m[cur - 1].y_size << endl;

	cout << "Optical resolution: " << m[cur - 1].optr << endl;

	cout << "Grey's gradation: " << m[cur - 1].grey << endl;

	output.close();

	return 0;

}