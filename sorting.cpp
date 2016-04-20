#include <fstream>
#include <iostream>
#include <string>
#include <queue> //implemented to use queues
#include <stack> //implemented to use stacks
#include <cstdlib> //implemented to use the atoi

using namespace std;

//template <class T> //Template Declared Class here
void Bubble_sort(vector<int>a,int n){
    int compare = 0;
    int exchange = 0;
    int temp;
    for(int i=0;i<n;i++) {
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){ //descending order
                    temp=a[j];
                    a[j]=a[j+1];  //Swap have been done here
                    a[j+1]=temp;
                    exchange++;}
                    compare++;
                                    }
                         }
    cout<<"Bubble sort: comparisons = "<< compare << ", exchanges = " << exchange <<endl;
}

//template <class T>
void Insertion_sort(vector<int>a,int n)
{int key;
int compare = 0;
int exchange = 0;
for(int i=1;i<n;i++){
        key=a[i];
        int j=i-1;
        while((j>=0)&&(a[j]>key)){
                a[j+1]=a[j];
                j--;//j=j-1;
                exchange++;}
        a[j+1]=key;
        compare++;}
cout<<"Insertion sort: comparisons = "<< compare << ", exchanges = " << exchange <<endl;
}

int partit(vector<int>A,int p,int q){
    int x= A[p];
    int i=p;
    int temp;

    for(int j=p+1; j<q; j++){
        if(A[j]<=x){
            i=i+1;
            temp= A[j];
            A[j]=A[i];
            A[i]=temp;}
    }
    temp= A[p];
    A[p]=A[i];
    A[i]=temp;

    return i;
}

void Quick_sort(vector<int>A, int p,int q){
    int r;
    if(p<q){
        r=partit(A,p,q);
        Quick_sort(A,p,(r-1)); //I think the problem is here this first quickSort call
                              // is reducing the value of r and hence value of q becomes
                              // less than p recursively. How can I separate both calls
                              // one for left and one for right sub array of the pivot.
        Quick_sort(A,(r+1),q);
    }
}

void Shell_sort(vector<int> num, int n){
int i, temp, flag = 1, compare=0, exchange=0, numLength = n;
int d = numLength;
while( flag || (d > 1)){      // boolean flag (true when not equal to 0)
    flag = 0;           // reset flag to 0 to check for future swaps
    d = (d+1) / 2;
    for (i = 0; i < (numLength - d); i++){
        if (num[i + d] > num[i]){
            temp = num[i + d];      // swap positions i+d and i
            num[i + d] = num[i];
            num[i] = temp;
            flag = 1;                  // tells swap has occurred
            exchange++;
              }
              compare++;
         }
     }
      cout<<"Shell sort: comparisons = "<< compare << ", exchanges = " << exchange <<endl;
}

int main(){
	vector<int> numbers; //Create a dynamic array to hold the values
	ifstream in("FewUnique.txt",ios::in); ////Create an input file stream
    int number;  //Variable to hold each number as it is read
    if (!in.is_open()){
        cout << "file doesn't exist" << endl;
    }
    else {
        while (in >> number) { //Read number using the extraction (>>) operator
		numbers.push_back(number); } //Add the number to the end of the array
    }
	//Close the file stream
	in.close();

	Bubble_sort(numbers,10000);
	//Insertion_sort(numbers, 10000);
	//Quick_sort(numbers,0,10000);
	//Shell_sort(numbers,10000);
}
