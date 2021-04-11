/**
 * @file txn.h
 * @author Indiya B Henly_258071 (indiyabhenly@gmail.com)
 * @brief Transmission line analysis tool - 
 * The parameters of transmission lines are considered and Peformance estimation and Fault analysis are evaluated. 
 * @version 0.1
 * @date 2021-04-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _TXN_LINE_
#define _TXN_LINE_
#include <stdlib.h>
#include <math.h>

typedef struct txnLine
{
    float _vr;
    float _r;
    float _x;
    float _l;
    float _sr;
    float _pf;
    float _z;
    float _pr;
    float _ir;
    float _vs;
    float _loss;
    float _efficiency;
    float _regulation;
}txnLine;

typedef struct txnLineFault
{
    float _z1;
    float _z2;
    float _z0;
    float _sr;
    float _vr;
    float _e;
    float _ib;
    float _if_sym;
    float _ia_slgf;
    float _if_slgf;
    float _ia_lgf;
    float _if_lgf;
    float _ia0_dlgf;
    float _ia1_dlgf;
    float _if_dlgf;
}txnLineFault;

typedef enum error_t{
    PASS = 0,
    FAIL = -1
}error_t;

/**
 * @brief Get the Data From File object
 * @param _param Transmission line parameters for Performance analysis
 * @return error_t returns error codes
 */
error_t getDataFromFile (txnLine *_param);
/**
 * @brief Impedance is computed
 * @param _param Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeImpedance (txnLine *_param);
/**
 * @brief Power is computed
 * @param _param Transmission line parameters
 * @return error_t returns error codes
 */
error_t computePower (txnLine *_param);
/**
 * @brief Current is computed
 * @param _param Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeCurrent (txnLine *_param);
/**
 * @brief Sending end voltage is computed
 * @param _param Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeVoltageSent (txnLine *_param);
/**
 * @brief Losses of the line are calculated
 * @param _param Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeLosses (txnLine *_param);
/**
 * @brief Efficiency of the line is calculated
 * @param _param Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeEfficiency (txnLine *_param);
/**
 * @brief Regulation of the line is calculated
 * @param _param Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeRegulation (txnLine *_param);
/**
 * @brief Get the Data From File2 object
 * @param _param2 Parameters for Fault analysis
 * @return error_t returns error codes
 */
error_t getDataFromFile2 (txnLineFault *_param2);
/**
 * @brief Base current is calculated
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeBaseCurrent (txnLineFault *_param2);
/**
 * @brief Symmetrical fault current is computed
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeSymFault (txnLineFault *_param2);
/**
 * @brief Compute Ia for SLG fault
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeIaSlg (txnLineFault *_param2);
/**
 * @brief Compute fault current for SLG fault
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t ComputeIfSlg (txnLineFault *_param2);
/**
 * @brief Compute Ia for LG fault
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeIalg (txnLineFault *_param2);
/**
 * @brief Compute fault current for LG fault
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeIfSlg (txnLineFault *_param2);
/**
 * @brief Compute Ia1 for LLG fault
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeIa1dlg (txnLineFault *_param2);
/**
 * @brief Compute Ia0 for LLG fault
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeIa0dlg (txnLineFault *_param2);
/**
 * @brief Compute fault current for LLG fault
 * @param _param2 Transmission line parameters
 * @return error_t returns error codes
 */
error_t computeIfdlg (txnLineFault *_param2);

#endif