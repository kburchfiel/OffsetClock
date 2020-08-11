//AMDG
//Program for displaying UTC offsets at the time the program was run
//Kenneth Burchfiel


/*Helpful resources included:
1. https://www.geeksforgeeks.org/c-program-print-current-day-date-time/ by Mrigendra Singh
2. Programming: Principles and Practices (2nd ed.) by Bjarne Stroustrup
3. Wikipedia (for time zone information and a list of current UTC offsets)
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>


using namespace std;


void offset(tm*tmptr, int houroffset, int minoffset, string utclabel)
{
    int hour = (*tmptr).tm_hour + houroffset;
    int min = (*tmptr).tm_min + minoffset;
    if (min >= 60) //Some offsets increase the minute count by 30 or 45, so the code needs to adjust for this
    {
        min -= 60;
        hour++;
    }

    if (hour >= 24)
    {
        if (min < 10) //This ensures that the program displays, for instance, 8:07 and not 8:7

        {
            cout << utclabel << ": (next day) " << hour-24 << ":0" << min << "\n";
        }
        else
        {
            cout << utclabel << ": (next day) " << hour-24 << ":" << min << "\n";
        }
    }

    else if (hour < 0)
    {
        if (min < 10)

        {
            cout << utclabel << ": (previous day) " << hour+24 << ":0" << min << "\n";
        }
        else
        {
            cout << utclabel << ": (previous day) " << hour+24 << ":" << min << "\n";
        }
    }

    else
    {
        if (min < 10)

        {
            cout << utclabel << ": " << hour << ":0" << min << "\n";
        }
        else
        {
            cout << utclabel << ": " << hour << ":" << min << "\n";
        }
    }

}

void help()
{
    cout << "This is a very simple program that displays the time for each UTC offset in use at the time the program was written.\nTo use the program to determine the time for a given city or region, you will need to know which offsets are used by that city/region, including during daylight savings time (if applicable); these can be found on Wikipedia.\nHere are some examples:\n";
    cout << "Japan: always UTC+9\n";
    cout << "U.S. Eastern Time Zone: UTC-5 outside of daylight savings time; UTC-4 during daylight savings time\n";
    cout << "India: always UTC+5:30\n.";
    cout << "Note that these times do not update automatically; therefore, to update the times, you will need to exit and restart the program.\n";


}
int main()


{

    time_t time1;
    time_t* time1ptr = &time1;
    time(time1ptr);
    tm* tmptr1 = gmtime(time1ptr); //gmtime takes a pointer to a time_t object as an argument but returns a tm* pointer

    cout << "For help, enter h.\n"; //The code for entering h appears below the offset() calls so that the times will display immediately whether or not someone enters 'h.'
    cout << "These times will not update automatically; to update the times, you will need to restart the program.\n\n";
    cout << "UTC time: " << asctime(tmptr1);
    offset(tmptr1, -12, 0, "UTC-12");
    offset(tmptr1, -11, 0, "UTC-11");
    offset(tmptr1, -10, 0, "UTC-10");
    offset(tmptr1, -10, 30, "UTC-9:30"); //Equivalent to setting the hour offset to -9 and the minute offset to -30
    offset(tmptr1, -9, 0, "UTC-9");
    offset(tmptr1, -8, 0, "UTC-8");
    offset(tmptr1, -7, 0, "UTC-7");
    offset(tmptr1, -6, 0, "UTC-6");
    offset(tmptr1, -5, 0, "UTC-5");
    offset(tmptr1, -4, 0, "UTC-4");
    offset(tmptr1, -4, 30, "UTC-3:30");
    offset(tmptr1, -3, 0, "UTC-3");
    offset(tmptr1, -2, 0, "UTC-2");
    offset(tmptr1, -1, 0, "UTC-1");
    offset(tmptr1, 0, 0, "UTC+0");
    offset(tmptr1, 1, 0, "UTC+1");
    offset(tmptr1, 2, 0, "UTC+2");
    offset(tmptr1, 3, 0, "UTC+3");
    offset(tmptr1, 3, 30, "UTC+3:30");
    offset(tmptr1, 4, 0, "UTC+4");
    offset(tmptr1, 4, 30, "UTC+4:30");
    offset(tmptr1, 5, 0, "UTC+5");
    offset(tmptr1, 5, 30, "UTC+5:30");
    offset(tmptr1, 5, 45, "UTC+5:45");
    offset(tmptr1, 6, 0, "UTC+6");
    offset(tmptr1, 6, 30, "UTC+6:30");
    offset(tmptr1, 7, 0, "UTC+7");
    offset(tmptr1, 8, 0, "UTC+8");
    offset(tmptr1, 8, 45, "UTC+8:45");
    offset(tmptr1, 9, 0, "UTC+9");
    offset(tmptr1, 9, 30, "UTC+9:30");
    offset(tmptr1, 10, 0, "UTC+10");
    offset(tmptr1, 10, 30, "UTC+10:30");
    offset(tmptr1, 11, 0, "UTC+11");
    offset(tmptr1, 12, 0, "UTC+12");
    offset(tmptr1, 12, 45, "UTC+12:45");
    offset(tmptr1, 13, 0, "UTC+13");
    offset(tmptr1, 14, 0, "UTC+14");


    char entry;
    cin >> entry;
    if (entry == 'h' || entry == 'H') //To activate help function
    {
        help();
    }

cout << "Press any key to exit.";

    char c;
    cin >> c; //Keeps console open until a key is pressed.






}

