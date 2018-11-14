/*
File: Banker
Email: herreram81266@student.vvc.edu
Date: Tue Nov 13 18:29:09 PST 2018
Description: Basically an ATM.
Developer: Matthew Herrera
*/

#include <iostream>
#include <string>
#include <vector>


#include "check.h"


using namespace std;


void interface()
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






int main()
{

    interface();


    return 0;


}

