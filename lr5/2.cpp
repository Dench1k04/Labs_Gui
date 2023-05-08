#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "conio.h"
using namespace std;

int MyFunc(int MyArr[25]);

int main() {
    int arr[25];

    cout << "Eneter elements:\n";
    for (int i = 0; i != 25; i++) {
        cin >> arr[i];
    }


    cout << "Max len: " << MyFunc(arr);
}

int MyFunc(int MyArr[25]) {
    int count = 0, max = 0;
    for (int i = 0; i != 25; i++) {
        if (MyArr[i + 1] < MyArr[i]) {
            count++;
            if (count > max) {
                max = count;
            }
        }
        else{
            count = 0;
        }
    }
    return max;
}
void main()
{
int a[20],i,n,sum=0,sreda=0;
printf("Enter size of massive \n"); //количество эл. в массиве
scanf_s("%d", &n);
for(i=0;i<n;i++)
a[i]=rand()%100; //числа генерируются рандомно

for(i=0;i<n-1;i++)
sum=a[i]+a[i+1];
sreda=sum/n
printf("%d",sreda);
_getch();
}
int main() 
{
	int mass[N], max, min;

	cout << "Элементы: |";
	for(int r = 0; r<N; r++)
	{
		mass[r] = rand()%99;
		cout << mass[r] << "|";
	}
	cout << endl;
	
	max = mass[0];
	min = mass[0];
	for(int r = 1; r<N; r++)
	{
		if(max < mass[r]) max = mass[r];
		if(min > mass[r]) min = mass[r];
	}
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	
	return 0;
}
int main( )
{    
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,20};
 
    const int coutNumber = 4;
 
    for(int q = coutNumber - 1; q < ARRAY_LENGTH(A) ; q += coutNumber)
    {
        cout << A[q] << "\n";
    }
    system( "pause" );
    return 0;
}
