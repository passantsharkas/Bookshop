#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct
{
    int day,month,year;
} Date_of_Pub;

typedef struct
{
    int bar_code;
    Date_of_Pub db;
    char author[20];
    char book_title[100];
    char categ[100];
    char language[20]; // language written
    float price, borrow_price_per_day;
    int pages, number_of_copy;
} bookINFO;

void borrowBook(bookINFO b[], char bookname[],int n, int amount,int day)     // amount of borrow book
{
    int i, f =0;
    float cost;
    for(i=0; i<n; i++)
    {
        if(strcmp(b[i].book_title, bookname) == 0)
        {
            if(b[i].number_of_copy >= amount)
            {
                b[i].number_of_copy-= amount;
                cost = b[i].borrow_price_per_day*day;
                f = 1;
            }
            else
            {
                printf("There is no enough Copy of this book\n");
                return;
            }
        }
        if(f==0)
		{
		printf("Book Not Found\n");
		return;
		}
        else
		printf("Total Cost of borrowd Book  = %f\n", cost);
    }
}
void saveFile(bookINFO b[], int n)
{
    FILE* f = fopen("book_data.txt","w");
    int i;
    fprintf(f,"%s\n","bar_code-Book_Title-Author-Category-Language-Data_of_Publish");
    for(i=0; i<n; i++)
    {
        fprintf(f,"%d",b[i].bar_code);
        fprintf(f,"%s","-");
        fprintf(f,"%s",b[i].book_title);
        fprintf(f,"%s","-");
        fprintf(f,"%s",b[i].author);
        fprintf(f,"%s","-");
        fprintf(f,"%s",b[i].categ);
        fprintf(f,"%s","-");
        fprintf(f,"%s",b[i].language);
        fprintf(f,"%s","-");
        fprintf(f,"%d",b[i].db.day);
        fprintf(f,"%s","/");
        fprintf(f,"%d",b[i].db.month);
        fprintf(f,"%s","/");
        fprintf(f,"%d",b[i].db.year);
        fprintf(f,"%s","-");
        fprintf(f,"%f",b[i].price);
        fprintf(f,"%s","-");
    	fprintf(f,"%f",b[i].borrow_price_per_day);
        fprintf(f,"%s","-");
		fprintf(f,"%d",b[i].pages);
        fprintf(f,"%s","-");
        fprintf(f,"%d",b[i].number_of_copy);
        fprintf(f,"%s\n","-");
    }
    fclose(f);
}

void addBook (bookINFO x[],int *index) //no of books
{
    printf("Enter bar_code for the book : ");
    scanf("%d",&x[*index].bar_code);
    printf("Enter Title for the book : ");
    scanf("%s",x[*index].book_title);
    printf("Enter author for the book:  ");
    scanf("%s",x[*index].author);
    printf("Enter category for the book: ");
    scanf("%s",x[*index].categ);
    printf("Enter day of the published date  ");
    scanf("%d",&x[*index].db.day);
    printf("Enter month of the published date ");
    scanf("%d",&x[*index].db.month);
    printf("Enter year of the published date ");
    scanf("%d",&x[*index].db.year);
    printf("Enter Book language: ");
    scanf("%s",x[*index].language);
    printf("Enter Book price to buy: ");
    scanf("%f",&x[*index].price);
    printf("Enter Book price for borrow per day: ");
    scanf("%f",&x[*index].borrow_price_per_day);
    printf("Enter Book's number of pages: ");
    scanf("%d",&x[*index].pages);
    printf("Enter Book's number of copies: ");
    scanf("%d",&x[*index].number_of_copy);
    *index= *index +1;
}

void diplayBooks(bookINFO b[], int n)
{
    int i;
    printf("------------------------------------------------------------------------\n");
    printf("bar_code   Book_Title  Author  Data_of_Publish  price  pages  no_Copies\n");
    printf("------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf("%d  ",b[i].bar_code);
        printf("%s  ",b[i].book_title);
        printf("%s  ",b[i].author);
        printf("%d/",b[i].db.day);
        printf("%d/",b[i].db.month);
        printf("%d  ",b[i].db.year);
        printf("%f  ",b[i].price);
        printf("%f  ",b[i].borrow_price_per_day);
        printf("%d  ",b[i].pages);
        printf("%d\n",b[i].number_of_copy);
    }
}

