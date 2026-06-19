#include <stdio.h>
int main (){
    int td,tm,ty,bd,bm,by,d,m,y;
    printf("Enter todays date (day/month/year)");
    scanf("%d/%d/%d",&td,&tm,&ty);

    printf("Enter your birthday date (day/month/year)");
    scanf("%d/%d/%d",&bd,&bm,&by);

    d=td-bd;
    m=tm-bm;
    y=ty-by;
    printf ("Your age is %d/%d/%d ",d,m,y);

    return 0;
}

