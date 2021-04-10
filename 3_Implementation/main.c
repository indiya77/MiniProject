#include <stdio.h>
#include "txn.h"

int main()
{
    txnLine data;
    int n;
    char str;
    printf ("\nEnter 1 to perform Performance analysis\n"
             "------------------------------------------------------------------------\n"
             "Enter 2 to perform Fault Analysis\n"
             "------------------------------------------------------------------------\n");
    scanf("%d",&n);
    if (n == 1)
    {
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
    
    else if (n == 2)
    {
        txnLineFault data2;
        printf ("\nEnter S to compute Symmetrical fault\n"
             "------------------------------------------------------------------------\n"
             "Enter U to compute Unsymmetrical fault\n"
             "------------------------------------------------------------------------\n");
        scanf ("%s",&str);
        if (str == 'U')
        {
            getDataFromFile2 (&data);
        }
    }
    return 0;
}


