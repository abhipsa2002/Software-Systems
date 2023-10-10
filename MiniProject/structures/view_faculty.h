#ifdef FACULTY
#define FACULTY
#include "courses.h"
struct faculty{
	int sno;
	int usrname;
	char name[50];
	int age;
	char address[100];
	char email[50];
	struct course take[4];  // a faculty can take atmax 4 courses per semester

};

#endif
