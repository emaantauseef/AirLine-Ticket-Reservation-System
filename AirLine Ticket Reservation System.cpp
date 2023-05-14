
// Header Files Included Here
//#include <stdio.h>
//#include <stdlib.h>
#include <conio.h>
//#include <string.h>
#include <Windows.h>
#include <iostream>
using namespace std;


// Declaration of all Global Variables and Arrays

// variable to control the loops
int i = 0, j = 0, k = 0, XX=0;

// variable to store : ......
// flight date = D = 1 - 31,
// flight time = T = 1=M, 2=E
// Seat type = ST = 1=B, 2=Ec
// Seat number booked = SN;
int D=0, T=0, ST=0, SN=0;

// array to record / check if a particular seart numebr on a given day is booked or vacant ?
// 1 = booked,  0 = vacant
//int Is_Seat_Booked [31][2][50];

// array used as counter to record / check how many seats are booked in given type (business / economy) ?
// 1 = booked,  0 = vacant
int Seat_Full_Counter [31][2][2];

// Counter to record how many seats are booked in business class (CB) and in economy class(CE)
int CB = 1, CE = 21;

// variable to get user option
char op, X='-';

// string array to store passenger name, each name has 25 char length
char Name [31][2][50][25];

//  end of Global Variable Declaration


// Function to Print a Header in the Beginning of Program
void print_header ()
{
system("COLOR B0");
//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 188);
//cout << "\a \n \n";
cout << "*****************************************************************\n ";
cout << "  Welcome to  SUFFA AIRLINE TICKET RESERVATION SYSTEM  \n";
cout << "*****************************************************************\n\n";
//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
cout << "  This Program is Prepared By : \n \n";
cout << "  Names:               Emaan Tauseef, Maryam Fatima Shahid\n";
cout << "  Subject Name:        Introduction to Computing and Programming \n";
cout << "  Submitted To:        Engr. Aireen \n";
cout << "  Date of Submission:  26/11/2020 \n";
}
// end of print_header function


// Function to clear garbage values in all the arrays
void clear_array()
{

for (i=0; i<31; i++)
{
	for (j=0; j<2; j++)
	{
		Seat_Full_Counter [i][j][0] = 0;   // counter for Business class = 1-20
		Seat_Full_Counter [i][j][1] = 20;  // counter for Economy class = 21-50

		for (k=0; k<50; k++)
		{
		//	Is_Seat_Booked [i][j][k] = 0 ;
		strcpy (Name[i][j][k], "XXXXXX") ;
		}
	}
}
}
// end of clear_array function


// Function to Purchase Ticket

void purchase_ticket ()
{

while (1)    // infinte loop
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 188);
cout << "\a \n\n  Welcome to  PURCHASE TICKET MODULE \n \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
cout << "  Press B - to Purchase Ticket for Business Class \n";
cout << "  Press E - to Purchase Ticket for Economy Class \n";
cout << "  Press M - to Return to Main Menu \n";
cout << "  Press Q - to Quit Application \n\n";
cout << "  Select the Correct Option : ";

op=getche();


if(op=='B' || op=='b' || op=='E' || op=='e')
{
cout << "\n\n  Enter Date of Travel ( 1 - 31 ): ";
cin >> D;
cout << "  Enter Travel Route ( 1 = Morning: Karachi to Lahore, 2 = Evening: Lahore to Karachi ): ";
cin >> T;

if (op=='B'|| op=='b') {ST=1;}
else if (op=='E' || op=='e') {ST=2;}

if (ST == 1) // Business Class
{
	CB = Seat_Full_Counter[D-1][T-1][ST-1]; // Count how many seats booked in business class
 	if ( CB == 20 )  // 19 = 2 over
	 {
		cout << "\n  Seats are full on this date. Please select another date and time. \n";
		getche();
	 }
	else
	{
 		CB++;  // increase counter for business seats
		cout << "  Enter Passenger Name: ";
		cin >> Name[D-1][T-1][CB-1];	  // store passenger name
		Seat_Full_Counter[D-1][T-1][ST-1] = CB;

		// Print Boarding Pass and PNR Number and Seat Confirmation message for user.
		cout << "\n  Congratulations, your seat is booked for: \n";
		cout << "\n ************************************************************** ";
		cout << "\n\t PNR Number: \t  " << D << "-" << T << "-" << ST << "-" << CB << "-00";
		cout << "\n\t Date: \t\t  " << D;
		if(T==1)  {cout << "\n\t Time: \t\t  " << T << ", Morning Flight";  cout << "\n\t Route: \t  Karachi to Lahore";}
		if(T==2)  {cout << "\n\t Time: \t\t  " << T << ", Eveninig Flight"; cout << "\n\t Route: \t  Lahore to Karachi";}
		if(ST==1) {cout << "\n\t Class:  \t  " << ST << ", Business Class";}
		if(ST==2) {cout << "\n\t Class:  \t  " << ST << ", Economy Class";}
		cout << "\n\t Seat Number:     " << CB ;
		cout << "\n\t Passenger Name:  " << Name[D-1][T-1][CB-1];
		cout << "\n ************************************************************** \n";

		cout << "\n  Kindly save your PNR Number for future use.";
		cout << "\n  To confirm your seat, kindly make payment at nearest booking office within 12 hours time.";
		cout << "\n  Thank You.";
		getche();
		cout << "\n\n  REMINDER: Kindly save your PNR Number for future use. Thank You.";
		getche();
	}
}

else if (ST == 2) // Economy Class
{
	CE = Seat_Full_Counter[D-1][T-1][ST-1]; // Count how many seats booked in economy class
 	if ( CE == 50 ) // 49 = 22 over
	 {
		cout << "\n  Seats are full on this date. Please select another date and time. \n";
		getche();
	 }
	else
	{
		CE++;  // increase counter for economy seats
	//	Is_Seat_Booked [D-1][T-1][CE-1] = 1; // Researve an economy seat
		cout << "  Enter Passenger Name: ";
		cin >> Name[D-1][T-1][CE-1];	  // store passenger name
		Seat_Full_Counter[D-1][T-1] [ST-1] = CE;

		// Print Boarding Pass and PNR Number and Seat Confirmation message for user.
		cout << "\n  Congratulations, your seat is booked for: \n";
		cout << "\n ************************************************************** ";
		cout << "\n\t PNR Number: \t  " << D << "-" << T << "-" << ST << "-" << CE << "-00";
		cout << "\n\t Date: \t\t  " << D;
		if(T==1)  {cout << "\n\t Time: \t\t  " << T << ", Morning Flight";  cout << "\n\t Route: \t  Karachi to Lahore";}
		if(T==2)  {cout << "\n\t Time: \t\t  " << T << ", Eveninig Flight"; cout << "\n\t Route: \t  Lahore to Karachi";}
		if(ST==1) {cout << "\n\t Class:  \t  " << ST << ", Business Class";}
		if(ST==2) {cout << "\n\t Class:  \t  " << ST << ", Economy Class";}
		cout << "\n\t Seat Number:     " << CE ;
		cout << "\n\t Passenger Name:  " << Name[D-1][T-1][CE-1];
		cout << "\n ************************************************************** \n";

		cout << "\n  Kindly save your PNR Number for future use.";
		cout << "\n  To confirm your seat, kindly make payment at nearest booking office within 12 hours time.";
		cout << "\n  Thank You.";
		getche();
		cout << "\n\n  REMINDER: Kindly save your PNR Number for future use. Thank You.";
		getche();
	}
}

}  // end of option B and option E

