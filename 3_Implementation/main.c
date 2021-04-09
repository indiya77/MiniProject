#include <stdio.h>
#include "txn.h"

int main()
{
    txnLine data;
    int n;
    printf ("Enter 1 to find out Regulation and Efficiency for Transmission line\n"
             "------------------------------------------------------------------------\n"
             "Enter 2 to compute Fault Analysis\n"
             "------------------------------------------------------------------------\n");
    scanf("%d",&n);
    if (n == 1){
        getDataFromFile (&data);
        computeImpedance (&data);
        computePower (&data);
        computeCurrent (&data);
        computeVoltageSent (&data);
        computeLosses (&data);
        computeEfficiency (&data);
        printf("The Efficiency of the considered Transmission Line is %.2f\n", data._efficiency);
        computeRegulation (&data);
        printf("The Regulation of the considered Transmission Line is %.2f\n", data._regulation);
    }
    return 0;
}


