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
    struct student* next;
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
    struct student* now = NULL;
    now = (struct student*)malloc(sizeof(struct student));
    int n = 0;
    while(1) {
        //if (strlen(names[n]) == 0) return first;
        strcpy(now->name, names[n]);
        now->english = scores[n][0];
        now->math = scores[n][1];
        /*now->next = first;
        first = now;*/
        if (n == 0) {
            first = now;
        }
        if(strlen(names[n+1]) != 0){
            now->next = malloc(sizeof(struct student));
            now = now->next;
        }
        else {
            now->next = NULL;
            return first;
        }
        n++;
    }
    
}