/*A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. Obtain a data representation mapping a deque into a 
one- dimensional array. Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.*/


#include <iostream>
#define MAX 10
using namespace std;
struct que{
    int front,rear,arr[MAX];
};

class deQue{
    struct que q;
    public:
    deQue(){
        q.front = q.rear =-1;
    }

    int isEmpty();
    int isFull();
    void addF(int);
    void addR(int);
    int delF();
    int delR();
    int display();
};

int deQue::isEmpty(){
    return (q.front==q.rear==-1)?1:0;
}

int deQue::isFull(){
    return (q.front=q.rear+1)?1:0;
}

void deQue::addF(int x){
    if(!isFull()){
        q.rear=q.front=0;
        q.arr[q.front] = x;
    }
    else{
        q.front = (q.front-1)%MAX;
        q.arr[q.front] = x;
    }
}

void deQue::addR(int x){
    if(!isFull()){
        q.rear=q.front=0;
        q.arr[q.rear] = x;
    }
    else{
        q.rear = (q.rear+1)%MAX;
        q.arr[q.rear] = x;
    }
}

int deQue::delF(){
        int x1;
        x1 = q.arr[q.front];
        if(q.rear==q.front){
            q.front=q.rear=-1;
        }
        else{
        q.front = (q.front+1)%MAX;
        return x1;
        }
}

int deQue::delR(){
        int x1;
        x1 = q.arr[q.rear];
        if(q.front==q.rear){
            q.front=q.rear=-1;
        }
        else{
        q.rear = (q.rear-1)%MAX;
        return x1;
        }
}


int deQue:: display(){
    // int i;
    // i = q.front;
    // while(i!=q.rear){
    // cout<<"\t"<<q.arr[i];
    // i = (i+1)%MAX;
    // }
    // cout<<"\t"<<q.arr[q.rear];
    int i;
    i=q.front;
    while(i!=q.rear)
    {
        cout<<"\t"<<q.arr[i];
        i=(i+1)%MAX;
    }
    cout<<"\t"<<q.arr[q.rear];
}

int main(){
    deQue q1;
    int ch,x,x1;
    do{
        cout<<"\n1.Add front\n2.Add rear\n3.Del front\n4.Del rear\n5.Display\n6.Exit\nEnter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\nEnter data to add:";
                cin>>x;
                q1.addF(x);
                break;
            case 2:
                cout<<"\nEnter data to add:";
                cin>>x;
                q1.addR(x);
                break;
            case 3:
                if(q1.isEmpty()){
                    cout<<"\nDequeue is empty";
                }
                else{
                    q1.delF();
                }
                break;
            case 4:
                if(q1.isEmpty()){
                    cout<<"\nDequeue is empty";
                }
                else{
                    q1.delR();
                }
                break;
            case 5:
                if(q1.isEmpty()){
                    cout<<"\nDequeue is empty";
                }
                else{
                    cout<<"\nDequeue elements are:";
                    q1.display();
                }
                break;
            case 6:
                cout<<"Thanks";
            default: cout<<"Invalid choice";
            }
    }while(ch!=6);
    return 0;
}

