#include <iostream>
#include <string>
#include <vector>

#include "check.h"

using namespace std;

Check::Check()
{
   day = 0;
   amount = 0;
   id = "";
}

Check::Check(int num, double amnt, string _id)
{
    day = num;
    amount = amnt;
    id = _id;
}

double Check::get_amount()
{
    return amount;
}

void Check::set_amount(double amnt)
{
    amount = amnt;
}

void Check::print()
{
    cout << day << " , " << amount << " , " << id << " ." << endl;
}




