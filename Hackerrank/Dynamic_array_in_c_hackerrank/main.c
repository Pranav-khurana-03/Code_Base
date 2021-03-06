#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;
#include<string.h>
int main()
{
    int total_number_of_shelves, queries, i, pages,shelf;
    scanf ("%d %d", &total_number_of_shelves, &queries);
    total_number_of_pages = (int**)malloc(sizeof(int*)*total_number_of_shelves);
    total_number_of_books = (int*)malloc(sizeof(int)*total_number_of_shelves);
    memset(total_number_of_books, 0, total_number_of_shelves*sizeof(int));
    for(i=0;i<total_number_of_shelves;i++)
    {
      total_number_of_pages[i] = (int*)malloc(sizeof(int)*1100);
      //memset(total_number_of_pages[i], 0, sizeof(int)*1100);
    }
    for(i=0;i<queries;i++)
    {
        int type_of_query;
        scanf("%d", &type_of_query);
        if(type_of_query==1)
        {
            scanf("%d %d", &shelf, &pages);
            total_number_of_pages[shelf][total_number_of_books[shelf]] = pages;
            total_number_of_books[shelf]++;
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }

    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

    return 0;
}
