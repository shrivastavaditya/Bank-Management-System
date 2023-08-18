#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
bool checkCaptcha(string &captcha, string &user_captcha)
{
    if (captcha == user_captcha)
        return true;
    else
        return false;
}
string generateCaptcha()
{
    time_t t;
    int n = 6;
    srand((unsigned)time(&t));
    char
        *chr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string captcha = "";
    while (n--)
        captcha.push_back(chr[rand() % 62]);
    return captcha;
}
void captcha_validation()
{
again:
    system("CLS");
    string captcha = generateCaptcha();
    fflush(stdin);
    cout << captcha;
    fflush(stdin);
    string usr_captcha;
    fflush(stdin);
    cout << "\nEnter above CAPTCHA: ";
    cin >> usr_captcha;
    if (checkCaptcha(captcha, usr_captcha))
    {
        cout << "\n";
        system("PAUSE");
    }
    else
    {
        cout << "Wrong captcha!! Enter again." << endl;
        cout << "\n";
        system("PAUSE");
        goto again;
    }
}
void otp_validation()
{
o:
    system("CLS");
    time_t t;
    int n = 4;
    srand((unsigned)time(&t));
    char *num = "0123456789";
    string otp = "";
    while (n--)
        otp.push_back(num[rand() % 10]);
    fflush(stdin);
    cout << otp;
    string uotp;
    fflush(stdin);
    cout << "\nEnter otp : ";
    cin >> uotp;
    fflush(stdin);
    if (uotp != otp)
    {
        cout << "\nWrong otp";
        cout << endl;
        system("PAUSE");
        goto o;
    }
    cout << "\n";
    system("PAUSE");
}
void intro();
void newuser();
void existing_user();
void enter(long long);
void transaction(long long);
void add(long long);
void send(long long);
void debitcard(long long);
void issue_debitcard(long long);
void create_debitcard_pin(long long);
void display_debitcard(long long, int);
void setting_debitcard(long long);
void profile(long long);
void setting(long long);
void contact(long long);
void ext();
class user
{
public:
    char name[50];
    char mail[50];
    long long pn;
    int pass;
    char address[100];
    long long aadhar;
    char fname[50];
    char mname[50];
    char occu[50];
    int gender;
    long long ai;
    char dob[12];
    long long accno;
    int mpin;
    long long bal;
    int dcheck;
    long long debitno;
    int dpin;
    int dcvv;
    int dstatus;
    int t;
    void getdata();
    void getpass();
    void get_account();
    void get_mpin();
} x, y;
void user::getdata()
{
    cout << "Enter full name : ";
    fflush(stdin);
    gets(name);
    cout << "\nEnter phone number : ";
    cin >> pn;
    cout << "\nEnter email id : ";
    fflush(stdin);
    gets(mail);
    otp_validation();
    system("CLS");
a:
    cout << "Enter aadhar no.: ";
    cin >> aadhar;
    long long check;
    check = aadhar;
    int count = 0;
    while (check > 0)
    {
        count++;
        check = check / 10;
    }
    if (count != 12)
    {
        cout << "\nAadhar number not valid.";
        cout << "\nIt must be of 12-digits." << endl;
        cout << "\n";
        system("PAUSE");
        system("CLS");
        goto a;
    }
    fflush(stdin);
    captcha_validation();
    system("CLS");
date:
    cout << "Enter DOB (DD/MM/YYYY) : ";
    fflush(stdin);
    gets(dob);
    if (dob[2] != '/' || dob[5] != '/' || dob[10] != '\0')
    {
        cout << "\nEnter valid format." << endl;
        cout << "\n";
        system("PAUSE");
        system("CLS");
        goto date;
    }
    cout << "\nEnter address : ";
    gets(address);
    cout << "\nEnter father's name : ";
    gets(fname);
    cout << "\nEnter mother's nmae : ";
    gets(mname);
    cout << "\nEnter occupation : ";
    gets(occu);
    cout << "\nEnter Gender";
    cout << "\n1.Male";
    cout << "\n2.Female";
    cout << "\n3.Other";
    cout << "\nEnter choice(1-3) : ";
    cin >> gender;
    cout << "\nEnter annual income : ";
    cin >> ai;
    bal = 0;
    t = 0;
    dcheck = 0;
    getpass();
    get_account();
    get_mpin();
}
void user::getpass()
{
start:
    int check, upass;
p:
    int count = 0;
    system("CLS");
    cout << "Create login password";
    cout << "\n\n\nEnter password (4-digit) : ";
    cin >> pass;
    check = pass;
    while (check > 0)
    {
        count++;
        check = check / 10;
    }
    if (count > 4)
    {
        cout << "\nGreater than 4-digit" << endl;
        cout << "\n";
        system("PAUSE");
        goto p;
    }
    if (count < 4)
    {
        cout << "\nLess than 4-digit" << endl;
        cout << "\n";
        system("PAUSE");
        goto p;
    }
    cout << "\nRe-enter the password to confirn : ";
    cin >> upass;
    if (upass != pass)
    {
        cout << "\nPassword didn't match." << endl;
        cout << "\n";
        goto start;
    }
}
void user::get_account()
{
x:
    user b;
    time_t t;
    srand((unsigned)time(&t));
    long int range = 9999999999 - 1000000000 + 1;
    accno = rand() % range + 1000000000;
    ifstream fin;
    fin.open("info.txt");
    fin.read((char *)&b, sizeof(b));
    while (!fin.eof())
    {
        if (accno == b.accno)
        {
            fin.close();
            goto x;
        }
        fin.read((char *)&b, sizeof(b));
    }
    fin.close();
}
void user::get_mpin()
{
s:
    int umpin;
m:
    int count = 0;
    system("CLS");
    cout << setw(115);
    cout << "Welcome, " << name;
    cout << "\n\nCreate a MPIN";
    cout << "\nNote: This will be used while transaction";
    cout << "\n\n\nEnter MPIN (6-digit) : ";
    cin >> mpin;
    int check = mpin;
    while (check > 0)
    {
        count++;
        check = check / 10;
    }
    if (count > 6)
    {
        cout << "\nGreater than 6-digit" << endl;
        cout << "\n";
        system("PAUSE");
        goto m;
    }
    if (count < 6)
    {
        cout << "\nLess than 6-digit" << endl;
        cout << "\n";
        system("PAUSE");
        goto m;
    }
    cout << "\nRe-enter the MPIN to confirn : ";
    cin >> umpin;
    if (umpin != mpin)
    {
        cout << "\nMPIN didn't match." << endl;
        cout << "\n";
        goto s;
    }
}
void enter(long long a)
{
s:
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        if (a == x.accno)
        {
            int ch;
            long long ac;
            int l, l1;
            ac = x.accno;
            system("CLS");
            l = strlen(x.name);
            l1 = 106 + (9 - l) / 2;
            cout << setw(115 - l);
            cout << "Welcome, " << x.name;
            cout << "\n\n\nWallet Balance : Rs. " << x.bal;
            cout << "\n\n";
            cout << setw(l1 + 4);
            cout << "Options";
            cout << "\n\n";
            cout << setw(l1 + 7);
            cout << "1.Transaction";
            cout << "\n\n";
            cout << setw(l1 + 6);
            cout << "2.Debit Card";
            cout << "\n\n";
            cout << setw(l1 + 6);
            cout << "3.My Profile";
            cout << "\n\n";
            cout << setw(l1 + 5);
            cout << "4.Settings";
            cout << "\n\n";
            cout << setw(l1 + 6);
            cout << "5.Contact Us";
            cout << "\n\n";
            cout << setw(l1 + 3);
            cout << "6.Exit";
            cout << "\n\n";
            cout << setw(l1 + 7);
            cout << "Enter choice : ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                f.close();
                transaction(ac);
                break;
            case 2:
                f.close();
                debitcard(ac);
                break;
            case 3:
                f.close();
                profile(ac);
                break;
            case 4:
                f.close();
                setting(ac);
                break;
            case 5:
                f.close();
                contact(ac);
                break;
            case 6:
                f.close();
                ext();
                break;
            default:
                f.close();
                system("CLS");
                cout << "Wrong input !!";
                cout << "\n\n";
                system("PAUSE");
                enter(ac);
                break;
            }
        }
    }
}
void transaction(long long a)
{
    system("CLS");
    long long ac = a;
    int umpin;
    cout << "Enter MPIN : ";
    cin >> umpin;
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        if (ac == x.accno)
        {
            if (umpin == x.mpin)
            {
                system("CLS");
                int o;
                cout << "1.Add money to wallet";
                cout << "\n2.Send money";
                cout << "\n3.No. of transactions done till now";
                cout << "\n\nEnter choice (1-3) : ";
                cin >> o;
                switch (o)
                {
                case 1:
                    f.close();
                    add(ac);
                    break;
                case 2:
                    f.close();
                    send(ac);
                    break;
                case 3:
                    system("CLS");
                    cout << "Total no of transactions done till now : " << x.t;
                    cout << "\n\n";
                    system("PAUSE");
                    f.close();
                    enter(ac);
                    break;
                default:
                    f.close();
                    cout << "\n\nWrong input !!";
                    cout << "\n\n";
                    system("PAUSE");
                    enter(ac);
                    break;
                }
            }
            else
            {
                cout << "\nInvalid MPIN !!";
                cout << "\n\n";
                system("PAUSE");
                f.close();
                enter(ac);
            }
        }
    }
}
void add(long long a)
{
    system("CLS");
    long long ac = a;
    int ch;
    cout << "How do you want to add money to wallet ?";
    cout << "\n\n1.UPI";
    cout << "\n2.Bank Transfer";
    cout << "\n\nEnter choice(1-2) : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        fstream f;
        f.open("info.txt", ios::in | ios::out);
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                char upi[50];
                long long upn, amt1;
                char c;
                cout << "\nEnter UPI Id linked to your phone no. associated with us : ";
                fflush(stdin);
                gets(upi);
                cout << "\nEnter phone no.: ";
                cin >> upn;
                cout << "\n\nValidating phone no. and UPI Id..... Please wait!!";
                Sleep(2.5 * 1000);
                if (x.pn == upn)
                {
                    system("CLS");
                    cout << "Re-directing to UPI app...";
                    Sleep(2.5 * 1000);
                    system("CLS");
                    cout << "Enter amount : ";
                    cin >> amt1;
                    otp_validation();
                    x.bal += amt1;
                    x.t++;
                    system("CLS");
                    cout << "Adding money to wallet....Please wait!!";
                    Sleep(2.5 * 1000);
                    cout << "\n\n\nWallet Balance has been updated successfully.";
                    cout << "\n\n";
                    system("PAUSE");
                    int pos = f.tellg();
                    f.seekp(pos - sizeof(x));
                    f.write((char *)&x, sizeof(x));
                }
                else
                {
                    cout << "\nInvalid UPI Id/phone no.";
                    cout << "\n\n";
                    system("PAUSE");
                }
            }
        }
        f.close();
        enter(ac);
        break;
    }
    case 2:
    {
        fstream f1;
        f1.open("info.txt", ios::in | ios::out);
        f1.seekg(0);
        while (f1.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                long long ac1, ac2, amt2;
                char ifsc[20];
                char n[50];
                cout << "\nEnter amount : ";
                cin >> amt2;
            bt:
                system("CLS");
                cout << "\nEnter account no.: ";
                cin >> ac1;
                cout << "\nRe-enter account no.: ";
                cin >> ac2;
                if (ac1 == ac2)
                {
                    cout << "\nEnter IFSC code : ";
                    fflush(stdin);
                    gets(ifsc);
                    cout << "\nEnter name : ";
                    gets(n);
                }
                else
                {
                    cout << "\nAccount no. didn't match...Try again!!";
                    cout << "\n\n";
                    system("PAUSE");
                    goto bt;
                }
                system("CLS");
                cout << "\nRedirecting to bank.... Please wait!!";
                Sleep(2.5 * 1000);
                captcha_validation();
                x.bal += amt2;
                x.t++;
                system("CLS");
                cout << "Adding money to wallet....Please wait!!";
                Sleep(2.5 * 1000);
                cout << "\n\n\nWallet Balance has been updated successfully.";
                cout << "\n\n";
                system("PAUSE");
                int pos = f1.tellg();
                f1.seekp(pos - sizeof(x));
                f1.write((char *)&x, sizeof(x));
                cout << x.bal << " ";
            }
        }
        f1.close();
        enter(ac);
        break;
    }
    default:
        system("CLS");
        cout << "Wrong input !!";
        cout << "\n\n";
        system("PAUSE");
        enter(ac);
        break;
    }
}
void send(long long a)
{
    system("CLS");
    long long ac = a;
    int ch;
    cout << "How do you want to send money ?";
    cout << "\n\n1.UPI";
    cout << "\n2.Bank Transfer";
    cout << "\n\nEnter choice(1-2) : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        fstream f;
        f.open("info.txt", ios::in | ios::out);
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                char upi[50];
                char n1[50];
                long long upn, amt1;
                char c;
                cout << "\nEnter Receiver's details";
                cout << "\n\nEnter UPI Id : ";
                fflush(stdin);
                gets(upi);
                cout << "\nEnter phone no.: ";
                cin >> upn;
                cout << "\nEnter name : ";
                fflush(stdin);
                gets(n1);
                cout << "\n\nValidating phone no. and UPI Id..... Please wait!!";
                Sleep(2.5 * 1000);
                system("CLS");
                cout << "Re-directing to UPI app...";
                Sleep(2.5 * 1000);
                system("CLS");
                cout << "Enter amount : ";
                cin >> amt1;
                otp_validation();
                if (amt1 > x.bal)
                {
                    system("CLS");
                    cout << "Insufficient balance...!!";
                    cout << "\n\n";
                    cout << "Taking back to main page...";
                    Sleep(1.5 * 1000);
                }
                else
                {
                    x.bal -= amt1;
                    x.t++;
                    system("CLS");
                    cout << "Sending money....Please wait!!";
                    Sleep(2.5 * 1000);
                    system("CLS");
                    cout << "\nRs. " << amt1 << " has been sent successfully to" << n1;
                    cout << "\n\n";
                    system("PAUSE");
                    int pos = f.tellg();
                    f.seekp(pos - sizeof(x));
                    f.write((char *)&x, sizeof(x));
                }
            }
        }
        f.close();
        enter(ac);
        break;
    }
    case 2:
    {
        fstream f1;
        f1.open("info.txt", ios::in | ios::out);
        f1.seekg(0);
        while (f1.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                long long ac1, ac2, amt2;
                char ifsc[20];
                char n2[50];
                cout << "\nEnter amount : ";
                cin >> amt2;
            bt:
                system("CLS");
                cout << "\nEnter Receiver's details";
                cout << "\n\nEnter account no.: ";
                cin >> ac1;
                cout << "\nRe-enter account no.: ";
                cin >> ac2;
                if (ac1 == ac2)
                {
                    cout << "\nEnter IFSC code : ";
                    fflush(stdin);
                    gets(ifsc);
                    cout << "\nEnter name : ";
                    gets(n2);
                }
                else
                {
                    cout << "\nAccount no. didn't match...Try again!!";
                    cout << "\n\n";
                    system("PAUSE");
                    goto bt;
                }
                system("CLS");
                cout << "Redirecting to bank.... Please wait!!";
                Sleep(2.5 * 1000);
                captcha_validation();
                if (amt2 > x.bal)
                {
                    system("CLS");
                    cout << "Insufficient balance...!!";
                    cout << "\n\n";
                    cout << "Taking back to main page...";
                    Sleep(1.5 * 1000);
                }
                else
                {
                    x.bal -= amt2;
                    x.t++;
                    system("CLS");
                    cout << "Sending money....Please wait!!";
                    Sleep(2.5 * 1000);
                    system("CLS");
                    cout << "\nRs. " << amt2 << " has been sent successfully to" << n2;
                    cout << "\n\n";
                    system("PAUSE");
                    int pos = f1.tellg();
                    f1.seekp(pos - sizeof(x));
                    f1.write((char *)&x, sizeof(x));
                }
            }
        }
        f1.close();
        enter(ac);
        break;
    }
    default:
        system("CLS");
        cout << "Wrong input !!";
        cout << "\n\n";
        system("PAUSE");
        enter(ac);
        break;
    }
}
void debitcard(long long a)
{
    system("CLS");
    long long ac = a;
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        if (ac == x.accno)
        {
            if (x.dcheck == 0)
            {
                char ch;
                cout << "Sorry!! Currently, you do not own any card.";
                cout << "\n\nDo you want to apply for debit card (y/n) : ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    issue_debitcard(ac);
                else
                {
                    f.close();
                    cout << "\n\n";
                    system("PAUSE");
                    enter(ac);
                }
            }
            else
                display_debitcard(ac, 0);
        }
    }
}
void issue_debitcard(long long a)
{
dc:
    long long ac = a;
    long long udebit, checkdebit = 0;
    int ucvv;
    time_t t;
    srand((unsigned)time(&t));
    long int range = 9999999999 - 1000000000 + 1;
    udebit = rand() % range + 1000000000;
    int drange = 999 - 100 + 1;
    ucvv = rand() % drange + 100;
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        if (udebit == checkdebit)
        {
            f.close();
            goto dc;
        }
        if (ac == x.accno)
        {
            x.debitno = udebit;
            x.dcvv = ucvv;
            x.dcheck = 1;
            x.dstatus = 1;
            int pos = f.tellg();
            f.seekp(pos - sizeof(x));
            f.write((char *)&x, sizeof(x));
            cout << "\n\nRequest processing.....";
            Sleep(5 * 1000);
            system("CLS");
            cout << "DEBIT CARD has been issued successfully !!";
            cout << "\n\nIt will be delivered to you within 5 working days at" << x.address << "." << endl;
            cout << "\n\n";
            system("PAUSE");
        }
        checkdebit = x.debitno;
    }
    f.close();
    display_debitcard(ac, 1);
}
void display_debitcard(long long a, int check)
{
    system("CLS");
    long long ac = a;
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        if (ac == x.accno)
        {
            cout << "Displaying DEBIT CARD....";
            Sleep(1.5 * 1000);
            cout << "\n\nCard status : ";
            if (x.dstatus == 1)
                cout << "ACTIVATED";
            else
                cout << "DEACTIVATED";
            cout << "\n\n\n";
            int l = strlen(x.name);
            for (int i = 0; i < 41; i++)
                cout << '-';
            cout << "\n"
                 << '|';
            cout << setw(2 + l) << x.name;
            cout << setw(36 - l) << "A&A FINANCES";
            cout << setw(2) << '|';
            cout << "\n|" << setw(40) << '|';
            cout << "\n|" << setw(25);
            cout << x.debitno;
            cout << setw(15) << '|';
            cout << "\n|" << setw(40) << '|';
            cout << "\n|" << setw(38);
            cout << x.dcvv << setw(2) << '|' << endl;
            for (int i = 0; i < 41; i++)
                cout << '-';
        }
    }
    f.close();
    if (check == 1)
    {
        cout << "\n\n\n\n";
        system("PAUSE");
        create_debitcard_pin(ac);
    }
    else
        setting_debitcard(ac);
}
void create_debitcard_pin(long long a)
{
    long long ac = a;
    int udpin, cudpin, check;
    system("CLS");
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        if (ac == x.accno)
        {
        dp:
            int count = 0;
            cout << "Create 4-digit pin : ";
            cin >> udpin;
            check = udpin;
            while (check > 0)
            {
                count++;
                check = check / 10;
            }
            if (count > 4)
            {
                cout << "\nGreater than 4-digit" << endl;
                cout << "\n\n";
                system("PAUSE");
                goto dp;
            }
            if (count < 4)
            {
                cout << "\nLess than 4-digit" << endl;
                cout << "\n\n";
                system("PAUSE");
                goto dp;
            }
            cout << "\nRe-enter the pin to confirn : ";
            cin >> cudpin;
            if (udpin != cudpin)
            {
                cout << "\nPassword didn't match." << endl;
                cout << "\n\n";
                system("PAUSE");
                goto dp;
            }
            else
            {
                cout << "\n\nPin has been created suucessfully !!";
                x.dpin = udpin;
                int pos = f.tellg();
                f.seekp(pos - sizeof(x));
                f.write((char *)&x, sizeof(x));
            }
        }
    }
    f.close();
    cout << "\n\n";
    system("PAUSE");
    enter(ac);
}
void setting_debitcard(long long a)
{
    long long ac = a;
    int ch;
    cout << "\n\nOptions";
    cout << "\n\n1.View Pin";
    cout << "\n2.Reset Pin";
    cout << "\n3.Set limit";
    cout << "\n4.Block/Unblock card";
    cout << "\n\nEnter choice(1-4) : ";
    cin >> ch;
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    switch (ch)
    {
    case 1:
    {
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                captcha_validation();
                system("CLS");
                cout << "PIN : " << x.dpin;
            }
        }
        cout << "\n\n";
        system("PAUSE");
        f.close();
        enter(ac);
        break;
    }
    case 2:
    {
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                f.close();
                system("CLS");
                create_debitcard_pin(ac);
            }
        }
        break;
    }
    case 3:
    {
        system("CLS");
        int limit;
        cout << "Enter limit to be set : ";
        cin >> limit;
        cout << "\n\nLimit has been set successfully !!";
        f.close();
        cout << "\n\n";
        system("PAUSE");
        enter(ac);
        break;
    }
    case 4:
    {
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                system("CLS");
                int take;
                cout << "Card status : ";
                if (x.dstatus == 1)
                {
                    cout << "ACTIVATED";
                    cout << "\n\nPress 0 to DEACTIVATE !! ";
                    cin >> take;
                    cout << "\n\nProcessing Request... Please wait !!";
                    Sleep(1.5 * 1000);
                    if (take == 0)
                        x.dstatus = 1;
                    cout << "\n\nRequest processed sucessfully !!";
                    system("CLS");
                    cout << "Card status : DEACTIVATED";
                }
                else
                {
                    cout << "\n\nWrong input !!";
                }
            }
        }
        f.close();
        cout << "\n\n";
        system("PAUSE");
        enter(ac);
        break;
    }
    default:
    {
        f.close();
        system("CLS");
        cout << "\n\nWrong input !!";
        cout << "\n\n";
        system("PAUSE");
        enter(ac);
        break;
    }
    }
}
void profile(long long a)
{
    system("CLS");
    captcha_validation();
    system("CLS");
    int ch;
    long long ac = a;
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        if (ac == x.accno)
        {
            cout << "Account number : " << x.accno;
            cout << "\n\nName : " << x.name;
            cout << "\n\nDate of Birth : " << x.dob;
            cout << "\n\nAadhar Number : " << x.aadhar;
            cout << "\n\nPhone Number : " << x.pn;
            cout << "\n\nEmail : " << x.mail;
            cout << "\n\nGender : ";
            if (x.gender == 1)
                cout << "Male";
            else if (x.gender == 2)
                cout << "Female";
            else
                cout << "Other";
            cout << "\n\nOccupation : " << x.occu;
            cout << "\n\nFather's Name : " << x.fname;
            cout << "\n\nMother's Name : " << x.mname;
            cout << "\n\nAddress : " << x.address;
            cout << "\n\nTo view MPIN, enter 1 ";
            cin >> ch;
            if (ch == 1)
            {
                otp_validation();
                system("CLS");
                cout << "MPIN : " << x.mpin;
            }
            else
                cout << "\n\nSorry, Wrong input !!";
        }
    }
    f.close();
    cout << "\n\n";
    system("PAUSE");
    enter(ac);
}
void setting(long long a)
{
    system("CLS");
    long long ac = a;
    int ch;
    cout << "1.Change login password";
    cout << "\n2.Change MPIN";
    cout << "\n3.Deactivate account";
    cout << "\n\nEnter choice(1-3) : ";
    cin >> ch;
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    switch (ch)
    {
    case 1:
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                int npass, cnpass;
            nlp:
                system("CLS");
                int count = 0;
                cout << "Enter new login password(4-digit) : ";
                cin >> npass;
                int check = npass;
                while (check > 0)
                {
                    count++;
                    check = check / 10;
                }
                if (count > 4)
                {
                    cout << "\nGreater than 4-digit" << endl;
                    cout << "\n";
                    system("PAUSE");
                    goto nm;
                }
                if (count < 4)
                {
                    cout << "\nLess than 4-digit" << endl;
                    cout << "\n";
                    system("PAUSE");
                    goto nlp;
                }
                cout << "\nRe-enter the password to confirn : ";
                cin >> cnpass;
                if (npass != cnpass)
                {
                    cout << "\nPassword didn't match." << endl;
                    f.close();
                    system("CLS");
                    cout << "Redirecting to main page...";
                    Sleep(1.5 * 1000);
                    enter(ac);
                }
                else
                {
                    otp_validation();
                    system("CLS");
                    cout << "Updating login password... Please wait !!";
                    Sleep(2 * 1000);
                    x.pass = npass;
                    int pos = f.tellg();
                    f.seekp(pos - sizeof(x));
                    f.write((char *)&x, sizeof(x));
                    cout << "\n\nLogin password updated successfully !!";
                    cout << "\n\n";
                    system("PAUSE");
                }
            }
        }
        f.close();
        existing_user();
        break;
    case 2:
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac == x.accno)
            {
                int nmpin, cnmpin;
            nm:
                system("CLS");
                int count = 0;
                cout << "Enter new MPIN(6-digit) : ";
                cin >> nmpin;
                int check = nmpin;
                while (check > 0)
                {
                    count++;
                    check = check / 10;
                }
                if (count > 6)
                {
                    cout << "\nGreater than 6-digit" << endl;
                    cout << "\n";
                    system("PAUSE");
                    goto nm;
                }
                if (count < 6)
                {
                    cout << "\nLess than 6-digit" << endl;
                    cout << "\n";
                    system("PAUSE");
                    goto nm;
                }
                cout << "\nRe-enter the password to confirn : ";
                cin >> cnmpin;
                if (nmpin != cnmpin)
                {
                    cout << "\nMPIN didn't match." << endl;
                    f.close();
                    system("CLS");
                    cout << "Redirecting to main page...";
                    Sleep(1.5 * 1000);
                    enter(ac);
                }
                else
                {
                    otp_validation();
                    system("CLS");
                    cout << "Updating MPIN... Please wait !!";
                    Sleep(2 * 1000);
                    x.mpin = nmpin;
                    int pos = f.tellg();
                    f.seekp(pos - sizeof(x));
                    f.write((char *)&x, sizeof(x));
                    cout << "\n\nMPIN updated successfully !!";
                    cout << "\n\n";
                    system("PAUSE");
                }
            }
        }
        f.close();
        enter(ac);
        break;
    case 3:
    {
        system("CLS");
        char ch;
        char feedback[1001];
        ofstream f1;
        f1.open("temp.txt", ios::app);
        f.seekg(0);
        while (f.read((char *)&x, sizeof(x)))
        {
            if (ac != x.accno)
            {
                f1.write((char *)&x, sizeof(x));
            }
            else
            {
                if (x.bal > 0)
                {
                    cout << "Your remaining balance of Rs." << x.bal << "will be credited to your upi id associated with phone no. " << x.pn;
                    cout << "\n\n";
                    system("PAUSE");
                }
            }
        }
        f.close();
        f1.close();
        remove("info.txt");
        rename("temp.txt", "info.txt");
        system("CLS");
        cout << "Account has been deactivated succesfully!!";
        cout << "\n\nWould you like to provide feedback why are you deactivating your account(y/n) : ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            system("CLS");
            cout << "We are happy to hear from you !!";
            cout << "\n\nEnter text (max. 1000 letters)" << endl;
            fflush(stdin);
            gets(feedback);
            system("CLS");
            cout << "Thanks for your feedback !!";
            ext();
        }
        else
            ext();
    }
    default:
        f.close();
        system("CLS");
        cout << "Wrong input !!";
        cout << "\n\n";
        system("PAUSE");
        enter(ac);
        break;
    }
}
void contact(long long a)
{
    long long ac = a;
    system("CLS");
    cout << "Thanks for reaching out to us.";
    cout << "\n\nContact no. : +912225222501/02/03";
    cout << "\nOR";
    cout << "\nMail us at : contact@aafinances.com";
    cout << "\n\nIt will be our pleasure to hear from you. Thanks !!";
    cout << "\n\n";
    system("PAUSE");
    enter(ac);
}
void intro()
{
    system("CLS");
    cout << "\n\n\n\n\n";
    cout << setw(120);
    cout << "Welcome to A&A FINANCES" << endl;
    cout << "\n\n\n\n\n\n\n\n";
    cout << setw(113);
    cout << "1.New User" << endl;
    cout << "\n";
    cout << setw(119);
    cout << "2.Existing user?Log in" << endl;
    cout << "\n";
    cout << setw(111);
    cout << "3.exit";
    cout << "\n\n\n\n\n";
    cout << setw(117);
    cout << "Enter choice(1-3) : ";
}
void newuser()
{
    user a;
    ofstream fout;
    fout.open("info.txt", ios::app);
    a.getdata();
    fout.write((char *)&a, sizeof(a));
    fout.close();
    long long ac = a.accno;
    enter(ac);
}
void existing_user()
{
    user b;
    long long upn;
    int upass, upass1;
    char umail[100];
    fstream f;
again:
    system("CLS");
    int flag = 0, count1 = 0, count2 = 0;
    f.open("info.txt");
    cout << "Enter phone no.: ";
    cin >> upn;
    cout << "\nEnter password : ";
    cin >> upass;
    f.seekg(0);
    while (f.read((char *)&b, sizeof(b)))
    {
        long long ac = b.accno;
        count1++;
        if (upn != b.pn || upass != b.pass)
        {
            count2++;
        }
        else
        {
            f.close();
            cout << "\n\n";
            system("PAUSE");
            captcha_validation();
            enter(ac);
        }
    }
    f.close();
    cout << "\n\n";
    system("PAUSE");
    if (count1 == count2)
    {
        cout << "\nInvalid phone no./password";
        char ch;
        cout << "\nForgot password ?(y/n) : ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            flag = 1;
        }
        else
            goto again;
    }
    if (flag != 0)
    {
        f.open("info.txt", ios::in | ios::out);
        long long uaccno;
        char udob[12];
        int check = 0;
        system("CLS");
        cout << "Enter email id : ";
        fflush(stdin);
        gets(umail);
    date:
        cout << "Enter DOB (DD/MM/YYYY) : ";
        fflush(stdin);
        gets(udob);
        if (udob[2] != '/' || udob[5] != '/' || udob[10] != '\0')
        {
            cout << "\nEnter valid date format." << endl;
            cout << "\n";
            system("PAUSE");
            goto date;
        }
        f.seekg(0);
        while (f.read((char *)&b, sizeof(b)))
        {
            long long ac = b.accno;
            if ((strcmp(b.mail, umail) == 0) && (strcmp(udob, b.dob) == 0))
            {
                check = 1;
            np:
                system("CLS");
                cout << "Enter new password : ";
                cin >> upass;
                cout << "\nRe-enter the password to confirn : ";
                cin >> upass1;
                if (upass != upass1)
                {
                    cout << "\nPassword didn't match." << endl;
                    cout << "\n\n";
                    system("PAUSE");
                    goto np;
                }
                else
                {
                    otp_validation();
                    b.pass = upass;
                    system("CLS");
                    cout << "Password has been reset successfully!!" << endl;
                    cout << "\n\n";
                    system("PAUSE");
                    int pos = f.tellg();
                    f.seekp(pos - sizeof(b));
                    f.write((char *)&b, sizeof(b));
                    f.close();
                    enter(ac);
                }
            }
        }
        if (check == 0)
        {
            system("CLS");
            cout << "Sorry!! You are not registered with us.";
            cout << "\n\n";
            cout << "Redirecting you back....";
            Sleep(1.5 * 1000);
            intro();
        }
    }
}
void ext()
{
    for (int i = 5; i > -1; i--)
    {
        system("CLS");
        cout << "\n\n\n\n\n";
        cout << setw(125);
        cout << "Thanks for visiting us !!";
        cout << "\n\n";
        cout << setw(119);
        cout << "Best wishes !!";
        cout << "\n\n\n\n\n";
        cout << setw(113);
        cout << "Exiting in " << i << " sec...";
        Sleep(1 * 1000);
    }
    exit(0);
}
void display()
{
    fstream f;
    f.open("info.txt", ios::in | ios::out);
    f.seekg(0);
    while (f.read((char *)&x, sizeof(x)))
    {
        cout << x.name << " " << x.mail << " " << x.bal << " " << x.pass << " " << x.dob << endl;
    }
    f.close();
}
int main()
{
    int ch;
    intro();
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("CLS");
        newuser();
        break;
    case 2:
        existing_user();
        break;
    case 3:
        ext();
        break;
    case 1010:
        display();
        break;
    default:
        system("CLS");
        cout << "\nWrong input !!";
        cout << "\n\n";
        system("PAUSE");
        intro();
        break;
    }
    return 0;
}