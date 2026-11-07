#include <bits/stdc++.h>

using namespace std;

struct Node {
	Node * next, * prev;
	int key, data;
};

class LRUCache {
public:

	unordered_map<int, Node*> map;
	Node *head, *tail;
	int capacity;
	int size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        map.reserve(capacity);
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
    	if (map.find(key) == map.end()) {
    		return -1;
    	}

    	Node *t = map.at(key);
    	moveToFront(t);
        return t->data;
    }
    
    void put(int key, int value) {

    	if (map.find(key) == map.end()) { // new value

    		if (this->size == this->capacity) { // max capacity, remove LRU cache
		    	Node * t = this->tail;
		    	map.erase(t->key);
		    	removeTail();
    		} else { // else, increment the capacity.
    			this->size++;
    		}

    		// Add the new node.
    		Node * t = createNode(key, value);
    		map[key] = t; 
    		insertFront(t);
    		return;

    	} else { // existing value, update value, move node to front.
		    Node *t = map.at(key);
		    t->data = value;
		    moveToFront(t);
    	}
    }

    Node * createNode(int key, int data) {
    	Node * node = new Node();
	    node->prev = nullptr;
	    node->next = nullptr;
	    node->data = data;
	    node->key = key;

	    return node;
    }

    void removeTail() {
    	Node * t = this->tail;

    	if (t->prev == nullptr) { // is at head
    		this->head = nullptr;    	
    		this->tail = nullptr;	
    	} else {
    		t->prev->next = nullptr;
    		this->tail = t->prev;
    	}

    	delete t;
    }

    void insertFront(Node * key) {

    	if (this->head == nullptr) {
    		this->head = key;
    		this->tail = key;
    		return;
    	}

    	this->head->prev = key;
    	key->next = this->head;
    	this->head = key;
    }

    // precondition key must exist in node.
    void moveToFront(Node *key) {
    	Node * prev = key->prev;
    	Node * next = key->next;

    	if (prev == nullptr) { // key is already in front.
    		return;
    	}

    	if (next != nullptr) {
    		next->prev = prev;
    	} else {
    		this->tail = prev;
    	}

    	prev->next = next;

    	this->head->prev = key;
    	key->next = this->head;
    	this->head = key;
    	key->prev = nullptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */