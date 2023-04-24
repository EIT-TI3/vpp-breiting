#include <iostream>
#include "textliste.h"
#include <list>

using namespace std;

int main() {
    /*
    // Einschub zu STL-Container und deren Verwendung;
    list<int> liste1{2, 3, 5, 7, 11, 13};
    
    for (auto wert : liste1)
        cout << wert << endl;

    auto it=liste1.begin();
    while(it != liste1.end()) {
        cout << *it << endl;
        ++it;
    }
    */

    TextListe t1;
    TextListe t2{"He ", "was soll ", "denn das?\n"};
    TextListe t3=t1;

    cout << "Ausgabe von t1:" << endl;
    t1.out(cout);
    t1.push_back("Hallo\n");
    t1.push_back("hier ");
    t1.push_back("da im Radio\n");
    t1.push_back("hä\n");
    cout << "Ausgabe von t1:" << endl;
    t1.out(cout);

    cout << "Ausgabe von t2" << endl;
    t2.out(cout);

    t2 = t1;

    cout << "Ausgabe von t2:" << endl;
    t2.out(cout);

    cout << "Ausgabe von t3:" << endl;
    t3.out(cout);

    return 0;
}
