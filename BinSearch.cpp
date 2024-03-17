#include <iostream>
using namespace std;

class IntialSort{
    public:
    //Function to check whether array is sorted
    bool checkSorted(int arr[],int n){
        bool res=true;
        for(int i=n-1;i>0;i--){
            if(arr[i]<arr[i-1]){
                res=false;
                return res;
            }
        }
        return res;
    }
    //Sorting the array before Binary Search, in case unsorted array was entered
    void bubbleSort(int arr[],int n){
        int temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j+1]<arr[j]){
                    temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
};
class BinSearch{
    public:
    //Binary Search iterative approach
    int iterativeBinSearch(int arr[],int n,int se){
        //ub = Upper Bound
        //lb = Lower Bound
        //se = Searching element(key)
        int ub=n-1,lb=0,mid,res=-1;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(arr[mid]==se){
                return mid;
            }
            else{
                if(se<arr[mid]){
                    ub=mid-1;
                }
                else{
                    lb=mid+1;
                }
            }
        }
        return res;
    }
    //Binary Search recursive approach
    int recursiveBinSearch(int arr[],int n,int se,int ub,int lb){
        int res=-1;
        if(lb>ub){
            return -1;
        }
        int mid=(ub+lb)/2;
        if(arr[mid]==se){
            return mid;
        }
        if(se<arr[mid]){
            recursiveBinSearch(arr,n,se,mid-1,lb);
        }
        else{
            recursiveBinSearch(arr,n,se,ub,mid+1);
        }
    }
};

int main(){
    int n;
    cout<<"Enter size of array:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter values in array:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Implementing sorting functions in case of unsorted array
    IntialSort obj;
    if(obj.checkSorted(arr,n)){
        cout<<"Thanks for entering a sorted array.\n\n";

        cout<<"Entered (Sorted) array:";
    }
    else{
        cout<<"Array is'nt sorted.\n.\n.\n.\nLet's sort using Bubble Sort Technique:\n";
        obj.bubbleSort(arr,n);

        cout<<"Entered and then Sorted array:";
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int se;
    cout<<"Enter Element to be searched:\n";
    cin>>se;

    BinSearch ob;
    int res;

    //Using switch to choose method of Binary Search implementation
    int choice;
    cout<<"Enter 1 to choose iterative approach for Binary search.\n";
    cout<<"Enter 2 to choose recursive approach for Binary search.\n";
    cin>>choice;

    switch(choice){
        case 1:
            res=ob.iterativeBinSearch(arr,n,se);
            break;
        case 2:
            res=ob.recursiveBinSearch(arr,n,se,n-1,0);
            break;
        default:
            cout<<"Invalid choice.\n";
    }

    if(res!=(-1)){
        cout<<"Element found. At position "<<(res+1)<<".\n";
    }
    else{
        cout<<"Element not found.\n";
    }

    return 0;
}