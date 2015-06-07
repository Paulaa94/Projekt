#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "Wektor.h"

using namespace std;

template <class T>
class Macierz {

	    int szerokosc;
	    int wysokosc;
	    wektor <T>*tablica_wektorow;

public:

        macierz();
        macierz(int wys, int szer);

        Macierz& operator>>(char *sciezka) {
	        ifstream plik = ifstream();
	        string linia = "";
	        istringstream strumien_znakow;

	        plik.open(sciezka);

	        getline(plik, linia);
	        strumien_znakow.str(linia);
	        strumien_znakow>>wysokosc;
	        strumien_znakow>>szerokosc;

	        tablica_wektorow=new wektor<T>[wysokosc];

	        int i = 0;
	        while (i<wysokosc)
            {
		        if (plik.good())
		        {
			        getline(plik, linia);
			        tablica_wektorow[i].wczytaj(linia,szerokosc);
		        } else
		        {
			        tablica_wektorow[i].wczytaj("",szerokosc);
		        }
		        i++;
	        }

	        plik.close();

            return *this;
        }

        void operator<<(char *sciezka)
        {
            ofstream plik = ofstream();
            plik.open(sciezka);

            plik<<wysokosc<<" "<<szerokosc<<endl;
            int i=0;
            for(int i=0; i<wysokosc; i++)
            {
              plik <<tablica_wektorow[i].zapisz()<<endl;
            }
            plik.close();
        }

        void wypisz();

        int wysokosc();
        int szerokosc();

        T element(int n, int m);
        bool ustaw_element(int y_pozycja, int x_pozycja, T nowy_element);

        Macierz& operator+ (Macierz &M) {
	        Macierz *S =new Macierz(this->wysokosc,this->szerokosc);

	        if ((this->wysokosc != M.wysokosc())||(this->szerokosc != M.szerokosc())){
		        cout<<"dodawanie maciarzy o roznych rozmiarach jest niedozwolone"<<endl;

	        }
	        else {
		        for(int n=0; n<this->wysokosc; n++) {
			        for (int m=0; m<this->szerokosc; m++) {
				        S->ustaw_element(n, m, this->element(n, m) + M.element(n, m));
			        }
		        }
	        }

            return *S;
        }

        Macierz& operator* (Macierz &M) {
	        Macierz *I=new macierz(this->wysokosc,M.szerokosc());

	        if (szerokosc!=M.wysokosc()){
		        cout <<"Nie da sie wymnozyc macierzy"<<endl;

	        }
	        else {
		        for(int n=0; n<this->wysokosc; n++) {
			        for(int k=0; k <M.szerokosc(); k++) {
				        T suma=0;
				        for(int m=0; m<this->szerokosc; m++) {
					        suma += element(n, m) * M.element(m, k);
				        }

				        I->ustaw_element(n,k,suma);
			        }
		        }
		        return *I;
	        }
        }

        ~macierz();
};
