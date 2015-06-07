#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <class T>
class Wektor
{
		int rozmiar;
		T *tablica;

public:

        wektor();
        wektor(int rozm);

		void wczytaj(string string_wejsciowy, int rozm);
        T element(int i);
        bool ustaw_element(int pozycja, T nowy_element);
		void wypisz();
		string zapisz();

	    ~wektor();
};
