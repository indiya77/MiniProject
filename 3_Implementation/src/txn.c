#include <stdio.h>
#include "txn.h"

error_t getDataFromFile (txnLine *_param)
{
    FILE *fp = NULL;
    fp = fopen ("txn.txt" , "r");
    if (fp == NULL)
    {
       printf("File not found!"); 
    }
    else
    {
    for (int i=0; i<6; i++){
        char str[100];
        fgets (str, 60, fp);
        switch (i)
        {
            case 0:
                _param->_vr = atof(str);
                break;
            case 1:
                _param->_r = atof(str);
                break;
            case 2:
                _param->_x = atof(str);
                break;
            case 3:
                _param->_l = atof(str);
                break;
            case 4:
                _param->_sr = atof(str);
                break;
            case 5:
                _param->_pf = atof(str);
                break;
        }
    }
    fclose(fp);
    }
}

error_t computeImpedance (txnLine *_param)
{
    _param->_z = (sqrt(((_param->_r) * (_param->_r))+ ((_param->_x) * (_param->_x)))) * _param->_l;
    return 0;
}

error_t computePower (txnLine *_param)
{
    _param->_pr = (_param->_sr) * (_param->_pf);
    return 0;
}

error_t computeCurrent (txnLine *_param)
{
    _param->_ir = (_param->_sr)/((sqrt(3)) * _param->_vr);
    return 0;
}

error_t computeVoltageSent (txnLine *_param)
{
    _param->_vs = (_param->_ir * _param->_z) + (_param->_vr);
}

error_t computeLosses (txnLine *_param)
{
    _param->_loss = (3 * _param->_ir * _param->_ir * _param->_r * _param->_l);
    return 0;
}

error_t computeEfficiency (txnLine *_param)
{
    _param->_efficiency = ((_param->_pr) / (_param->_pr + _param->_loss)) * 100;
    return 0;
}

error_t computeRegulation (txnLine *_param)
{
    _param->_regulation = ((_param->_vs - _param->_vr)/(_param->_vr)) * 100;
    return 0;
}