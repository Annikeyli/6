#include <iostream>
#include <fstream>
#include <ios>
#include <stdio.h>
#include <string.h>
#include "zodiak.h"
using namespace std;

const int k = 3;
class Znak { 

public: 

    char surname[20] = { '\0' };
    char name[20] = { '\0' };
    Zodiak zodiak = Zodiak::Aries;
    int data[k];
    Znak();
    Znak(const char* n, const char* s, Zodiak z, int day, int month, int year);
    Znak(Znak& m);
    bool operator<(Znak& z);
    static bool compZodiak(Znak& z, Znak& z1);
    friend ostream& operator<<(ostream& os, const Znak& m);
    friend istream& operator>>(istream& is, Znak& m);
};
