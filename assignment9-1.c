#include <stdio.h>
#define MaxRow 10 //array-maximum no of rows
#define MinRow 1 //array-minimum no of rows
#define MaxCol 6 //array-maximum no of columns
#define MinCol 1 //array-minimum no of columns


int main()
{
    int RowSize, ColSize;
    int a[MaxRow][MaxCol],//1st input array
     b[MaxRow][MaxCol],//2nd input array
     c[MaxRow][MaxCol];//resulting array

//Functions declaration
        int ReadArraySize(int,int);
       void ReadArray(int [][MaxCol], int, int),
            AddArray(int [][MaxCol], int[][MaxCol],int[][MaxCol], int, int),
             DispArray(int [][MaxCol], int, int),
              DispArrayT(int [][MaxCol], int, int);
             // optional MulArray(int [][MaxCol], int[][MaxCol], int[][MaxCol], int, int),

    printf("Please specify no. of rows of arrays: ");
    RowSize=ReadArraySize(MinRow,MaxRow);

    printf("Please specify no. of columns of arrays: ");
    ColSize=ReadArraySize(MinCol,MaxCol);
    printf("Array size is set to: [%d] [%d]\n", RowSize, ColSize);

    printf("Read array A\n");
    ReadArray(a, RowSize, ColSize);//get all value for arrays a (scanf)
    printf("Read array B\n");
    ReadArray(b, RowSize, ColSize);//get all value for arrays b (scanf)

//find array c[][] = array a[][] + b[][]
   AddArray(a, b, c, RowSize, ColSize);
   printf("-Array A-\n");
   DispArray(a, RowSize, ColSize);//display a
   printf("-Array B-\n");
   DispArray(b, RowSize, ColSize);//display b
   printf("-Array C-\n");
   DispArray(c, RowSize, ColSize);//display c

    printf( "please type any key to show the transpose: ");
    char ch=getchar();
    scanf("%c%*c",&ch);
    printf("-Transpose of matrix A-\n");
    DispArrayT(a, RowSize, ColSize);//display a^T
    printf("\n");
    printf("-Transpose of matrix B-\n");
    DispArrayT(b, RowSize, ColSize);//display b^T
    printf("\n");
    printf("-Transpose of matrix C-\n");
    DispArrayT( c, RowSize, ColSize);//display c^T
    printf("\n");

    return 0;
}


int ReadArraySize(int MinSize,int MaxSize) //read array size, row then column
{
    int size;
	do{
      	printf(" range[%d..%d] : ",MinSize,MaxSize);
	    scanf("%d", &size);
   	}while(size > MaxSize || size <= MinSize);

    return size;

}//end

void ReadArray(int a[][MaxCol],int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("Insert [%d,%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

}
void DispArray(int a[][MaxCol],int row,int column)
{
      for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

}
void AddArray(int a[][MaxCol],int b[][MaxCol],int c[][MaxCol],int row,int column)
{
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}
void DispArrayT(int a[][MaxCol],int row, int column)
{
    for(int i=0;i<column;i++)
    {
        for(int j=0;j<row;j++)
        {
            printf("%4d",a[j][i]);
        }
        printf("\n");
    }

}