void displaybyCategories(bookINFO b[], int n, char cat[10])
{
    int i;
    printf("------------------------------------------------------------------------\n");
    printf("bar_code   Book_Title  Author  Data_of_Publish  price  pages  no_Copies\n");
    printf("------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        if(strcmp(b[i].categ, cat) == 0)
        {
            printf("%d  ",b[i].bar_code);
        printf("%s  ",b[i].book_title);
        printf("%s  ",b[i].author);
        printf("%d/",b[i].db.day);
        printf("%d/",b[i].db.month);
        printf("%d  ",b[i].db.year);
        printf("%f  ",b[i].price);
        printf("%f  ",b[i].borrow_price_per_day);
        printf("%d  ",b[i].pages);
        printf("%d\n",b[i].number_of_copy);
        }

    }
}



int deleteBookbybar_code (bookINFO x[],int *n, int bar_code) //n no of books
{
    int f=0,i,j;
    for (i=0; i<*n; i++)
    {
        if (bar_code==x[i].bar_code)
        {
            f=1;
            for ( j=i; j<*n; j++)
            {
                x[j]=x[j+1];
                *n = *n-1;
            }
            return 1;
        }
    }
    if (f==0)
    {
        return 0;
    }
}

int deleteBookbyLanguage (bookINFO x[],int *n, char lang[20])
{
    int f=0,i,j;
    for ( i=0; i< *n; i++)
    {
        if (strcmp(lang,x[i].language)==0)
        {
            f=1;
            for ( j=i; j< *n; j++)
            {
                x[j]=x[j+1];
                *n = *n-1;
            }
            return 1;
        }
    }
    if (f==0)
    {
        return 0;
    }
}

int editBookBybar_code (bookINFO x[],int n, int oldbar_code, int newbar_code)
{
    int f=0,i;
    for ( i=0; i<n; i++)
    {
        if ( oldbar_code == x[i].bar_code)
        {
            f=1;
            x[i].bar_code = newbar_code;
            return 1;
        }
    }
    if (f==0)
    {
        return 0;
    }
}

int searchbyauthor(bookINFO x[], int n, char aut[])
{
    int f =0,i,j;
    for ( i=0 ; i<n; i++)
    {
        if (strcmp(aut, x[i].author)== 0)
        {
            f=1;
            printf("Found!\n");
            return i;
        }
    }
    if (f==0)
    {
        printf("NOT Found!\n");
        return 0;
    }
}

int searchbybar_code(bookINFO x[],int n,int bar_code)
{
    int f=0,i;
    for ( i=0; i<n; i++)
    {
        if (bar_code == x[i].bar_code)
        {
            f=1;
            printf("Found!\n");
            return i;
        }
    }
    if (f==0)
    {
        printf("NOT Found!\n");
        return 0;
    }
}

void sortBooksbybar_code (bookINFO x[],int n)
{
    int pass,j;
    bookINFO s;
    for ( pass=1; pass<n; pass++)
        for ( j=0; j<n-pass; j++)
        {
            if (x[j].bar_code > x[j+1].bar_code)
            {
                s=x[j];
                x[j]=x[j+1];
                x[j+1]=s;
            }
        }
}
void SortBypublishYear(bookINFO x[], int n)
{

    int pass,j;
    bookINFO s;
    for ( pass=1; pass<n; pass++)
        for ( j=0; j<n-pass; j++)
        {
            if (x[j].db.year > x[j+1].db.year)
            {
                s=x[j];
                x[j]=x[j+1];
                x[j+1]=s;
            }
        }
}

