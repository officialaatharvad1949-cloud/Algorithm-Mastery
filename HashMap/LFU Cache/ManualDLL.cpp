struct Node{
    int key , val , freq;
    Node* prev;
    Node* next;
    Node(int a , int b) : key(a) , val(b) , freq(1) , prev(nullptr) , next(nullptr){}
};
struct DLL{
    int size;
    Node* head;
    Node* tail;

    DLL(){
       size = 0;
       head = new Node(-1 , -1);
       tail = new Node(-1 , -1);
       head->next = tail;
       tail->prev = head;
    }

    void addToHead(Node* node){
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
        size += 1;
    }
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size -=1;
    }
    Node* remove_DLL(){
        if(size == 0) return nullptr;
        Node* to_rmv = tail->prev;
        remove(to_rmv);
        return to_rmv;
    }
};
class LFUCache {
private:
int cap;
int min_freq;

unordered_map<int , Node*> key_value; // < key , Node> pair 
unordered_map<int , DLL*> freq_list; // <key , Doubly linked list of keys>

void update(Node* node){
    int oldfreq = node->freq;
    freq_list[oldfreq]->remove(node);

    if(min_freq == oldfreq && freq_list[oldfreq]->size == 0) min_freq += 1;

    node->freq += 1;
    int newfreq = node->freq;

    if(freq_list.find(newfreq) == freq_list.end()) freq_list[newfreq] = new DLL();

    freq_list[newfreq]->addToHead(node);

}

public:
    LFUCache(int capacity) {
        min_freq = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(key_value.find(key) == key_value.end()) return -1;
        Node* to_get = key_value[key];
        update(to_get);
        return to_get->val;
    }   
    void put(int key, int value) {
        if(cap == 0) return;

        if(key_value.find(key) != key_value.end()){
            Node* to_updt = key_value[key];
            to_updt->val = value;
            update(to_updt);
            return;
        }
        if(cap == key_value.size()){
            Node* evict = freq_list[min_freq]->remove_DLL();
            key_value.erase(evict->key);
            delete evict;
        }
        Node* to_insrt = new Node(key , value);
        key_value[key] = to_insrt;

        if(freq_list.find(1) == freq_list.end()) freq_list[1] = new DLL();

        freq_list[1]->addToHead(to_insrt);
        min_freq = 1;

        
    }
};
