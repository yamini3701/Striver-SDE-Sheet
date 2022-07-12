class LRUCache {
public:
    class node{
      public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>m;
    
    void addNode(node* newnode)
    {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    void deleteNode(node* deletenode)
    {
        node* deleteprev=deletenode->prev;
        node* deletenext=deletenode->next;
        deleteprev->next=deletenext;
        deletenext->prev=deleteprev;
    }
    
    LRUCache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }
    
    int get(int key_) 
    {
        if(m.find(key_)!=m.end())
        {
            node* resnode=m[key_];
            int res=resnode->val;
            // m.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            m[key_]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value_)
    {
        if(m.find(key_)!=m.end())
        {
            node* existnode=m[key_];
            // m.erase(key_);
            deleteNode(existnode);
            addNode(new node(key_,value_));
            m[key_]=head->next;
        }
        else if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
            addNode(new node(key_,value_));
            m[key_]=head->next;
        }
        else
        {
            addNode(new node(key_,value_));
            m[key_]=head->next;
        }
    }
};
