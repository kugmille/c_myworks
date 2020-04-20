#include <stdio.h>
#include <stdlib.h>


struct _retire_info {
  int months;
  double contri; // add  or spent in negative
  double rate_return;
}; 

typedef struct _retire_info retire_info;

double cal_acc( double cal_money, retire_info wor){

    cal_money= (cal_money * wor.rate_return) + cal_money + wor.contri ;
  
    return cal_money;
}

  

void retirement (int startAge, double initial_save, retire_info working, retire_info retired) {

  int monthcount= startAge - 1;

  //task 1) calculation retirement_working case, account balance with monthly printer
    for( int i= 0; i< working.months; i++){

    monthcount++;
    printf(" Age %3d month %2d you have $%.2lf\n", (monthcount / 12), (monthcount % 12), (initial_save));
    initial_save= cal_acc(initial_save, working);

    }
      
  //task 2) calculation retirement_retired case, account balance with monthly printer
    for ( int j= 0; j< retired.months; j++){

      monthcount++;
      printf(" Age %3d month %2d you have $%.2lf\n", (monthcount / 12), (monthcount % 12), (initial_save));
      initial_save= cal_acc(initial_save, retired);

    }
}
 int main(void) {

  retire_info working;
  working.months = 489; 
  working.contri = 1000; // monthly add
  working.rate_return = (0.045 / 12.0);// monthly rate
  
  retire_info retired;
  retired.months = 384;
  retired.contri = -4000;
  retired.rate_return = (0.01 / 12.0);

  retirement( 327, 21345, working, retired);

  return EXIT_SUCCESS;
}
