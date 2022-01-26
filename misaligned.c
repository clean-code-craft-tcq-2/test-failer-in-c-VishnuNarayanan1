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

int ColorCodeIndexToBePrintedInConsole = 0;
int MaxPossibleMajorColour = 5;
int MaxPossibleMinorColour = 5;
St_ColourInfo ParseColourStub(int majorColourIndex, int minorColourIndex);
void printColourPairAndCodeInConsoleStub(int colorCode, char* majorColor, char* minorColor);
int printColorMapStub(void (*Fn_Ptr_printColourPairAndCodeInConsole)(int,int,  char*,  char* ));
 

// Source code as given 
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

// All the following code are either to show case the segregation of responsibilities without modifying the inherent bug in the source code given
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

// Ideally this print should take ColourInfo.colourCode to print the colour code.
// But just to replicate the nature of original source code :
void printColourPairAndCodeInConsoleStub(int majorColourIndex, int minorColourIndex,  char* majorColor,  char* minorColor)
{
    printf("%d | %s | %s\n", majorColourIndex * 5 + minorColourIndex, majorColor, minorColor);
    ColorCodeIndexToBePrintedInConsole++;
}


// Main comprising of test cases that could catch the bug
int main() {
    St_ColourInfo test_colourInfo;
    int test_majorColourIndex = 0;
    int test_minorColourIndex = 0;
    int test_expectedColourCode = 0;
    ColorCodeIndexToBePrintedInConsole = 0;
    void (*Fn_Ptr)(int,int,  char*,  char*) = printColourPairAndCodeInConsoleStub;
     // Test to see if the expected colour code is mapped against the colour indices passed.
    // This is just a sample, similar checks can be made randomly for various colours.
    test_colourInfo = ParseColourStub(test_majorColourIndex,test_minorColourIndex);
    test_expectedColourCode = (test_majorColourIndex * 5 + test_minorColourIndex);
    assert(test_colourInfo.colourCode == test_expectedColourCode);
    assert(strcmp(test_colourInfo.majorColour,majorColor[test_majorColourIndex]) == 0);
    assert(strcmp(test_colourInfo.minorColour,minorColor[test_minorColourIndex]) == 0);
    // Test if print action has taken place number of times this function is called
    int result = printColorMapStub(Fn_Ptr);
    assert(result == ColorCodeIndexToBePrintedInConsole);
    ColorCodeIndexToBePrintedInConsole = 0;
    printf("All is well (maybe!)\n");
    return 0;
}

