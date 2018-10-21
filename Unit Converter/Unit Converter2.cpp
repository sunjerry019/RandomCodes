// Unit Converter.cpp : Defines the entry point for the console application.
//


#include<iostream>

using namespace std;

int main()
{
    int a,b,c;
    double answer;
    char fc;
    double n;
    start:
    system("cls");
    cout<<"Unit Converter"<<endl<<"----------------------------";
    cout<<endl<<"Coded by Sun Yudong, Icon from taptaptap."<<endl;
    cout<<"----------------------------";
    cout<<endl<<"Select conversion type:"<<endl;
    cout<<"1.Mass\n"<<"2.Distance and length\n"<<"3.Capacity and volume\n";
    cout<<"4.Area\n"<<"5.Speed\n"<<"6.Time\n"<<"7.Pressure and Stress\n";
    cout<<"8.Power\n"<<"9.Temperature\n"<<"0.Exit\n"<<"----------------------------\n"<<"Please enter a number corresponding to the type of conversion:";
    cin>>a;
    if(a==1)
    {
         mass1:
         system("cls");
         cout<<"1.Mass\n"<<"----------------------------\n";
         cout<<"1.Kilograms to Grams\n"<<"2.Grams to Kilograms\n"<<"3.Tons to Kilograms\n"<<"4.Kilograms to Tons\n";
         cout<<"5.Grams to Tons\n"<<"6.Tons to Grams\n"<<"7.Back to menu\n"<<"0.Exit\n"<<"----------------------------\n";
         cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";

         switch(b)
         {
              case 1:
                   cout<<"Kilograms to Grams\n"<<"--------------\n";
                   cout<<"Enter Kilograms:";
                   cin>>n;
                   answer=n*1000.00;
                   cout<<"Converted into Grams: "<<answer<<"g.\n";
                   break;
              case 2:
                   cout<<"Grams to Kilograms\n"<<"--------------\n";
                   cout<<"Enter Grams:";
                   cin>>n;
                   answer=n/1000.00;
                   cout<<"Converted into Kilograms: "<<answer<<"kg.\n";
                   break;
              case 3:
                   cout<<"Tons to Kilograms\n"<<"--------------\n";
                   cout<<"Enter Tons:";
                   cin>>n;
                   answer=n*1000.00;
                   cout<<"Converted into Kilograms: "<<answer<<"kg.\n";
                   break;
                   case 4:
                   cout<<"Kilograms to Tons\n"<<"--------------\n";
                   cout<<"Enter Kilograms:";
                   cin>>n;
                   answer=n/1000;
                   cout<<"Converted into Tons: "<<answer<<" t.\n";
                   break;          
              case 5:
                   cout<<"Grams to Tons\n"<<"--------------\n";
                   cout<<"Enter Grams:";
                   cin>>n;
                   answer=(n*1000)*1000.00;
                   cout<<"Converted into Tons: "<<answer<<" t.\n";
                   break;
              case 6:
                   cout<<"Tons to Grams\n"<<"--------------\n";
                   cout<<"Enter Tons:";
                   cin>>n;
                   answer=(n/1000)/1000.00;
                   cout<<"Converted into Grams: "<<answer<<"g.\n";                   
                   break;
              case 7:
                   system("cls");
                   goto start;
                   break;
              case 0:
                   return 0;
                   break;
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to reselect\n";
                   system("pause");
                   goto mass1;
         }
         
         cout<<"Further conversion?(y/n):";
         cin>>fc;
 
         switch(fc) 
         {
              case 'y':
                   n=answer;
                   goto mass;
                   break;
              case'n':
                   exitmass1:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                            cout<<"This is not a valid selection\n";
                            cout<<"Continue to reselect\n";
                            system("pause");
                            goto exitmass1;
                   }
                   break;
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;
         }
         mass:
         system("cls");
         cout<<"1.Mass\n"<<"----------------------------\n";
         cout<<"1.Kilograms to Grams\n"<<"2.Grams to Kilograms\n"<<"3.Tons to Killograms\n"<<"4.Kilograms to Tons\n";
         cout<<"5.Grams to Tons\n"<<"6.Tons to Grams\n"<<"7.Back to menu\n"<<"0.Exit\n"<<"----------------------------\n";
         cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
         
         switch(b)
         {
              case 1:
                   cout<<"Kilograms to Grams\n"<<"--------------\n";
                   answer=n*1000.00;
                   cout<<"Converted into Grams: "<<answer<<"g.\n";
                   break;
              case 2:
                   cout<<"Grams to Kilograms\n"<<"--------------\n";
                   answer=n/1000.00;
                   cout<<"Converted into Kilograms: "<<answer<<"kg.\n";
                   break;
              case 3:
                   cout<<"Tons to Kilograms\n"<<"--------------\n";
                   answer=n*1000.00;
                   cout<<"Converted into Kilograms: "<<answer<<"kg.\n";
                   break;
              case 4:
                   cout<<"Kilograms to Tons\n"<<"--------------\n";
                   answer=n/1000.00;
                   cout<<"Converted into Tons: "<<answer<<" t.\n";
                   break;
              case 5:
                   cout<<"Grams to Tons\n"<<"--------------\n";
                   answer=(n*1000)*1000.00;
                   cout<<"Converted into Tons: "<<answer<<" t.\n";
                   break;
              case 6:
                   cout<<"Tons to Grams\n"<<"--------------\n";
                   answer=(n/1000)/1000.00;
                   cout<<"Converted into Grams: "<<answer<<"g.\n";
                   break;
              case 7:
                   system("cls");
                   goto start;
                   break;
              case 0:
                   return 0;
                   break;
              default:
                   cout<<"This is not a valid selection\n";
                   cout<<"Contimue to reselect\n";
                   system("pause");
                   goto mass;
         }
         cout<<"Further conversion?(y/n):";
         cin>>fc;
         
         switch(fc)
         {
              case 'y':
                   n=answer;
                   goto mass;
                   break;
              case 'n':
                   exitmass:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                             cout<<"This is not a valid selection\n";
                             cout<<"Continue to reselect";
                             system("pause");
                             goto exitmass;
                             
                   }
                   break;  
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;          
         }
    }        
    else if(a==2)
    {
         //length
         length1:
         system("cls");
         cout<<"2.Distance and length\n"<<"----------------------------\n";
         cout<<"1.Meters to Kilometers               "<<"2.Kilometers to Meters\n";
		 cout<<"3.Centimeters to Meters              "<<"4.Meters to Centimeters\n";
         cout<<"5.Kilometers to Centimeters          "<<"6.Centimeters to Kilometeres\n";
	     cout<<"7.Millimeters to Centimeters         "<<"8.Centimeters to Millimeters\n";
		 cout<<"9.Millimeters to Meters              "<<"10.Meters to Millimeters\n";
         cout<<"11.Millimeters to Kilometers         "<<"12.Kilometers to Millimeters\n";
		 cout<<"13.Miles to Kilometers               "<<"14.Kilometers to Miles\n";
         cout<<"15.Feet to Yards                     "<<"16.Yards to Feet\n";
		 cout<<"17.Feet to Centimeters               "<<"18.Centimeters to Feet\n";
		 cout<<"19.Feet to Meters                    "<<"20.Meters to Feet\n";
		 cout<<"21.Inches to Centimeters             "<<"22.Centimeters to Inches\n";
		 cout<<"23.Yards to Miles                    "<<"24.Miles to Yards\n";
		 cout<<"25.Miles to Feet                     "<<"26.Feet to Miles\n";
		 cout<<"27.Back to menu                      "<<"0.Exit\n";
		 cout<<"----------------------------\n";
         cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
		 switch(b)
		 {
		 case 1:
			 cout<<"Meters to Kilometers\n";
			 cout<<"--------------\n";
			 cout<<"Enter Meters:";
             cin>>n;
             answer=n/1000.00;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 2:
			 cout<<"Kilometers to Meters\n";
		 	 cout<<"--------------\n";
			 cout<<"Enter Kilometers:";
             cin>>n;
             answer=n*1000.00;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 3:
			 cout<<"Centimeters to Meters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Centimeters:";
             cin>>n;
             answer=n/100.00;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 4:
			 cout<<"Meters to Centimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Meters:";
             cin>>n;
             answer=n*100.00;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 5:
			 cout<<"Kilometers to Centimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Kilometers:";
             cin>>n;
             answer=n*100000.00;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 6:
			 cout<<"Centimeters to Kilometers\n";
			 cout<<"--------------\n";
			 cout<<"Enter Kilometers:";
             cin>>n;
             answer=n/100000.00;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 7:
			 cout<<"Millimeters to Centimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Millimeters:";
             cin>>n;
             answer=n/10.00;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 8:
			 cout<<"Centimeters to Millimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter centimeters:";
             cin>>n;
             answer=n*10.00;
             cout<<"Converted into Millimeters: "<<answer<<" mm.\n";
             break;
		 case 9:
			 cout<<"Millimeters to Meters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Millimeters:";
             cin>>n;
             answer=(n/10)/100.00;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 10:
			 cout<<"Meters to Millimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Meters:";
             cin>>n;
             answer=(n*100)*10.00;
             cout<<"Converted into Millimeters: "<<answer<<" mm.\n";
             break;
		 case 11:
			 cout<<"Millimeters to Kilometers\n";
			 cout<<"--------------\n";
			 cout<<"Enter Millimeters:";
             cin>>n;
             answer=((n/10)/100)/1000.00;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 12:
			 cout<<"Kilometers to Millimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Kilometers:";
             cin>>n;
             answer=((n*1000)*100)*10.00;
             cout<<"Converted into Millimeters: "<<answer<<" mm.\n";
             break;
		 case 13:
			 cout<<"Miles to Kilometers\n";
			 cout<<"--------------\n";
			 cout<<"Enter Miles:";
             cin>>n;
             answer=n*1.609344;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 14:
			 cout<<"Kilometers to Miles\n";
			 cout<<"--------------\n";
			 cout<<"Enter Kilometers:";
             cin>>n;
             answer=n/1.609344;
             cout<<"Converted into Miles: "<<answer<<" miles.\n";
             break;
		 case 15:
			 cout<<"Feet to Yards\n";
			 cout<<"--------------\n";
			 cout<<"Enter Feet:";
             cin>>n;
             answer=n/3.00;
             cout<<"Converted into Yards: "<<answer<<" yd.\n";
             break;
		 case 16:
			 cout<<"Yards to Feet\n";
			 cout<<"--------------\n";
			 cout<<"Enter Yard:";
             cin>>n;
             answer=n*3.00;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 17:
			 cout<<"Feet to Centimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Feet:";
             cin>>n;
             answer=n*30.48;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 18:
			 cout<<"Centimeters to Feet\n";
			 cout<<"--------------\n";
			 cout<<"Enter Centimeters:";
             cin>>n;
             answer=n/30.48;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 19:
			 cout<<"Feet to Meters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Feet:";
             cin>>n;
             answer=n*0.3048;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 20:
			 cout<<"Meters to Feet\n";
			 cout<<"--------------\n";
			 cout<<"Enter Meters:";
             cin>>n;
             answer=n/0.3048;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 21:
			 cout<<"Inches to Centimeters\n";
			 cout<<"--------------\n";
			 cout<<"Enter Inches:";
             cin>>n;
             answer=n*2.54;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 22:
			 cout<<"Centimeters to Inches\n";
			 cout<<"--------------\n";
			 cout<<"Enter Centimeters:";
             cin>>n;
             answer=n/2.54;
             cout<<"Converted into Inches: "<<answer<<" in.\n";
             break;
		 case 23:
			 cout<<"Yards to Miles\n";
			 cout<<"--------------\n";
			 cout<<"Enter Yards:";
             cin>>n;
             answer=n/1760.00;
             cout<<"Converted into Miles: "<<answer<<" miles.\n";
             break;
		 case 24:
			 cout<<"Miles to Yards\n";
			 cout<<"--------------\n";
			 cout<<"Enter Miles:";
             cin>>n;
             answer=n*1760.00;
             cout<<"Converted into Yards: "<<answer<<" yd.\n";
             break;
		 case 25:
			 cout<<"Miles to Feet\n";
			 cout<<"--------------\n";
			 cout<<"Enter Miles:";
             cin>>n;
             answer=n*5280.00;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 26:
			 cout<<"Feet To Miles\n";
			 cout<<"--------------\n";
			 cout<<"Enter Feet:";
             cin>>n;
             answer=n/5280.00;
             cout<<"Converted into Miles: "<<answer<<" miles.\n";
             break;
		 case 27:
			 system("cls");
             goto start;
             break;
		case 0:
			 return 0;
			 break;
		default:
		   	 cout<<endl<<"This is not a valid selection.\n";
             cout<<"Continue to reselect\n";
             system("pause");
             goto length1;
		 }
		 cout<<"Further conversion?(y/n):";
         cin>>fc;
         
         switch(fc)
         {
              case 'y':
                   n=answer;
                   goto length;
                   break;
              case 'n':
                   exitlength1:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                             cout<<"This is not a valid selection\n";
                             cout<<"Continue to reselect\n";
                             system("pause");
                             goto exitlength1;
                             
                   }
                   break;  
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;          
         }
		 length:
		 system("cls");
         cout<<"2.Distance and length\n"<<"----------------------------\n";
         cout<<"1.Meters to Kilometers               "<<"2.Kilometers to Meters\n";
		 cout<<"3.Centimeters to Meters              "<<"4.Meters to Centimeters\n";
         cout<<"5.Kilometers to Centimeters          "<<"6.Centimeters to Kilometeres\n";
	     cout<<"7.Millimeters to Centimeters         "<<"8.Centimeters to Millimeters\n";
		 cout<<"9.Millimeters to Meters              "<<"10.Meters to Millimeters\n";
         cout<<"11.Millimeters to Kilometers         "<<"12.Kilometers to Millimeters\n";
		 cout<<"13.Miles to Kilometers               "<<"14.Kilometers to Miles\n";
         cout<<"15.Feet to Yards                     "<<"16.Yards to Feet\n";
		 cout<<"17.Feet to Centimeters               "<<"18.Centimeters to Feet\n";
		 cout<<"19.Feet to Meters                    "<<"20.Meters to Feet\n";
		 cout<<"21.Inches to Centimeters             "<<"22.Centimeters to Inches\n";
		 cout<<"23.Yards to Miles                    "<<"24.Miles to Yards\n";
		 cout<<"25.Miles to Feet                     "<<"26.Feet to Miles\n";
		 cout<<"27.Back to menu                      "<<"0.Exit\n";
		 cout<<"----------------------------\n";
         cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
		 switch(b)
		 {
		 case 1:
			 cout<<"Meters to Kilometers\n";
			 cout<<"--------------\n";
             answer=n/1000.00;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 2:
			 cout<<"Kilometers to Meters\n";
		 	 cout<<"--------------\n";
             answer=n*1000.00;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 3:
			 cout<<"Centimeters to Meters\n";
			 cout<<"--------------\n";
             answer=n/100.00;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 4:
			 cout<<"Meters to Centimeters\n";
			 cout<<"--------------\n";
             answer=n*100.00;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 5:
			 cout<<"Kilometers to Centimeters\n";
			 cout<<"--------------\n";
             answer=n*100000.00;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 6:
			 cout<<"Centimeters to Kilometers\n";
			 cout<<"--------------\n";
             answer=n/100000.00;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 7:
			 cout<<"Millimeters to Centimeters\n";
			 cout<<"--------------\n";
             answer=n/10.00;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 8:
			 cout<<"Centimeters to Millimeters\n";
			 cout<<"--------------\n";
             answer=n*10.00;
             cout<<"Converted into Millimeters: "<<answer<<" mm.\n";
             break;
		 case 9:
			 cout<<"Millimeters to Meters\n";
			 cout<<"--------------\n";
             answer=(n/10)/100.00;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 10:
			 cout<<"Meters to Millimeters\n";
			 cout<<"--------------\n";
             answer=(n*100)*10.00;
             cout<<"Converted into Millimeters: "<<answer<<" mm.\n";
             break;
		 case 11:
			 cout<<"Millimeters to Kilometers\n";
			 cout<<"--------------\n";
             answer=((n/10)/100)/1000.00;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 12:
			 cout<<"Kilometers to Millimeters\n";
			 cout<<"--------------\n";
             answer=((n*1000)*100)*10.00;
             cout<<"Converted into Millimeters: "<<answer<<" mm.\n";
             break;
		 case 13:
			 cout<<"Miles to Kilometers\n";
			 cout<<"--------------\n";
             answer=n*1.609344;
             cout<<"Converted into Kilometers: "<<answer<<" km.\n";
             break;
		 case 14:
			 cout<<"Kilometers to Miles\n";
			 cout<<"--------------\n";
             answer=n/1.609344;
             cout<<"Converted into Miles: "<<answer<<" miles.\n";
             break;
		 case 15:
			 cout<<"Feet to Yards\n";
			 cout<<"--------------\n";
             answer=n/3.00;
             cout<<"Converted into Yards: "<<answer<<" yd.\n";
             break;
		 case 16:
			 cout<<"Yards to Feet\n";
			 cout<<"--------------\n";
             answer=n*3.00;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 17:
			 cout<<"Feet to Centimeters\n";
			 cout<<"--------------\n";
             answer=n*30.48;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 18:
			 cout<<"Centimeters to Feet\n";
			 cout<<"--------------\n";
             answer=n/30.48;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 19:
			 cout<<"Feet to Meters\n";
			 cout<<"--------------\n";
             answer=n*0.3048;
             cout<<"Converted into Meters: "<<answer<<" m.\n";
             break;
		 case 20:
			 cout<<"Meters to Feet\n";
			 cout<<"--------------\n";
             answer=n/0.3048;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 21:
			 cout<<"Inches to Centimeters\n";
			 cout<<"--------------\n";
             answer=n*2.54;
             cout<<"Converted into Centimeters: "<<answer<<" cm.\n";
             break;
		 case 22:
			 cout<<"Centimeters to Inches\n";
			 cout<<"--------------\n";
             answer=n/2.54;
             cout<<"Converted into Inches: "<<answer<<" in.\n";
             break;
		 case 23:
			 cout<<"Yards to Miles\n";
			 cout<<"--------------\n";
             answer=n/1760.00;
             cout<<"Converted into Miles: "<<answer<<" miles.\n";
             break;
		 case 24:
			 cout<<"Miles to Yards\n";
			 cout<<"--------------\n";
             answer=n*1760.00;
             cout<<"Converted into Yards: "<<answer<<" yd.\n";
             break;
		 case 25:
			 cout<<"Miles to Feet\n";
			 cout<<"--------------\n";
             answer=n*5280.00;
             cout<<"Converted into Feet: "<<answer<<" ft.\n";
             break;
		 case 26:
			 cout<<"Feet To Miles\n";
			 cout<<"--------------\n";
             answer=n/5280.00;
             cout<<"Converted into Miles: "<<answer<<" miles.\n";
             break;
		 case 27:
			 system("cls");
             goto start;
             break;
		case 0:
			 return 0;
			 break;
		default:
		   	 cout<<endl<<"This is not a valid selection.\n";
             cout<<"Continue to reselect\n";
             system("pause");
             goto length;
		 }
		 cout<<"Further conversion?(y/n):";
         cin>>fc;
         
         switch(fc)
         {
              case 'y':
                   n=answer;
                   goto length;
                   break;
              case 'n':
                   exitlength:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                             cout<<"This is not a valid selection\n";
                             cout<<"Continue to reselect\n";
                             system("pause");
                             goto exitlength;
                             
                   }
                   break;  
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;          
         }
    }
    else if(a==3)
    {
         system("cls");
         cout<<"3.Capacity and volume\n"<<"----------------------------\n";
    }
    else if(a==4)
    {
         system("cls");
         cout<<"4.Area\n"<<"----------------------------\n";
    }
    else if(a==5)
    {
         speed1:
		 system("cls");
         cout<<"5.Speed\n"<<"----------------------------\n";
		 cout<<"1.km/h to mph                    "<<"2.mph to km/h\n";
		 cout<<"3.m/s to km/h                    "<<"4.km/h to m/s\n";
		 cout<<"5.ft/s to m/s                    "<<"6.m/s to ft/s\n";
		 cout<<"7.ft/s to km/h                   "<<"8.km/h to ft/s\n";
		 cout<<"9.Knots to mph                   "<<"10.mph to Knots\n";
		 cout<<"11.Knots to km/h                 "<<"12.km/h to Knots\n";
		 cout<<"13.Back to menu                  "<<"0.Exit\n";
		 cout<<"----------------------------\n";
		 cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
		 
		 switch(b)
		 {
			case 1:
				cout<<"Kilometers per hour to Miles per hour\n"<<"--------------\n";
                cout<<"Enter km/h:";
                cin>>n;
                answer=n/1.609344;
                cout<<"Converted into mph: "<<answer<<" mph.\n";
                break;
			case 2:
				cout<<"Miles per hour to Kilometer per hour\n"<<"--------------\n";
                cout<<"Enter mph:";
                cin>>n;
                answer=n*1.609344;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 3:
				cout<<"Meter per second to Kilometer per hour\n"<<"--------------\n";
                cout<<"Enter m/s:";
                cin>>n;
                answer=n*3.6;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 4:
				cout<<"Kilometer per Hour to Meter per second\n"<<"--------------\n";
                cout<<"Enter km/h:";
                cin>>n;
                answer=n/3.6;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 5:
				cout<<"Feet per second to Meter per second\n"<<"--------------\n";
                cout<<"Enter ft/s:";
                cin>>n;
                answer=n*0.3048;
                cout<<"Converted into m/s: "<<answer<<" m/s.\n";
                break;
			case 6:
				cout<<"Meter per second to Feet per second\n"<<"--------------\n";
                cout<<"Enter m/s:";
                cin>>n;
                answer=n/0.3048;
                cout<<"Converted into ft/s: "<<answer<<" ft/s.\n";
                break;
			case 7:
				cout<<"Feet per second to Kilometer per hour\n"<<"--------------\n";
                cout<<"Enter ft/s:";
                cin>>n;
                answer=n*1.09728;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 8:
				cout<<"Kilometer per hour to Feet per second\n"<<"--------------\n";
                cout<<"Enter km/h:";
                cin>>n;
                answer=n/1.09728;
                cout<<"Converted into ft/s: "<<answer<<" ft/s.\n";
                break;
			case 9:
				cout<<"Knots to Miles per hour\n"<<"--------------\n";
                cout<<"Enter Knots:";
                cin>>n;
                answer=n*1.150779;
                cout<<"Converted into mph: "<<answer<<" mph.\n";
                break;
			case 10:
				cout<<"Miles per hour to Knots\n"<<"--------------\n";
                cout<<"Enter mph:";
                cin>>n;
                answer=n*0.868976;
                cout<<"Converted into Knots: "<<answer<<" Knots.\n";
                break;
			case 11:
				cout<<"Knots to Kilometer per hour\n"<<"--------------\n";
                cout<<"Enter Knots:";
                cin>>n;
                answer=n*1.852;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 12:
				cout<<"Kilometer per hour to Knots\n"<<"--------------\n";
                cout<<"Enter km/h:";
                cin>>n;
                answer=n/1.852;
                cout<<"Converted into Knots: "<<answer<<" Knots.\n";
                break;
			case 13:
				system("cls");
                goto start;
                break;
			case 0:
				return 0;
				break;
			default:
				cout<<endl<<"This is not a valid selection.\n";
                cout<<"Continue to reselect\n";
                system("pause");
                goto speed1;
		 }
		 cout<<"Further conversion?(y/n):";
         cin>>fc;
         
         switch(fc)
         {
              case 'y':
                   n=answer;
                   goto speed;
                   break;
              case 'n':
                   exitspeed1:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                             cout<<"This is not a valid selection\n";
                             cout<<"Continue to reselect\n";
                             system("pause");
                             goto exitspeed1;
                             
                   }
                   break;  
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;          
         }
		 speed:
		 system("cls");
         cout<<"5.Speed\n"<<"----------------------------\n";
		 cout<<"1.km/h to mph                    "<<"2.mph to km/h\n";
		 cout<<"3.m/s to km/h                    "<<"4.km/h to m/s\n";
		 cout<<"5.ft/s to m/s                    "<<"6.m/s to ft/s\n";
		 cout<<"7.ft/s to km/h                   "<<"8.km/h to ft/s\n";
		 cout<<"9.Knots to mph                   "<<"10.mph to Knots\n";
		 cout<<"11.Knots to km/h                 "<<"12.km/h to Knots\n";
		 cout<<"13.Back to menu                  "<<"0.Exit\n";
		 cout<<"----------------------------\n";
		 cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
		 
		 switch(b)
		 {
			case 1:
				cout<<"Kilometers per hour to Miles per hour\n"<<"--------------\n";
                answer=n/1.609344;
                cout<<"Converted into mph: "<<answer<<" mph.\n";
                break;
			case 2:
				cout<<"Miles per hour to Kilometer per hour\n"<<"--------------\n";
                answer=n*1.609344;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 3:
				cout<<"Meter per second to Kilometer per hour\n"<<"--------------\n";
                answer=n*3.6;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 4:
				cout<<"Kilometer per Hour to Meter per second\n"<<"--------------\n";
                answer=n/3.6;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 5:
				cout<<"Feet per second to Meter per second\n"<<"--------------\n";
                answer=n*0.3048;
                cout<<"Converted into m/s: "<<answer<<" m/s.\n";
                break;
			case 6:
				cout<<"Meter per second to Feet per second\n"<<"--------------\n";
                answer=n/0.3048;
                cout<<"Converted into ft/s: "<<answer<<" ft/s.\n";
                break;
			case 7:
				cout<<"Feet per second to Kilometer per hour\n"<<"--------------\n";
                answer=n*1.09728;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 8:
				cout<<"Kilometer per hour to Feet per second\n"<<"--------------\n";
                answer=n/1.09728;
                cout<<"Converted into ft/s: "<<answer<<" ft/s.\n";
                break;
			case 9:
				cout<<"Knots to Miles per hour\n"<<"--------------\n";
                answer=n*1.150779;
                cout<<"Converted into mph: "<<answer<<" mph.\n";
                break;
			case 10:
				cout<<"Miles per hour to Knots\n"<<"--------------\n";
                answer=n*0.868976;
                cout<<"Converted into Knots: "<<answer<<" Knots.\n";
                break;
			case 11:
				cout<<"Knots to Kilometer per hour\n"<<"--------------\n";
                answer=n*1.852;
                cout<<"Converted into km/h: "<<answer<<" km/h.\n";
                break;
			case 12:
				cout<<"Kilometer per hour to Knots\n"<<"--------------\n";
                answer=n/1.852;
                cout<<"Converted into Knots: "<<answer<<" Knots.\n";
                break;
			case 13:
				system("cls");
                goto start;
                break;
			case 0:
				return 0;
				break;
			default:
				cout<<endl<<"This is not a valid selection.\n";
                cout<<"Continue to reselect\n";
                system("pause");
                goto speed;
		 }
		 cout<<"Further conversion?(y/n):";
         cin>>fc;
         
         switch(fc)
         {
              case 'y':
                   n=answer;
                   goto speed;
                   break;
              case 'n':
                   exitspeed:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                             cout<<"This is not a valid selection\n";
                             cout<<"Continue to reselect\n";
                             system("pause");
                             goto exitspeed;
                             
                   }
                   break;  
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;          
         }
    }
    else if(a==6)
    {
         time1:
         system("cls");
         cout<<"6.Time\n"<<"----------------------------\n";
         cout<<"1.Seconds to Minutes             "<<"2.Minutes to Seconds\n";
         cout<<"3.Minutes to Hours               "<<"4.Hours to Minutes\n";
         cout<<"5.Seconds to Hours               "<<"6.Hours to Seconds\n";
         cout<<"7.Hours to Months                "<<"8.Months to Hours\n";
         cout<<"9.Hours to Days                  "<<"10.Days to Hours\n";
		 cout<<"11.Hours to Years                "<<"12.Years to Hours\n";
		 cout<<"13.Years to Minutes              "<<"14.Minutes to Years\n";
		 cout<<"15.Days to Years                 "<<"16.Years to Days\n";
		 cout<<"17.Back to Menu                  "<<"0.Exit\n";
		 cout<<"----------------------------\n";
		 cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
		 
		 switch(b)
		 {
			case 1:
				cout<<"Seconds to Minutes\n"<<"--------------\n";
                cout<<"Enter Seconds:";
                cin>>n;
                answer=n/60.00;
                cout<<"Converted into Minutes: "<<answer<<" min.\n";
                break;
			case 2:
				cout<<"Minutes to Seconds\n"<<"--------------\n";
                cout<<"Enter Minutes:";
                cin>>n;
                answer=n*60.00;
                cout<<"Converted into Seconds: "<<answer<<" sec.\n";
                break;
			case 3:
				cout<<"Minutes to Hours\n"<<"--------------\n";
                cout<<"Enter Minutes:";
                cin>>n;
                answer=n/60.00;
                cout<<"Converted into Hours: "<<answer<<" h.\n";
                break;
			case 4:
				cout<<"Hours to Minutes\n"<<"--------------\n";
                cout<<"Enter Hours:";
                cin>>n;
                answer=n*60.00;
                cout<<"Converted into Minutes: "<<answer<<" min.\n";
                break;
            case 5:
                cout<<"Seconds to Hours\n"<<"--------------\n";
                cout<<"Enter Seconds:";
                cin>>n;
                answer=n/60.00/60.00;
                cout<<"Converted into Hours: "<<answer<<" h.\n";
                break;
            case 6:
                 cout<<"Hours to Seconds\n"<<"--------------\n";
                 cout<<"Enter Hours:";
                 cin>>n;
                 answer=n*60.00*60.00;
                 cout<<"Converted into Seconds: "<<answer<<" sec.\n";
                 break;
            case 7:
                 cout<<"Hours to Months"<<"--------------\n";
                 cout<<"Enter Hours:";
                 cin>>n;
                 answer=n/(24.00*30);
                 cout<<"Note: A month is taken as 30 days.\n";
                 cout<<"Converted into Months: "<<answer<<" sec.\n";
                 break;
            case 8:
                 cout<<"Months to Hours\n"<<"--------------\n";
                 cout<<"Note: A month is taken as 30 days.\n";
                 cout<<"Enter Months:";
                 cin>>n;
                 answer=n*30*24.00;
                 cout<<"Converted into Hours: "<<answer<<" h.\n";
                 break;
            case 9:
                 cout<<"Hours to Days\n"<<"--------------\n";
                 cout<<"Enter Hours:";
                 cin>>n;
                 answer=n/24.00;
                 cout<<"Converted into Days: "<<answer<<" days.\n";
                 break;
            case 10:
                 cout<<"Days to Hours\n"<<"--------------\n";
                 cout<<"Enter Days:";
                 cin>>n;
                 answer=n*24.00;
                 cout<<"Converted into Hours: "<<answer<<" h.\n";
                 break;
            case 11:
                 cout<<"Hours to Years\n"<<"--------------\n";
                 cout<<"Enter Hours:";
                 cin>>n;
                 answer=(n/24.00)/365;
                 cout<<"Converted into Years: "<<answer<<" years.\n";
                 break;
            case 12:
                 cout<<"Years to Hours\n"<<"--------------\n";
                 cout<<"Enter Years:";
                 cin>>n;
                 answer=(n*365)*24.00;
                 cout<<"Converted into Hours: "<<answer<<" h.\n";
                 break;
            case 13:
                 cout<<"Years to Minutes\n"<<"--------------\n";
                 cout<<"Enter Years:";
                 cin>>n;
                 answer=(n*365)*24.00*60;
                 cout<<"Converted into Minutes: "<<answer<<" min.\n";
                 break;
            case 14:
                 cout<<"Minutes to Years\n"<<"--------------\n";
                 cout<<"Enter Minutes:";
                 cin>>n;
                 answer=((n/60)/24.00)/365;
                 cout<<"Converted into Years: "<<answer<<" years.\n";
                 break;
            case 15:
                 cout<<"Days to Years\n"<<"--------------\n";
                 cout<<"Note: 1 year is taken as 365 days.\n";
                 cout<<"Enter Days:";
                 cin>>n;
                 answer=n/365;
                 cout<<"Converted into Years: "<<answer<<" years.\n";
                 break;
            case 16:
                 cout<<"Years to Days\n"<<"--------------\n";
                 cout<<"Note: 1 year is taken as 365 days.\n";
                 cout<<"Enter Years:";
                 cin>>n;
                 answer=n*365;
                 cout<<"Converted into Days: "<<answer<<" days.\n";
                 break;
            case 17:
                 system("cls");
                 goto start;
                 break;
            case 0:
                 return 0;
                 break;
            default:
                 cout<<endl<<"This is not a valid selection.\n";
                 cout<<"Continue to reselect\n";
                 system("pause");
                 goto time1;
         }
         cout<<"Further conversion?(y/n):";
         cin>>fc;
         
         switch(fc)
         {
              case 'y':
                   n=answer;
                   goto time;
                   break;
              case 'n':
                   exittime1:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                             cout<<"This is not a valid selection\n";
                             cout<<"Continue to reselect\n";
                             system("pause");
                             goto exittime1;
                             
                   }
                   break;  
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;          
         }
         time:
         system("cls");
         cout<<"6.Time\n"<<"----------------------------\n";
         cout<<"1.Seconds to Minutes             "<<"2.Minutes to Seconds\n";
         cout<<"3.Minutes to Hours               "<<"4.Hours to Minutes\n";
         cout<<"5.Seconds to Hours               "<<"6.Hours to Seconds\n";
         cout<<"7.Hours to Months                "<<"8.Months to Hours\n";
         cout<<"9.Hours to Days                  "<<"10.Days to Hours\n";
		 cout<<"11.Hours to Years                "<<"12.Years to Hours\n";
		 cout<<"13.Years to Minutes              "<<"14.Minutes to Years\n";
		 cout<<"15.Days to Years                 "<<"16.Years to Days\n";
		 cout<<"17.Back to Menu                  "<<"0.Exit\n";
		 cout<<"----------------------------\n";
		 cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
		 
		 switch(b)
		 {
			case 1:
				cout<<"Seconds to Minutes\n"<<"--------------\n";
                answer=n/60.00;
                cout<<"Converted into Minutes: "<<answer<<" min.\n";
                break;
			case 2:
				cout<<"Minutes to Seconds\n"<<"--------------\n";;
                answer=n*60.00;
                cout<<"Converted into Seconds: "<<answer<<" sec.\n";
                break;
			case 3:
				cout<<"Minutes to Hours\n"<<"--------------\n";
                answer=n/60.00;
                cout<<"Converted into Hours: "<<answer<<" h.\n";
                break;
			case 4:
				cout<<"Hours to Minutes\n"<<"--------------\n";
                answer=n*60.00;
                cout<<"Converted into Minutes: "<<answer<<" min.\n";
                break;
            case 5:
                cout<<"Seconds to Hours\n"<<"--------------\n";
                answer=n/60.00/60.00;
                cout<<"Converted into Hours: "<<answer<<" h.\n";
                break;
            case 6:
                 cout<<"Hours to Seconds\n"<<"--------------\n";
                 answer=n*60.00*60.00;
                 cout<<"Converted into Seconds: "<<answer<<" sec.\n";
                 break;
            case 7:
                 cout<<"Hours to Months"<<"--------------\n";
                 answer=n/(24.00*30);
                 cout<<"Note: A month is taken as 30 days.\n";
                 cout<<"Converted into Months: "<<answer<<" sec.\n";
                 break;
            case 8:
                 cout<<"Months to Hours\n"<<"--------------\n";
                 cout<<"Note: A month is taken as 30 days.";
                 answer=n*30*24.00;
                 cout<<"Converted into Hours: "<<answer<<" h.\n";
                 break;
            case 9:
                 cout<<"Hours to Days\n"<<"--------------\n";
                 answer=n/24.00;
                 cout<<"Converted into Days: "<<answer<<" days.\n";
                 break;
            case 10:
                 cout<<"Days to Hours\n"<<"--------------\n";
                 answer=n*24.00;
                 cout<<"Converted into Hours: "<<answer<<" h.\n";
                 break;
            case 11:
                 cout<<"Hours to Years\n"<<"--------------\n";
                 answer=(n/24.00)/365;
                 cout<<"Converted into Years: "<<answer<<" years.\n";
                 break;
            case 12:
                 cout<<"Years to Hours\n"<<"--------------\n";
                 answer=(n*365)*24.00;
                 cout<<"Converted into Hours: "<<answer<<" h.\n";
                 break;
            case 13:
                 cout<<"Years to Minutes\n"<<"--------------\n";
                 answer=(n*365)*24.00*60;
                 cout<<"Converted into Minutes: "<<answer<<" min.\n";
                 break;
            case 14:
                 cout<<"Minutes to Years\n"<<"--------------\n";
                 answer=((n/60)/24.00)/365;
                 cout<<"Converted into Years: "<<answer<<" years.\n";
                 break;
            case 15:
                 cout<<"Days to Years\n"<<"--------------\n";
                 cout<<"Note: 1 year is taken as 365 days.\n";
                 answer=n/365;
                 cout<<"Converted into Years: "<<answer<<" years.\n";
                 break;
            case 16:
                 cout<<"Years to Days\n"<<"--------------\n";
                 cout<<"Note: 1 year is taken as 365 days.\n";
                 answer=n*365;
                 cout<<"Converted into Days: "<<answer<<" days.\n";
                 break;
            case 17:
                 system("cls");
                 goto start;
                 break;
            case 0:
                 return 0;
                 break;
            default:
                 cout<<endl<<"This is not a valid selection.\n";
                 cout<<"Continue to reselect\n";
                 system("pause");
                 goto time1;
         }
         cout<<"Further conversion?(y/n):";
         cin>>fc;
         
         switch(fc)
         {
              case 'y':
                   n=answer;
                   goto time;
                   break;
              case 'n':
                   exittime:
                   system("cls");
                   cout<<"1.Exit\n"<<"2.Back to menu\n";
                   cout<<"Please select option:";
                   cin>>c;
                   
                   switch(c)
                   {
                        case 1:
                             return 0;
                             break;
                        case 2:
                             system("cls");
                             goto start;
                             break;
                        default:
                             cout<<"This is not a valid selection\n";
                             cout<<"Continue to reselect\n";
                             system("pause");
                             goto exittime;
                             
                   }
                   break;  
              default:
                   cout<<"This is not a valid selection.\n";
                   cout<<"Continue to exit.\n";
                   system("pause");
                   return 0;          
         }        
    }
    else if(a==7)
    {
         system("cls");
         cout<<"7.Pressure and Stress\n"<<"----------------------------\n";
    }
    else if(a==8)
    {
         system("cls");
         cout<<"8.Power\n"<<"----------------------------\n";
    }
    else if(a==9)
    {
         temp:
         system("cls");
         cout<<"10.Temperature\n"<<"----------------------------\n";
         cout<<"1.Celsius to Fahrenheit\n"<<"2.Fahrenheit to Celsius\n";
         cout<<"3.Kelvin to Celsius\n"<<"4.Celsius to Kelvin\n";
         cout<<"5.Kelvin to Fahrenheit\n"<<"6.Fahrenheit to Kelvin\n";
         cout<<"7.Back to menu\n"<<"0.Exit\n"<<"----------------------------\n";
         cout<<"Please enter the corresponding number to your selection:";
         cin>>b;
         cout<<"----------------------------\n";
         switch(b)
         {
             case 1:
                  cout<<"Celsius to Fahrenheit\n"<<"--------------\n";
                  cout<<"Enter Celsius:";
                  cin>>n;
                  answer=(9.00/5)*n+32;
                  cout<<"Converted into Fahrenheit:"<<answer<<" deg F.\n";
                  break;
             case 2:
                  cout<<"Fahrenheit to Celsius\n"<<"--------------\n";
                  cout<<"Enter Fahrenheit:";
                  cin>>n;
                  answer=(n-32.00)*(5.00/9);
                  cout<<"Converted into Celsius:"<<answer<<" deg C.\n";
                  break;
             case 3:
                  cout<<"Kelvin to Celsius\n"<<"--------------\n";
                  cout<<"Enter Kelvin:";
                  cin>>n;
                  answer=n-273.15;
                  cout<<"Converted into Celsius:"<<answer<<" K.\n";
                  break;
             case 4:
                  cout<<"Celsius to Kelvin\n"<<"--------------\n";
                  cout<<"Enter Celsius:";
                  cin>>n;
                  answer=n+273.15;
                  cout<<"Converted into Kelvin:"<<answer<<" deg C.\n";
                  break;
             case 5:
                  cout<<"Kelvin to Fahrenheit\n"<<"--------------\n";
                  cout<<"Enter Kelvin:";
                  cin>>n;
                  answer=n*(9/5.00) - 459.67;
                  cout<<"Converted to Fahrenheit:"<<answer<<" deg F.\n";
                  break;
             case 6:
                  cout<<"Fahrenheit to Kelvin\n"<<"--------------\n";
                  cout<<"Enter Fahrenheit:";
                  cin>>n;
                  answer=(n+ 459.67)*5.00/9;
                  cout<<"Converted to Kelvin:"<<answer<<" K.\n";
                  break;
             case 7:
                  system("cls");
                  goto start;
             case 0:
                  return 0;
                  break;
             default:
                  //Program crashed when typed a char
                  cout<<endl<<"This is not a valid selection.\n";
                  cout<<"Continue to reselect\n";
                  system("pause");
                  goto temp;
         }
    }
    else if(a==0)
    {
         return 0;
    }
    else
    {
         cout<<endl<<"This is not a valid selection.\n";
         cout<<"Continue to reselect\n";
         system("pause");
         goto start;
    }
    
    system("pause");
    return 0;
}
