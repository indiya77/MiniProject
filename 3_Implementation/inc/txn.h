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
    float _z0;
    float _z1;
    float _z2;
}txnLineFault;

typedef enum error_t{
    PASS = 0,
    FAIL = -1
}error_t;

/**
 * @brief Get the Data From File object
 * @param _param Transmission line parameters
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

error_t getDataFromFile2 (txnLineFault *_param2);



#endif