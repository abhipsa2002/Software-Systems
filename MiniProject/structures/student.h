
#ifndef STUDENT
#define STUDENT
#include "courses.h"
struct student{
	int sno; //like record number, it'll be useful while record locking
        int rollno;
        char name[50];v
        int age;
        char email[50];
        char address[100];
        char password[8];
        char status[20];
        struct course c[4]; //A student is allowed to take atmax 4 courses per semester
};

#endif
