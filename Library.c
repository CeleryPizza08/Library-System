// Name: Wong Zhan Choon
// ID : 20312555
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct book {
char *title;
char *author;
char *subject;
};

struct library {
struct book collection;
int num_books;
struct library *next;
};


void addBook(struct library **thislib, struct book books) //adding book function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if(fp1 == NULL)
    {
        printf("File is not created.\n");
        return;
    }

    struct library *newbook = malloc(sizeof(struct library));
    if(newbook != NULL) // if there's space available, store the data of the book.
    {
    newbook->collection.title = malloc(strlen(books.title)+1); //memory allocate the input.
    newbook->collection.author = malloc(strlen(books.author)+1);
    newbook->collection.subject = malloc(strlen(books.subject)+1);
    strcpy(newbook->collection.title,books.title);
    strcpy(newbook->collection.author,books.author);
    strcpy(newbook->collection.subject,books.subject);
    newbook->next = NULL;
    }
    else
    {
        return;
    }

    if(*thislib == NULL) // if linked list is empty , create a node.
    {
        *thislib = newbook; // move the head pointer to the 1st node.
    }
    else // add the nodes from last of linked list.
    {
        struct library *lastptr = *thislib;

        while(lastptr->next != NULL) // traverse to the last node in the linked list.
        {
            lastptr = lastptr->next; // move to next node.
        }
        lastptr->next = newbook; // insert the new node from the end of linked list.
    }

    fprintf(fp1,"The book %s author %s subject %s has been added to the library.\n\n",newbook->collection.title,newbook->collection.author,newbook->collection.subject);
    fclose(fp1);
}

void deleteTBook(struct library **thislib, char title[49]) // deleting book function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if (fp1 == NULL)
    {
        printf("File is not created.\n");
        return;
    }
    int found = 0, pos = 0; // start position = 0 and if data found then found++.
    struct library *pptr = *thislib; // previous pointer.
    struct library *cptr = *thislib; // current pointer.
    struct library *temp2 = *thislib; // last 2nd node.
    struct library *temp3 = *thislib; // last 3rd node.
    struct library *counter = *thislib; // count total no. of books inside my library.
    int num = 0; // no. of books.

    if(*thislib == NULL) // if linked list is empty.
    {
        fprintf(fp1,"Linked list is empty.\n\n");
        return;
    }

    while(counter != NULL) // Traverse the linked list.
    {
        num++; // increment.
        counter = counter->next; // move to next node.
    }

    while(temp2->next->next != NULL) // if last 2nd node is not NULL.
    {
        temp3 = temp2; // last 3rd node.
        temp2 = temp2->next; // last 2nd node.
    }

    while(cptr != NULL) // Traverse the linked list.
    {
        if(strcmp(cptr->collection.title,title)== 0) // if data is matched.
        {
            pos++; // increment position to search the target's position.
            found++; // flag.
            break;
        }
            pos++; // increment position to search the target's position.
            pptr = cptr; // previous = current.
            cptr = cptr->next; // current = next;
    }

    if(found == 1) // if data is matched.
    {
        if(num == 1) // if there is only 1 book in the collection.
        {
            if(pos == 1) // 1st position.
            {
                free(cptr); // free the node.
                cptr = NULL; // current = NULL.
                *thislib = NULL; // collection will become empty.
            }
            num--; // decrement the book inside the library.
            fprintf(fp1,"The book %s has been removed from the library.\n\n",title);
        }
        if(num == 2) // if there is only 2 books in the collection.
        {
            if(pos == 1) // 1st position.
            {
                pptr = cptr->next; // previous = current->next;
                *thislib = pptr; // head = previous;
                free(cptr); // free the node.
                cptr = NULL; // current = NULL.
            }
            if(pos == 2) // 2nd position.
            {
                pptr->next = NULL; // unlink the last node.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL.
            }
            num--; // decrement the book inside the library.
            fprintf(fp1,"The book %s has been removed from the library.\n\n",title);
        }
        if(num == 3) // if there is only 3 books in the collection.
        {
            if(pos == 1) // 1st position.
            {
                pptr = cptr->next; // previous = current->next.
                *thislib = pptr; // head = previous.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL.
            }
            if(pos == 2) // 2nd position.
            {
                pptr->next = cptr->next; // unlink the 2nd node.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL.
            }
            if (pos == 3) // 3rd position.
            {
                pptr->next = NULL; // unlink the last node.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL.
            }
            num--; // decrement the book inside the library.
            fprintf(fp1,"The book %s has been removed from the library.\n\n",title);
        }
        if(num >= 4 && num <= 30) // if there is more than 4 books in the collection.
        {
            if((num-pos) == (num-1))
            {
                temp3->next = temp2->next; // unlink the last 2nd node.
                temp2->next = cptr->next; // last 2nd node link to current->next node.
                *thislib = temp2; // move header to temp2.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL
            }
            if((num-pos) > 2 && (num-pos) != (num-1))
            {
                temp3->next = temp2->next; // unlink the last 2nd node.
                temp2->next = cptr->next; // last 2nd node link to current->next node.
                pptr->next = temp2; // previous->next link to last 2nd node.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL
            }
            if((num-pos) == 2)
            {
                pptr->next = temp2; // previous->next link to last 2nd node.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL
            }
            if((num-pos) == 1)
            {
                temp3->next = temp2->next;  // unlink the last 2nd node.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL
            }
            if((num-pos) == 0)
            {
                pptr->next = NULL; // unlink the last node.
                free(cptr); // free the node.
                cptr = NULL; // current = NULL
            }
            num--;
            fprintf(fp1,"The book %s has been removed from the library.\n\n",title);
        }
    }
    else // if all the data are not matched.
    {
        fprintf(fp1,"Deletion cannot be performed as the requested item does not exist.\n\n");
    }
    fclose(fp1);
}

