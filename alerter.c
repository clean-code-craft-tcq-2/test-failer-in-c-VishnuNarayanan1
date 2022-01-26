#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
int UpperThresholdLimitInCelcius = 200;
int LowerThresholdLimitInCelcius = 100;
int MinimumAcceptableCelciusInWorkingEnvironment = 1;
int MaximumAcceptableCelciusInWorkingEnvironemnt = 399;

int networkAlert(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit, int (*Fn_Ptr_NetworkAlert)(float)) {
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

                    /*************** Test environment ***************/
                    
int networkAlertStub(float celcius) 
{
    int alertCode = 0;
    if((celcius >= UpperThresholdLimitInCelcius) || (celcius <= LowerThresholdLimitInCelcius) && (MinimumAcceptableCelciusInWorkingEnvironment >= MinimumAcceptableCelciusInWorkingEnvironment) &&
        (celcius <= MaximumAcceptableCelciusInWorkingEnvironemnt))
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        alertCode = 500;
    } 
    else if ((celcius < UpperThresholdLimitInCelcius) && (celcius > LowerThresholdLimitInCelcius))
    {
        alertCode = 200;
    }
    else
    {
        alertCode = 0xff ;
       // Invalid use case should also be captured, (this catches the returnCode != 200 condition in the code, which cannot be the sole condition for counting the alerts)
    }
    return alertCode;
}
                    
int main() {
    int (*Fn_Ptr_NetworkAlert)(float) = networkAlertStub;
    alertInCelcius(400.5,Fn_Ptr_NetworkAlert); // Celcius 204.7 -> Alert
    alertInCelcius(303.6, Fn_Ptr_NetworkAlert); // Celcius 150.8 -> Don't Alert
    alertInCelcius(50,Fn_Ptr_NetworkAlert); // Celcius 10 -> Alert
    alertInCelcius(752,Fn_Ptr_NetworkAlert); // Celcius 400 -> Invalid use case
    alertInCelcius(0,Fn_Ptr_NetworkAlert); // Celcius 32 -> Invalid use case
    assert(2 == alertFailureCount);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
