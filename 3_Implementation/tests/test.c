#include "unity.h"
#include "txn.h"

void setUp(void){}

void tearDown(void){}

void test_computeImpedance(void)
{
    txnLine _param ;
    // for positive values
    _param._r = 1;
    _param._x = 1;
    _param._l = 1;
    _param._z;
    TEST_ASSERT_EQUAL_INT(PASS, computeImpedance(&_param));
    TEST_ASSERT_EQUAL_FLOAT(1.414214f, _param._z);
    // for negative values
    _param._r = -1;
    _param._x = -1;
    _param._l = -1;
    _param._z;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeImpedance(&_param));
}

void test_computePower(void)
{
    txnLine _param ;
    // for positive values
    _param._sr = 1;
    _param._pf = 1;
    _param._pr;
    TEST_ASSERT_EQUAL_INT(PASS, computePower(&_param));
    TEST_ASSERT_EQUAL_FLOAT(1.0f, _param._pr);
    // for negative values
     _param._sr = 1;
    _param._pf = -1;
    _param._pr;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computePower(&_param));
}

void test_computeCurrent(void)
{
    txnLine _param ;
    // for positive values
    _param._sr = 1;
    _param._vr = 1;
    _param._ir;
    TEST_ASSERT_EQUAL_INT(PASS, computeCurrent(&_param));
    TEST_ASSERT_EQUAL_FLOAT(0.577350f, _param._ir);
    // for negative values
    _param._sr = 1;
    _param._vr = -1;
    _param._ir;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeCurrent(&_param));
}

void test_computeVoltageSent(void)
{
    txnLine _param ;
    // for positive values
    _param._ir = 1;
    _param._z = 1;
    _param._vr = 1;
    _param._vs;
    TEST_ASSERT_EQUAL_INT(PASS, computeVoltageSent(&_param));
    TEST_ASSERT_EQUAL_FLOAT(2.0f, _param._vs);
    // for negatve values
    _param._ir = 1;
    _param._z = -1;
    _param._vr = -1;
    _param._vs;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeVoltageSent(&_param));
}

void test_computeLosses(void)
{
    txnLine _param ;
    // for positive values
    _param._ir = 1;
    _param._r = 1;
    _param._l = 1;
    _param._loss;
    TEST_ASSERT_EQUAL_INT(PASS, computeLosses(&_param));
    TEST_ASSERT_EQUAL_FLOAT(3.0f, _param._loss);
    // for negatve values
    _param._ir = 1;
    _param._r = 1;
    _param._l = -1;
    _param._loss;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeLosses(&_param));
}

void test_computeEfficiency(void)
{
    txnLine _param ;
    // for positive values
    _param._pr = 1;
    _param._loss = 1;
    _param._efficiency;
    TEST_ASSERT_EQUAL_INT(PASS, computeEfficiency(&_param));
    TEST_ASSERT_EQUAL_FLOAT(50.0f, _param._efficiency);
    // for negatve values
    _param._pr = -1;
    _param._loss = 2;
    _param._efficiency;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeEfficiency(&_param));
}

void test_computeRegulation(void)
{
    txnLine _param ;
    // for positive values
    _param._vs = 2;
    _param._vr = 1;
    _param._regulation;
    TEST_ASSERT_EQUAL_INT(PASS, computeRegulation(&_param));
    TEST_ASSERT_EQUAL_FLOAT(100.0f, _param._regulation);
    // for negatve values
    _param._vs = -2;
    _param._vr = 1;
    _param._regulation;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeRegulation(&_param));
}

