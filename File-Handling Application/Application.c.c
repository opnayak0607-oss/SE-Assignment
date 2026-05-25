#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//FILE DEFINE
#define BOOK_FILE "book.dat"
#define MEMB_FILE "member.dat"
#define ISSUE_FILE "issue.dat"

//FINE DECLARATION
float FINE_RATE=5;

//STRUCT DEFINE
typedef struct 
{
    int  bookId;
    char title[50];
    char author[30];
    char publisher[30];
    float price;
    int  quantity;      
    int  available;     
    char category[20];
}book;

typedef struct
{
    int  memberId;
    char name[30];
    char mobile[11];
    char email[40];
    char address[50];
} member;

typedef struct
{
    int  issueId;
    int  bookId;
    int  memberId;
    char issueDate[11]; 
    char dueDate[11];   
    int  returned;      
    float fine;         
} issue;
//FUNCTION PROTOTYPE
void printline();

//Validation
int isValidMobile(char []);
int isvalidemail(char []);

// Login
int login();

// Book module
void bookMenu();
void addBook();
void displayBooks();
void DisplayBookRecod(book b);
void printBookHeader();
void searchBookMenu();
void searchBookById();
void searchBookByTitle();
void searchBookByAuthor();
void searchBookByCategory();
void searchBookByPriceRange();
void deleteBookMenu();
void deleteBookById();
void deleteBookByTitle();
void deleteBookByAuthor();
void deleteBookByCategory();
void deleteBookByPriceRange();
void updateBookById();
void sortBooks();
int  countBooks();
int  isBookIdExists(int id);

// Member module
void membMenu();
void printMembHeader();
void addMember();
void displayMembers();
void DisplayMembRecod(member m);
void searchMembMenu();
void searchMemberById();
void searchMemberByName();
void searchMemberByMobile();
void searchMemberByEmail();
void deleteMembMenu();
void deleteMembById();
void deleteMembByName();
void deleteMembByMobile();
void deleteMembByEmail();
void updateMembById();
void sortMemb();
int countMemb();
int isMemberIdExists(int id);

// Issue module
void issueMenu();
void issueBook();
void returnBook();
void listIssuedBooks();
int isIssueIdExists(int id);

//Padding Concept
void printSpaces(int);
void printInt(int,int);
void printChar(char [],int );

int main(void)
{
    int l=login();
   if(l==0)
    {
        printf("\nLogin failed. Exiting...\n");
        return 0;
    }
    int choice = 0;
    if(l==1)
    {
        do
        {
            printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
            printf("\t\t\t\t\t\t|           LIBRARY MANAGEMENT SYSTEM          |\n");
            printf("\t\t\t\t\t\t+==============================================+\n");
            printf("\t\t\t\t\t\t|  1. Book Management                          |\n");
            printf("\t\t\t\t\t\t|  2. Member Management                        |\n");
            printf("\t\t\t\t\t\t|  3. Issue / Return                           |\n");
            printf("\t\t\t\t\t\t|  4. Exit                                     |\n");
            printf("\t\t\t\t\t\t+----------------------------------------------+\n");
            printf("Enter your choice = ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: bookMenu();   break;
                case 2: membMenu(); break;
                case 3: issueMenu();  break;
                case 4: printf("Exiting...\n"); break;
                default: printf("Invalid choice\n");
            }
            
        }while(choice != 4);
    }
    else if(l==2)
    {
        do
        {
            printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
            printf("\t\t\t\t\t\t|           LIBRARY MANAGEMENT SYSTEM          |\n");
            printf("\t\t\t\t\t\t+==============================================+\n");
            printf("\t\t\t\t\t\t|  1. Book List                                |\n");
            printf("\t\t\t\t\t\t|  2. Member Management                        |\n");
            printf("\t\t\t\t\t\t|  3. Issue / Return List                      |\n");
            printf("\t\t\t\t\t\t|  4. Exit                                     |\n");
            printf("\t\t\t\t\t\t+----------------------------------------------+\n");
            printf("Enter your choice = ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: displayBooks();break;
                case 2: membMenu(); break;
                case 3: listIssuedBooks();  break;
                case 4: printf("Exiting...\n"); break;
                default: printf("Invalid choice\n");
            }
            
        }while(choice != 4);
    }
    

    return 0;
}
/* ==================== LOGIN SYSTEM ==================== */
int login()
{
    char user[20], pass[20];
    int count=3;
    while(count > 0)
    {
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|                    LOGIN                     |\n");
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t  Username: ");
        scanf("%s", user);
        printf("\t\t\t\t\t\t  Password: ");
        scanf("%s", pass);
        if(strcmp(user,"admin")==0 && strcmp(pass,"1234")==0)
        {
            printf("\n\t\t\t\t\t\tLogin successful.\n");
            printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
            return 1;
        }
        else if(strcmp(user,"member")==0 && strcmp(pass,"1234")==0)
        {
            printf("\n\t\t\t\t\t\tLogin successful.\n");
            printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
            return 2;
        }
        else
        {
            count--;
            printf("\nInvalid credentials. Attempts left: %d\n", count);
            printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        }
    }
    
    return 0;
}
//Validation
int isValidMobile(char mob[])
{
    int i = 0;

    while(mob[i] != '\0') i++;
    if(i != 10) return 0;

    for(i = 0; mob[i] != '\0'; i++)
    {
        if(mob[i] < '0' || mob[i] > '9')
            return 0;
    }
    return 1;
}
int isvalidemail(char email[])
{
    int i, at = -1, dot = -1;

    for(i = 0; email[i] != '\0'; i++)
    {
        if(email[i] == '@') at = i;
        if(email[i] == '.') dot = i;
    }

    if(at > 0 && dot > at+1)
        return 1;

    return 0;
}
// Common helper
void printline()
{
    printf("\n");
    for(int i=0;i<150;i++)
    {
        printf("=");
    }
    printf("\n");
    return;
}
//Padding Concept
void printSpaces(int count)
{
    for(int i=0;i<count;i++)
    {
        printf(" ");
    }
    return;
}
void printInt(int num,int width)
{
    int temp=num,len=0;
    temp=num;
    if(temp==0)
    {
        len=1;
    }
    else
    {
        if(temp<0)
        {
            len++; 
            temp=-1*temp;
        }
        while(temp>0)
        {
            len++;
            temp/=10;
        }
    }
    printf("%d",num);
    if(len<width)
    {
        printSpaces(width-len);
    }
    return;
}
void printChar(char str[],int width)
{
    int l=0;
    while(str[l]!='\0')
    {
        l++;
    }
    if(width<=l)
    {
        for(int i=0;i<width;i++)
        {
            printf("%c",str[i]);
        }
    }
    else
    {
        printf("%s",str);
        printSpaces(width-l);
    }
    return;
}
// Book module
void bookMenu()
{   
    int choice=0;
    do{
        //printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|               BOOK MANAGEMENT                |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. Add Book                                 |\n");
        printf("\t\t\t\t\t\t|  2. Display Books                            |\n");
        printf("\t\t\t\t\t\t|  3. Search Book                              |\n");
        printf("\t\t\t\t\t\t|  4. Update Book                              |\n");
        printf("\t\t\t\t\t\t|  5. Delete Book                              |\n");
        printf("\t\t\t\t\t\t|  6. Sort Books                               |\n");
        printf("\t\t\t\t\t\t|  7. Count Books                              |\n");
        printf("\t\t\t\t\t\t|  8. Exit                                     |\n");
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        //printline();
        printf("Enter your choice = ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addBook();break;
            case 2: displayBooks();break;
            case 3: searchBookMenu();break;
            case 4: updateBookById();break;
            case 5: deleteBookMenu();break;
            case 6: sortBooks();break;
            case 7: printf("\nTotal Books = %d\n",countBooks());break;
            case 8: printf("\nexiting....");break;
            default: printf("INVALID CHOICE\n");
        }
    }while(choice!=8);
    return;
}
void printBookHeader()
{
    printline();
    printChar("ID",6);
    printf(" | ");
    printChar("Title",20);
    printf(" | ");
    printChar("Author",18);
    printf(" | ");
    printChar("Publisher",18);
    printf(" | ");
    printChar("Qty",6);
    printf(" | ");
    printChar("Avail",8);
    printf(" | ");
    printChar("Category",12);
    printf(" | ");
    printChar("Price",6);
    printline();
    return;
}