void deleteAllBook(struct library **thislib, char author[49]) // deleting book by author function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if (fp1 == NULL)
    {
        printf("File is not created.\n");
        return;
    }

    int found = 0, pos = 0; // start position = 0 and if data found then found++.
    struct library *pptr = *thislib; // previous pointer.
    struct library *cptr = *thislib; // current pointer.
    struct library *temp = *thislib; // free pointer.
    struct library *temp2 = *thislib; // last 2nd node.
    struct library *temp3 = *thislib; // last 3rd node.
    struct library *counter = *thislib; // count total no. of books inside my library.
    int i,num = 0; // no. of books.
    char author1[49], title[49]; // to store the author from the node.

    if(*thislib == NULL) // if linked list is empty.
    {
        fprintf(fp1,"Linked list is empty.\n\n");
        return;
    }

    while(counter != NULL) // Traverse the linked list.
    {
        num++; // increment.
        counter = counter->next; // move to next node.
    }

    while(temp2->next->next != NULL) // if last 2nd node is not NULL.
    {
        temp3 = temp2; // last 3rd node.
        temp2 = temp2->next; // last 2nd node.
    }

    while(cptr != NULL) // Traverse the linked list.
    {
        strcpy(author1,cptr->collection.author);
        for(i=0; author1[i]!='\0' && author[i]!='\0'; i++) // looping to uppercase the string (insensitive case).
        {
            author1[i] = toupper(author1[i]);
            author[i] = toupper(author[i]);
        }
            pos++; // to search the target's position.

        if(strcmp(author1,author)== 0) // if data is matched.
        {
            found++; // flag.
            strcpy(title,cptr->collection.title);

                if(num == 1) // if there is only 1 book in the collection.
                {
                    if(pos == 1) // 1st position.
                    {
                        free(cptr); // free the node.
                        cptr = NULL; // current = NULL.
                        *thislib = NULL; // collection will become empty.
                    }
                    pos = 0; //reset position counter.
                    num--; // decrement no. of books in the library.
                    fprintf(fp1,"The book %s authored by %s has been removed from the library.\n\n",title,author);
                }
                if(num == 2) // if there is only 2 books in the collection.
                {
                    if(pos == 1) // 1st position.
                    {
                        pptr = temp->next; // previous = current->next;
                        *thislib = pptr; // head = previous;
                        free(cptr); // free the node.
                    }
                    if(pos == 2) // 2nd position.
                    {
                        pptr->next = NULL; // unlink the last node.
                        free(cptr); // free the node.
                    }
                    pos = 0; //reset position counter.
                    num--; // decrement no. of books in the library.
                   fprintf(fp1,"The book %s authored by %s has been removed from the library.\n\n",title,author);
                }
                if(num == 3) // if there is only 3 books in the collection.
                {
                    if(pos == 1) // 1st position.
                    {
                        pptr = cptr->next; // previous = current->next.
                        *thislib = pptr; // head = previous.
                        free(cptr); // free the node.
                    }
                    if(pos == 2) // 2nd position.
                    {
                        pptr->next = cptr->next; // unlink the 2nd node.
                        free(cptr); // free the node.
                    }
                    if (pos == 3) // 3rd position.
                    {
                        pptr->next = NULL; // unlink the last node.
                        free(cptr); // free the node.
                    }
                    pos = 0; //reset position counter.
                    num--; // decrement no. of books in the library.
                    fprintf(fp1,"The book %s authored by %s has been removed from the library.\n\n",title,author);
                }
                if(num >= 4 && num <= 30) // if there is more than 4 books in the collection.
                {
                    if((num-pos) == (num-1))
                    {
                        temp3->next = temp2->next; // unlink the last 2nd node.
                        temp2->next = cptr->next; // last 2nd node link to cptr->next.
                        *thislib = temp2; // move header to last 2nd node.
                        free(cptr); // free the node.
                    }
                    if((num-pos) > 2 && (num-pos) != (num-1))
                    {
                        temp3->next = temp2->next; // unlink the last 2nd node.
                        temp2->next = cptr->next; // last 2nd node link to cptr->next.
                        pptr->next = temp2; // previous->next link to last 2nd node.
                        free(cptr); // free the node.
                    }
                    if((num-pos) == 2)
                    {
                        pptr->next = temp2; // unlink the last 2nd node.
                        free(cptr); // free the node.
                    }
                    if((num-pos) == 1)
                    {
                        temp3->next = temp2->next; // unlink the last 2nd node.
                        free(cptr); // free the node.
                    }
                    if((num-pos) == 0)
                    {
                        pptr->next = NULL; // unlink the last node.
                        free(cptr); // free the node.
                    }
                    pos = 0; //reset position counter.
                    num--; // decrement no. of books in the library.
                    fprintf(fp1,"The book %s authored by %s has been removed from the library.\n\n",title,author);
                }
        }
        else
        {
            pptr = cptr; // previous = current.
            cptr = cptr->next; // current = next.
        }
    }

        if(found == 0) // if all the data are not matched.
        {
            fprintf(fp1,"Deletion cannot be performed as the requested item does not exist.\n\n");
        }
    fclose(fp1);
}

