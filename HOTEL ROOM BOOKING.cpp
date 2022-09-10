/* JOYDEEP GHOSH
INTERNSHIP STUDIO PROJECT
SRM UNIVERSITY,ANDHRA PRADESH
COMPLETED ON 29 JULY 2022 */
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cmath>
using namespace std;
static int q = 0;
class reservation
{
    char room_number[5], host[5], start[5], send[5], from[5], to[5], chair[10][4][10];

public:
    void booking();
    void allotment();
    void empty();
    void display();
    void avail();
    void position(int t);
} hotel[10];
void design(char todraw)
{
    for (int i = 0; i < 402; i++)
        cout << todraw;
}
void reservation::booking()
{
    cout << "Please enter room number : ";
    cin >> hotel[q].room_number;
    cout << endl
         << "Please enter Customer's name : ";
    cin >> hotel[q].host;
    cout << endl
         << "Enter start time :";
    cin >> hotel[q].start;
    cout << endl
         << "Enter Session end time :";
    cin >> hotel[q].send;
    cout << endl
         << "From : ";
    cin >> hotel[q].from;
    cout << endl
         << "To : ";
    cin >> hotel[q].to;
    hotel[q].empty();
    q++;
}
void reservation::allotment()
{
    int chair;
    char num[5];
top:
    cout << "Room no. :";
    cin >> num;
    int n;
    for (n = 0; n <= q; n++)
    {
        if (strcmp(hotel[n].room_number, num) == 0)
            break;
    }
    while (n <= q)
    {
        cout << endl
             << "Chair number :";
        cin >> chair;
        if (chair > 40)
            cout << endl
                 << "Only 40 chairs are available int the room !";
        else
        {
            if (strcmp(hotel[n].chair[chair / 4][(chair % 4) - 1], "Empty") == 0)
            {
                cout << "Enter traveller's name: ";
                cin >> hotel[n].chair[chair / 4][(chair % 4) - 1];
                break;
            }
            else
                cout << "The chair no. is already reserved " << endl;
        }
    }
    if (n > q)
    {
        cout << "Enter correct room no" << endl;
        goto top;
    }
}
void reservation::empty()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(hotel[q].chair[i][j], "Empty");
        }
    }
}
void reservation::display()
{
    int a;
    char num[5];
    cout << "Enter room no :";
    cin >> num;
    for (a = 0; a <= q; a++)
    {
        if (strcmp(hotel[a].room_number, num) == 0)
            break;
    }
    while (a <= q)
    {
        design('#');
        cout << "Room number \t" << hotel[a].room_number << "\nHost: \t" << hotel[a].host << "\t\tStart time: \t"
             << hotel[a].start << "\t End time:" << hotel[a].send << "\nFrom: \t\t" << hotel[a].from << "\t\tTo: \t\t" << hotel[a].to << "\n";
        design('#');
        hotel[0].position(a);
        int n = 1;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                n++;
                if (strcmp(hotel[n].chair[i][j], "Empty") != 0)
                {
                    // cout<<endl<<" The chair no."<<(n-1)<<"is reserved for : "<<hotel[a].chair[i][j]<<".";
                }
            }
        }
        break;
    }
    if (a > q)
        cout << "Enter correct room number :";
}
void reservation::position(int l)
{
    int s = 0, p = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(hotel[l].chair[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << hotel[l].chair[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << hotel[l].chair[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << " Chairs empty in Room No: " << hotel[l].room_number;
}
void reservation::avail()
{
    for (int n = 0; n < q; n++)
    {
        design('#');
        cout << "Room no: \t" << hotel[n].room_number << "\nHost: \t" << hotel[n].host << "\t\tStart time: \t" << hotel[n].start << "\tEnd  Time: \t"
             << hotel[n].send << "\nFrom: \t\t" << hotel[n].from << "\t\tTo: \t\t\t"
             << hotel[n].to << "\n";
        design('#');
        design('_');
    }
}
int main()
{
    system("cls");
    int w;
    while (1)
    {
        cout << "\n\n\n\n\n";
        design('#');
        cout << "\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t Hotel Room Booking System";
        cout << "\n\n\n\t\t\t\t\t\t1.Booking\n\t\t\t\t\t\t"
             << "2.Reservation\n\t\t\t\t\t\t"
             << "3.Show\n\t\t\t\t\t\t"
             << "4.Rooms Available. \n\t\t\t\t\t\t"
             << "5.Exit";
        cout << "\n\t\t\t\t\t\tEnter your choice:-> ";
        cin >> w;
        switch (w)
        {

        case 1:
            hotel[q].booking();
            break;
        case 2:
            hotel[q].allotment();
            break;
        case 3:
            hotel[0].display();
            break;
        case 4:
            hotel[0].avail();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}