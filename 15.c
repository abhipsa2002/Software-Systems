/*
============================================================================
Name : 15.c
Author : Abhipsa Panda
Description: Write a program to display the environmental variable of the user (use environ).
Date: 8th Sept, 2023.
============================================================================
*/

Write a program to display the environmental variable of the user (use environ).
#include <unistd.h>
#include <stdio.h>

extern char **environ; // Declare environ to access environment variables

int main() {
    int i = 0;

    // Use environ to access environment variables
    while (environ[i]) {
        printf("%s\n", environ[i++]);
    }

    return 0;
}

