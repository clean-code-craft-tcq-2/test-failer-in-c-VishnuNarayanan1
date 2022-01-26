#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
int UpperThresholdLimitInCelcius = 200;
int LowerThresholdLimitInCelcius = 100;

int networkAlert(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit, int (*Fn_Ptr_NetworkAlert)(float) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = Fn_Ptr_NetworkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

                    // Test environment 
                    
int networkAlertStub(float celcius) 
{
    int alertCode = 0;
    if((celcius >= UpperThresholdLimitInCelcius) || (celcius <= LowerThresholdLimitInCelcius)) && (celcius > 0))
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        alertCode = 500;
    } 
    else if ((celcius < UpperThresholdLimitInCelcius) && (celcius > LowerThresholdLimitInCelcius)))
    {
        alertCode = 200;
    }
    else
    {
        alertCode = 0xff // Invalid use case
    }
    return alertCode;
}
                    
int main() {
    int (*Fn_Ptr_NetworkAlert)(float) = networkAlertStub;
    alertInCelcius(400.5,Fn_Ptr_NetworkAlert);
    alertInCelcius(303.6,Fn_Ptr_NetworkAlert);
    alertInCelcius(50,Fn_Ptr_NetworkAlert);
    alertInCelcius(1000,Fn_Ptr_NetworkAlert);
    alertInCelcius(0,Fn_Ptr_NetworkAlert);
    assert(2,alertFailureCount);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