int countBooks()
{
    int count=0;
    book b;
    FILE *fp;
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fp))
    {
        count++;
    }
    fclose(fp);
    return count;
}

int  isBookIdExists(int id)
{
    int flag=0;
    book b;
    FILE *fp;
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.bookId==id)
        {
            flag=1;
            break;
        }
    }
    fclose(fp);
    return flag;
}
void addBook()
{
    FILE *fp;
    book b;
    int count=0;
    fp=fopen(BOOK_FILE,"a");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter Book ID = ");
    scanf("%d",&b.bookId);
    if(isBookIdExists(b.bookId))
    {
        printf("\nBook ID already exists. Record not added.\n");
        fclose(fp);
        return;
    }
    printf("Enter Book Title:");
    scanf(" %[^\n]",b.title);
    printf("Enter Book Author :");
    scanf(" %[^\n]",b.author);
    printf("Enter Book Publisher :");
    scanf(" %[^\n]",b.publisher);
    printf("Enter Book Price :");
    scanf("%f",&b.price);
    printf("Enter Book Quantity (total copies of book) :");
    scanf("%d",&b.quantity);
    printf("Enter Book Category:");
    scanf(" %[^\n]",b.category);
    b.available = b.quantity;//IMP

    fwrite(&b,sizeof(b),1,fp);
    fclose(fp);
    return;
}
void DisplayBookRecod(book b)
{
    
    printInt(b.bookId,6);
    printf(" | ");
    printChar(b.title,20);
    printf(" | ");
    printChar(b.author,18);
    printf(" | ");
    printChar(b.publisher,18);
    printf(" | ");
    printInt(b.quantity,6);
    printf(" | ");
    printInt(b.available,8);
    printf(" | ");
    printChar(b.category,12);
    printf(" | ");
    printf("%.2f\n",b.price);
    return;
}
void displayBooks()
{
    book b;
    FILE *fp;
    int count=0;
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printBookHeader();
    while (fread(&b,sizeof(b),1,fp))
    {
        count++;
        DisplayBookRecod(b);
    }
    printline();
    if(count==0)
    printf("\nNo records found.\n");
    else
    printf("\n%d records displayed\n",count);
    fclose(fp);
    return;
}
void searchBookMenu()
{
    int choice=0;
    do{

        //printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|               SEARCH BOOK MENU               |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. Search by Book ID                        |\n");
        printf("\t\t\t\t\t\t|  2. Search by Title                          |\n");
        printf("\t\t\t\t\t\t|  3. Search by Author                         |\n");
        printf("\t\t\t\t\t\t|  4. Search by Price Range                    |\n");
        printf("\t\t\t\t\t\t|  5. Search by category                       |\n");
        printf("\t\t\t\t\t\t|  6. Exit search book menu                    |\n");
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        //printline();
        printf("\nEnter your choice = ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: searchBookById();break;
            case 2: searchBookByTitle();break;
            case 3: searchBookByAuthor();break;
            case 4: searchBookByPriceRange();break;
            case 5: searchBookByCategory();break;
            case 6: printf("\nexiting....");break;
            default:printf("\nINVALID CHOICE");
        }
    }
    while(choice!=6);
    return;
}

