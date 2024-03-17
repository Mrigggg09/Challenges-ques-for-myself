#include <iostream>
using namespace std;

class BinSearch{
    public:
    int iterativeBinSearch(int arr[],int n,int se){
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
    int se;
    cout<<"Enter Element to be searched:\n";
    cin>>se;

    BinSearch ob;
    int res;

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
}