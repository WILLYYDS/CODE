#include <iostream>
using namespace std;
#include "Coins.h"
const int CENT_FOR_CHIPS = 68;
const int DEPOSIT = 205;


int main()
{
	Coins pocket( 5, 3, 6, 8 );
	Coins piggyBank( 50, 50, 50, 50);

	Coins buy_Chips =
		pocket.extract_exact_change( coins_required_for_cents(CENT_FOR_CHIPS) );
	
	cout << " Bought Chips " << endl;
	cout << " Pocket: " ;
	pocket.print(cout);
	
	
	Coins extract_bank =
		piggyBank.extract_exact_change(coins_required_for_cents(DEPOSIT));
	Coins De = coins_required_for_cents(DEPOSIT);
		pocket.deposit_coins(De);
	

	cout << " Transfer Money to Pocket " << endl;
	cout << " Pocket: " ;
	pocket.print(cout);
	cout << " Piggy Bank: " ;
	extract_bank.print(cout);


	cout << " Vacuuming Change " << endl;
	Coins sofa_change( 10, 10, 10, 10);
	piggyBank.deposit_coins(sofa_change);
	double pk = piggyBank.total_value_in_cents()/100.0;
	cout << " Piggy Bank: ";
	cout << "$" << pk;

}