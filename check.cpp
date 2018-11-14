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



void Check::interface()
{   
    vector<Check> book;

    Check Blank(0, 0, "Balance");
    book.push_back(Blank);


    int day_limit = 30;
    int current_day = 0;

    bool entry_mode = 1;

    
    do{
      for(int i = 1; i <= day_limit;i)
      {

        cout << "------------------------" << endl;

        current_day = i;
        cout << "Current day: " << current_day << endl;
   
   
         cout << "1. Deposit" << endl
              << "2. Withdrawl" << endl
              << "3. View Balance"<< endl 
              << "4. View Statement" << endl << endl
              << "enter to increment day" << endl
              << "q to quit" << endl
              << "-------------------------" << endl;
       
     string a;
     getline(cin, a);

      if(a == "q" || i == 30)
       {
            double apr = 0.005;
            double interest = (book[0].get_amount() * apr);
           
            cout << "Final Balance: " << book[0].get_amount() << "." << endl;
            cout << "Monthly interest accrued: $" << interest << endl << endl;

            entry_mode = 0;
            i = 31;

       }else if(a == "1")
       {
            cout << "Enter amount: ";
            double deposit;
            cin >> deposit;
            
            string remainder;
            getline(cin, remainder);

            Check Deposit(current_day, deposit, "Deposit");
            book.push_back(Deposit);
           
            book[0].set_amount(book[0].get_amount() + deposit);

           
       } else if(a == "2")
       {
           cout << "Enter amount: ";
           double withdrawl;
           cin >> withdrawl;
         
           string remainder;
           getline(cin, remainder);


           Check Withdrawl(current_day, (withdrawl * -1), "Withdrawl");
           book.push_back(Withdrawl);
           
           book[0].set_amount(book[0].get_amount() + (withdrawl * -1));

       } else if(a == "3")
       {
           double balance;
         
           cout << endl;

           balance = book[0].get_amount();
           cout << "Balance: " << balance << endl;

       }else if(a == "4")
       {
           cout << endl;

           for(int b = 1; b<book.size() ; b++)
           {
                book[b].print();
           }

           cout << endl;
       
       }else 
       {
            i++;
       }
        
    }
    

    }while(entry_mode);
    

}





