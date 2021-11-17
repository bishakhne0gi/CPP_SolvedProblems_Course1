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
};

int main(){
    List l;
    l.push_front(30);
    l.push_front(20);
    l.push_back(15);
    l.insert(10,0);
    l.pop_front();
    l.pop_back();
    Node *head=l.begin();
    cout<<l.getCount(head);
    cout<<endl;
    while(head != NULL)
    {
        cout<<head->getData()<<"->";
        head=head->next;
    }
    cout<<endl;
    int key;
    cin>>key;
    Node *k=l.begin();
    cout<<l.l_search(k,key)<<endl;

    
    return 0;
}