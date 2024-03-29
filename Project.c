#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define Admin "mesbah"
#define Password "12345"

void admin_login();
void student_login();
void student_signup();
void home();
void marks_entry();
void result();
void laptop();
void registered_course();
void choice();
void notice_add();
void notice_board();

struct studentINFO
{
    char firstname[30];
    char lastname[30];
    char id[15];
    char program[50];
    char mail[20];
    int contact;
    char birthdateDate[30];
    char presentAdd[60];
    char permanentAdd[60];
    char username[20];
    char password[10];
} student_info;

struct student
{
    char ID[15];
    int name;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float sgpa;
};
struct student stu;

FILE *stu_data;

void main()
{
    system("cls");
    printf("\t\t\t\t\t ---------------Welcome---------------\n");
    printf("\n\t\t\t\t\t**********please Log In First**********\n");
    printf ("\n\t\t\t\t********************************************************");
    printf ("\n\t\t\t\t********************************************************\n\n\n");
again:
    printf("\n\t\t\tAdmin Login press    1\n");
    printf("\n\t\t\tStudent Login press  2\n");
    printf("\n\t\t\tStudent Signup press 3\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        admin_login();
        break;
    case 2:
        student_login();
        break;
    case 3:
        student_signup();
        break;
    default:
        printf("Wrong Keyword");
        goto again;
    }
}

admin_login()
{
    system("cls");
    char user_name[10],pass[10];
    int count=0,stay=3;

again:
    count++;
    if(count==4)
        exit(0);
    stay--;

    printf("\n\n\t\t\t\t\t\t\tUser Name:\n");
    scanf("%s",&user_name);

    printf("\n\t\t\t\t\t\t\tPassword:\n");
    scanf("%s",&pass);

    if(strcmp(user_name,Admin)==0)
    {
        if(strcmp(pass,Password)==0)
        {
            home();
        }
        else
        {
            printf("\n\t\t\t\t\t\t   wrong password");
            printf("\n\t\t\t\t\t\tYou have %d last chance\n",stay);
            goto again;
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\t  User doesn't exist");
        printf("\n\t\t\t\t\t\tYou have %d last chance\n",stay);
        goto again;
    }
}

home()
{
    system("cls");
    int choice;
again:
    printf("\n\t\t\t\t\t\t What you want to do?\n");
    printf("\n\t\t\t\t\t\tStudent Marks Entry --> 1\n");
    printf("\n\t\t\t\t\t\tNotice Board Update --> 2\n");
    printf("\n\n\t\t\t\t\t\t exit '3'");

    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        marks_entry();
        break;
    case 2:
        notice_add();
        break;
    case 3:
        exit(0);
        break;
    default:
        goto again;
    }

}

