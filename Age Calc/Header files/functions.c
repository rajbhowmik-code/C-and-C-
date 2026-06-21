#include <stdio.h>
#include "../Function files/functions.h"

int ly (int ty){  //leap year check
    if ((ty % 400 == 0) || (ty % 4 == 0 && ty % 100 != 0)){
        return 1;
    }
    return 0;
}

int vd(int td , int tm, int ty){ //validity check
    if (td < 1||td > 31 || tm < 1 || tm > 12 || ty <1){
        printf("❌ Error: Invalid range! Day must be 1-31, Month 1-12, and Year positive.\n\n");
        return 0;
    }
    if (tm == 2){ //when 28 and when 29 check
        if (ly(ty) && td > 29){
            printf("❌ Error: %d is a Leap Year! February can't have more than 29 days.\n\n", ty);
            return 0;
        }
        else if (!ly(ty) && td > 28){
            printf("❌ Error: %d isn't a Leap Year! February can't have more than 28 days.\n\n", ty);
            return 0;
        }
    }
    if ((tm == 4 || tm == 6 || tm == 9 || tm == 11) && td > 30) { //when 30 when 31 check
        printf("❌ Error: This month can't have more than 30 days.\n\n");
        return 0;
    }
    return 1;
}

int vdb(int bd, int bm, int by, int ty){ //birtday validity
    if (!vd (bd, bm, by)) {
        return 0;
    }
    if (by < (ty - 120)) {
        printf("❌ Error: Birth year can't go before 120 years of current year you would be dead (%d).\n\n", ty - 120);
        return 0;
    }
    if (by > ty) {
        printf("❌ Error: Birthday cannot be in the future!\n\n");
        return 0;
    }
    return 1;
}

void next_birthday(int td, int tm, int ty, int bd, int bm) { //bday reminder
    int next_y = ty;
    int rem_m, rem_d;
    int pm, dim;

    if (bm < tm || (bm == tm && bd < td)) { //check if bday this year or not
        next_y = ty + 1; 
    }

    if (bd == td && bm == tm) {
        printf("\n🎉 Happy Birthday, Bhalo! Today is your special day! 🎂\n"); 
        return;
    }

    if (bd >= td) { //if bday month is before or mext year
        if (bm >= tm || next_y > ty) {
            int target_m = (next_y > ty) ? bm + 12 : bm;
            rem_m = target_m - tm;
        }
        rem_d = bd - td;
    } 
    else {
        pm = bm - 1;
        if (pm == 0) {
            pm = 12; 
        }

        if (pm == 2) {
            dim = ly(next_y) ? 29 : 28;
        } else if (pm == 4 || pm == 6 || pm == 9 || pm == 11) {
            dim = 30;
        } else {
            dim = 31;
        }

        rem_d = (bd + dim) - td; //previous day loan than
        
        int target_m = (next_y > ty) ? (bm - 1) + 12 : bm - 1; //? is shortcut to if else
        rem_m = target_m - tm;
    }

    printf("\n⏳ Next Birthday Countdown:\n");
    printf("Remaining: %d month(s) and %d day(s) until your next birthday!\n", rem_m, rem_d);
}


void print_birth_day_name(int bd, int bm, int by) {
    int original_bm = bm; 
    int original_by = by;

    if (bm == 1) { bm = 13; by--; } //lemme tell you tdg a f*** how this works
    if (bm == 2) { bm = 14; by--; }
    
    int q = bd;
    int m = bm;
    int k = by % 100;
    int j = by / 100;
    
    int h = (q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7; //zeller 
    char days[][15] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("You were born on a: %s\n", days[h]);
}