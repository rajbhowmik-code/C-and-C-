#include <stdio.h>
#include <math.h>
#include "../Header files/functions.h"

int main (){
    char choice;

    do {
        int td, tm, ty, bd, bm, by, d, m, y, pm, dim;
        int check_vd = 0;
        printf ("\n This App was developed by me Raj Bhowmik Sust Swe 2025");
        
        while (check_vd == 0) {
            printf("\nEnter todays date (day/month/year)\n");
            scanf("%d/%d/%d", &td, &tm, &ty);
            
            if (vd(td, tm, ty)) {
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

        
        int temp_td = td; //to keep td... intact cuz we used them already the values are changed
        int temp_tm = tm;
        int temp_ty = ty;

        if (bd > temp_td){
            pm = temp_tm - 1;
            if (pm == 0) { 
                pm = 12; 
            }
            if (pm == 2) {
                dim = ly(temp_ty) ? 29 : 28;
            }
            else if (pm == 4 || pm == 6 || pm == 9 || pm == 11) {
                dim = 30;
            }
            else {
                dim = 31;
            }

            temp_td = temp_td + dim; 
            temp_tm = temp_tm - 1; 
        }
        d = temp_td - bd;

        if (bm > temp_tm){
            temp_tm = temp_tm + 12; 
            temp_ty = temp_ty - 1; 
        }
        m = temp_tm - bm;
        y = temp_ty - by;

        printf ("\nYour age is %d day %d month %d year \n", d, m, y);

        
        next_birthday(td, tm, ty, bd, bm);

        
        print_birth_day_name(bd, bm, by);

        
        long int total_days = (y * 365) + (m * 30) + d; 
        long int total_hours = total_days * 24;
        long int total_minutes = total_hours * 60;

        printf("\n--- Total Breakdown ---\n");
        printf("Total Days: %ld\n", total_days);
        printf("Total Hours: %ld\n", total_hours);
        printf("Total Minutes: %ld\n", total_minutes);

        
        printf("\nDo you want to calculate another age? (y/n): ");
        scanf(" %c", &choice); 

    } while (choice == 'y' || choice == 'Y'); // y চাপলে লুপ আবার ঘুরবে

    return 0;
}