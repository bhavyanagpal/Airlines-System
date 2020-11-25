
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


int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

class database
{
public:
    static void Connect()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            //getch();

        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "secret", "airlines", 0, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};


int ReserveSeat()
{

    //system("cls");
    cout<<"IN";
    int userId=0;
    string userFlightNo;
    string userName ;
    string userPhone;
    string userPassportNo;
    string userTicket ;
    string userAddress;
    char choose;

    //string store[500][500];
    //int storeId1 = 0, storeId2 = 0;



    cout << "Airlines Reservation System" << endl << endl;
    cout << "Reserve Seat Menu" << endl << endl;

    //cin.ignore(1, '\n');
    cout << "Enter User Id: "<<endl;
    cin>>userId;
    cin.ignore(1, '\n');
    cout <<endl <<"Enter User Name: ";
    getline(cin, userName);
    cout <<endl<< "Enter User Phone No: ";
    getline(cin, userPhone);
    cout << endl<<"Enter User Passport: ";
    getline(cin, userPassportNo);
    cout << endl<<"Enter User Ticket: ";
    getline(cin, userTicket);
    cout <<endl<< "Enter User Address: ";
    getline(cin, userAddress);

    qstate = mysql_query(conn, "select * from flight_details where f_available > 0");
    if (!qstate)
    {
        res = mysql_store_result(conn);
    cout<<"--------------------------------------------------------------------------------------------------------------------\n";
        printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "Flight No", "From", "Destination", "Time", "Amount");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", row[1], row[3], row[4], row[5], row[6]);
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
}
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    cout << "Enter Flight No: ";
    getline(cin, userFlightNo);
        stringstream ss;
    ss <<"insert into user_reservation (u_id, u_name, u_phone, u_passport, u_ticket_id, u_flight_no, u_address) values ('"<<userId<<"','"+userName<<"','"+userPhone<<"','"<<userPassportNo<<"','"+userTicket<<"','"<<userFlightNo<<"','"<<userAddress<<"')";

    string insert_query = ss.str();
    const char* q = insert_query.c_str(); 

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Reserve Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        return 1;
    }
    else if (choose == 'a' || choose == 'A')
    {
        ReserveSeat();
    }
    else
    {
        exit(0);
    }
}

int UserTicket()
{

}


int FlightSchedule()
{

}
int DisplayPassenger()
{

}

int FlightDetails()
{

}

int Exit()
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
            system("cls");
            return 1;
        }
        else{
         cout<<endl<<"Input correctly please!";
         int x=Exit();
        }
}


int main()
{
    database::Connect();
    int choice;
    char sure;
    int menuChoice=1;




    do
    {
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
        case 1: {menuChoice = ReserveSeat();

                break;}

        case 2: {menuChoice = UserTicket();
                break;}

        case 3: {menuChoice = FlightSchedule();
                break;}

        case 4: {menuChoice = DisplayPassenger();
                break;}

        case 5: {menuChoice = FlightDetails();
                break;}

        case 6: {menuChoice = Exit();
                    break;}
        default:
        cout << "Please choose between The Given Numbers. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;

    }
    }while(menuChoice);

    return 0;
}