else if(op=='M' || op=='m')
{
 cout << " \n\n  Now Returning Back to Main Menu. ....... ";
 getche();
 goto KK ;
 //return(0); .... error
}

else if(op=='Q' || op=='q')
{
// Printing Thank You Message before Clsoing the Program

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 189);
 cout << "\a \n\n  Thank You for Using Our Program";
 cout << "\n  Now closing Down the Program";
  cout << "\n  Press Any Key to Continue and Exit ......";
 cout << "\n";
 getche();
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
 exit(0);
 //return (0);
}

else
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 188);
cout << "\a \n\n  You entered wrong value."; getche();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
}


}  // end of while loop

// End Marker
KK :
;
}  // end of purchase_ticket function


// Function to Print Boarding Pass

void print_boarding ()
{
Beep(523,500);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 188);
cout << "\a \n\n  Welcome to  PRINT BOARDING PASS MODULE \n \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
cout << "  Please enter your PNR Number (as NN-NN-NN-NN-00): ";
cin >> D >> X >> T >> X >> ST >> X >> SN >> X >> XX;

// Print Boarding Pass and PNR Number and Seat Confirmation message for user.

cout << "\n ************************************************************** ";
cout << "\n Your Boarding Pass is: ";
cout << "\n\t PNR Number: \t  " << D << "-" << T << "-" << ST << "-" << SN << "-00";
cout << "\n\t Date: \t\t  " << D;
if(T==1)  {cout << "\n\t Time: \t\t  " << T << ", Morning Flight";  cout << "\n\t Route: \t  Karachi to Lahore";}
if(T==2)  {cout << "\n\t Time: \t\t  " << T << ", Eveninig Flight"; cout << "\n\t Route: \t  Lahore to Karachi";}
if(ST==1) {cout << "\n\t Class:  \t  " << ST << ", Business Class";}
if(ST==2) {cout << "\n\t Class:  \t  " << ST << ", Economy Class";}
cout << "\n\t Seat Number:     " << SN ;
cout << "\n\t Passenger Name:  " << Name[D-1][T-1][SN-1];
cout << "\n ************************************************************** \n";

cout << "\n  Enjoy a Safe Journey...... :) :) \n";
cout << "  Thank You.";
cout << " \n\n  Now Returning Back to Main Menu. ....... ";
getche();

}  // End of print_boarding function




// beginning of main program
int main ()
{
// Printing the Header Lines using function
  print_header ();

// to avoid garbage valsues, initialize all arrays to ZERO in the beginning of program
  clear_array ();

// Asking the required data from user

while (1)  // infinite loop
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 188);
cout << "\a \n \n  Welcome to  SUFFA AIRLINE TICKET RESERVATION SYSTEM  \n \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
cout << "  Press P - to Purchase Ticket \n";
cout << "  Press V - to Print Boarding Pass \n";
cout << "  Press Q - to Quit Application \n\n";
cout << "  Select the Correct Option : ";

op=getche();

if(op=='P' || op=='p')
{ purchase_ticket (); }

else if(op=='V' || op=='v')
{ print_boarding (); }

else if(op=='Q' || op=='q')
{ goto KK ; }

else
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 188);
cout << "\a \n\n  You entered wrong value."; getche();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
}

}  // end of while loop


// End Marker
KK :

// Printing Thank You Message before Closing the Program

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 189);
cout << "\a \n\n  Thank You for Using Our Program";
cout << "\n  Now closing Down the Program";
cout << "\n  Press Any Key to Continue and Exit ......";
cout << "\n";
getche();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
return (0);

} // end of main program


