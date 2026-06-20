#include <stdio.h>
#include <math.h>
#include "../Function files/functions.h"

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
        if (pm ==0) { 
            pm = 12; // for january
        }
        if (pm == 2) {
            if (ly(ty)) { 
                dim = 29;
            }
            else {
                dim = 28;
            }
        }
        else if (pm == 4 ||pm == 6 ||pm == 9 ||pm == 11) {
            dim = 30;
        }
        else {
            dim = 31;
        }

        td = td + dim; 
        tm = tm-1; 
    }
    d = td-bd;

    if(bm>tm){
        tm = tm+12; 
        ty = ty-1; 
    }
    m=tm-bm;

    y=ty-by;

    printf ("Your age is %d day %d month %d year \n",d,m,y);

    return 0;
}