void searchBookById()
{
    book b;
    int id,count=0;
    FILE *fp;
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the id for search:");
    scanf("%d",&id);
    printBookHeader();
    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.bookId==id)
        {
            count++;
            DisplayBookRecod(b);
        }
    }
    if(count==0)
    {
        printf("\nno record found");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void searchBookByTitle()
{
    FILE *fp;
    book b;
    int count=0;
    char title[30];
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the title for search:");
    scanf(" %[^\n]",title);
    printBookHeader();
    while(fread(&b,sizeof(b),1,fp))
    {
        if(strcasecmp(b.title,title)==0)
        {
            count++;
            DisplayBookRecod(b);
        }
    }
    if(count==0)
    {
        printf("\nno record found.");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void searchBookByAuthor()
{
    FILE *fp;
    book b;
    char author[30];
    int count=0;
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the author for search:");
    scanf(" %[^\n]",author);
    printBookHeader();
    while(fread(&b,sizeof(b),1,fp))
    {
        if(strcasecmp(b.author,author)==0)
        {
            count++;
            DisplayBookRecod(b);
        }
    }
    if(count==0)
    {
        printf("\nno record found.");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void searchBookByPriceRange()
{
    FILE *fp;
    book b;
    int count=0;
    float up,lp;
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the Highest price for search:");
    scanf("%f",&up);
    printf("\nEnter the Lowest price for search:");
    scanf("%f",&lp);
    printBookHeader();
    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.price>=lp && b.price<=up)
        {
            count++;
            DisplayBookRecod(b);
        }
    }
    if(count==0)
    {
        printf("\nno record found.");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void searchBookByCategory()
{
    FILE *fp;
    book b;
    char category[30];
    int count=0;
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the category for search:");
    scanf(" %[^\n]",category);
    printBookHeader();
    while(fread(&b,sizeof(b),1,fp))
    {
        if(strcasecmp(b.category,category)==0)
        {
            count++;
            DisplayBookRecod(b);
        }
    }
    if(count==0)
    {
        printf("\nno record found.");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void deleteBookMenu()
{
    int choice=0;
    book inb ;
    do{

        //printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|               DELETE BOOK MENU               |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. delete by Book ID                        |\n");
        printf("\t\t\t\t\t\t|  2. delete by Title                          |\n");
        printf("\t\t\t\t\t\t|  3. delete by Author                         |\n");
        printf("\t\t\t\t\t\t|  4. delete by Price Range                    |\n");
        printf("\t\t\t\t\t\t|  5. delete by category                       |\n");
        printf("\t\t\t\t\t\t|  6. Exit delete book menu                    |\n");
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        //printline();
        printf("Enter your choice = ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:deleteBookById();break;
            case 2:deleteBookByTitle();break;
            case 3:deleteBookByAuthor();break;
            case 4:deleteBookByPriceRange();break;
            case 5:deleteBookByCategory();break;
            case 6:printf("\nexiting....");break;
            default:printf("\nINVALID CHOICE");
        }
    }
    while(choice!=6);
    return;
}
void deleteBookById()
{
    FILE *fp1,*fp2;
    book b;
    int id;
    fp1=fopen(BOOK_FILE,"r");
    fp2=fopen("temp_book.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the Id of book to delete:");
    scanf("%d",&id);
    while(fread(&b,sizeof(b),1,fp1))
    {
        if(b.bookId==id)
        {
            continue;
        }
        fwrite(&b,sizeof(b),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(BOOK_FILE,"w");
    fp2=fopen("temp_book.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fp2))
    {
        fwrite(&b,sizeof(b),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayBooks();
    return;
}
void deleteBookByTitle()
{
    FILE *fp1,*fp2;
    book b;
    char title[30];
    fp1=fopen(BOOK_FILE,"r");
    fp2=fopen("temp_title.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the Title to delete:");
    scanf(" %[^\n]",title);
    while(fread(&b,sizeof(b),1,fp1))
    {
        if(strcasecmp(b.title,title)==0)
        {
            continue;
        }
        fwrite(&b,sizeof(b),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(BOOK_FILE,"w");
    fp2=fopen("temp_title.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fp2))
    {
        fwrite(&b,sizeof(b),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayBooks();
    return;
}
void deleteBookByAuthor()
{
    FILE *fp1,*fp2;
    book b;
    char author[30];
    fp1=fopen(BOOK_FILE,"r");
    fp2=fopen("temp_author.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the author to delete:");
    scanf(" %[^\n]",author);
    while(fread(&b,sizeof(b),1,fp1))
    {
        if(strcasecmp(b.author,author)==0)
        {
            continue;
        }
        fwrite(&b,sizeof(b),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(BOOK_FILE,"w");
    fp2=fopen("temp_author.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fp2))
    {
        fwrite(&b,sizeof(b),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayBooks();
    return;
}
void deleteBookByCategory()
{
    FILE *fp1,*fp2;
    book b;
    char category[30];
    fp1=fopen(BOOK_FILE,"r");
    fp2=fopen("temp_category.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the category to delete:");
    scanf(" %[^\n]",category);
    while(fread(&b,sizeof(b),1,fp1))
    {
        if(strcasecmp(b.category,category)==0)
        {
            continue;
        }
        fwrite(&b,sizeof(b),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(BOOK_FILE,"w");
    fp2=fopen("temp_category.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fp2))
    {
        fwrite(&b,sizeof(b),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayBooks();
    return;
}
void deleteBookByPriceRange()
{
    FILE *fp1,*fp2;
    book b;
    float up,lp;
    fp1=fopen(BOOK_FILE,"r");
    fp2=fopen("temp_price.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the Highest price for search:");
    scanf("%f",&up);
    printf("\nEnter the Lowest price for search:");
    scanf("%f",&lp);
    while(fread(&b,sizeof(b),1,fp1))
    {
        if(b.price>=lp && b.price<=up)
        {
            continue;
        }
        fwrite(&b,sizeof(b),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(BOOK_FILE,"w");
    fp2=fopen("temp_price.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fp2))
    {
        fwrite(&b,sizeof(b),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayBooks();
    return;
}
void updateBookById()
{
    FILE *fp1,*fp2;
    book b;
    int id,choice;
    
    do
    {       //printline();
            printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
            printf("\t\t\t\t\t\t|               UPDATE BOOK MENU               |\n");
            //printline();
            printf("\t\t\t\t\t\t+==============================================+\n");
            printf("\t\t\t\t\t\t|  1. Upadate id                               |\n");
            printf("\t\t\t\t\t\t|  2. update title                             |\n");
            printf("\t\t\t\t\t\t|  3. update author                            |\n");
            printf("\t\t\t\t\t\t|  4. Update publisher                         |\n");
            printf("\t\t\t\t\t\t|  5. update price                             |\n");
            printf("\t\t\t\t\t\t|  6. update qty                               |\n");
            printf("\t\t\t\t\t\t|  7. update category                          |\n");
            printf("\t\t\t\t\t\t|  8. update whole record                      |\n");
            printf("\t\t\t\t\t\t|  9. exiting....                              |\n");
            printf("\t\t\t\t\t\t+----------------------------------------------+\n");
            //printline();
            printf("Enter your choice = ");
            scanf("%d",&choice);

            if(choice == 9)
                break;
            
                printf("\nEnter the Id of book to update:-");
                scanf("%d",&id);
        
                fp1=fopen(BOOK_FILE,"r");
                fp2=fopen("temp_book.dat","w");
                if(fp1==NULL || fp2==NULL)
                {
                    printf("\nError in opening file.");
                    exit(-1);
                }
                
                int iFound = 0;
                while(fread(&b,sizeof(b),1,fp1))
                {
                    if(b.bookId==id)
                    {
                        iFound = 1;
                        switch(choice)
                        {
                            case 1: printf("\nEnter the NEW Id of book to update:");
                                    scanf("%d",&b.bookId);break;
                            case 2: printf("\nEnter NEW Book Title to update:");
                                    scanf(" %[^\n]",b.title);break;
                            case 3: printf("Enter NEW Book Author to update :");
                                    scanf(" %[^\n]",b.author);break;
                            case 4: printf("Enter NEW Book Publisher to update :");
                                    scanf(" %[^\n]",b.publisher);break;
                            case 5: printf("Enter NEW Book Price to update :");
                                    scanf("%f",&b.price);break;
                            case 6: printf("Enter NEW Book Quantity (total copies of book) to update :");
                                    scanf("%d",&b.quantity);
                                    if(b.available > b.quantity)
                                    b.available = b.quantity;break;
                            case 7: printf("Enter NEW Book Category to update:");
                                    scanf(" %[^\n]",b.category);
                                    break;
                            case 8: printf("\nEnter the NEW Id of book to update:");
                                    scanf("%d",&b.bookId);
                                    printf("\nEnter NEW Book Title to update:");
                                    scanf(" %[^\n]",b.title);
                                    printf("Enter NEW Book Author to update :");
                                    scanf(" %[^\n]",b.author);
                                    printf("Enter NEW Book Publisher to update :");
                                    scanf(" %[^\n]",b.publisher);
                                    printf("Enter NEW Book Price to update :");
                                    scanf("%f",&b.price);
                                    printf("Enter NEW Book Quantity (total copies of book) to update :");
                                    scanf("%d",&b.quantity);
                                    b.available = b.quantity;
                                    printf("Enter NEW Book Category to update:");
                                    scanf(" %[^\n]",b.category);
                                    break;
                            case 9:printf("\nexiting....");break;
                            default:printf("\nINVALID CHOICE\n");
                        }
                        printf("Record updated successfully\n");
                    }
                    fwrite(&b,sizeof(b),1,fp2);
                }

                if(iFound == 0)
                {
                    printf("Book id not found.");
                    continue;
                }
                fclose(fp1);
                fclose(fp2); 
                fp1=fopen(BOOK_FILE,"w");
                fp2=fopen("temp_book.dat","r");
                if(fp1==NULL || fp2==NULL)
                {
                    printf("\nError in opening file.");
                    exit(-1);
                }
                while(fread(&b,sizeof(b),1,fp2))
                {
                    fwrite(&b,sizeof(b),1,fp1);
                }
                fclose(fp1);
                fclose(fp2);  
            

    } while (choice!=9);
    displayBooks();
    return;
}
void sortBooks()
{
    int no=countBooks();
    book b[no],stemp;
    FILE *fp;
    int count=0,choice=0;
    if(no==0)
    {
        printf("No books to sort\n");
        return;
    }
    fp=fopen(BOOK_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    for(int i=0;i<no;i++)
    {
        fread(&b[i],sizeof(stemp),1,fp);
    }
    do{
        //printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|                SORT BOOK MENU                |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. sort by id.                              |\n");
        printf("\t\t\t\t\t\t|  2. sort by title.                           |\n");
        printf("\t\t\t\t\t\t|  3. sort by author.                          |\n");
        printf("\t\t\t\t\t\t|  4. sort by publisher.                       |\n");
        printf("\t\t\t\t\t\t|  5. sort by price.                           |\n");
        printf("\t\t\t\t\t\t|  6. sort by quantity.                        |\n");
        printf("\t\t\t\t\t\t|  7. sort by category.                        |\n");
        printf("\t\t\t\t\t\t|  8. exit the sort menu.                      |\n");
        //printline();
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("Enter your choice = ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            for(int i=0;i<no;i++)
            {
                for(int j=i+1;j<no;j++)
                {
                    if(b[i].bookId>b[j].bookId)
                    {
                        stemp=b[i];
                        b[i]=b[j];
                        b[j]=stemp;
                    }
                }
            }
            printBookHeader();

            for(int i=0;i<no;i++)
            {
                DisplayBookRecod(b[i]);
            }
            break;
            case 2:
            for(int i=0;i<no;i++)
            {
                for(int j=i+1;j<no;j++)
                {
                    if(strcasecmp(b[i].title,b[j].title)>0)
                    {
                        stemp=b[i];
                        b[i]=b[j];
                        b[j]=stemp;
                    }
                }
            }
             printBookHeader();

            for(int i=0;i<no;i++)
            {
                DisplayBookRecod(b[i]);
            }
            break;
            case 3:
            for(int i=0;i<no;i++)
            {
                for(int j=i+1;j<no;j++)
                {
                    if(strcasecmp(b[i].author,b[j].author)>0)
                    {
                        stemp=b[i];
                        b[i]=b[j];
                        b[j]=stemp;
                    }
                }
            }
             printBookHeader();

            for(int i=0;i<no;i++)
            {
                DisplayBookRecod(b[i]);
            }
            break;
            case 4:
            for(int i=0;i<no;i++)
            {
                for(int j=i+1;j<no;j++)
                {
                    if(strcasecmp(b[i].publisher,b[j].publisher)>0)
                    {
                        stemp=b[i];
                        b[i]=b[j];
                        b[j]=stemp;
                    }
                }
            }
             printBookHeader();

            for(int i=0;i<no;i++)
            {
                DisplayBookRecod(b[i]);
            }
            break;
            case 5:
            for(int i=0;i<no;i++)
            {
                for(int j=i+1;j<no;j++)
                {
                    if(b[i].price>b[j].price)
                    {
                        stemp=b[i];
                        b[i]=b[j];
                        b[j]=stemp;
                    }
                }
            }
             printBookHeader();

            for(int i=0;i<no;i++)
            {
                DisplayBookRecod(b[i]);
            }
            break;
            case 6:
            for(int i=0;i<no;i++)
            {
                for(int j=i+1;j<no;j++)
                {
                    if(b[i].quantity>b[j].quantity)
                    {
                        stemp=b[i];
                        b[i]=b[j];
                        b[j]=stemp;
                    }
                }
            }
             printBookHeader();

            for(int i=0;i<no;i++)
            {
                DisplayBookRecod(b[i]);
            }
            break;
            case 7:
            for(int i=0;i<no;i++)
            {
                for(int j=i+1;j<no;j++)
                {
                    if(strcasecmp(b[i].category,b[j].category)>0)
                    {
                        stemp=b[i];
                        b[i]=b[j];
                        b[j]=stemp;
                    }
                }
            }
             printBookHeader();

            for(int i=0;i<no;i++)
            {
                DisplayBookRecod(b[i]);
            }
            break;
            case 8:printf("\nexiting....");break;
            default:printf("\nINVALID INPUT.");
        }
    }while(choice!=8);
    
    return;
}

//----------------------MEMBER MODULE---------------------------
void membMenu()
{
    int choice=0;
    do{
        // printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|               MEMBER MANAGEMENT              |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. Add Member                               |\n");
        printf("\t\t\t\t\t\t|  2. Display Members                          |\n");
        printf("\t\t\t\t\t\t|  3. Search Member                            |\n");
        printf("\t\t\t\t\t\t|  4. Update Member                            |\n");
        printf("\t\t\t\t\t\t|  5. Delete Member                            |\n");
        printf("\t\t\t\t\t\t|  6. Sort Member                              |\n");
        printf("\t\t\t\t\t\t|  7. Count Members                            |\n");
        printf("\t\t\t\t\t\t|  8. Exit                                     |\n");
        //printline();
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");

        printf("Enter your choice = ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addMember();break;
            case 2: displayMembers();break;
            case 3: searchMembMenu();break;
            case 4: updateMembById();break;
            case 5: deleteMembMenu();break;
            case 6: sortMemb();break;
            case 7: printf("\nTotal Members = %d\n",countMemb());break;
            case 8: printf("\nexiting....");break;
            default: printf("INVALID CHOICE\n");
        }
    }while(choice!=8);
    return;
}
int countMemb()
{
    int count=0;
    member m;
    FILE *fp;
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&m,sizeof(m),1,fp))
    {
        count++;
    }
    fclose(fp);
    return count;
}
int isMemberIdExists(int id)
{
    int flag=0;
    member m;
    FILE *fp;
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&m,sizeof(m),1,fp))
    {
        if(m.memberId==id)
        {
            flag=1;
            break;
        }
    }
    fclose(fp);
    return flag;
}
void addMember()
{
    FILE *fp;
    fp=fopen(MEMB_FILE,"a");
    member m;
    if(fp == NULL)
    {
        printf("Error in opening file\n");
        exit(-1);
    }
    printf("\nEnter Member ID : ");
    scanf("%d",&m.memberId);
    if(isMemberIdExists(m.memberId))
    {
        printf("\nMember ID already exists. Record not added.\n");
        fclose(fp);
        return;
    }
    printf("Enter Name : ");
    scanf(" %[^\n]", m.name);
    do {
            printf("Enter Mobile (10 digits): ");
            scanf("%s", m.mobile);

            if(!isValidMobile(m.mobile))
                printf("Invalid mobile number! Try again.\n");

        } while(!isValidMobile(m.mobile));
    do {
            printf("Enter Email: ");
            scanf("%s", m.email);

            if(!isvalidemail(m.email))
                printf("Invalid email! Try again.\n");

        } while(!isvalidemail(m.email));
    printf("Enter Address : ");
    scanf(" %[^\n]", m.address);

    fwrite(&m,sizeof(m),1,fp);
    fclose(fp);
    return;
}
void DisplayMembRecod(member m)
{
    
    printInt(m.memberId,6);
    printf(" | ");
    printChar(m.name,20);
    printf(" | ");
    printChar(m.address,18);
    printf(" | ");
    printChar(m.email,30);
    printf(" | ");
    printChar(m.mobile,10);
    printf("\n");
    return;
}
void displayMembers()
{
    member m;
    FILE *fp;
    int count=0;
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printMembHeader();
    while(fread(&m,sizeof(m),1,fp))
    {
        count++;
        DisplayMembRecod(m);
    }
    if(count==0)
    printf("\nNo records found.\n");
    else
    printf("\n%d records displayed\n",count);
    fclose(fp);
    return;
}
void printMembHeader()
{
    printline();
    printChar("ID",6);
    printf(" | ");
    printChar("Name",20);
    printf(" | ");
    printChar("Address",18);
    printf(" | ");
    printChar("Email",30);
    printf(" | ");
    printChar("Mobile",10);
    printline();
    return;
}
void searchMembMenu()
{
    int choice=0;
    do{

       // printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|               SEARCH MEMBER MENU             |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. Search by Member ID                      |\n");
        printf("\t\t\t\t\t\t|  2. Search by Name                           |\n");
        printf("\t\t\t\t\t\t|  3. Search by Email                          |\n");
        printf("\t\t\t\t\t\t|  4. Search by Mobile                         |\n");
        printf("\t\t\t\t\t\t|  5. Exit search book menu                    |\n");
        //printline();
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\nEnter your choice = ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: searchMemberById();break;
            case 2: searchMemberByName();break;
            case 3: searchMemberByEmail();break;
            case 4: searchMemberByMobile();break;
            case 5: printf("\nexiting....");break;
            default:printf("\nINVALID CHOICE");
        }
    }
    while(choice!=5);
    return;
}
void searchMemberById()
{
    member m;
    int id,count=0;
    FILE *fp;
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the id for search:");
    scanf("%d",&id);
    printMembHeader();
    while(fread(&m,sizeof(m),1,fp))
    {
        if(m.memberId==id)
        {
            count++;
            DisplayMembRecod(m);
        }
    }
    if(count==0)
    {
        printf("\nno record found");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void searchMemberByName()
{
    member m;
    int count=0;
    char name[30];
    FILE *fp;
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the name for search:");
    scanf(" %[^\n]",name);
    printMembHeader();
    while(fread(&m,sizeof(m),1,fp))
    {
        if(strcasecmp(m.name,name)==0)
        {
            count++;
            DisplayMembRecod(m);
        }
    }
    if(count==0)
    {
        printf("\nno record found");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void searchMemberByMobile()
{
    member m;
    int count=0;
    char mobile[30];
    FILE *fp;
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the mobile for search:");
    scanf(" %[^\n]",mobile);
    printMembHeader();
    while(fread(&m,sizeof(m),1,fp))
    {
        if(strcasecmp(m.mobile,mobile)==0)
        {
            count++;
            DisplayMembRecod(m);
        }
    }
    if(count==0)
    {
        printf("\nno record found");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void searchMemberByEmail()
{
    member m;
    int count=0;
    char email[30];
    FILE *fp;
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the email for search:");
    scanf(" %[^\n]",email);
    printMembHeader();
    while(fread(&m,sizeof(m),1,fp))
    {
        if(strcasecmp(m.email,email)==0)
        {
            count++;
            DisplayMembRecod(m);
        }
    }
    if(count==0)
    {
        printf("\nno record found");
    }
    else
        printf("\n%d record(s) found.\n", count);
    fclose(fp);
    return;
}
void deleteMembMenu()
{
    int choice=0;
    do{

        //printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|               DELETE MEMBER MENU             |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. Delete by Member ID                      |\n");
        printf("\t\t\t\t\t\t|  2. Delete by Name                           |\n");
        printf("\t\t\t\t\t\t|  3. Delete by Email                          |\n");
        printf("\t\t\t\t\t\t|  4. Delete by Mobile                         |\n");
        printf("\t\t\t\t\t\t|  5. Exit Delete book menu                    |\n");
        //printline();
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\nEnter your choice = ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: deleteMembById();break;
            case 2: deleteMembByName();break;
            case 3: deleteMembByEmail();break;
            case 4: deleteMembByMobile();break;
            case 5: printf("\nexiting....");break;
            default:printf("\nINVALID CHOICE");
        }
    }
    while(choice!=5);
    return;
}
void deleteMembById()
{
    FILE *fp1,*fp2;
    member m;
    int id;
    fp1=fopen(MEMB_FILE,"r");
    fp2=fopen("temp_memb.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the Id of member to delete:");
    scanf("%d",&id);
    while(fread(&m,sizeof(m),1,fp1))
    {
        if(m.memberId==id)
        {
            continue;
        }
        fwrite(&m,sizeof(m),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(MEMB_FILE,"w");
    fp2=fopen("temp_memb.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&m,sizeof(m),1,fp2))
    {
        fwrite(&m,sizeof(m),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayMembers();
    return;
}
void deleteMembByName()
{
    FILE *fp1,*fp2;
    member m;
    char name[30];
    fp1=fopen(MEMB_FILE,"r");
    fp2=fopen("temp_memb.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the name to delete:");
    scanf(" %[^\n]",name);
    while(fread(&m,sizeof(m),1,fp1))
    {
        if(strcasecmp(m.name,name)==0)
        {
            continue;
        }
        fwrite(&m,sizeof(m),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(MEMB_FILE,"w");
    fp2=fopen("temp_memb.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&m,sizeof(m),1,fp2))
    {
        fwrite(&m,sizeof(m),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayMembers();
    return;
}
void deleteMembByMobile()
{
    FILE *fp1,*fp2;
    member m;
    char mobile[10];
    fp1=fopen(MEMB_FILE,"r");
    fp2=fopen("temp_memb.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the mobile no. to delete:");
    scanf(" %[^\n]",mobile);
    while(fread(&m,sizeof(m),1,fp1))
    {
        if(strcasecmp(m.mobile,mobile)==0)
        {
            continue;
        }
        fwrite(&m,sizeof(m),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(MEMB_FILE,"w");
    fp2=fopen("temp_memb.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&m,sizeof(m),1,fp2))
    {
        fwrite(&m,sizeof(m),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayMembers();
    return;
}
void deleteMembByEmail()
{
    FILE *fp1,*fp2;
    member m;
    char email[30];
    fp1=fopen(MEMB_FILE,"r");
    fp2=fopen("temp_memb.dat","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printf("\nEnter the Email to delete:");
    scanf(" %[^\n]",email);
    while(fread(&m,sizeof(m),1,fp1))
    {
        if(strcasecmp(m.email,email)==0)
        {
            continue;
        }
        fwrite(&m,sizeof(m),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen(MEMB_FILE,"w");
    fp2=fopen("temp_memb.dat","r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&m,sizeof(m),1,fp2))
    {
        fwrite(&m,sizeof(m),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    displayMembers();
    return;
}
void updateMembById()
{
    FILE *fp1,*fp2;
    member m;
    int id,choice;
    do
    {
        //printline();
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|               UPDATE BOOK MENU               |\n");
        //printline();
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. Upadate ID                               |\n");
        printf("\t\t\t\t\t\t|  2. update Name                              |\n");
        printf("\t\t\t\t\t\t|  3. update Email                             |\n");
        printf("\t\t\t\t\t\t|  4. Update Mobile                            |\n");
        printf("\t\t\t\t\t\t|  5. update whole record                      |\n");
        printf("\t\t\t\t\t\t|  6. exiting....                              |\n");
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        //printline();
        printf("Enter your choice = ");
        scanf("%d",&choice);
        
        if(choice== 6)
        {
            break;
        }
        printf("\nEnter the Id of member to update:-");
        scanf("%d",&id);
        fp1=fopen(MEMB_FILE,"r");
        fp2=fopen("temp_memb.dat","w");
        if(fp1==NULL || fp2==NULL)
        {
            printf("\nError in opening file.");
            exit(-1);
        }
        int iFound = 0;
        while(fread(&m,sizeof(m),1,fp1))
        {
            if(m.memberId==id)
            {
                iFound = 1;
                switch(choice)
                {
                    case 1: printf("\nEnter the NEW Id of member to update:");
                            scanf("%d",&m.memberId);break;
                    case 2: printf("\nEnter NEW Member Name to update:");
                            scanf(" %[^\n]",m.name);break;
                    case 3: printf("\nEnter NEW Member Email to update:");
                            scanf(" %[^\n]",m.email);break;
                    case 4: printf("\nEnter NEW Member Mobile to update:");
                            scanf(" %[^\n]",m.mobile);break;
                    case 5: printf("\nEnter the NEW Id of member to update:");
                            scanf("%d",&m.memberId);
                            printf("\nEnter NEW Member Name to update:");
                            scanf(" %[^\n]",m.name);
                            printf("\nEnter NEW Member Email to update:");
                            scanf(" %[^\n]",m.email);
                            printf("\nEnter NEW Member Mobile to update:");
                            scanf(" %[^\n]",m.mobile);
                            break;
                    case 9: printf("\nexiting....");break;

                }
                printf("Record updated successfully\n");
            }
            fwrite(&m,sizeof(m),1,fp2);
        }
        if(iFound == 0)
        {
            printf("Member id not found.");
            continue;
        }
        fclose(fp1);
        fclose(fp2);
        fp1=fopen(MEMB_FILE,"w");
        fp2=fopen("temp_memb.dat","r");
        if(fp1==NULL || fp2==NULL)
        {
            printf("\nError in opening file.");
            exit(-1);
        }
        while(fread(&m,sizeof(m),1,fp2))
        {
            fwrite(&m,sizeof(m),1,fp1);
        }
        fclose(fp1);
        fclose(fp2); 
    }while(choice!=6);
    displayMembers();
    return;
}
void sortMemb()
{
    int no=countMemb();
    member m[no],stemp;
    FILE *fp;
    int count=0,choice=0;
    if(no==0)
    {
        printf("No member to sort\n");
        return;
    }
    fp=fopen(MEMB_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    for(int i=0;i<no;i++)
    {
        fread(&m[i],sizeof(stemp),1,fp);
    }
    do{
            //printline();
            printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
            printf("\t\t\t\t\t\t|               SORT MEMBER MENU               |\n");
            //printline();
            printf("\t\t\t\t\t\t+==============================================+\n");
            printf("\t\t\t\t\t\t|  1. sort by id.                              |\n");
            printf("\t\t\t\t\t\t|  2. sort by name.                            |\n");
            printf("\t\t\t\t\t\t|  3. sort by email.                           |\n");
            printf("\t\t\t\t\t\t|  4. exit the sort menu.                      |\n");
            //printline();
            printf("\t\t\t\t\t\t+----------------------------------------------+\n");
            printf("Enter your choice = ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                for(int i=0;i<no;i++)
                {
                    for(int j=i+1;j<no;j++)
                    {
                        if(m[i].memberId>m[j].memberId)
                        {
                            stemp=m[i];
                            m[i]=m[j];
                            m[j]=stemp;
                        }
                    }
                }
                printMembHeader();
                for(int i=0;i<no;i++)
                {
                    DisplayMembRecod(m[i]);
                }
                break;
                case 2:
                for(int i=0;i<no;i++)
                    {
                        for(int j=i+1;j<no;j++)
                        {
                            if(strcasecmp(m[i].name,m[j].name)>0)
                            {
                                stemp=m[i];
                                m[i]=m[j];
                                m[j]=stemp;
                            }
                        }
                    }
                    printMembHeader();
                    for(int i=0;i<no;i++)
                    {
                        DisplayMembRecod(m[i]);
                    }
                    break;
                case 3:
                for(int i=0;i<no;i++)
                    {
                        for(int j=i+1;j<no;j++)
                        {
                            if(strcasecmp(m[i].email,m[j].email)>0)
                            {
                                stemp=m[i];
                                m[i]=m[j];
                                m[j]=stemp;
                            }
                        }
                    }
                    printMembHeader();
                    for(int i=0;i<no;i++)
                    {
                        DisplayMembRecod(m[i]);
                    }
                    break;
                case 4:printf("\nexiting....");break;
                default:printf("\nINVALID INPUT.");
            }
    }while(choice !=4);
    return;
}

/* ==================== ISSUE / RETURN ==================== */
void issueMenu()
{
    int ch=0, cont=0;
    do
    {
        printf("\n\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("\t\t\t\t\t\t|                ISSUE / RETURN                |\n");
        printf("\t\t\t\t\t\t+==============================================+\n");
        printf("\t\t\t\t\t\t|  1. Issue Book                               |\n");
        printf("\t\t\t\t\t\t|  2. Return Book                              |\n");
        printf("\t\t\t\t\t\t|  3. List Issued Books                        |\n");
        printf("\t\t\t\t\t\t|  4. Back to Main Menu                        |\n");
        printf("\t\t\t\t\t\t+----------------------------------------------+\n");
        printf("Enter your choice = ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: issueBook();break;
            case 2: returnBook();break;
            case 3: listIssuedBooks();break;
            case 4: printf("\nexiting....");break;
            default: printf("Invalid choice\n");
        }
    }while(ch!= 4);
    return ;
}

int isIssueIdExists(int id)
{
    int flag=0;
    issue i;
    FILE *fp;
    fp=fopen(ISSUE_FILE,"r");
    if(fp==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&i,sizeof(i),1,fp))
    {
        if(i.issueId==id)
        {
            flag=1;
        }
    }
    fclose(fp);
    return flag;
}
void issueBook()
{
    FILE *fb,*fi,*temp;
    book b;
    issue i;
    int bid,mid;
    int found=0;
    fb=fopen(BOOK_FILE,"r");
    temp = fopen("temp.dat", "w");
    if(fb==NULL || temp==NULL)
    {
        printf("opening file error\n");
        exit(-1);
    }
    printf("Enter Book ID to issue = ");
    scanf("%d",&bid);
    printf("Enter Member ID = ");
    scanf("%d",&mid);
    if(!isMemberIdExists(mid))
    {
        printf("Invalid Member ID\n");
        fclose(fb);
        fclose(temp);
        return;
    }
    while(fread(&b,sizeof(b),1,fb))
    {
        if(b.bookId==bid)
        {
            found=1;
            if(b.available<=0)
            {
                printf("\nNo copies available for this book.\n");
                fclose(fb);
                fclose(temp);
                return;
            }
            
            b.available--;
         }
         fwrite(&b,sizeof(b),1,temp);
    }
    fclose(fb);
    fclose(temp);
    fb=fopen(BOOK_FILE,"w");
    temp = fopen("temp.dat", "r");
    if(fb==NULL || temp==NULL)
    {
        printf("opening file error\n");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,temp))
    {
        fwrite(&b,sizeof(b),1,fb);
    }
    fclose(fb);
    fclose(temp);
    if(!found)
    {
        printf("\nBook not found.\n");
        return;
    }
    fi=fopen(ISSUE_FILE,"a");
    if(fi == NULL)
    {
        printf("Issue file error\n");
        exit(-1);
    }
    do
    {
        printf("Enter Issue ID:");
        scanf("%d",&i.issueId);
        if(isIssueIdExists(i.issueId))
        {
            printf("Issue ID already exists.Enter different ID.\n");
        }
        else
        {
            break;
        }
    } while(1);

    i.bookId=bid;
    i.memberId=mid;
    printf("Enter Issue Date (dd-mm-yyyy) = ");
    scanf("%s", i.issueDate);
    printf("Enter Due Date (dd-mm-yyyy) = ");
    scanf("%s", i.dueDate);
    i.returned = 0;
    i.fine = 0.0;
    fwrite(&i,sizeof(i),1,fi);
    fclose(fi);
    printf("\nBook issued successfully. Issue ID = %d\n", i.issueId);
    return;
}
void returnBook()
{
    FILE *fi,*fb,*tempi,*tempb;
    issue i;
    book b;
    int issueid,found=0,latedays=0;
    int bookIdToReturn = -1;

    printf("Enter Issue ID to return:");
    scanf("%d",&issueid);

    fi=fopen(ISSUE_FILE,"r");
    tempi=fopen("temp_issue.dat","w");
    if(fi==NULL || tempi==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&i,sizeof(i),1,fi))
    {
        if(i.issueId==issueid && i.returned==0)
        {
            found=1;
            bookIdToReturn = i.bookId;
            printf("Enter late days (0 -> if on time) :");
            scanf("%d",&latedays);
            if(latedays<=0)
            {
                latedays=0;
            }
            i.fine=latedays * FINE_RATE;
            i.returned=1;
        }
        fwrite(&i,sizeof(i),1,tempi);
    }
    fclose(fi);
    fclose(tempi);
    
    if(!found)
    {
        printf("\nActive issue record not found for this Issue ID.\n");
        return;
    }
    fi=fopen(ISSUE_FILE,"w");
    tempi=fopen("temp_issue.dat","r");
    if(fi==NULL || tempi==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&i,sizeof(i),1,tempi))
    {
        fwrite(&i,sizeof(i),1,fi);
    }
    fclose(fi);
    fclose(tempi);

    fb=fopen(BOOK_FILE,"r");
    tempb=fopen("temp_book.dat","w");
    if(fb==NULL || tempb==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,fb))
    {
        if(b.bookId == bookIdToReturn)
        {
            b.available++;
            if(b.available > b.quantity)
                b.available = b.quantity;
        }
        fwrite(&b,sizeof(b),1,tempb);
    }
    fclose(fb);
    fclose(tempb);
    fb=fopen(BOOK_FILE,"w");
    tempb=fopen("temp_book.dat","r");
    if(fb==NULL || tempb==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    while(fread(&b,sizeof(b),1,tempb))
    {
        fwrite(&b,sizeof(b),1,fb);
    }
    fclose(fb);
    fclose(tempb);
    printf("\nBook returned successfully.");
    return;
}
void listIssuedBooks()
{
    FILE *fi;
    issue i;
    int count=0;

    fi=fopen(ISSUE_FILE,"r");
    if(fi==NULL)
    {
        printf("\nError in opening file.");
        exit(-1);
    }
    printline();
    printf("IssueID\tBookID\tMemberID\tIssueDate\tDueDate\t\tReturned\tFine\n");
    printline();
    while(fread(&i,sizeof(i),1,fi))
    {
        count++;
        printf("%d\t%d\t%d\t\t%s\t%s\t%s\t\t%.2f\n",
               i.issueId, i.bookId, i.memberId,
               i.issueDate, i.dueDate,
               (i.returned ? "Yes" : "No"),
               i.fine);
    }
    printf("\n%d issue record(s) shown.\n", count);
    fclose(fi);
}