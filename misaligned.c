#include <stdio.h>
#include <string.h>
#include <assert.h>

int InvocationOfPrintInConsole = 0;
int MaxPossibleMajorColour = 5;
int MaxPossibleMinorColour = 5;
void (*Fn_Ptr_printColourPairAndCodeInConsole)(int, char*, char* );
//Fn_Ptr_printColourPairAndCodeInConsole Ptr_printColourPairAndCodeInConsole;
int ParseColour(int majorColourIndex, int minorColourIndex);
void printColourPairAndCodeInConsoleStub(int colorCode, char* majorColor, char* minorColor);
int printColorMapStub(void (*Fn_Ptr_printColourPairAndCodeInConsole)(int, char*, char* ));
    
struct 
{
    char* majorColour;
    char* minorColour;
    int colourCode;
    
}St_ColourInfo;

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMapStub(printColourPairAndCodeInConsoleStub);
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}

int printColorMapStub(void (*Fn_Ptr_printColourPairAndCodeInConsole)(int, char*, char* ))
{

    int majorColourIndex = 0, minorColourIndex = 0;
    St_ColourInfo ColourInfo;
    for(majorColourIndex = 0; majorColourIndex < 5; majorColourIndex++) 
    {
        for(minorColourIndex = 0; minorColourIndex < 5; minorColourIndex++) 
        {
            ColourInfo = ParseColour(majorColourIndex,minorColourIndex);
            Fn_Ptr_printColourPairAndCodeInConsole(ColourInfo.colourCode,ColourInfo.majorColour,minorColour);
        }
    }
    return InvocationOfPrintInConsole;
}

int ParseColour(int majorColourIndex, int minorColourIndex)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    St_ColourInfo ColourInfo;
    strcpy(ColourInfo.majorColour, majorColor[majorColourIndex]);
    strcpy(ColourInfo.minorColour, minorColor[minorColourIndex]);
    ColourInfo.colourCode = (MaxPossibleMajorColour * majorColourIndex) + minorColourIndex + 1;
    return ColourInfo;   
}

void printColourPairAndCodeInConsoleStub(int colorCode, char* majorColor, char* minorColor)
{
     printf("%d | %s | %s\n", colorCode ,majorColor, minorColor);
    InvocationOfPrintInConsole++;
}
