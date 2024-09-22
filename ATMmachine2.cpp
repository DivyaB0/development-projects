//Creating ATM Machine With Transfer Method  using OOP | Bank Management System Project
//check balance
//cash withdraw
//cash deposit
//cash transfer
//exit
#include<iostream>
using namespace std;
class ATM
{
private:
int balance;
int pinCode, success;
public: 
//construction
ATM(int bal, int pin){
    balance=bal;
    pinCode=pin;
}
//view balance
int getBalance()
{
    return balance;
}
//for cash withdraw...
int withdraw(int amount, int pin)
{
    if(pin!=pinCode){
    return false;
}
if(amount>balance){
    return false;
}
//balance=balance-amount;
balance-=amount;
return true;
}
//for deposite
void deposit(int amount)
{
//balance=balance+amount;
balance+= amount;
}
//for transfer
int transfer(int amount, ATM receiver, int pin)
{
if(pin!=pinCode){
    return false;
}
success=withdraw(amount, pin);
if(success){
    receiver.deposit(amount);
    return true;
}
else{
    return false;
}
}
};
main(){
    ATM atm(1000, 1234);
    int choice, amount, success, pin;
    char op;
    do{
        system("cls");
       cout<<"1.View Balance"<<endl;
       cout<<"2.Cash Withdraw"<<endl;
       cout<<"3.Cash deposit"<<endl;
       cout<<"4.Cash Transfer"<<endl;
       cout<<"5. Exit"<<endl;
       cout<<"Enter Your Choice: "<<endl;
       cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"Your Balance is :"<<atm.getBalance();
        break;
        case 2:
        cout<<"Your Available Balance is :"<<atm.getBalance();
        cout<<"\n Enter the Amount to Withdraw :";
        cin>>amount;
        success=atm.withdraw(amount,1234);
        if(success){
            cout<<"withdraw is successful..."<<endl;
        }
        else{
            cout<<"Insufficient Balance...."<<endl;
        }
        break;
        case 3:
        cout<<"Enter the Amount to Deposit :";
        cin>>amount;
        atm.deposit(amount);
         cout<<"Deposit is successful..."<<endl;
         break;
         case 4:
         cout<<"Enter the amount to Transfer : ";
         cin>>amount;
         cout<<"Enter the Pin Code :";
         cin>>pin;
         success=atm.transfer(amount, atm, pin);
         if(success){
            cout<<"Transfer is successful..."<<endl;
        }
        else{
            cout<<"Invalid pin or Insufficient Balance...."<<endl;
        }
        break;
        case 5:
        cout<<" Thanks for using ATM"<<endl;
        exit(1);
        break;
        default:
        cout<<"Invalid Choice"<<endl;

    }
    cout<<"\n Do You Want to try another Transaction [yes / no] : ";
    cin>>op;
    }
    while(op=='y' || op=='Y');
    
    //cout<<"Your Balance is :"<<atm.getBalance();
}