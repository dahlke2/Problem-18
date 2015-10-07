//
//  main.c
//  Problem 18
//
//  Created by Ethan Dahlke on 11/29/13.
//  Copyright (c) 2013 Ethan Dahlke. All rights reserved.
//

#include <stdio.h>
#include </Users/ethandahlke/Desktop/ProjectEuler/euler.h>

//#define RECURS_DEBUG

#ifdef RECURS_DEBUG
#define TRIANGLE "/Users/ethandahlke/Desktop/ProjectEuler/Problem 18/Problem 18/debug.txt"
#define ROWS 15
#endif
#ifndef RECURS_DEBUG
#define TRIANGLE "/Users/ethandahlke/Desktop/ProjectEuler/Problem 18/Problem 18/triangle"
#define ROWS 15
#endif

int array[15][15];
int best_array[15][15];
int tri_row, tri_col;
long sum, best_sum, row, col, count;
int *greater();

void grid_recurs(int *row, int *col);


void setup()
{
    int i,j;
    for(i=0; i<ROWS; i++)
        for(j=0; j<ROWS; j++){
            array[i][j]=0;
            best_array[i][j]=0;
        }
    tri_row=0;
    tri_col=0;
    row = 0;
    col = 0;
    count = 0;
    sum=0;
    best_sum=sum;
//    greater = malloc(sizeof(int));
}

void exit();

void grid_recurs(int *row, int *col){
    
    array[*row][*col]= 1;
    
    if((*row)<(ROWS-1) && (*col)<(ROWS-1))
    {
        (*row)++;
        grid_recurs(row, col);
        sum-=array[(*row)][(*col)];
        array[*row][*col]=0;
        (*col)++;
        //        (*row)--;
        grid_recurs(row, col);
        array[*row][*col]=0;
        (*row)--;
        (*col)--;
    }
    
    if(*row==(ROWS-1) ){
    for (int i = 0; i<15; i++){
		for (int c=0; c<15; c++)
			printf("%2i ",array[i][c]);
		printf("\n");
	}
        printf("\n");
        count++;
    }
//    grid_recurs(row, col);
//    array[*row][*col] = 0;

}

void tri_recurs(int *row, int *col)
{
//    int complete = 0;
    sum+=array[(*row)][(*col)];
    
    if((*row)==(ROWS-1))
    {
        count++;
        best_sum = *greater(&sum, &best_sum);
//        printf("%ld, %ld\n", sum, best_sum);
        return ;
    }

    if ((best_sum-sum) >= (99*(ROWS-1-(*row)))){
//        printf("%i\n",*row);
        return ;
    }
    
    if((*row)<(ROWS-1) && (*col)<(ROWS-1))
    {
//        (*row)++;
//        if(array[*row][*col]>=array[*row][*col+1])
//            tri_recurs(row,col);
//        else{
//            (*col)++;
//            tri_recurs(row,col);
//        }
        
        (*row)++;
        tri_recurs(row, col);
        sum-=array[(*row)][(*col)];
        (*col)++;
        tri_recurs(row, col);
        sum-=array[(*row)][(*col)];
        (*row)--;
        (*col)--;
    }
    
        return ;
}

int *greater(int *first, int *second)
{
    if ((*first)>= (*second))
        return first;
    else
        return second;
}


void read_triangle()
{
    int i=0;
    int j=0;
    FILE *triangle;
    triangle = fopen(TRIANGLE, "r");
#ifndef RECURS_DEBUG
//    while (EOF != fscanf(triangle, "%2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5], &array[i][6], &array[i][7], &array[i][8], &array[i][9], &array[i][10], &array[i][11], &array[i][12], &array[i][13], &array[i][14]))
//        i++;
    while (EOF != fscanf(triangle, "%2u", &array[i][j])){
        if(j==(ROWS-1) || j==i){
            i++;
            j=0;
        }
        else
            j++;
    }
#endif
#ifdef RECURS_DEBUG
    while (EOF != fscanf(triangle, "%2i %2i %2i %2i", &array[i][0], &array[i][1], &array[i][2], &array[i][3]))
        i++;
#endif
    fclose(triangle);
//    for (int i = 0; i<ROWS; i++){
//		for (int c=0; c<ROWS; c++)
//			printf("%2i ",array[i][c]);
//		printf("\n");
//	}
}

int main(int argc, const char * argv[])
{
    setup();
    
#ifndef RECURS_DEBUG
    read_triangle();
    tri_recurs(&tri_row, &tri_col);
#endif
#ifdef RECURS_DEBUG
    grid_recurs(&row, &col);
//    read_triangle();
//    tri_recurs(&tri_row, &tri_col);
#endif
//    printf("\n");
//    for (int i = 0; i<ROWS; i++){
//		for (int c=0; c<ROWS; c++)
//			printf("%2i ",best_array[i][c]);
//		printf("\n");
//	}
    printf("%ld, %ld\n",best_sum, count);
    return 1;
}

