#include <stdio.h>
#include "txn.h"

int main()
{
    txnLine data;
    txnLineFault data2;
    char ch = 'P';
    printf ("\nEnter P to perform Performance analysis\n"
             "------------------------------------------------------------------------\n"
             "Enter F to perform Fault Analysis\n"
             "------------------------------------------------------------------------\n");
    scanf("%s",&ch);
    if (ch == 'P' || ch == 'p')
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
    
    else if (ch == 'F' || ch == 'f')
    {
        printf ("\nEnter S to compute Symmetrical fault\n"
             "------------------------------------------------------------------------\n"
             "Enter U to compute Unsymmetrical fault\n"
             "------------------------------------------------------------------------\n");
        scanf ("%s",&ch);
        if (ch == 'S' || ch == 's')
        {
            getDataFromFile2 (&data2);
            computeBaseCurrent(&data2);
            computeSymFault (&data2);
            printf("The Symmetrical fault current is %.2f", data2._if_sym);
        }
        else if (ch == 'U' || ch == 'u')
        {
            int n2;
            getDataFromFile2 (&data2);
            computeBaseCurrent(&data2);
            printf ("\nEnter 1 to compute SLG fault\n"
             "------------------------------------------------------------------------\n"
             "Enter 2 to compute LG fault\n"
             "------------------------------------------------------------------------\n"
             "Enter 3 to compute LLG Fault\n"
             "------------------------------------------------------------------------\n");
            scanf ("%d",&n2);
            if (n2 == 1)
            {
                computeIaSlg (&data2);
                computeIfSlg (&data2);
                printf ("The Single line to ground fault curret is %.2f\n",data2._if_slgf);
            }
            else if (n2 == 2)
            {
                computeIalg (&data2);
                computeIflg (&data2);
                printf ("The Line to ground fault current is %.2f\n",data2._if_lgf);
            }
            else if (n2 == 3)
            {
                computeIa1dlg (&data2);
                computeIa0dlg (&data2);
                computeIfdlg (&data2);
                printf ("The Line to ground fault curret is %.2f\n",data2._if_dlgf); 
            }
        }
    }
    else {
        printf("ERROR !");
    }
    return 0;
}


