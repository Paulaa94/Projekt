#include <iostream>
#include <string>
#include <sstream>
#include "Macierz.h"

typedef Macierz<int> macierzInt;
typedef Macierz<double> macierzDobule;

using namespace std;

int main() {
	Macierz<int> *A, *B, *C;

    A = new macierzInt();
    B = new macierzInt();
    C = new macierzInt();

	cout <<"Wczytywanie macierzy A z pliku macierz1.txt"<<endl;
	*A >>"../macierz1.txt";
	cout<<"A: " <<endl;
	A->wypisz();

	cout<<"Wczytywanie macierzy B z pliku macierz2.txt"<<endl;
	*B>>"../macierz2.txt";
	cout <<"B: " <<endl;
	B->wypisz();

	cout<<"B+A:" <<endl;
    *C=(*A)+(*B);
	cout<<"C: "<<endl;
	C->wypisz();

	cout <<"B*C:"<<endl;
	*C=(*B)*(*C);
	cout <<"C: "<<endl;
	C->wypisz();

	cout<<"Wczytywanie macierzy A z pliku macierz3.txt"<<endl;
	*A>>"../macierz3.txt";
	cout << "Wypisuje A: " << endl;
	A->wypisz();

	cout<<"Wczytywanie macierzy B z pliku macierz4.txt"<< endl;
	*B >>"../macierz4.txt";
	cout<<"B: " << endl;
	B->wypisz();

	cout<<"A*B: "<<endl;
	*C =(*A)*(*B);
	cout<<"C: " << endl;
	C->wypisz();

    cout<<"Zapis macierzy C do pliku macierzC.txt"<<endl;
    *C << "../macierzC.txt";

    delete A;
    delete B;
    delete C;


    system("pause");
	return 0;
}
