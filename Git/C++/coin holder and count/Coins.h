#ifndef __COINS_H__
#define __COINS_H__

#include <iostream>


const int CENTS_PRE_QUARTER = 25, CENT_PRE_DIME = 10, CENT_PER_NIKEL = 5;
class Coins
{
	public:
	Coins( int q, int d, int n, int p )
	{
		quarters = q;
		dimes = d;
		nickels = n;
		pennies = p;
	}

	void deposit_coins ( Coins & c )
	{
		quarters += c.quarters;
		dimes += c.dimes;
		nickels += c.nickels;
		pennies += c.pennies;

		c.quarters = 0;
		c.dimes = 0;
		c.nickels = 0;
		c. pennies = 0;
	}

	bool has_exact_change_for_coins( Coins c )
	{
		if( quarters >= c.quarters && dimes >= c.dimes && nickels >= c.nickels && this -> pennies)
		{
			return true;
		}
		else return false;

	}

	Coins extract_exact_change( Coins c )
	{
		if(!has_exact_change_for_coins(c))
		{
			std::cout << " ERROR: Insufficient Funds " << std::endl;
			return Coins ( 0, 0, 0, 0);
		}
		else
		{
			quarters -= c.quarters;
			dimes -= c.dimes;
			nickels -=  c.nickels;
			pennies -= c.pennies;

			return *this;
		}
	}

	int total_value_in_cents()
	{
		int total_value = 0;
		total_value = (quarters * CENTS_PRE_QUARTER) + (dimes * CENT_PRE_DIME) + (nickels * CENT_PER_NIKEL) + pennies;
		return total_value;
	}

	void print( std::ostream & out )
	{
		out << quarters << " quarters, " << dimes << " dimes, " << nickels <<
          " nickels, " << pennies << " pennies" << std::endl;
        out << std::endl;
	}


	private:
	int quarters, dimes, nickels, pennies;
};

std::ostream & operator << ( std::ostream & out, Coins c)
{
	c.print(out);
	return out;
}

Coins coins_required_for_cents(int amout_in_cents)
{
	int q = amout_in_cents / 25;
	amout_in_cents %= 25;
	int d = amout_in_cents / 10;
	amout_in_cents %= 10;
	int n = amout_in_cents / 5;
	amout_in_cents %= 5;
	int p = amout_in_cents;
	return Coins ( q, d, n, p );

}


#endif