#include <iostream>
using namespace std;
 
 double knots_to_mile_per_minute(int knot)
 {
 
   double knot_to_mile  = (knot * 6076.0) / 5280.0; //knot to mile then mile per minute 
   double mile_per_minute = knot_to_mile / 60.0;
   return mile_per_minute;
  
  }
  int main()
  {
      int knot;
      cout << " Inter the value " << endl;
      cin >> knot;
      double mile_per_minute = knots_to_mile_per_minute(knot);
      cout << mile_per_minute << endl;
      return 0;
  
 }
