#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "Wektor.h"
#include "Macierz.h"

using namespace std;

template <class T>

Macierz::macierz()
        {
	        wysokosc = 0;
	        szerokosc = 0;
	        tablica_wektorow = NULL;
        }

Macierz::macierz(int wys, int szer)
        {
	        wysokosc=wys;
	        szerokosc=szer;

	        tablica_wektorow=new wektor<T>[wysokosc];
	        for (int i=0; i<wysokosc; i++) {
		        tablica_wektorow[i].wczytaj("",szerokosc);
	        }
        }

void Macierz::wypisz()
        {
	        for (int i=0; i<wysokosc; i++)
                {
		         tablica_wektorow[i].wypisz();
                }
        }

int Macierz::wysokosc()
        {
	        return wysokosc;
        }

int Macierz::szerokosc()
        {
	        return szerokosc;
        }

T Macierz::element(int n, int m)
        {
	        if ((n>=wysokosc)||(n<0))
		        return NULL;
	        else
		        return tablica_wektorow[n].element(m);
        }

bool Macierz::ustaw_element(int y_pozycja,int x_pozycja,T nowy_element){
	        if ((y_pozycja>=wysokosc)||(y_pozycja<0))
		        return false;

	        return tablica_wektorow[y_pozycja].ustaw_element(x_pozycja, nowy_element);
        }




Macierz::~macierz()
        {
	        delete [] tablica_wektorow;
        }
