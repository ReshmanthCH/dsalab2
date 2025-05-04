#include <iostream>
using namespace std;
#define size 10

class heap{
    private:
        int arr[size];
        int cur;
        int count;
    public:
        heap(){
            count=0;
            cur= -1;
        }
        void heapifyup();
        void heapifydown(int);
        void heapsort(int);
        void insert(int);
        void del(); 
        void search(int);
        void sort();
        void display();
};


int main(){
    int loop=0;
    heap h1;
    int num;
    while (loop==0){
        int ch;
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter the number to be inserted:";   
                cin>>num;
                h1.insert(num);
                break;
            case 2:
                h1.del();
                break;
            case 3:
                h1.display();
                break;
            case 4:
                cout<<"Enter the number to be searched:";
                cin>>num;
                h1.search(num);
                break;
            case 5:
                h1.sort();
                break;
            case 6:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
        }
    }
}


void heap::heapifydown(int i){
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if (left<=cur && arr[left]>arr[largest]){
        largest=left;
    }
    if (right<=cur && arr[right]>arr[largest]){
        largest=right;
    }
    if (largest != i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapifydown(largest);
    }
}


void heap::heapifyup(){
    int temp=cur;
    while (temp>0 && arr[(temp-1)/2]<arr[temp]){
        int swap=arr[temp];
        arr[temp]=arr[(temp-1)/2];
        arr[(temp-1)/2]=swap;
        temp=(temp-1)/2;
    }
}


void heap::insert(int num){
    count++;
    if (count==0){
        cout<<"\nThe array is full\n\n";
        return;
    }
    cur++;
    arr[cur]=num;
    
    heapifyup();
}


void heap::del(){
    arr[0]=arr[cur];
    cur--;
    heapifydown(0);
}


void heap::search(int num){
    for (int i=0;i<=cur;i++){
        if (arr[i]==num){
            cout<<"\nElement Found\n\n";
            return;
        }
    }
    cout<<"\nElement Not Found\n\n";
}


void heap::display(){
    cout<<"\n";
    for (int i=0;i<=cur;i++){
        cout<<arr[i]<<",";
    }
    cout<<"\n\n";
}

void heap::sort(){
    int temparr[size];
    int tempcur=cur;
    for (int i=0;i<=cur;i++){
        temparr[i]=arr[i];
    }
    
    for (int i = tempcur; i >= 0; i--) {
        swap(temparr[0], temparr[i]);
        int root = 0;
        int largest;
        while (true){
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            largest = root;

            if (left < i && temparr[left] > temparr[largest]) {
                largest = left;
            }
            if (right < i && temparr[right] > temparr[largest]) {
                largest = right;
            }
            if (largest != root) {
                swap(temparr[root], temparr[largest]);
                root = largest;
            } 
            else{
                break;
            }
        } 
    }
    cout << "\nSorted Heap:\n";
    for (int i = 0; i <= tempcur; i++) {
        cout << temparr[i] << ", ";
    }
    cout << "\n\n";
}
