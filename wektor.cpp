#include <iostream>
#include <sstream>
#include <string>
#include "Wektor.h"

using namespace std;

template <class T>

Wektor::wektor(){
	        rozmiar = 0;
	        tablica = NULL;
        }

Wektor::wektor(int rozm)
        {
	        rozmiar = rozm;
	        tablica = new T[rozmiar];
        }

void Wektor::wczytaj(string string_wejsciowy, int rozm)
            {

	         rozmiar = rozm;
	         tablica = new T[rozmiar];

	        istringstream strumien_znakow(string_wejsciowy);

	        for(int i = 0; i < rozm; i++)
                {
		        strumien_znakow>>tablica[i];

		        if(strumien_znakow.fail() && !strumien_znakow.eof())
                    {
			        cout<<"Blad rzutowania na typ <T>"<<endl;

		            }

		        if (strumien_znakow.fail() && strumien_znakow.eof())
                    {
			         tablica[i] = 0;
		            }
	        }
        }


T Wektor::element(int i)
        {
	        if (i>=rozmiar)
		        return NULL;

	        return tablica[i];
        }

bool Wektor::ustaw_element(int pozycja, T nowy_element)
        {
	        if ((pozycja<0)||(pozycja>=rozmiar))
		        return false;
	        else {
		        tablica[pozycja]=nowy_element;
		        return true;
	        }
        }

void Wektor::wypisz(){
	        for (int i=0; i<rozmiar; i++) {
                cout<<tablica[i]<< " ";
	        }
            cout << endl;
        }

string Wektor::zapisz() {
            string n = "";
            ostringstream convert;

	        for (int i=0; i<rozmiar; i++) {
                convert<<tablica[i]<<" ";
                n=convert.str();
	        }
            return n;
        }

Wektor::~wektor()
        {
            delete [] tablica;
        }

