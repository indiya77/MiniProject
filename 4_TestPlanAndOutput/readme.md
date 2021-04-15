# Test Plan

## High level test plan
---

| Test_ID | Description | Exp I/P | Exp O/P | Actual O/P | Type of test |
| --- | --- | --- | --- | --- | --- |
| HT01 | Check if the user can read data from text file | User inputs | File containing required parameters | PASS | Technical |
| HT02 | Check if the texts from file is stored in variables | Invoke program | Program variables storing parameters | PASS | Technical |
| HT03 | Decide which analysis to be performed | User inputs | Invoke program | PASS | Technical |


## Low level test plan
---

| Test_ID | Description | Exp I/P | Exp O/P | Actual O/P | Type of test |
| --- | --- | --- | --- | --- | --- |
| LT01 | Test the function *getDataFromFile* and *getDataFromFile2* to see if the user can retrieve or modify data from text file | User inputs | Retrieve texts to program or modify it | PASS | Technical |
| LT02 | The texts from text file should be stored in variables and should be converted to floating point numbers. These variables should be available to be used in the later half of the program. | Invoking program | Variables stored in variables using structures | PASS | Technical |
| LT03(a) | If the user decides to perform Performance evaluation, compute parameters required to do that and store in structures. | Value of the required functions | Storing it and using it in later part of program | PASS | Technical |
| LT03(b) | Test the function *computeEfficiency* and *computeRegulation* to find out regulation and efficiency | Check if the functions are giving desired outputs | Expected output | PASS | Technical |
| LT03(c) | If the user decides to perform Fault analysis, should select which type of fault currents should be evaluated and proceed according to that | User input | Expected output as given by the user | PASS | Technical |
| LT03(d) | According to the type of fault input given by the user <br/> test *computeSymFault* to find out Symmetrical fault current <br/> test *computeIfSlg* to find out SLG fault current <br/> test *computeIflg* to fing out LG fault current <br/> test *computeIfdlg* to find out LLG fault current | Check if the functions are giving desired output | Expected output given | PASS | Technical |