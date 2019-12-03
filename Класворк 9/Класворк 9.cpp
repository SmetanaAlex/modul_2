#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;
struct Notebook {
	struct disp_res {   //resolution of display
		int x, y;     //horizontal and vertical
	};
	disp_res l;
	int f; //frequancy of regeneration
	float d; //diagonale
	float hdd;  //capacity
	char model[21];  //model
	int price; //price
	double weight;
	double length;
	double width;
	double height;
	int cf;   //cpu frequancy
	int ram;
	int gpu;
};

int main()
{
	ifstream f("note.txt");
	int n = 0;
	char t, t1[1];
	char* r = new char[1000];
	while (!f.eof()) {
		
			f.getline(r, 1000);
			n++;
		
	}
	f.seekg(0, ios::beg);
	Notebook* m = new Notebook[n];
	for (int i = 0; i < n; ++i) {
		f.get(m[i].model, 21);
		/*for (int j = 0; j < 21; ++j) {     //8:40 - 10:10,  thanks a lot
			f.get(m[i].model[j]);
		}
		f.getline(m[i].model, 21);*/
		f >> m[i].price >> m[i].weight >> m[i].height >> t >> m[i].length >> t >> m[i].width >> m[i].cf >> m[i].ram >> m[i].d >> m[i].gpu >> m[i].l.x >> t >> m[i].l.y >> m[i].f >> m[i].hdd;
		cout << ' ' << m[i].model << ' ' << m[i].price << ' ' << setw(3) << m[i].weight << ' ' << setw(3) << m[i].height << '*' << setw(4) << m[i].length << '*' << setw(4) << m[i].width << ' ' << setw(3) << m[i].cf << ' ' << setw(3) << m[i].ram << ' ' << setw(3) << m[i].d << ' ' << setw(3) << m[i].gpu << ' ' << setw(4) << m[i].l.x << '*' << setw(4) << m[i].l.y << ' ' << setw(3) << m[i].f << ' ' << setw(3) << m[i].hdd;
		cout << endl;
		f.getline(t1, 1);
	}
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (m[i].price >= 2500) {
			k++;
		}
	}
	Notebook p;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (m[j].price < m[i].price || (m[j].price == m[i].price && m[j].weight < m[i].weight) || (m[j].price == m[i].price && m[j].weight == m[i].weight && m[j].height * m[j].length * m[j].width < m[i].height * m[i].length * m[i].width)) {
				p = m[i];
				m[i] = m[j];
				m[j] = p;
			}
		}
	}
	ofstream bin("out.bin");
	bin << k;
	for (int i = 0; i < n; ++i) {
		if (m[i].price >= 3500) {
			bin.write((char*)&m[i], sizeof(Notebook));
		}
	}
	f.close();
	bin.close();
	delete[] m;
	return 0;
}

