#include <stdio.h>
#define MaxRow 10 //array-maximum no of rows
#define MinRow 1 //array-minimum no of rows
#define MaxCol 6 //array-maximum no of columns
#define MinCol 1 //array-minimum no of columns


int main()
{
    int RowSizeA,RowSizeB,ColSizeA,ColSizeB;
    int a[MaxRow][MaxCol],//1st input array
     b[MaxRow][MaxCol],//2nd input array
     c[MaxRow][MaxCol];//resulting array

//Functions declaration
        int ReadArraySize(int,int);
       void ReadArray(int [][MaxCol], int, int),
            MulArray(int [][MaxCol], int[][MaxCol],int[][MaxCol], int, int, int, int),
             DispArray(int [][MaxCol], int, int),
              DispArrayT(int [][MaxCol], int, int);
             // optional MulArray(int [][MaxCol], int[][MaxCol], int[][MaxCol], int, int),

    printf("Please specify no. of rows of array A: ");
    RowSizeA=ReadArraySize(MinRow,MaxRow);
    printf("Please specify no. of columns of array A: ");
    ColSizeA=ReadArraySize(MinCol,MaxCol);
    printf("Array A size is set to: [%d] [%d]\n", RowSizeA, ColSizeA);

   printf("Please specify no. of rows of array B: ");
    RowSizeB=ReadArraySize(MinRow,MaxRow);
    printf("Please specify no. of columns of array B: ");
    ColSizeB=ReadArraySize(MinCol,MaxCol);
    printf("Array B size is set to: [%d] [%d]\n", RowSizeB, ColSizeB);

    printf("Read array A\n");
    ReadArray(a, RowSizeA, ColSizeA);//get all value for arrays a (scanf)
    printf("Read array B\n");
    ReadArray(b, RowSizeB, ColSizeB);//get all value for arrays b (scanf)

//multiplying arrays
   printf("Multiplying array A and B\n");
   MulArray(a, b, c, RowSizeA, ColSizeA, RowSizeB, ColSizeB);
   printf("-Array A-\n");
   DispArray(a, RowSizeA, ColSizeA);//display a
   printf("-Array B-\n");
   DispArray(b, RowSizeB, ColSizeB);//display b
   printf("-Array C-\n");
   DispArray(c, RowSizeA, ColSizeB);//display c

    printf( "please type any key to show the transpose: ");
    char ch=getchar();
    scanf("%c%*c",&ch);
    printf("-Transpose of matrix A-\n");
    DispArrayT(a, RowSizeA, ColSizeA);//display a^T
    printf("\n");
    printf("-Transpose of matrix B-\n");
    DispArrayT(b, RowSizeB, ColSizeB);//display b^T
    printf("\n");
    printf("-Transpose of matrix C-\n");
    DispArrayT( c, RowSizeA, ColSizeB);//display c^T
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
void MulArray(int a[][MaxCol],int b[][MaxCol],int c[][MaxCol],int row1,int column1,int row2,int column2)
{
    int sum;
     for(int i=0;i<row1;i++)
    {
        sum=0;
        if(column1!=row2)
        {
            printf("Invalid\n");
            break;
        }
        for(int j=0;j<row1;j++)
        {
            for(int k=0;k<column1;k++)
            {
               sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
            printf("%4d",c[i][j]);
        }
        printf("\n");
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
