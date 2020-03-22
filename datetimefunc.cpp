#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

int gettime(string s) {
    int y, mo, d, h, min;
    sscanf(s.c_str(), "%d-%d-%d %d:%d",&y, &mo, &d, &h, &min);

    time_t rawtime;
    struct tm * timeinfo;

    /* get current timeinfo: */
    time ( &rawtime ); //or: rawtime = time(0);
    /* convert to struct: */
    timeinfo = localtime ( &rawtime ); 

    /* now modify the timeinfo to the given date: */
    timeinfo->tm_year   = y - 1900;
    timeinfo->tm_mon    = mo - 1;    //months since January - [0,11]
    timeinfo->tm_mday   = d;         //day of the month - [1,31] 
    timeinfo->tm_hour   = h;         //hours since midnight - [0,23]
    timeinfo->tm_min    = min;       //minutes after the hour - [0,59]
    timeinfo->tm_sec    = 0;         //seconds after the minute - [0,59]

    /* call mktime: create unix time stamp from timeinfo struct */
    int date = mktime ( timeinfo );
    cout << date << endl;
    return date;
}

int day_of_week(int d, int m, int y)  
{  
    int t[12] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;
    // return [0, 1, ..., 6] with 0 is sunday  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
} 

int main()
{
    string dt = "2020-03-22 23:48";//use this format
    gettime(dt);
    cout << dayofweek(22, 3, 2020);
    return 0;
}
