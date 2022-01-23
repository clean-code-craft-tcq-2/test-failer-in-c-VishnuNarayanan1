#include <stdio.h>
#include <string.h>
#include <assert.h>

struct St_ColourInfo
{
    char majorColour[25];
    char minorColour[25];  
    char colourCode;
};

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int ColorCodeIndexPrintedInConsole = 1;
int MaxPossibleMajorColour = 5;
int MaxPossibleMinorColour = 5;
St_ColourInfo ParseColourStub(int majorColourIndex, int minorColourIndex);
void printColourPairAndCodeInConsoleStub(int colorCode, char* majorColor, char* minorColor);
int printColorMapStub(void (*Fn_Ptr_printColourPairAndCodeInConsole)(int,int,  char*,  char* ));
 


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

int printColorMapStub(void (*Fn_Ptr_printColourPairAndCodeInConsole)(int,int, char*,  char* ))
{

    int majorColourIndex = 0; 
    int minorColourIndex = 0;
    St_ColourInfo ColourInfo;
    for(majorColourIndex = 0; majorColourIndex < 5; majorColourIndex++) 
    {
        for(minorColourIndex = 0; minorColourIndex < 5; minorColourIndex++) 
        {
            ColourInfo = ParseColourStub(majorColourIndex,minorColourIndex);
            Fn_Ptr_printColourPairAndCodeInConsole(majorColourIndex,minorColourIndex,ColourInfo.majorColour,ColourInfo.minorColour);
        }
    }

    return (minorColourIndex * majorColourIndex);
}

St_ColourInfo ParseColourStub(int majorColourIndex, int minorColourIndex)
{
   
    St_ColourInfo ColourInfo;
    strcpy(ColourInfo.majorColour, majorColor[majorColourIndex]);
    strcpy(ColourInfo.minorColour, minorColor[minorColourIndex]);
    ColourInfo.colourCode = (MaxPossibleMajorColour * majorColourIndex) + minorColourIndex + 1;
    return ColourInfo;   
}

void printColourPairAndCodeInConsoleStub(int majorColourIndex, int minorColourIndex,  char* majorColor,  char* minorColor)
{
    printf("%d | %s | %s\n", majorColourIndex * 5 + minorColourIndex, majorColor, minorColor);
    ColorCodeIndexPrintedInConsole++;
}


int main() {
    St_ColourInfo test_colourInfo;
    void (*Fn_Ptr)(int,int,  char*,  char*) = printColourPairAndCodeInConsoleStub;
    test_colourInfo = ParseColourStub(0,0);
    assert(test_colourInfo.colourCode == 1);
    assert(strcmp(test_colourInfo.minorColour,majorColor[0]) == 0);
    assert(strcmp(test_colourInfo.minorColour,minorColor[0]) == 0);
    int result = printColorMapStub(Fn_Ptr);
    assert(result == ColorCodeIndexPrintedInConsole);
    printf("All is well (maybe!)\n");
    return 0;
}

