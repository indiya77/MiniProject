#include <stdio.h>
#include "txn.h"

error_t getDataFromFile (txnLine *_param)
{
    FILE *fp = NULL;
    fp = fopen ("txn.txt" , "r");
    if (fp == NULL)
    {
       printf("File not found!"); 
       return FAIL;
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
    if (_param == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computePower (txnLine *_param)
{
    _param->_pr = (_param->_sr) * (_param->_pf);
    if (_param == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeCurrent (txnLine *_param)
{
    _param->_ir = (_param->_sr)/((sqrt(3)) * _param->_vr);
    if (_param == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeVoltageSent (txnLine *_param)
{
    _param->_vs = (_param->_ir * _param->_z) + (_param->_vr);
    if (_param == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeLosses (txnLine *_param)
{
    _param->_loss = (3 * _param->_ir * _param->_ir * _param->_r * _param->_l);
    if (_param == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeEfficiency (txnLine *_param)
{
    _param->_efficiency = ((_param->_pr) / (_param->_pr + _param->_loss)) * 100;
    if (_param == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeRegulation (txnLine *_param)
{
    _param->_regulation = ((_param->_vs - _param->_vr)/(_param->_vr)) * 100;
    if (_param == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t getDataFromFile2 (txnLineFault *_param2)
{
    FILE *fptr = NULL;
    fptr = fopen ("fault.txt" , "r");
    if (fptr == NULL)
    {
       printf("File not found!"); 
       return FAIL;
    }
    else
    {
    for (int i=0; i<3; i++){
        char str2[100];
        fgets (str2, 60, fptr);
        switch (i){
            case 0:
                _param2->_z1 = atof(str2);
                break;
            case 1:
                _param2->_z2 = atof(str2);
                break;
            case 2:
                _param2->_z0 = atof(str2);
                break;
            case 3:
                _param2->_sr = atof(str2);
                break;
            case 4:
                _param2->_vr = atof(str2);
                break;
            case 5:
                _param2->_e = atof(str2);
                break;
        }
    }
    fclose(fptr);
}
}

error_t computeBaseCurrent (txnLineFault *_param2)
{
    _param2->_ib = (_param2->_sr)/(sqrt(3) * _param2->_vr);
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeSymFault (txnLineFault *_param2)
{
    _param2->_if_sym = (_param2->_e / _param2->_z1) * (_param2->_ib);
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeIaSlg (txnLineFault *_param2)
{
    _param2->_ia_slgf = (_param2->_e / (_param2->_z1 + _param2->_z2 + _param2->_z0));
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t ComputeIfSlg (txnLineFault *_param2)
{
    _param2->_if_slgf = 3 * _param2->_ia_slgf * _param2->_ib;
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeIalg (txnLineFault *_param2)
{
    _param2->_ia_lgf = (_param2->_e / (_param2->_z1 + _param2->_z2));
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t ComputeIflg (txnLineFault *_param2)
{
    _param2->_if_slgf = sqrt(3) * _param2->_ia_slgf * _param2->_ib;
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t ComputeIa1dlg (txnLineFault *_param2)
{
    _param2->_ia1_dlgf = _param2->_e / (_param2->_z1 + ((_param2->_z0 * _param2->_z1) / (_param2->_z0 + _param2->_z1)));
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeIa0dlg (txnLineFault *_param2)
{
    _param2->_ia0_dlgf = - ((_param2->_ia1_dlgf) * (_param2->_z2/(_param2->_z0 + _param2->_z2)));
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}

error_t computeIfdlg (txnLineFault *_param2)
{
    _param2->_if_dlgf = 3 * _param2->_ia0_dlgf * _param2->_ib;
    if (_param2 == NULL){
        return FAIL;
    }
    else {
        return PASS;
    }
    return 0;
}