#include <bits/stdc++.h>
using namespace std;
class List;
class Node
{
    int data;
    public:
        Node * next;
        Node(int d):data(d),next(NULL){}

        int getData(){
            return data;
        }
        friend class List;
};
class List
{
     Node * head;
    Node * tail;
    
    public: 
       
        List():head(NULL),tail(NULL){}

        Node * begin()
        {
            return head;
        }

        void push_front(int data)
        {
            if(head== NULL)
            {
                Node * n =new Node(data);
                head=tail=n;
                return;
            }
            else
            {
                Node * n = new Node(data);
                n->next=head;
                head=n;
            }
        }

        void push_back(int data)
        {
            if(head== NULL)
            {
                Node * n =new Node(data);
                head=tail=n;
                return;
            }
            else
            {
                Node * n = new Node(data);
                tail->next=n;
                tail=n;
            }
        }
        void insert(int data, int pos)
        {
            if(pos==0){
                push_front(data);
                return;
            }
            Node *temp = head;
            for(int jump=1; jump<=pos-1; jump++)
            {
                temp= temp->next;
            }
            Node * n = new Node(data);
            n->next=temp->next;
            temp->next=n;
        }
        bool l_search(Node* head, int key)
        {
            Node * temp = head;
            while(temp!= NULL)
            {
                if(head->data==key)
                {
                    return true;
                }
                head=head->next;
            }
            return false;
        }
        void pop_front()
        {
            Node * temp = head;
            head = head->next;
            temp->next=NULL;
            delete temp;
        }
        int getCount(Node* head) 
        { 
            int count = 0; 
            Node* current = head; 
            while (current != NULL) 
            { 
                count++; 
                current = current->next; 
            } 
            return count; 
        } 
        void pop_back()
        {
            int n=getCount(head);
            Node *temp = head;
            for(int jump=1; jump< n-1; jump++)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp->next;
        }
        void traversal(Node * head)
        {
            while(head != NULL)
            {
                cout<<head->getData()<<"->";
                head=head->next;
            }
            cout<<endl;
        }
        void reverse()
        {
            Node * prev= NULL;
            Node * current=head;
            Node * temp;
            while(current!=NULL)
            {
                temp=current->next;
                current->next=prev;
                prev=current;
                current=temp;
            }
            head=prev;
        }
};

int main(){
    List l;
    Node *head=l.begin();
    // cout<<"1.Push Back 2.Push Front 3.Input at specific position 4.Pop Back 5.Pop Front 6.Traversal 7.Count no. of nodes 8.Search 9.Exit"<<endl;
    int choice;
    int info;
    int pos;
    int key;
    do{
        cout<<"1.Push Back 2.Push Front 3.Input at specific position 4.Pop Back 5.Pop Front 6.Traversal 7.Count no. of nodes 8.Search 9.Reverse 10.Exit"<<endl;
        cout<<"Enter the choice: "<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Input: "<<endl;
            cin>>info;
            l.push_back(info);
            break;
        case 2:
            cout<<"Input: "<<endl;
            cin>>info;
            l.push_front(info);
            break;
        case 3:
            cout<<"Enter the data: "<<endl;
            cin>>info;
            cout<<"Enter the pos: "<<endl;
            cin>>pos;
            l.insert(info,pos);
            break;
        case 4:
            cout<<"popped back"<<endl;
            l.pop_back();
            break;
        case 5:
            cout<<"popped front"<<endl;
            l.pop_front();
            break;
        case 6:
            head=l.begin();
            cout<<"The nodes are: "<<endl;
            l.traversal(head);
            cout<<endl;
            break;
        case 7:
            head=l.begin();
            cout<<"No. of nodes: "<<endl;
            cout<<l.getCount(head)<<endl;
            break;

        case 8:
            cout<<"Enter the element to be searched: "<<endl;
            cin>>key;
            if(l.l_search(head,key)==true)
                cout<<"Element Found:"<<endl;
            else
                cout<<"Not found"<<endl;
            break;
        case 9:
          
            l.reverse();
            break;
        default:
            cout<<"Wrong Choice!"<<endl;
        }
    }while(choice!=10);
    cout<<endl;
    return 0;
}