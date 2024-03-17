#include <iostream>
using namespace std;

class ArrangingSol{
    public:
        void RotateForwardByArrayIn0(int arr[],int n){
            int fv=arr[0];
            int temp;
            if(fv>(n/2))
            {
                int arr1[fv];
                for(int i=0;i<(fv%n);i++){
                    arr1[i]=arr[(i+fv)%n];
                    arr[(i+fv)%n]=arr[i];
                }
                for(int i=0;i<n-(fv%n);i++){
                    arr[i+((2*fv)%n)]=arr1[i];
                }
            }
            else{
                for(int i=0;i<(fv%n);i++)
                {
                    temp=arr[(i+fv)%n];
                    arr[(i+fv)%n]=arr[i];
                    arr[i]=temp;
                }
                for(int i=fv;i<n-(fv%n);i++){
                    temp=arr[(i+fv)%n];
                    arr[(i+fv)%n]=arr[fv-1];
                    arr[fv-1]=temp;
                }
            }
        }
};
int main(){
    int n;
    cout<<"Enter array size:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter values to array:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Values entered:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    ArrangingSol ob;
    ob.RotateForwardByArrayIn0(arr,n);

    cout<<"New rotated array:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}