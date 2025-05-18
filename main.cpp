#include <iostream>
using namespace std;
#include <string.h> 
#include "list.h" 
#include <string> 


int main()
{
    cout << "\n Spisok \n";
    MyList<Znak> list;
    for (Znak x: gr)list.addEnd(x);
    cout << list << "\n";
}
