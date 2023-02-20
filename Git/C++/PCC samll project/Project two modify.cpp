#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
void order_pizza(double &sum)
{
    cout<<"Pizza Size(inches)     Cost"<<endl;
    cout<<"        10            $10.99"<<endl;
    cout<<"        12            $12.99"<<endl;
    cout<<"        14            $14.99"<<endl;
    cout<<"        16            $16.99 "<<endl;
    cout<<"What size pizza would you like?";
    cout<<"10, 12, 14, or 16 (enter the number only):";
    int number;
    cin>>number;
    if(number==10)sum+=10.99;
    else if(number==12)sum+=12.99;
    else if(number==14)sum+=14.99;
    else if(number==16)sum+=16.99;
    else 
    {
            cout<<"Input was not one of the choices, so a 12-inch pizza will be made. "<<endl;
            number=12;
            sum+=12.99;
    }
    cout<<"What type of crust do you want? ";
    cout<<"(H)Hand-tossed, (T) Thin-crust, or (D) Deep-dish (enter H, T, or D):";
    char type;
    cin>>type;
    string crust_type;
    switch(type)
    {
            case 'H':{crust_type="Hand-tossed crust";break;}
            case 'h':{crust_type="Hand-tossed crust";break;}
            case 'T':{crust_type="Thin-crust";break;}
            case 't':{crust_type="Thin-crust";break;}
            case 'D':{crust_type="Deep-dish";break;}
            case 'd':{crust_type="Deep-dish";break;}
            default:
            {
                cout<<"input was not one of the choices, so a Hand-tossed crust will be made. "<<endl;
                crust_type="Hand-tossed crust";
                break;
            }
    }
    cout<<"All pizzas come with cheese."<<endl;
    cout<<"Additional toppings are $1.25 each, choose from:"<<endl;
    cout<<"Pepperoni, Sausage, Onion, Mushroom"<<endl;
    cout<<"Do you want Pepperoni? (Y/N):";
    char p;
    cin>>p;
    cout<<"Do you want Sausage? (Y/N):";
    char s;
    cin>>s;
    cout<<"Do you want Onion? (Y/N):";
    char o;
    cin>>o;
    cout<<"Do you want Mushroom? (Y/N):";
    char m;
    cin>>m;
    cout<<"Your order is as follows: "<<endl;
    cout<<number<<"-inch pizza"<<endl;
    cout<<crust_type<<endl;
    cout<<"Cheese"<<" ";
    if(p=='Y'||p=='y'){sum+=1.25;cout<<" Pepperoni ";}
    if(s=='Y'||s=='y'){sum+=1.25;cout<<" Sausage ";}
    if(o=='Y'||o=='y'){sum+=1.25;cout<<" Onion ";}
    if(m=='Y'||m=='y'){sum+=1.25;cout<<" Mushroom ";}
    cout<<endl;
}
void output(double &sum)
{
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<"The cost of your order is: $"<<sum<<endl;
    cout<<"The tax is: $"<<sum*0.0795<<endl;
    cout<<"The total due is: $"<<sum+1.23<<endl;
    cout<<"Your order will be ready for pickup in 30 minutes."<<endl;
    cout<<endl;
}
int main( )
{
    cout<<"Welcome to May and Adam Pizzeria"<<endl;
    cout<<"Enter your first name: ";
    string name;
    cin>>name;
    double sum = 0;
    while(1)
    {
        sum = 0;
        order_pizza(sum);
        output(sum);
        cout<<"Do you need to continue buying? (Y/N)"<<endl;
        char b;
        cin>>b;
        if(b=='N'||b=='n') break;
    }
    return 0;
}
