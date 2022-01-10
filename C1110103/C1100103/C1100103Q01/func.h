#pragma once
#include <string.h>
#include <stdlib.h>
// The string length of name
#define LEN_NAME 50

// A structure represents the information of each student
struct student
{
    // The name string
    // Parameter: name (string)
     char name[LEN_NAME];
    
    // The score of English
    // Parameter: english (integer)
    int english;
    
    // The score of Math
    // Parameter: math (integer)
    int math;

    // Pointer to next student
    // Parameter: next (pointer)
    struct student *next;
};


/// <summary>
/// Convert the given 2 arrays into a linked list using 'student' structure.
/// </summary>
/// <param name="names">The name list.</param>
/// <param name="scores">The score list</param>
/// <returns>The first node of the created linked list.</returns>
struct student* convert(char names[][50], int scores[][2])
{
    struct student* first = NULL;
    struct student* s1 = NULL;
    char clear[50] = { '\0' };
    char* arr;
    int n = 0;
    while (strlen(names[n] ) != 0) {
        n++;
    }
   // printf("%d\n",n);
    
    for (int i = n-1; i >= 0; i--) {
        
        s1 = (struct student*)malloc(1*sizeof(struct student));

        strcpy(s1->name,names[i]);
        //strcpys1 = names;
        s1->english = scores[i][0];
        s1->math = scores[i][1];
        s1->next = first;
        first = s1;
        
    }
    //free(s1);
    return first;
}