void sTitle(struct library **thislib, char title[49]) // search title function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if(fp1 == NULL)
    {
        printf("Unable to read the file.\n");
        return;
    }
    struct library *searchT = *thislib;

    while(searchT != NULL) //traverse the linked list.
    {
        if(strcmp(searchT->collection.title,title) == 0) // if data is matched.
        {
            fprintf(fp1,"The Book %s is currently in the library.\n\n",searchT->collection.title);
            break;
        }
        searchT = searchT->next; // move to next node.
    }

    if(searchT == NULL) // if the data is not found.
    {
        fprintf(fp1,"The Book %s is currently not in the library.\n\n",title);
    }
    fclose(fp1);
}

void sAllBook(struct library **thislib, char author[49]) // search all book by author function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if(fp1 == NULL)
    {
        printf("Unable to read the file.\n");
        return;
    }
    struct library *searchA = *thislib;
    char author1[49]; // store the author from the node.
    int i,found = 0;

    while(searchA != NULL) // traverse the linked list.
    {
        strcpy(author1,searchA->collection.author);
        for(i=0; author1[i]!= '\0' && author[i]!= '\0'; i++) // looping to uppercase the string (insensitive case).
        {
            author1[i] = toupper(author1[i]);
            author[i] = toupper(author[i]);
        }
        if(strcmp(author1,author)== 0) // if data is matched.
        {
            found++; // flag.
            fprintf(fp1,"The Book %s authored by %s is currently in the library.\n\n",searchA->collection.title,searchA->collection.author);
        }
        searchA = searchA->next; // move to the next node.
    }

    if(found == 0) // if all the data are not matched
    {
        fprintf(fp1,"The Book authored by %s is NOT currently in the library.\n\n",author);
    }

    fclose(fp1);
}

void LAuthor(struct library **thislib, char author[49]) // list all book by author function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if(fp1 == NULL)
    {
        printf("Unable to read the file.\n");
        return;
    }
    char title[30][49], temp[49];
    int i,j,n=0;
    struct library *listA = *thislib;
    char author1[49]; // to store author from the node.

    while(listA != NULL) // traverse the linked list.
    {
        strcpy(author1,listA->collection.author);
        for(i=0; author1[i]!='\0' && author[i]!='\0'; i++) // looping to uppercase the string (insensitive case).
        {
            author1[i] = toupper(author1[i]);
            author[i] = toupper(author[i]);
        }
        if(strcmp(author1,author)== 0) // if data is matched.
        {
            strcpy(title[n],listA->collection.title); //copy the string to the array.
            n++; // flag.
        }
        listA = listA->next; // move to next node.
    }

    if(n == 1) // if there's only 1 data matched found.
    {
        fprintf(fp1,"List of all books by %s\n",author);
        fprintf(fp1,"%s\n",listA->collection.title);
    }
    else if(n > 1) // if there's more than 1 data matched found, compare the string and sort it in ascending order.
    {
        fprintf(fp1,"List of all books by %s\n",author);
        for(i=0; i<n; i++) // comparison.
        {
            for(j=i+1; j<n; j++)
            {
                if(strcmp(title[i],title[j])>0 ) // sort title in ascending order.
                {
                    strcpy(temp,title[i]);
                    strcpy(title[i],title[j]);
                    strcpy(title[j],temp);
                }
            }
            fprintf(fp1,"%s\n",title[i]);
        }
    }
    else // if there's no data matched.
    {
        fprintf(fp1,"List of all books on %s\n",author);
        fprintf(fp1,"No related book for %s is found in the library.\n",author);
    }
    fprintf(fp1,"\n");
    fclose(fp1);
}

