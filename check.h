#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Check
{
    public:
    Check();

    
    Check(int num, double amnt, string id);

    double get_amount();
    void set_amount(double amnt);

    void print();

    void interface();

    private:
    int day;
    double amount;
    string id;

};

#endif
