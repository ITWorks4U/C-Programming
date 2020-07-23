/**
*	An own defined header file for C/C++.
*
*	@author			ITWorks4U
*/

#ifndef HEADER_FILE_H
#define HEADER_FILE_H

struct SExample {
    int i;
    float f;
    char cString[20];
};

void addDataToStruct(struct SExample *example_S);
void printToConsole(struct SExample *example_S);

#endif