void test_computeBaseCurrent(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._sr = 1;
    _param2._vr = 1;
    _param2._ib;
    TEST_ASSERT_EQUAL_INT(PASS, computeBaseCurrent(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(0.57735f,_param2._ib);
    // for negative values
    _param2._sr = -1;
    _param2._vr = 1;
    _param2._ib;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeBaseCurrent(&_param2));
}

void test_computeSymFault(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._e = 1;
    _param2._z1 = 1;
    _param2._ib = 1;
    _param2._if_sym;
    TEST_ASSERT_EQUAL_INT(PASS, computeSymFault(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(1.0f,_param2._if_sym);
    // for negative values
    _param2._e = 1;
    _param2._z1 = -1;
    _param2._ib = 1;
    _param2._if_sym;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeSymFault(&_param2));
}

void test_computeIaSlg(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._e = 1;
    _param2._z1 = 1;
    _param2._z2 = 1;
    _param2._z0 = 1;
    _param2._ia_slgf;
    TEST_ASSERT_EQUAL_INT(PASS, computeIaSlg(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(0.3333334f,_param2._ia_slgf);
    // for negative values
    _param2._e = 1;
    _param2._z1 = -1;
    _param2._z2 = -1;
    _param2._z0 = -1;
    _param2._ia_slgf;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeIaSlg(&_param2));
}

void test_computeIfSlg(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._ia_slgf = 1;
    _param2._ib = 1;
    _param2._if_slgf;
    TEST_ASSERT_EQUAL_INT(PASS, computeIfSlg(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(3.0f,_param2._if_slgf);
    // for negative values
    _param2._ia_slgf = 1;
    _param2._ib = -1;
    _param2._if_slgf;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeIfSlg(&_param2));
}

void test_computeIalg(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._e = 1;
    _param2._z1 = 1;
    _param2._z2 = 1;
    _param2._ia_lgf;
    TEST_ASSERT_EQUAL_INT(PASS, computeIalg(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(0.5f, _param2._ia_lgf);
    // for negative values
    _param2._e = -1;
    _param2._z1 = 1;
    _param2._z2 = 1;
    _param2._ia_lgf;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeIalg(&_param2));
}

void test_computeIflg(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._ia_slgf = 1;
    _param2._ib = 1;
    _param2._if_lgf;
    TEST_ASSERT_EQUAL_INT(PASS, computeIflg(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(1.73205f, _param2._if_lgf);
    // for negative values
    _param2._ia_slgf = 1;
    _param2._ib = -1;
    _param2._if_lgf;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeIflg(&_param2));
}

void test_computeIa1dlg(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._e = 1;
    _param2._z0 = 1;
    _param2._z1 = 1;
    _param2._ia1_dlgf;
    TEST_ASSERT_EQUAL_INT(PASS, computeIa1dlg(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(0.6666667f, _param2._ia1_dlgf);
    // for negative values
    _param2._e = -1;
    _param2._z0 = 1;
    _param2._z1 = 1;
    _param2._ia1_dlgf;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeIa1dlg(&_param2));
}

void test_computeIa0dlg(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._ia1_dlgf = -1;
    _param2._z2 = 1;
    _param2._z0 = 1;
    _param2._ia0_dlgf;
    TEST_ASSERT_EQUAL_INT(PASS, computeIa0dlg(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(0.5f, _param2._ia0_dlgf);
    // for negative values
    _param2._ia1_dlgf = 1;
    _param2._z2 = 1;
    _param2._z0 = 1;
    _param2._ia0_dlgf;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeIa0dlg(&_param2));
}

void test_computeIfdlg(void)
{
    txnLineFault _param2;
    // for positive values
    _param2._ia0_dlgf = 1; 
    _param2._ib = 1;
    _param2._if_dlgf;
    TEST_ASSERT_EQUAL_INT(PASS, computeIfdlg(&_param2));
    TEST_ASSERT_EQUAL_FLOAT(3.0f, _param2._if_dlgf);
    // for negative values
    _param2._ia0_dlgf = 1; 
    _param2._ib = -1;
    _param2._if_dlgf;
    TEST_ASSERT_EQUAL_INT(ERR_NEGATIVE, computeIfdlg(&_param2));
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_computeImpedance);
    RUN_TEST(test_computePower);
    RUN_TEST(test_computeCurrent);
    RUN_TEST(test_computeVoltageSent);
    RUN_TEST(test_computeLosses);
    RUN_TEST(test_computeEfficiency);
    RUN_TEST(test_computeRegulation);
    RUN_TEST(test_computeBaseCurrent);
    RUN_TEST(test_computeSymFault);
    RUN_TEST(test_computeIaSlg);
    RUN_TEST(test_computeIfSlg);
    RUN_TEST(test_computeIalg);
    RUN_TEST(test_computeIflg);
    RUN_TEST(test_computeIa1dlg);
    RUN_TEST(test_computeIa0dlg);
    RUN_TEST(test_computeIfdlg);
    return UNITY_END();
}