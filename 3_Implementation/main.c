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
        getDataFromFile2 (&data2);
        computeBaseCurrent(&data2);
        if (str == 'S')
        {
            error_t computeSymFault (txnLineFault *_param2);
            printf("The Symmetrical fault current is %.2f", data2._if_sym);
        }
        else if (str == 'U')
        {
            int n2;
            printf ("\nEnter 1 to compute SLG fault\n"
             "------------------------------------------------------------------------\n"
             "Enter 2 to compute LG fault\n"
             "------------------------------------------------------------------------\n"
             "Enter 3 to compute LLG Fault\n"
             "------------------------------------------------------------------------\n");
            scanf ("%d",&n2);
            if (n2 == 1)
            {
                error_t computeIaSlg (txnLineFault *_param2);
                error_t ComputeIfSlg (txnLineFault *_param2);
                printf ("The Single line to ground fault curret is %.2f\n",data2._if_slgf);
            }
            else if (n2 == 2)
            {
                error_t computeIalg (txnLineFault *_param2);
                error_t computeIfSlg (txnLineFault *_param2);
                printf ("The Line to ground fault curret is %.2f\n",data2._if_lgf);
            }
            else if (n2 == 3)
            {
                error_t computeIa1dlg (txnLineFault *_param2);
                error_t computeIa0dlg (txnLineFault *_param2);
                error_t computeIfdlg (txnLineFault *_param2);
                printf ("The Line to ground fault curret is %.2f\n",data2._if_dlgf); 
            }
        }
    }
    return 0;
}


