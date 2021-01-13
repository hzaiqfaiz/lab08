/*
Lab_pensionplans.cpp
Purpose :
- Create a simple financial application to calculate retirement plans
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void displayMenu()
{
system("cls");
cout << "+-------------------------------------+"<<endl;
cout << "|    Golden Years Financial Inc.      |"<<endl;
cout << "|=====================================|"<<endl;
cout << "| Select:                             |"<<endl;
cout << "| 1 => Display Data                   |"<<endl;
cout << "| 2 => Change Data                    |"<<endl;
cout << "|-------------------------------------|"<<endl;
cout << "| 3 => One Lump Sum Withdrawal Plan   |"<<endl;
cout << "| 4 => Yearly Withdrawal Plan         |"<<endl;
cout << "| 5 => Comparison of Both Plans       |"<<endl;
cout << "|-------------------------------------|"<<endl;
cout << "| Q => Quit                           |"<<endl;
cout << "+-------------------------------------+"<<endl;
cout << endl;
cout << "Choice => ";
}

void displayData( int startingAge, int numOfYears,
double lumpSumAmount, double yearlyAmount,
double interestRate )
{
cout << endl;
cout << "Starting Age = " << startingAge<< endl;
cout << "Number of Years = " << numOfYears<< endl;
cout << "Lump Sum Amount = " << lumpSumAmount << endl;
cout << "Yearly Amount = " << yearlyAmount << endl;
cout << "Interest Rate (%) = " << interestRate << endl;
cout << endl;
system("pause");
}

void changeData( int* startingAge, int* numOfYears,
double* lumpSumAmount, double* yearlyAmount,
double* interestRate )//something not right here
{
    cout << endl;
    cout << "Starting Age = "<<endl;
    cin >> *startingAge;
    cout << "Number of Years = "<<endl;
    cin >> *numOfYears;
    cout << "Lump Sum Amount = "<<endl;
    cin >> *lumpSumAmount;
    cout << "Yearly Amount = "<<endl;
    cin >> *yearlyAmount;
    cout << "Interest Rate (%) = "<<endl;
    cin >> *interestRate;
}

void oneLumpSumWithdrawal( int startingAge, int numOfYears,
double lumpSumAmount, double interestRate )
{
    int age = startingAge;
    int lastAge = startingAge + numOfYears;
    double cash = lumpSumAmount;
    cout << "Age | Yearly Plan" << endl;
    cout << "----+----------------" << endl;
    while (age <= lastAge)
    {
        cout.width(3);
        cout << age << " | ";
        cout.width(15);
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << cash << endl;
    if (age != lastAge)
    cash = cash + cash*interestRate / 100.0;
    age++;
    }
system("pause");
}

void yearlyWithdrawal( int startingAge, int numOfYears,
double lumpSumAmount, double interestRate )
{
    int age = startingAge;
    int lastAge = startingAge + numOfYears;
    double cash = 25000;
    cout << "Age | Yearly Plan" << endl;
    cout << "----+----------------" << endl;
    while (age <= lastAge)
    {
        cout.width(3);
        cout << age << " | ";
        cout.width(15);
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << cash << endl;
    if (age != lastAge)
    cash = 25000 + cash + cash*interestRate / 100.0;
    age++;
    }
system("pause");
}

void comparison( int startingAge, int numOfYears,
double lumpSumAmount, double interestRate ){
    int age = startingAge;
    int lastAge = startingAge + numOfYears;
    double cash1 = lumpSumAmount;
    double cash2 = 25000;
    cout << "Age | Lump Sum Plan          Yearly Plan" << endl;
    cout << "----+-----------------------------------" << endl;
    while (age <= lastAge)
    {
        cout.width(6);
        cout << age << " | ";
        cout.width(15);
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << cash1 <<"       "<<cash2<< endl;
    if (age != lastAge){
        cash1 = cash1 + cash1*interestRate / 100.0;
        cash2 = 25000 + cash2 + cash2*interestRate / 100.0;
        }
    age++;https://github.com/hzaiqfaiz/lab08/blob/main/1-5.cpp
    }
system("pause");
}

int main()
{
    int startingAge = 55;
    int numOfYears  = 20;
    double lumpSumAmount = 400000;
    double yearlyAmount = 25000;
    double interestRate = 5;

    char choice;
    bool done = false;
    do
    {
        displayMenu();
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case '1' : displayData( startingAge, numOfYears,
                                lumpSumAmount, yearlyAmount,
                                interestRate);
                break;
        case '2' : changeData(&startingAge,&numOfYears, &lumpSumAmount, &yearlyAmount,&interestRate );
                   system("pause");
                break;
        case '3' : oneLumpSumWithdrawal(startingAge,numOfYears,lumpSumAmount,interestRate );
                //system("pause");
                break;
        case '4' : yearlyWithdrawal( startingAge,numOfYears,lumpSumAmount,interestRate );
            //system("pause");
            break;
        case '5' : comparison(startingAge,numOfYears,lumpSumAmount,interestRate );
            //system("pause");
            break;
        case 'Q' : done = true;
            break;
        default : cout << "Invalid selection, try again!"<<endl;
            //system("pause");
            break;
        }
    }while(!done);

    cout<<"Good Bye!"<<endl;
    cout<<endl;

    return 0;
}

