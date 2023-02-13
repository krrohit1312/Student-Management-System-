/*
Student Management Project
which store detail, show and serach its detail
update detail by searching rno
delete detail by search rno 
Project developed by me
guide:sushil kumar patel
college name:IES Institute of Technology and Management,Bhopal
Name:Rohit Kumar
mailid:rohitkumaranand1312@gmail.com
phoneno:8862940763
                                    */
/*********** header files inclusion ************/
#include<stdio.h> //for printf()/scanf()/fopen()/fclose()/gets()/puts()/fread()/fwrite()/fflush()
#include<process.h> //exit(0) ----which ends program
#include<conio.h>
#include<string.h>

/**********Declaration of Structure Student *************/
struct Student
{
	int rno;
	char name[20];
	char nickname[20];
	char city[20];
	char mno[15];
}s;  //s(global)  /* global variable of structure student--->s  */
/*********** Prototyping of Functions ************/
void input_Student_Detail();
void show_Student_Detail();
void search_Student_Detail();
void update_Student_Detail();
void delete_Student_Detail();
/******************** Definition of main function ***************/
int main()
{
	//struct Student s;
	int ich;
	while(1)
	{
		system("cls");
		printf("\n1.Input Detail:");
		printf("\n2.Show Detail:");
		printf("\n3.Search Detail:");
		printf("\n4.Update Detail:");
		printf("\n5.Delete Detail:");
		printf("\n6.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ich);
		system("cls");
		switch(ich)
		{
			case 1:
				input_Student_Detail();
			break;
			case 2:
				show_Student_Detail();
			break;
			case 3:
				search_Student_Detail();
			break;
			case 4:
				update_Student_Detail();
			break;
			case 5:
				delete_Student_Detail();
			break;
			case 6:
				exit(0);   //loopxxx-----------exit from program
			default:
				printf("\nwrong choice");
		}//switch closed
		getch();
	}//while closed
	return 0;
}
/************ input_Student_Detail() function definition ***************/
void input_Student_Detail()
{
	FILE *fptr;
	fptr=fopen("stu.dat","ab");
	//read data from console input to memory of s=28 byte (rno,name,marks)(RAM)
	printf("Enter rno:");
	scanf("%d",&s.rno);
	printf("Enter name:");
	fflush(stdin);
	gets(s.name);
	printf("Enter nick name:");
	gets(s.nickname);
	printf("Enter city:");
	gets(s.city);
	printf("Enter mobile number:");
	gets(s.mno);
	//xxxxfprintf(fptr,"%d %s %f",rno,name,marks);
	//fwrite((char*)&stvar,1,sizeof(stvar),filepointer);
	fwrite((char*)&s,1,sizeof(s),fptr);
	fclose(fptr);
}
/************* show_Student_Detail() function definition ****************/
void show_Student_Detail()
{
	FILE *fptr;
	fptr=fopen("stu.dat","rb");
	//fread((char*)&stvar,1,sizeof(stvar),filepointer);
	//read data from file(stu.txt) to memory of s(RAM)
	while(fread((char*)&s,1,sizeof(s),fptr))
	{
		//read--- 28/non zero =true ,fail=0
		printf("\nDetail of student:\n");
		printf("\nRno=>%d",s.rno);
		printf("\nName=>%s",s.name);
		printf("\nNickName=>%s",s.nickname);
		printf("\nCity=>%s",s.city);
		printf("\nMobile number=>%s",s.mno);
		getch();
	}
	fclose(fptr);
}
/*********** search_Student_Detail() function definition **************/
void search_Student_Detail()
{
	int ich,sno,f=0;
	char sname[20],cname[20],nname[20],Mno[15];
	FILE *fptr;
	fptr=fopen("stu.dat","rb");
	printf("\n1.search detail by rno:");
	printf("\n2.search detail by name:");
	printf("\n3.search detail by city/state:");
	printf("\n4.search detail by nickname:");
	printf("\n5.search detail by mobile number:");
	printf("\nEnter your choice:");
	scanf("%d",&ich);
	switch(ich)
	{
		case 1:
			
	        printf("Enter rno for search:");
	        scanf("%d",&sno);
            while(fread((char*)&s,1,sizeof(s),fptr))
	        {
		        if(s.rno==sno)
		        {
			        printf("\nDetail of Student:\n");
			        printf("\nRno=>%d",s.rno);
			        printf("\nName=>%s",s.name);
			        printf("\nCity=>%s",s.city);
			        getch();
			        f=1;
			        break;
		        }
	        }
	        if(f==0)
	        {
		        printf("Student record not found");
        	}
        break;
		case 2:
		    
			
			printf("Enter name for search:");
			fflush(stdin);
			gets(sname);
			while(fread((char*)&s,1,sizeof(s),fptr))
	        {
		        if(strcmp(s.name,sname)==0)
		        {
			        printf("\nDetail of Student:\n");
			        printf("\nRno=>%d",s.rno);
			        printf("\nName=>%s",s.name);
			        printf("\nCity=>%s",s.city);
			        getch();
			        f=1;
			        
		        }
	        }
	        if(f==0)
	        {
		        printf("Student record not found");
        	}
		break;
		case 3:	
		    
			
			printf("Enter city for search:");
			fflush(stdin);
			gets(cname);
			while(fread((char*)&s,1,sizeof(s),fptr))
	        {
		        if(strcmp(s.city,cname)==0)
		        {
			        printf("\nDetail of Student:\n");
			        printf("\nRno=>%d",s.rno);
			        printf("\nName=>%s",s.name);
			        printf("\nCity=>%s",s.city);
			        getch();
			        f=1;
			        
		        }
	        }
	        if(f==0)
	        {
		        printf("Student record not found");
        	}
		break;	
		case 4:
		    	printf("Enter nick name for search:");
				fflush(stdin);
				gets(nname);
				while(fread((char*)&s,1,sizeof(s),fptr))
		        {
			        if(strcmp(s.nickname,nname)==0)
			        {
				        printf("\nDetail of Student:\n");
				        printf("\nRno=>%d",s.rno);
				        printf("\nName=>%s",s.name);
				        printf("\nNickName=>%s",s.nickname);
				        printf("\nCity=>%s",s.city);
				        printf("\nMobile Number=>%s",s.mno);
				        getch();
				        f=1;
				        
			        }
			    }
		        if(f==0)
		        {
			        printf("Student record not found");
		       	}
		break;
		case 5:	
		    
			
			printf("Enter mobile number for search:");
			fflush(stdin);
			gets(Mno);
			while(fread((char*)&s,1,sizeof(s),fptr))
	        {
		        if(strcmp(s.mno,Mno)==0)
		        {
			        printf("\nDetail of Student:\n");
			        printf("\nRno=>%d",s.rno);
			        printf("\nName=>%s",s.name);
			        printf("\nNickName=>%s",s.nickname);
			        printf("\nCity=>%s",s.city);
			        printf("\nMobile Number=>%s",s.mno);
			        getch();
			        f=1;
			        
		        }
	        }
	        if(f==0)
	        {
		        printf("Student record not found");
        	}
		break;
   	}
	
	fclose(fptr);
}
/**************** update_Student_Detail() function definition ****************/
void update_Student_Detail()
{
	FILE *fptr1,*fptr2;
	fptr1=fopen("stu.dat","rb");
	fptr2=fopen("temp.dat","w");
	
	int sno,f=0;
	printf("Enter rno for search:");
	scanf("%d",&sno);
	while(fread((char*)&s,1,sizeof(s),fptr1))
	{
		if(s.rno==sno)
		{
			printf("\nDetail of student:\n");
			printf("\nRno=>%d",s.rno);
			printf("\nName=>%s",s.name);
			printf("\nNickName=>%s",s.nickname);
			printf("\nCity=>%s",s.city);
			printf("\nMobile Number=>%s",s.mno);
			printf("\nEnter values for new input:\n");
			printf("\nEnter Rno:");
			scanf("%d",&s.rno);
			printf("\nEnter name:");
			fflush(stdin);
			gets(s.name);
			printf("\nEnter nick name:");
			gets(s.nickname);
			printf("\nEnter city:");
			gets(s.city);
			printf("\nEnter Mobile Number:");
			gets(s.mno);
			fwrite((char*)&s,1,sizeof(s),fptr2);
			f=1;
		}
		else
		{
			fwrite((char*)&s,1,sizeof(s),fptr2);
		}
	}
	if(f==0)
	{
		printf("Student record not found");
	}
	fclose(fptr1);
	fclose(fptr2);
	remove("stu.dat");
	rename("temp.dat","stu.dat");
	
}
/************* delete_Student_Detail() function definition ***********/
void delete_Student_Detail()
{
	FILE *fptr1,*fptr2;
	fptr1=fopen("stu.dat","rb");
	fptr2=fopen("temp.dat","w");
	int sno,f=0;
	printf("Enter rno for search:");
	scanf("%d",&sno);
	while(fread((char*)&s,1,sizeof(s),fptr1))
	{
		if(s.rno==sno)
		    f=1;
		else
		    fwrite((char*)&s,1,sizeof(s),fptr2);
	}
	if(f==1)
	{
		printf("Student record deleted");
	}
	else
	{
		printf("Student record not found");
	}
	fclose(fptr1);
	fclose(fptr2);
	remove("stu.dat");
	rename("temp.dat","stu.dat");
}

