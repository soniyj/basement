/**
 * How to convert a week number into a C tm's struct
 * 
 * @author:      Marco "soniyj" Matascioli
 * @date:        11 October 2013
 * @file:        weeknum.c
 * 
 * Copyright (C) 2013. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct ordinal_day {
    char month[4];
    unsigned short weeknum;
};

/**
 * Get the day of the week from an input date
 * @param y year
 * @param m month
 * @param d day
 * @return the day of the week
 */
int day_of_week(int y, int m, int d) {
    /* 0 = Sunday */
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

/**
 * Get a date from a week number and store it into a tm's struct
 * @param weekn week number
 * @param year
 * @param tm pinter to struct tm
 */
void weeknum_to_tm_struct(const int weekn, const int year, struct tm *tm) {
    /**
    * Formula
    * Day = ((NumWeek * 7 - 2) - DayOfWeek) - NumTable
    * NumTable = Month Value
    * Check the leap year
    * DayOfWeek = 3/4 Jan of the same year
    **/
    
    /* Get from Wikipedia */
    struct ordinal_day weeknums[] = {
        {"Jan",0},{"Feb", 31},{"Mar", 59},{"Apr", 90},{"May", 120},{"Jun", 151},
        {"Jul",181},{"Aug",212},{"Sep",243},{"Oct",273},{"Nov",304},{"Dec",334}
    };

    unsigned int dim = sizeof(weeknums) / sizeof(weeknums[0]);
    int i=0;

    /* In case the conversion is wrong use 4 instead of 3 */
    int wday = day_of_week(year, 1, 3);
    int yday = ((weekn * 7) - 2) - wday;

    if(yday < 180) {
        /* First part of the year */
        dim = (dim/2);
    }
    else {
        /* Second part of the year */
        i = (dim/2);
    }

    if(yday > weeknums[dim-1].weeknum) {
        /* December */
        i = dim-1;
    }
    else {
        for(i = i; i < dim && yday >=0; i++) {
            if(weeknums[i].weeknum <= yday && yday <= weeknums[i+1].weeknum) {
                break;
            }
        } /* End For */
    } /* End else */

    /* Checking leap year */
    if((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0)) {
        /* Adding 1 to the weeknum */
        weeknums[i].weeknum+=1;
    }

    /* Set up struct with day correction */
    tm->tm_year = year - 1900;
    tm->tm_mon = i;
    tm->tm_mday = (yday - weeknums[i].weeknum) - 1;
} /* End Function */
