#include <iostream>
using namespace std;
#include <string.h> 
#include "MyList.h" 
#include <string> 

int main()
{
    MyList<Znak> list;
    cout << "\nSpisok\n";
    
    Znak z1("Ivanov", "Ivan", Zodiak::Aries, 10, 3, 1990);
    Znak z2("Petrov", "Petr", Zodiak::Taurus, 15, 4, 1985);
    Znak z3("Petrova", "Lena", Zodiak::Libra, 10, 10, 2010);
    list.addEnd(z1);
    list.addEnd(z2);
    list.addBegin(z3);

    cout << list << "\n";

    cout << "Is empty? " << (list.IsEmpty() ? "yes" : "no") << "\n";
       
    list.deleteEl(z2);
    cout << "\nAfter delete element\n" << list << "\n";

    list.deleteList();
    cout << "After delete list\n";
    cout << "Is empty? " << (list.IsEmpty() ? "yes" : "no") << "\n";

    return 0;
}
