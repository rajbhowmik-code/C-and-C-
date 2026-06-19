#include <stdio.h>
#include <math.h>
int main (){
    int td,tm,ty,bd,bm,by,d,m,y,pm,dim;
    printf("Enter todays date (day/month/year)\n");
    scanf("%d/%d/%d",&td,&tm,&ty); //collecting values

    printf("Enter your birthday date (day/month/year)\n");
    scanf("%d/%d/%d",&bd,&bm,&by); //collecting values

    if (bd>td){
        pm = tm -1;
        if (pm ==0)
        { 
        pm = 12;//for january
        }
        if (pm==2){
            if ((ty % 400 == 0) || (ty % 4 == 0 && ty % 100 != 0)) //leap year check
            {
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
