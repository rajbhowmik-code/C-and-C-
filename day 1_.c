#include <stdio.h>
#include <math.h>
int ly (int ty){ // leap year check
     if ((ty % 400 == 0) || (ty % 4 == 0 && ty % 100 != 0)){
     return 1;
    }
    return 0;
    }

 int vd(int td , int tm, int ty){ //date month year valid naki check
if (td < 1||td > 31 || tm < 1 || tm > 12 || ty <1){
    printf("❌ Error: Invalid range! Day must be 1-31, Month 1-12, and Year positive.\n\n");
        return 0;
        }
    if (tm ==2){ //feb 28/29 day check
        if (ly(ty) && td >29){
            printf("❌ Error: %d is a Leap Year! February can't have more than 29 days.\n\n", ty);
            return 0;
        }
        else if (!ly(ty) && td >28){
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
   int vdb(int bd, int bm, int by, int ty){ //valid date birthday
    if (!vd (bd, bm, by)) {
        return 0;
    }
    //120 year
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

int main (){
    int td,tm,ty,bd,bm,by,d,m,y,pm,dim;
    int check_vd = 0;
    while (check_vd == 0) {
        printf("Enter todays date (day/month/year)\n");
        scanf("%d/%d/%d", &td, &tm, &ty);
        
        if (vd(td,tm,ty)) {
            check_vd = 1;
        }
    }
    
    int check_vdb = 0;
    while (check_vdb == 0) {
        printf("Enter your birthday date (day/month/year)\n");
        scanf("%d/%d/%d", &bd, &bm, &by);
        
        if (vdb(bd, bm, by, ty)) {
            check_vdb = 1;
        }
     } 

    if (bd>td){
        pm = tm -1;
        if (pm ==0)
        { 
        pm = 12;//for january
        }
        if (pm == 2) {
            if (ly(ty)) { 
                dim = 29;
            }
            else {
                dim = 28;
            }
        }
           else if (pm == 4 ||pm == 6 ||pm == 9 ||pm == 11) //checking if dim is 30 or 31
           {
           dim = 30;
           }
        else {
            dim = 31;
             }

        td = td + dim; //adding day
        tm = tm-1; //reducting month
    }
    d = td-bd;

    if(bm>tm){
        tm = tm+12; //adding monthy
        ty = ty-1; //reducting year
    }
    m=tm-bm;

    y=ty-by;

    printf ("Your age is %d day %d month %d year ",d,m,y);

    return 0;
}
