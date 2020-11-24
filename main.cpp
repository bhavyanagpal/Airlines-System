
#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>

using namespace std;

void ReserveSeat()
{

}

void UserTicket()
{

}


void FlightSchedule()
{

}
void DisplayPassenger()
{

}

void FlightDetails()
{

}

void Exit()
{
    char sure;
    cout<<"Are you sure you want to leave the program?"<<endl;
    cin>>sure;
    if (sure=='y' || sure=='Y')
        {
            exit(0);
        }
        else if(sure=='n' || sure=='N')
        {

        }
        else{
         cout<<endl<<"Input correctly please!";
         Exit();
        }
}


int main()
{
    int choice;
    char sure;
    cout << "Welcome To Airlines Reservation System" << endl << endl;
    cout << "Airlines Reservation System Menu" << endl;
    cout << "1. Reserve Seat." << endl;
    cout << "2. User Ticket." << endl;
    cout << "3. Flights Schedule." << endl;
    cout << "4. Display Passenger." << endl;
    cout << "5. Flight Details." << endl;
    cout << "6. Exit Program." << endl;
    cout << "Choose One: ";
    cin >> choice;
    switch(choice)
    {
        case 1: ReserveSeat();
                break;

        case 2: UserTicket();
                break;

        case 3: FlightSchedule();
                break;

        case 4: DisplayPassenger();
                break;

        case 5: FlightDetails();
                break;

        case 6: Exit:
            cout << "Program terminating. Are you sure? (y/N): ";
        cin >> sure;
        if (sure == 'y' || sure == 'Y') {
            return 0;
        }else if (sure == 'n' || sure == 'N') {
            system("cls");
            main();
        }else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto Exit;
        }
        default:
        cout << "Please choose between The Given Numbers. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;

    }
    return 0;
}
