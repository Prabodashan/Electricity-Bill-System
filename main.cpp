#include <iostream>
#include<conio.h>
#include<string.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

const char companyName[30] = "WinSo Energy Resources";
const char branchName[30] = "Sri Lankan Branch";

//structure to store data
struct consumerCategory
{
    int consumerCategoryId;
    char consumerCategory[20];
    float ChargeforKilowattHour;
    float fixedPrice;
};

//make array using Structure consumer category and add data to it
struct consumerCategory cc[3] = {{1,"Residential", 15,250},{2,"Commercial", 25,500},{3,"Industrial", 50,1000}};


//method to exit or go to main menu
void exitToMenu(){
    char choice;
    cout<< "You want to proceed to the Main Menu or Exit"<<endl;
    cout<< "Y/y to the Main Menu or N/n to Exit"<<endl;
    cin>>choice;

    if(choice == 'N' || choice == 'n'){
        exit(0);
    }
}

//method to display electricity tariff details
void displayElectricityTariffDetails()
{

    system ("CLS"); // clear CMD
    cout<<"Electricity Tariff Details"<<endl;

    for(int i =0; i<sizeof(cc)/sizeof(consumerCategory); i++)
    {

        cout<<"   Consumer Category Id               :- "<<cc[i].consumerCategoryId<<endl;
        cout<<"   Consumer Category                  :- "<<cc[i].consumerCategory<<endl;
        cout<<"   Energy Charge for Kilowatt Hour    :- "<<cc[i].ChargeforKilowattHour<<endl;
        cout<<"   Fixed Price                        :- "<<cc[i].fixedPrice<<endl;
        cout<<endl;

    }

    cout<<"\n\n Press any key to go to Main Menu.."<<endl;
    getch();
    exitToMenu();
}

//method to calculate and display total bill
void calculateTotalBil()
{
    system ("CLS");

    int id, unit;
    cout<<"Consumer Category List"<<endl;
    for(int i =0; i<sizeof(cc)/sizeof(consumerCategory); i++)
    {

        cout<<"   Consumer Category Id               :- "<<cc[i].consumerCategoryId<<endl;
        cout<<"   Consumer Category                  :- "<<cc[i].consumerCategory<<endl;
    }
    cout<<"-------------------------"<<endl;

    //get consumer category and consume number of units from user
    cout<<"Enter your Consumer Category Id :";
    cin>>id;
    cout<<"Enter your Consume Number of Units :";
    cin>>unit;

    //calculate the total bill and display
    float totalBill = cc[id-1].fixedPrice + (unit * cc[id-1].ChargeforKilowattHour);
    cout<< "Total bill:"<<totalBill<<endl;
    cout<<"Press any key to go to Main Menu.."<<endl;
    getch();
    exitToMenu();
}




main()
{
    // variable for username and password
    char username[20];
    char password[20];
    // variable for count login attempt
    int loginAttempts = 0;
    // variable for user choice
    int choice=1;

    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);

    while(loginAttempts < 3)
    {
        // print the startup message with company name and branch current date and time
        cout<<" **************************************  "<<endl;
        cout<<"      "<<companyName<<endl;
        cout<<"      "<<branchName<<endl;
        cout <<"      "<<  1900 + ltm->tm_year<< ":";
        cout <<  1 + ltm->tm_mon<< ":";
        cout <<  ltm->tm_mday;
        cout <<" "<< 5+ltm->tm_hour << ":";
        cout << 30+ltm->tm_min << ":";
        cout << ltm->tm_sec << endl;
        cout<<" **************************************  "<<endl;

        //get username and password from user
        cout<<"please enter the username:";
        cin>>username;
        cout<<"please enter the password: ";
        cin>>password;

        //check username and passworf match
        if((strcmp(username,"a")==0 && strcmp(password,"a")==0) || (strcmp(username,"jake")==0 && strcmp(password,"jake@wiso")==0) || (strcmp(username,"Kevin22")==0 && strcmp(password,"winsoSL123")==0))
        {
            loginAttempts =5;
        }
        else
        {
            cout<<"Incorrect username/password. Please try again"<<endl;
            cout<<"Press any key to try again.."<<endl;
            getch();
            loginAttempts++;

            if(loginAttempts >= 3)
            {
                exit(0);
            }
            system ("CLS");
        }
    }
    while(choice!=3)
    {
        system ("CLS"); // clear CMD

        //display menu items
        cout<<"MAIN MENU  "<<endl;
        cout<<"1. Electricity Tariff Details  "<<endl;
        cout<<"2. Bill Calculator   "<<endl;
        cout<<"3. Log Out  "<<endl;
        cout<<"Enter your choice :";
        cin>>choice;
        switch(choice)
        {
        case 1:
            displayElectricityTariffDetails();
            break;
        case 2:
            calculateTotalBil();
            break;
        case 3:
            break;
        default:
        {
            cout<<"\n\n  Invalid Choice...!"<<endl;
            cout<<"\n\n Press any key to continue.."<<endl;
            getch();
        }
        }
    }
}