int main()
{
    bookINFO b[1000];
    int i=0, index;
    int j=0;
    char bookname[20];
    int amount,day;

    while(1)
    {
        printf("1-Add Book\n");
        printf("2-Delete a book \n");
        printf("3-Display All Books\n");
        printf("4-Display All Books for specific category\n");
        printf("5-Search for a book\n");
        printf("6-Sort All books\n");
        printf("7-Borrow a book\n");
        printf("8-Edit a book by bar_code\n");
        printf("9-Save to file\n");
        printf("10-Exit\n---------------------------------------------\n");
        int choice, RemChoice,SortChoice,SearchChoice;
        printf("Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addBook(b,&i);
            break;

        case 2:
            if(i==0) //i no of books
            {
                printf("No Data Found\n");
                break;
            }
            printf("delete By\n1-bar_code\n2-Language of the book\n");
            printf("Your Choice : ");
            scanf("%d",&RemChoice);
            if(RemChoice==1) // bar_code
            {
                int bar_code;
                printf("Enter the barcode of the book you want to remove\n");
                scanf("%d", &bar_code);
                index = deleteBookbybar_code(b,&i,bar_code);
            }
            else if(RemChoice==2)
            {
                char language[50];
                printf("Enter Language of the book\n");
                scanf("%s", language);
                index = deleteBookbyLanguage(b,&i,language);
            }

            if(index ==1)
            {
                saveFile(b,i);
                printf("Found And Removed !\n");
            }
            else printf("NOT Found!\n");
            break;

        case 3:
            if(i==0)
            {
                printf("No Data to display\n");
                break;
            }
            printf("************************************************************\n");
            diplayBooks(b,i);
            printf("************************************************************\n");
            break;
        case 4:
            if(i==0)
            {
                printf("No Data to display\n");
                break;
            }
            char categ[10];
            printf("Enter Category want to display");
            scanf("%s", categ);
            printf("************************************************************\n");
            displaybyCategories(b,i, categ);
            printf("************************************************************\n");
            break;

        case 5:
            if(i==0)
            {
                printf("No Data Found\n");
                break;
            }
            printf("Search by By\n1-bar_code\n2-Author Name\n");
            printf("Your Choice : ");
            scanf("%d",&SearchChoice);
            if(SearchChoice==1)
            {
                int bar_code;
                printf("Enter bar_code You Search\n");
                scanf("%d", &bar_code);
                index = searchbybar_code(b,i,bar_code);
                printf("Book_Title  Author  Data_of_Publish  price  pages  no_Copies\n");
    printf("------------------------------------------------------------------------\n");
        printf("%s  ",b[index].book_title);
        printf("%s  ",b[index].author);
        printf("%d/",b[index].db.day);
        printf("%d/",b[index].db.month);
        printf("%d  ",b[index].db.year);
        printf("%f  ",b[index].price);
        printf("%d  ",b[index].pages);
        printf("%d\n",b[index].number_of_copy);

            }
            else if(SearchChoice==2)
            {
                char aut[50];
                printf("Enter Author Name \n");
                scanf("%s", aut);
                index = searchbyauthor(b,i,aut);
        printf("bar_code-Book_Title-Data_of_Publish-price-pages-no_Copies\n");
    printf("------------------------------------------------------------------------\n");
        printf("%d  ",b[index].bar_code);
        printf("%s  ",b[index].book_title);
        printf("%d/",b[index].db.day);
        printf("%d/",b[index].db.month);
        printf("%d  ",b[index].db.year);
        printf("%f  ",b[index].price);
        printf("%d  ",b[index].pages);
        printf("%d\n",b[index].number_of_copy);

            }
            break;

        case 6:
            if(i==0)
            {
                printf("No Data Found\n");
                break;
            }
            printf("Sort by By\n1-bar_code\n2-Publish Year\n");
            printf("Your Choice : ");
            scanf("%d",&SortChoice);
            if(SortChoice==1)
            {
                sortBooksbybar_code(b,i);
            }
            else if(SortChoice==2)
            {
                SortBypublishYear(b,i);
            }
            printf("---------------------------------------------\n");
            printf("Sort Successfully\n");
            printf("---------------------------------------------\n");
            saveFile(b,i);
            break;

        case 7:
            printf("Enter book title, number of copy you want, how many days respectively\n");
            scanf("%s%d%d",bookname, &amount, &day );
            borrowBook(b,bookname,i,amount,day);
            break;

        case 8:
            if(i==0)
            {
                printf("No Data to edit\n");
                break;
            }
            int bar_code, bar_codeN;
            printf("Enter bar_code of the book You want to edit\n");
            scanf("%d", &bar_code);
            printf("Enter New bar_code of the book \n");
            scanf("%d", &bar_codeN);
            int u;
			u =editBookBybar_code(b,i,bar_code, bar_codeN);

            printf("===================\n");
            if(u ==1)
            {
                printf("Edit Done\n");
                saveFile(b,i);
            }
            else printf("bar_code Not found\n");
            printf("===================\n");
            break;
        case 9:
            saveFile(b,i);
            printf("Data has been Saved into the File\n");
            break;
        case 10:
            exit(1);

        default:
            printf("Error Choice\n");
        }
    }
}