void LSubject(struct library **thislib, char subject[49]) // list all book by subject function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if(fp1 == NULL)
    {
        printf("Unable to read the file.\n");
        return;
    }
    char title[30][49], temp[49];
    int i,j,n=0;
    struct library *listS = *thislib;
    char subject1[49]; // to store the subject from the node.

    while(listS != NULL) // traverse the linked list.
    {
        strcpy(subject1,listS->collection.subject);
        for(i=0; subject1[i]!= '\0' && subject[i]!= '\0'; i++)
        {
            subject1[i] = toupper(subject1[i]);
            subject[i] = toupper(subject[i]);
        }
        if(strcmp(subject1,subject)== 0) // if data is matched.
        {
            strcpy(title[n],listS->collection.title); // copy the string to the array.
            n++; // flag.
        }
            listS = listS->next; // move to next node.
    }

    if(n == 1) // if there's only 1 data matched found.
    {
        fprintf(fp1,"List of all books on %s\n",subject);
        fprintf(fp1,"%s\n",listS->collection.title);
    }
    else if(n > 1) // if there's more than 1 data match found, compare the string and sort it in descending order.
    {
        fprintf(fp1,"List of all books on %s\n",subject);
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(strcmp(title[i],title[j])<0 ) // sort title in descending order.
                {
                    strcpy(temp,title[i]);
                    strcpy(title[i],title[j]);
                    strcpy(title[j],temp);
                }
            }
            fprintf(fp1,"%s\n",title[i]);
        }
    }
    else // if there's none data matched found.
    {
        fprintf(fp1,"List of all books on %s\n",subject);
        fprintf(fp1,"No related book for %s is found in the library.\n",subject);
    }
    fprintf(fp1,"\n");
    fclose(fp1);
}

void LAllBook(struct library **thislib) // list all book in original order function.
{
    FILE *fp1;
    fp1 = fopen("output.txt","a+");
    if(fp1 == NULL)
    {
        printf("Unable to read the file.\n");
        return;
    }
    struct library *cptr = *thislib;

    fprintf(fp1,"List all the books in original order.\n");
    while(cptr != NULL) // traverse the linked list and list all the books in original order.
    {
        fprintf(fp1,"%s %s %s\n",cptr->collection.title,cptr->collection.author,cptr->collection.subject);
        cptr = cptr->next; // move to next node.
    }
    fprintf(fp1,"\n");
    fclose(fp1);
}

void copybook(struct book* dest, struct book* source)
{
    strcpy(dest->title,source->title); //copybook.
}

int main(void)
{
    struct library *thislib = NULL; // initiate the collection is empty.
    struct book books;
    books.title = malloc(49*sizeof(char)); // assign title to store max 49 characters.
    books.author = malloc(49*sizeof(char)); // assign author to store max 49 characters.
    books.subject = malloc(49*sizeof(char)); // assign subject to store max 49 characters.
    int i,a,op;

    FILE *fp;
    fp = fopen("library.txt","r");
    if(fp == NULL)
    {
        printf("Unable to read the file.");
        return 0;
    }
    fscanf(fp,"%d",&op); // scan the total number of operations.

        for(int i=0;i<op;i++) // loop to execute the number of operations.
        {
            fscanf(fp,"%d",&a); // scan the operation.

        switch (a) // switch case to assign the operation.
        {
            case 1: // Adding book.
                fscanf(fp,"%s %s %s",books.title,books.author,books.subject);
                addBook(&thislib, books);
                break;
            case 2: // Deleting book.
                fscanf(fp,"%s",books.title);
                deleteTBook(&thislib, books.title);
                break;
            case 3: // Deleting all book by a particular author.
                fscanf(fp,"%s",books.author);
                deleteAllBook(&thislib, books.author);
                break;
            case 4: // Search book by a particular title.
                fscanf(fp,"%s",books.title);
                sTitle(&thislib, books.title);
                break;
            case 5: // Search all book by a particular author.
                fscanf(fp,"%s",books.author);
                sAllBook(&thislib, books.author);
                break;
            case 6: // List all book by a particular author.
                fscanf(fp,"%s",books.author);
                LAuthor(&thislib, books.author);
                break;
            case 7: // List all book by a particular subject.
                fscanf(fp,"%s",books.subject);
                LSubject(&thislib, books.subject);
                break;
            case 8: // List all book in original order.
                LAllBook(&thislib);
                break;
            default: // wrong input. Not within (1-8)
                printf("Wrong Input! Please Try Again.\n");
                break;
        }
        }

    fclose(fp);
    return 0;
}
