struct Node {
    int key, val, cnt;
    Node *next; 
    Node *prev;
    Node (int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List {
    Node * head;
    Node * tail;
    int size;

    List () {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    void addFront(Node * newnode) {
        newnode->prev = head;
        newnode->next = head->next;
        head->next = newnode;
        head->next->next->prev = newnode;
        size++;
    }

    void removeNode(Node * deletenode) {
        Node * delprev = deletenode->prev;
        Node * delnext = deletenode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
    public:
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;

    public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqListMap(Node * node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];    
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node * node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if (keyNode.find(key) != keyNode.end()) {
            Node * node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else {
            if (currSize == maxSizeCache) {
                List * list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List * listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }

            Node * node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */