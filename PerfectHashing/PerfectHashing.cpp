#include <iostream>
#include<map>
#include"Rational.h"
#define SIZE 10
using namespace std;
void Create_HashTable() {
		for (int i = 0; i < SIZE; ++i) {
			int n = rand() % 100;
			int d = rand() % 10000 + 10;

			Rational r(n, d);
			int hash = r.hash();


			cout << r.getnumerator() << "/" << r.getdivisor() << "  " << hash << endl;
		}
	}

int main()
{
	Create_HashTable();
}

