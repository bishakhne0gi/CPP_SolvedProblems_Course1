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
        
};

int main(){
    List l;
    l.push_front(30);
    l.push_front(20);
    l.push_back(15);
    l.insert(10,1);
    l.pop_front();
    Node *head=l.begin();
    while(head != NULL)
    {
        cout<<head->getData()<<"->";
        head=head->next;
    }
    int key;
    cin>>key;
    Node *k=l.begin();
    cout<<l.l_search(k,key)<<endl;
    return 0;
}