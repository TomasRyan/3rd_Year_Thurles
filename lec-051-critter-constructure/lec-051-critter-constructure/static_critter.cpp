//Static Critter
//Demonstrates static member variables and functions
#include "Static_header.h"

int main()
{
    cout << "The total number of critters is: ";
    cout << Critter::s_Total << "\n\n";
     
    Critter crit1, crit2, crit3, steve(9), bob(12), jacob(123);
      
    cout << "\nThe total number of critters is: ";
    cout << crit1.GetTotal() << "\n";
    
    return 0;
}