marks_entry()
{
    system("cls");
    int print = 37,choice;
    float wgpa;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    if(fp == NULL)
    {
        printf(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }
    else
    {
        fflush(stdin);
        printf("ID: ");
        gets(stu.ID);
        printf("Enter Semester");
        scanf("%d",&stu.name);

        if(stu.name==1)
        {
            printf("GPA of MATHEMATICS: ");
            scanf("%f",&stu.m1);
            printf("GPA of ENGLISH: ");
            scanf("%f",&stu.m2);
            printf("GPA of PHYSICS: ");
            scanf("%f",&stu.m3);
            printf("GPA of CHEMISTRY: ");
            scanf("%f",&stu.m4);
            printf("GPA of BIOLOGY: ");
            scanf("%f",&stu.m5);
            wgpa=stu.m1*3+stu.m2+stu.m3*3+stu.m4*3+stu.m5*3;
            stu.sgpa=wgpa/13.00;
            fwrite(&stu, sizeof(stu), 1, fp);
            printf("The record is sucessfully added");
        }
        fclose(fp);
        printf("Do you want to continue? press '1' for continue or '0' for exit");
        scanf("%d",choice);
        switch(choice)
        {
        case 1:
            home();
            break;
        case 0:
            exit(0);
        default:
            exit(1);
        }
    }
}

result()
{
    system("cls");
    char s_id[15];
    int semester;
    int isFound = 0;
    printf("Enter Your Student ID Again: ");
    fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","r");
    while(fread(&stu,sizeof(stu),1,fp) == 1)
    {
        if(strcmp(s_id,stu.ID) == 0)
        {
            isFound = 1;
            break;
        }
    }
    if(isFound == 1)
    {
        printf("\n\n\t\t\t\t\tNOTICE BOARD");
        printf("\n\n\n\t\t\t\tGPA of MATHEMATICS: ");
        printf("%.2f",stu.m1);
        printf("\n\t\t\t\tGPA of ENGLISH: ");
        printf("%.2f",stu.m2);
        printf("\n\t\t\t\tGPA of PHYSICS: ");
        printf("%.2f",stu.m3);
        printf("\n\t\t\t\tGPA of CHEMISTRY: ");
        printf("%.2f",stu.m4);
        printf("\n\t\t\t\tGPA of BIOLOGY: ");
        printf("%.2f",stu.m5);
        printf("\n\t\t\t\tYour SGPA is %.2f\n", stu.sgpa);
        fwrite(&stu, sizeof(stu), 1, fp);
        fclose(fp);
    }

    else
    {
        printf("\nSorry, No record found in the database\n");
    }
    fclose(fp);
    printf("\n\t\tDo you want to continue? press '1' for continue or '0' for exit");
    int chc;
    scanf("%d",&chc);
    switch(chc)
    {
    case 1:
        choice();
        break;
    case 0:
        exit(0);
    default:
        main();
    }
}

student_signup()
{
    system("cls");

    int index, check=0;
    char testUser[20], testPass[10], retype_pass[10];

retry:
    printf("\n\n\t\t\t\tFill all the information to register you...\n");
    stu_data=fopen("signup.txt","a");

    if(stu_data==NULL)
    {
        printf("\n\t\t\tFile not found!!!\n");
        exit(1);
    }
    getchar();
    printf("\n\t\t\tFirst Name: ");
    gets(student_info.firstname);
    printf("\n\t\t\tLast Name: ");
    gets(student_info.lastname);
    printf("\n\t\t\tId No: ");
    gets(student_info.id);
    printf("\n\t\t\tProgram: ");
    gets(student_info.program);
    printf("\n\t\t\tUniversity Mail: ");
    gets(student_info.mail);
    printf("\n\t\t\tContact No: ");
    scanf("%d",&student_info.contact);
    getchar();
    printf("\n\t\t\tBirthdate: ");
    gets(student_info.birthdateDate);
    printf("\n\t\t\tPresent Address: ");
    gets(student_info.presentAdd);
    printf("\n\t\t\tPermanent Address: ");
    gets(student_info.permanentAdd);
    printf("\n\t\t\tUsername: ");
    gets(testUser);
    while(fread(&student_info.username, sizeof(student_info.username), 1, stu_data)==1)
    {
        if(testUser==student_info.username)
        {
            check=1;
            system("cls");
            printf("\n\t\t\tUsername taken\n");
            goto retry;
        }
        else
            check=0;
    }
    if(check == 0)
        strcpy(student_info.username,testUser);
    printf("\n\t\t\tPassword(**Must be 5 charecter**): ");
    scanf("%s",&testPass);
    printf("\n\t\t\tRetype Password: ");
    scanf("%s",&retype_pass);
    if(strcmp(testPass, retype_pass)==0)
    {
        strcpy(student_info.password, testPass);
        fwrite(&student_info, sizeof(student_info), 1, stu_data);
        fclose(stu_data);
    }
    printf("\n\t\t\t SignUp Completted");
    main();
}

student_login()
{
    system("cls");
    char usr_name[15],passw[10];
    int count=0,check=1;
try_again:
    printf("\n\n\t\t\t\t\t\tUser Name: ");
    scanf("%s",&usr_name);

    printf("\n\t\t\t\t\t\tPassword: ");
    scanf("%s",&passw);
    stu_data=fopen("signup.txt","r");
    if(stu_data==NULL)
        printf("\n\t\t\tError!!! Failed to compare.\n");
    else
    {
        while(fread(&student_info, sizeof(student_info), 1, stu_data)==1)
        {
            if(strcmp(usr_name,student_info.username)== 0 && strcmp(passw,student_info.password)== 0)
            {
                check=1;
                fclose(stu_data);
                choice();
                break;
            }
        }
    }
    if(check=0)
    {
        printf("Error log in, try again!!!\n");
        ++count;
        if(count==3)
            exit(1);
        goto try_again;
    }
}

choice()
{
    system("cls");
    printf("\t\t\t\t\t ----------------Welcome---------------\n");
    printf("\n\t\t\t\t\t**********What You Want To Do**********\n");
    printf ("\n\t\t\t\t********************************************************");
    printf ("\n\t\t\t\t********************************************************\n\n\n");
again:
    printf("\t\t\tSee Result ------------> 1\n");
    printf("\n\t\t\tLaptp Eligibility -----> 2\n");
    printf("\n\t\t\tSee Registered Course -> 3\n");
    printf("\n\t\t\tSee Notice Board ------> 4\n");
    int chc;
    scanf("%d",&chc);
    switch(chc)
    {
    case 1:
        result();
        break;
    case 2:
        laptop();
        break;
    case 3:
        registered_course();
        break;
    case 4:
        notice_board();
        break;
    default:
        goto again;
    }
}

notice_add()
{
    char sentence[1000];
    FILE *fptr;
    fptr = fopen("notice.txt", "w");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    printf("Enter the notice:\n");
    scanf("%s",&sentence);
    fprintf(fptr, "%s", sentence);
    fclose(fptr);
    printf("Do you want to continue? press '1' for continue or '0' for exit");
    int choice;
    scanf("%d",choice);
    switch(choice)
    {
    case 1:
        home();
        break;
    case 0:
        exit(0);
    default:
        exit(1);
    }
}
notice_board()
{
    system("cls");
    FILE *fptr;
    char c[1000];
    if ((fptr = fopen("notice.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    fscanf(fptr,"%s", c);
    printf("\n\t\t\t\t\t\t Notice Board\n");
    printf("\n%s",c);
    fclose(fptr);
    int o;
    printf("\nTo continue press '1' to exit press'0'.");
    scanf("%d",&o);
    switch(o)
    {
    case 1:
        choice();
        break;
    case 0:
        exit(0);
        break;
    default:
        main();
    }
}

laptop ()
{
    system ("cls");
    int x;

    printf ("\n\t\t\tWhich semester do you read now?\n\t\t\t");
    scanf ("%d", &x);
    if (x > 6)
        printf ("\n\t\t\tYou have received your laptop. If not, contact your advisor or DIU Register office.");
    else if (x == 6)
        printf ("\n\t\t\tWelcome! You are eligible for the laptop campaign.");
    else
        printf ("\n\t\t\tSorry, you are not eligible for the laptop campaign.");

    int o;
    printf("\nTo continue press '1' to exit press'0'.");
    scanf("%d",&o);
    switch(o)
    {
    case 1:
        choice();
        break;
    case 0:
        exit(0);
        break;
    default:
        main();
    }
}

registered_course()
{
    system("cls");

    int x;
    printf ("\t\t\t\tEnter your semester: ");
    scanf ("%d", &x);
    printf ("Course Code\t\tCourse Title\t\t\tCourse Credit\n");
    if (x >= 1 && x <= 11)
    {
        if (x == 1)
        {
            printf ("SE111\t\tComputer Fundamentals\t\t\t3\n");
            printf ("SE113\t\tIntroduction to Software Engineering\t\t\t3\n");
            printf ("SE112\t\tComputer Fundamentals Lab\t\t\t1\n");
            printf ("ENG 101\t\tEnglish I\t\t\t3\n");
            printf ("AOL 101\t\tArt of Living\t\t\t3\n");
        }
        else if (x == 2)
        {
            printf ("SE122\t\tStructured Programming Lab\t\t\t1\n");
            printf ("SE123\t\tDiscrete Mathematics\t\t\t3\n");
            printf ("SE121\t\tStructured Programming\t\t\t3\n");
            printf ("MAT 101\t\tMathematics I\t\t\t3\n");
            printf ("PHY 101\t\tPhysics I\t\t\t3\n");
        }
        else if (x == 3)
        {
            printf ("SE131\t\tData Structure\t\t\t3\n");
            printf ("SE132\t\tData Structure Lab\t\t\t1\n");
            printf("SE133\t\tSoftware Development Capstone Project\t\t\t3\n");
            printf ("STA101\t\tStatistics I\t\t\t3\n");
            printf ("MAT102\t\tMathematics II\t\t\t3\n");

        }
        else if (x == 4)
        {
            printf ("SWE 132\t\tJava Programming With Lab\t\t\t4\n");
            printf ("SWE 213\t\tComputer Algorithm With Lab\t\t\t4\n");
            printf ("SWE 211\t\tIntroduction to Database With Lab\t\t\t4\n");
        }
        else if (x == 5)
        {
            printf ("SWE 233\t\tObject Oriented Concept & Design With Lab\t\t\t4\n");
            printf ("SWE 222\t\tSoftware Engineering Assurance & Testing\t\t\t3\n");
            printf ("SWE 223\t\tDigital Electronics With Lab\t\t\t4\n");
            printf ("SWE 224\t\tDiscrete Mathematics\t\t\t3\n");
        }
        else if (x == 6)
        {
            printf("SWE 131\t\tDocumentation of Software Engineering\t\t\t3\n");
            printf ("SWE 232\t\tOperating System With Lab\t\t\t4\n");
            printf ("SWE 132\t\tSoftware Project Management\t\t\t3\n");
            printf ("SWE 435\t\tBussiness Communication\t\t\t3\n");

        }
        else if (x == 7)
        {
            printf ("SWE 323\t\tSystem Analysis and Design\t\t\t3\n");
            printf ("SWE 312\t\tTheory of Computing\t\t\t3\n");
            printf ("SWE 322\t\tSoftware Security\t\t\t3\n");
            printf ("SWE 313\t\t.Net Programming With Lab\t\t\t4\n");
        }
        else if (x == 8)
        {
            printf ("SWE 321\t\tData Communication With Lab\t\t\t4\n");
            printf ("SWE 333\t\tDesktop and Web Programming With Lab\t\t\t4\n");
            printf ("SWE 311\t\tComputer Architecture & Organization\t\t\t3\n");
            printf ("SWE 413\t\tSoftware Engineering & Cyber Laws\t\t\t3\n");
        }
        else if (x == 9)
        {
            printf ("SWE 412\t\tManagement Information System\t\t\t3\n");
            printf ("SWE 331\t\tObject Oriented Software Development\t\t\t3\n");
            printf ("SWE 422\t\tNumerical Analysis With Lab\t\t\t4\n");
            printf ("SWE 424\t\tArtificial Intelligence With Lab\t\t\t4\n");
        }
        else if (x == 10)
        {
            printf ("SWE 423\t\tAdvance Database Management System With Lab\t\t\t4\n");
            printf ("SWE 425\t\tTelecommunication Engineering With Lab\t\t\t4\n");
            printf ("SWE 426\t\tDistrubutive Computing and Network Security With Lab\t\t\t4\n");
            printf ("SWE 332\t\tSoftware Engineering Project II (Web Programming)\t\t\t3\n");
        }
        else if (x == 11)
        {
            printf ("SWE 411\t\tComputer Networking With Lab\t\t\t4\n");
            printf ("SWE 439\t\tProject / Thesis\t\t\t3\n");
        }
    }
    else
    {
        printf ("Wrong option. Choice a correct one among 1 to 11.\n");
    }

    int o;
    printf("\nTo continue press '1' to exit press'0'.");
    scanf("%d", &o);
    switch(o)
    {
    case 1:
        choice();
        break;
    case 0:
        exit(0);
        break;
    default:
        main();
    }
}


