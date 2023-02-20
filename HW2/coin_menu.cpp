#include <iostream>
#include"Coins.h"
using namespace std;
void menu()
{
	cout << " 1. Deposit " << endl;
	cout << " 2. Pay Bill " << endl;
	cout << " 3. Your balance " << endl;
	cout << " 4. Exit " << endl;
}

int main()
{
	Coins pocket( 0, 0, 0, 0);
	int number;
	int q = 0;
	int d = 0;
	int n = 0;
	int p = 0;
    
 do
  
  {
	menu();
    cin >> number;

    switch(number)
    {
	case 1:// number 1 deposit
    {

    cout << " How Many Quarters? ";
    cin >> q;
    cout<< " How Many Dimes? ";
    cin >> d;
    cout << " How Many Nickels? ";
    cin >> n;
    cout<< " How Many Pennies? ";
    cin >> p;
    Coins deposit( q, d, n, p);
    pocket.deposit_coins(deposit);
	}

    break;

	case 2://number 2 deduct
    {
    cout << " How Many Quarters? ";
    cin >> q;
    cout << " How Many Dimes? ";
    cin >> d;
    cout << " How Many Nickels? ";
    cin >> n;
    cout << " How Many Pennies? ";
    cin >> p;
	Coins extract( q, d, n, p);
    pocket.extract_exact_change(extract);
    }
    
	break;


    case 3: //number 3 print
    {
    double T = pocket.total_value_in_cents();
    cout << "$"<< T/100 << endl;
    }
    
	break;

    case 4: //number 4 option Quit
    exit(0);
    break;

    default:
    cout<<"Invalid input"<<endl;

    }
    }
    while(number!=0);
	
}


