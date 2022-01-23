#include <stdio.h>
#include <string.h>
#include <assert.h>

struct St_ColourInfo
{
    char* majorColour;
    char* minorColour;
    int colourCode;
    
};
int InvocationOfPrintInConsole = 0;
int MaxPossibleMajorColour = 5;
int MaxPossibleMinorColour = 5;
St_ColourInfo ParseColour(int majorColourIndex, int minorColourIndex);
void printColourPairAndCodeInConsoleStub(int colorCode, char* majorColor, char* minorColor);
//int printColorMapStub(void (*Fn_Ptr_printColourPairAndCodeInConsole)(int,  char*,  char* ));
int printColorMapStub(void);
    
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

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

//int printColorMapStub(void (*Fn_Ptr_printColourPairAndCodeInConsole)(int,  char*,  char* ))
int printColorMapStub(void)
{

    int majorColourIndex = 0; 
    int minorColourIndex = 0;
    St_ColourInfo ColourInfo;
    for(majorColourIndex = 0; majorColourIndex < 5; majorColourIndex++) 
    {
        for(minorColourIndex = 0; minorColourIndex < 5; minorColourIndex++) 
        {
            ColourInfo.colourCode = 1;
            ColourInfo = ParseColour(majorColourIndex,minorColourIndex);
            printf("Print %d", InvocationOfPrintInConsole);
            printf("Print %d", ColourInfo.colourCode);
            printf("Print %d", ColourInfo.majorColour);
            printf("Print %d", ColourInfo.minorColour);
           // Fn_Ptr_printColourPairAndCodeInConsole(ColourInfo.colourCode,ColourInfo.majorColour,ColourInfo.minorColour);
        }
    }

    return InvocationOfPrintInConsole;
}

St_ColourInfo ParseColour(int majorColourIndex, int minorColourIndex)
{

    St_ColourInfo ColourInfo;
    strcpy(ColourInfo.majorColour, majorColor[majorColourIndex]);
    strcpy(ColourInfo.minorColour, minorColor[minorColourIndex]);
    ColourInfo.colourCode = (MaxPossibleMajorColour * majorColourIndex) + minorColourIndex + 1;
    return ColourInfo;   
}

void printColourPairAndCodeInConsoleStub(int colorCode,  char* majorColor,  char* minorColor)
{
     printf("%d | %s | %s\n", colorCode ,majorColor, minorColor);
    InvocationOfPrintInConsole++;
}


int main() {
    //void (*Fn_Ptr)(int,  char*,  char*) = printColourPairAndCodeInConsoleStub;
    //int result = printColorMapStub(Fn_Ptr);
    int result = printColorMapStub();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}

