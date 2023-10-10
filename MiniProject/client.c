#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>  
#include<arpa/inet.h>  
#include<unistd.h>
#include<stdbool.h>
#include<strings.h>
#include<string.h>

int opt,currid;

void selectopt(int sd){
	printf("1 : FACULTY  \n");
	printf("2 : STUDENT  \n");
	printf("3 : ADMIN  \n");
	printf("Choose an option: ");
	scanf("%d",&opt);
	printf("Option selected: %d\n",opt);

	switch(option){
		case 1 :
			FacultyLogin(sd);
			break;
		case 2 :
			StudentLogin(sd);
			break;
		case 3 :
			AdminLogin(sd);
			break;
		default :
			printf("Inavlid!!! Choose a valid option \n");
			selectopt(sd);
			break;
	}
}

void disp_menu(int sd){
	int d;
	if(opt==1){
		printf("1 : Add a new course \n");
		printf("2 : Remove an existing course \n");
		printf("3 : View enrollments in course \n");
		printf("4 : Password Change\n");
		printf("5 : Exit \n");
		printf("Choose the task : ");
		scanf("%d",&d);
		printf("Option : %d\n",d);

		switch(d){
		case 1 :
			add_course(sd);
			break;
		case 2 :
			remove_course(sd);
			break;
		case 3 :
			view_enrol(sd);
			break;
		case 4 :
			change_password(sd);
			break;
		case 5 :
			//write(sd,&d,sizeof(int));
			printf("Adios! \n");
			exit(0);
		default :
			printf("Inavlid!!! Choose a valid option \n");
			disp_menu(sd);
			break;
		}
	}
	if(opt==2){
		printf("1 : View all courses \n");
		printf("2 : Enroll to a new course \n");
		printf("3 : Unenroll from an existing course \n");
		printf("4 : View enrolled courses \n");
		printf("5 : Password Change\n");
		printf("6 : Exit \n");
		printf("Choose the task : ");
		scanf("%d",&d);
		printf("Option : %d\n",d);

		switch(d){
		case 1:
			view_allcourse(sd);
			break;
		case 2 :
			enroll_course(sd);
			break;
		case 3 :
			unenroll_course(sd);
			break;
		case 4 :
			view_course(sd);
			break;
		case 5 :
			change_password(sd);
			break;
		case 6 :
			//write(sd,&d,sizeof(int));
			printf("Adios! \n");
			exit(0);
		default :
			printf("Inavlid!!! Choose a valid option \n");
			disp_menu(sd);
			break;
		}
	}
	else if(opt==3){
		printf("1 : Add Student \n");
		printf("2 : Add Faculty \n");
		printf("3 : Activate Student \n");
		printf("4 : Deactivate Student \n");
		printf("5 : Update Faculty Details \n");
		printf("6 : Update Student Details \n");
		printf("7 : Delete Faculty \n");
		printf("8 : Delete Stduent \n");
		printf("9 : Change password \n");
		printf("10 : Exit \n");
		printf("Choose the task: ");
		scanf("%d",&d);
		printf("Option : %d\n",d);

		switch(d){
		case 1 :
			add_student(sd);
			break;
		case 2 :
			add_faculty(sd);
			break;
		case 3 :
			activate_student(sd);
			break;
		case 4 :
			deactivate_student(sd);
			break;
		case 5:
			update_faculty(sd);
			break;
		case 6:
			update_student(sd);
			break;
		case 7:
			del_faculty(sd);
			break;
		case 8:
			del_student(sd);
			break;
			
		case 9: 
			change_password(sd);
			break;
		case 10:
			//write(sd,&select,sizeof(int));
			printf("Adios !\n");
			exit(0);
		default:
			printf("Inavlid!!! Choose a valid option \n");
			disp_menu(sd);
			break;
		}
	}
}

//FACULTY LOGIN
void FacultyLogin(int sd){
	bool res;
	struct faculty curr;
	printf("User ID : ");
	scanf("%d",&curr.id);
	currid=curr.id;
	printf("Password : ");
	char* pass = getpass("");
	strcpy(curr.password, pass);

	getchar(); //wait till user presses enter
	write(sd,&opt,sizeof(int)); //pass to server
	write(sd,&currUser,sizeof(struct faculty)); //pass to server

	read(sd,&res,sizeof(res)); //wait for server to do the password matching and save the return value in 'res' variable

	if(!res){			
		printf("Invalid password or userid \n");
		printf("TRY AGAIN !!! \n");
		selectopt(sd);
	}
	else{
		printf("Logged in!!!\n");
	}
}

//STUDENT LOGIN

void StudentLogin(int sd){
	bool res;
	struct student curr;
	printf("User ID : ");
	scanf("%d",&curr.id);
	currid=curr.id;
	printf("Password : ");
	char* pass = getpass("");
	strcpy(curr.password, pass);

	getchar(); //wait till user presses enter
	write(sd,&opt,sizeof(int));  //pass to server
	write(sd,&currUser,sizeof(struct student)); //pass to server

	read(sd,&res,sizeof(res)); //wait for server to do the password matching and save the return value in 'res' variable

	if(!res){
		printf("Invalid password or userid \n");
		printf("TRY AGAIN !!! \n");
		selectopt(sd);
	}
	else{
		printf("Logged in!!!\n");
	}
}

//ADMIN LOGIN

void AdminLogin(int sd){
	bool res;
	struct admin curr;
	printf("User ID : ");
	scanf("%d",&curr.id);
	currid=curr.id;
	printf("Password : ");
	char* pass = getpass("");
	strcpy(curr.password, pass);
	getchar(); //wait till user presses enter
	write(sd,&opt,sizeof(int));  //pass to server
	write(sd,&currUser,sizeof(struct admin)); //pass to server

	read(sd,&res,sizeof(res)); //wait for server to do the password matching and save the return value in 'res' variable

	if(!res){
		printf("Invalid password or userid \n");
		printf("TRY AGAIN !!! \n");
		selectopt(sd);
	}
	else{
		printf("Logged in!!!\n");
	}
}

void change_password(int sd){
	int select;
	if(opt==1) select=4;
	if(opt==2) select=5;
	if(opt==3) select=9;
	char old_pass[10];
	char new_pass[10];
	bool res;

	printf("Enter your current password : ");
	char* pass = getpass("");
        strcpy(old_pass, pass);

	//to the server
	write(sd,&select,sizeof(int));
	write(sd,old_pass,sizeof(old_pass));
	printf("Enter the new password(max 10 characters) : ");
	pass = getpass("");
        strcpy(new_pass, pass);
	write(sd,new_pass,sizeof(new_pass));

	read(sd,&res,sizeof(res));
	if(!result){
		printf("Error changing your password! \n");
	}
	else{
		printf("Succesfully changed your password! \n");
	}
	disp_menu(sd);
}

int main(){
	printf("WELCOME TO COURSE MANAGEMENT SYSTEM ");
	struct sockaddr_in server;    
	int sd;
	char buff[50];
	char result;

	sd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INNADDR_ANY;
	server.sin_port=htons(5000);

	connect(sd,(struct sockaddr *)&server,sizeof(server));
	selectopt(sd);
	disp_menu(sd);
	close(sd);
	return 0;
}
