struct Node{
    int key; 
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
  private:
  int cap;
  Node* head ;
  Node* tail ;
  unordered_map<int , Node*> hashmap;
  void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
  public:

  LRUCache(int capacity) {
    cap = capacity;
    head = new Node(-1 , -1);
    tail = new Node(-1 , -1);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key_) {
    if(hashmap.find(key_) == hashmap.end()) return -1;
    Node* ele = hashmap[key_];
    remove(ele);
    insertAtHead(ele);
    return ele->val;
 
  }

  void put(int key_, int value) {
    if(hashmap.find(key_) != hashmap.end()){
        Node* ele = hashmap[key_];
        ele->val = value;
        remove(ele);
        insertAtHead(ele);
        return;
    }
    if(hashmap.size() == cap){
        Node* to_be_dlt = tail->prev;
        hashmap.erase(to_be_dlt->key);
        remove(to_be_dlt);
        delete(to_be_dlt);
    }
    Node* to_insert = new Node(key_ , value);
    insertAtHead(to_insert);
    hashmap[key_] = to_insert;
    
  
  }
  ~LRUCache(){
    Node* current = head;
    while(current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
  }
};
