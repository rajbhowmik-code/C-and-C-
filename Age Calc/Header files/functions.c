#include <stdio.h>
#include "../Function files/functions.h"

int ly (int ty){ 
    if ((ty % 400 == 0) || (ty % 4 == 0 && ty % 100 != 0)){
        return 1;
    }
    return 0;
}

int vd(int td , int tm, int ty){ 
    if (td < 1||td > 31 || tm < 1 || tm > 12 || ty <1){
        printf("❌ Error: Invalid range! Day must be 1-31, Month 1-12, and Year positive.\n\n");
        return 0;
    }
    if (tm == 2){ 
        if (ly(ty) && td > 29){
            printf("❌ Error: %d is a Leap Year! February can't have more than 29 days.\n\n", ty);
            return 0;
        }
        else if (!ly(ty) && td > 28){
            printf("❌ Error: %d isn't a Leap Year! February can't have more than 28 days.\n\n", ty);
            return 0;
        }
    }
    if ((tm == 4 || tm == 6 || tm == 9 || tm == 11) && td > 30) { 
        printf("❌ Error: This month can't have more than 30 days.\n\n");
        return 0;
    }
    return 1;
}

int vdb(int bd, int bm, int by, int ty){ 
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