#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//template <class T> //Template Declared Class here
void Bubble_sort(vector<int>a,int n){
    int compare = 0, exchange = 0; // the counters for the comparisons and swaps
    int temp; //hold variable
    for(int i=0;i<n;i++) {
            for(int j=0;j<n-i-1;j++){
                    compare++; // comparing done here, add counter
                if(a[j]>a[j+1]){ //descending order
                    temp=a[j];
                    a[j]=a[j+1];  //Swap have been done here
                    a[j+1]=temp;
                    exchange++;} //since swap done here, add counter for exchange
                                    }
                         }
    cout<<"Bubble sort: comparisons = "<< compare << ", exchanges = " << exchange <<endl;
}

//template <class T>
void Insertion_sort(vector<int>a,int n)
{int key, compare = 0, exchange = 0;
for(int i=1;i<n;i++){
        key=a[i];
        int j=i-1;
        while((j>=0)&&(a[j]>key)){ //compares the vector with key
                a[j+1]=a[j];
                j--;//j=j-1;
                compare++;}
        a[j+1]=key; //if order incorrect swaps it
        exchange++;}
cout<<"Insertion sort: comparisons = "<< compare << ", exchanges = " << exchange <<endl;
}

int Qcompare = 0, Qexchange = 0;
int partit(vector<int> a, int left, int right, int pivotIndex){
    int pivot = a[pivotIndex]; //hold the pivot value
    int compare =0, exchange =0;
    do
    {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left < right && a[left] != a[right]) //comparison
        {
            swap(a[left], a[right]);
            Qexchange++;
        }
        else
        {
            return right;
        }
        Qcompare++;
    }
    while (left < right);
    return right;
}
void Quick_sort(vector<int> a, int left, int right)
{
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partit(a, left, right, pivot);
        Quick_sort(a, left, pivotNew - 1);
        Quick_sort(a, pivotNew + 1, right);
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

int Mcompare =0, Mexchange=0;
void merge1(vector<int> &vec,const vector<int>& left, const vector<int>& right){
    // Fill the resultant vector with sorted results from both vectors
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size()){
        // If the left value is smaller than the right it goes next
        // into the resultant vector
        if(left[left_it] < right[right_it]){
            vec[left_it + right_it] = left[left_it];
            left_it++;
            Mcompare++;}
        else{
            vec[left_it + right_it] = right[right_it];
            right_it++;}
    }
    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size()){
        vec[left_it + right_it] = left[left_it];
        left_it++;
        Mexchange++;}

    while(right_it < right.size()){
        vec[left_it + right_it] = right[right_it];
        right_it++;
        Mexchange++;}
    //show merge process..
     /* int i;
      for(i=0;i<result.size();i++)
         {
	     cout<<result[i]<<" ";
         }
    // break each line for display purposes..
        cout<<"***********"<<endl;*/
}

void Merge_sort(vector<int>& vec){
    // Termination condition: List is completely sorted if it or only contains a single element.
    if(vec.size() == 1){
        return;}

    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    // Perform a merge sort on the two smaller vectors
    Merge_sort(left);
    Merge_sort(right);

    merge1(vec,left, right);
   // cout << "Merge sort: comparisons = " << Mcompare << ", exchanges = " << Mexchange << endl;
}

void printArray(vector<int> thearray, int counter) //function to check and debug
{
    for (int i=0; i<counter; ++i)
    {
        cout << thearray[i] << " ";
    }
    cout << endl;
}

int main(){
	vector<int> numbers; //Create a dynamic array to hold the values
	ifstream in("Reversed.txt",ios::in); ////Create an input file stream
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

    /*vector<int> numbers6; //testing
	int num6[] = {4,2,7,16,6}; //testing
	for(int c=0; c<5; c++){
        numbers6.push_back(num6[c]);
	}

    Quick_sort(numbers6,0,4);
    Bubble_sort(numbers6,5); //swap done..?
    Shell_sort(numbers6,5);
    Insertion_sort(numbers6,5); //done
    Merge_sort(numbers6);
    cout << "Merge sort : comparisons = " << Mcompare << " exchanges = " << Mexchange << endl;
    cout << "Quick sort: comparisons = " << Qcompare << " exchanges = " << Qexchange << endl;
	printArray(numbers6, 5); */

	Bubble_sort(numbers,10000);
	Insertion_sort(numbers, 10000);
	Quick_sort(numbers,0,9999);
	Shell_sort(numbers,10000);
	Merge_sort(numbers);
	cout << "Merge sort : comparisons = " << Mcompare << " exchanges = " << Mexchange << endl;
    cout << "Quick sort: comparisons = " << Qcompare << " exchanges = " << Qexchange << endl;

	/*for (int o =0; 0<numbers.size(); o++){
        cout << numbers[o] << endl;
	}
	cout << numbers.size() << endl;
	cout << numbers[9996] << endl; //for debugging*/
}
