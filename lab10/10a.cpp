#include <iostream>
#include <vector>
using namespace std;

void polycrap();

int main(){
    int t;
    cout<<"Enter test case:";
    cin>>t;
    while (t--){
        polycrap();
    }
}

void polycrap(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector <int> arr;
    for (int i=0;i<n;i++){
        int val;
        cout<<"Enter value:";
        cin>>val;
        arr.push_back(val);
    }
    int count=0;
    while (true){
        int duplicate=0;
        for (int i=0;i<arr.size();i++){
            for (int j=i+1;j<arr.size();j++){
                if (arr[i]==arr[j]){
                    duplicate=1;
                    break;
                }
            }
            if (duplicate==1){
                break;
            }
        }

        if (duplicate==0){
            break;
        }
        arr.erase(arr.begin());
        count++;
        
    }
    cout<<count<<endl;
}
