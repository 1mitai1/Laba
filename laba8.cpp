#include <iostream>
#include <fstream>
#include <string>

#include "Exception.h"
#include "File.h"
#include "Toy.h"

using namespace std;



int main()
{
    Toy u1("Sponge", 1, 15,5);
    Toy u2("Max", 10, 20, 10);
    Toy u3("Iasda", 89, 35, 0);
    Toy u4("Vad", 2, 23, 1);
    Toy flg[4] = { u1,u2,u3,u4 };
    File f1("1.txt", txt);
    f1.open("w");
    f1.set_size(4);
    f1 << u1;
    f1 << u2;
    f1 << u3;
    f1 << u4;
    f1.close();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n\n";
    File f2("2.txt", bin);
    f2.open("w");
    f2.set_size(4);
    f2 << u1;
    f2 << u2;
    f2 << u3;
    f2 << u4;
    f2.close();
    f2.open("r");
    cout << f2;
    f2.close();
    cout << "\n\n";
    File f3("3.bin", bin);
    f3.open("w");
    f3.set_size(4);
    f3 << u1;
    f3 << u2;
    f3 << u3;
    f3 << u4;
    f3.close();
    f3.open("r");
    cout << f3;
    f3.close();
    cout << "\n\n";

    cout << "Sort by name:" << endl;
    f1.bubble_sort_name();
    f1.open("r");
    cout << f1;
    f1.close();

    cout << "Sort by amount:" << endl;
    f1.bubble_sort_amount();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "Sort by price :" << endl;
    f1.bubble_sort_price();
    f1.open("r");
    cout << f1;
    f1.close();


    return 0;
}