#include <iostream>
#include "strarray.h"

/*
	Aufgabe:
	// Folgende Anweisungen sollen möglich gemacht werden:
	// StrArray c("Hallo"), d(" Du");
	
	// cout << c+d+" da!" << endl;
	
	Aufgabe:
	// Realisieren Sie das Abspeichern als einfach verkettete Liste
	//    Ein Listenelement ist ein char und ein Pointer 
	//    auf das nächste Listenelement
*/
using namespace std;

int main()
{
    StrArray a('A'), b=a;

	
    cout << a << " " << a.size() << endl;
    cout << b << " " << b.size() << endl;

    cout << a+b << " <- a+b" << endl;

    for (int x=0; x<5; ++x) {
        a+=a; // als freie Funktion: operator+=(a,a);
              // als Methode: a.operator+=(a);
        cout << x << ". " << a << " " << a.size() << endl;
    }

    b=a;   //
    a=a;

    cout << "b: " << b << endl;
    return 0;
}
