/*
    Use Hash Table to accelerate get()
    Use two-end List to manage use list.  
*/
#include <iostream>
#include <stdio.h>
using namespace std;

class LRUCache{
public:
	struct item {
		item():key(-1), value(0), prev(NULL), next(NULL), hash_prev(NULL), hash_next(NULL){};
		int key;
		int value;
		item* prev;
		item* next;
        item* hash_prev;
        item* hash_next;
	};
    static const int HASH_SIZE = 2048;
    item* hash[HASH_SIZE];   
	item *head;
	item *tail;
	int count;
	int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        head = new item;
        tail = new item;
        head->next = tail; head->prev = NULL;
        tail->prev = head; tail->next = NULL;
        int i;
        for (i = 0; i < HASH_SIZE; i++) {
            hash[i] = new item;
        }
    }
    void adjust(item* p) {
    	p->prev->next = p->next;
    	p->next->prev = p->prev;
    	p->next = head->next;
    	head->next->prev = p;
    	head->next = p;
    	p->prev = head;
    }
    int get(int key) {
    	item *p = hash[key%HASH_SIZE]->hash_next;
    	while (p != NULL) {
    		if (p->key == key) {
    			adjust(p);
    			return p->value;
    		}
    		p = p->hash_next;
    	}
    	return -1;
    }
    
    void set(int key, int value) {
    	item *p = head->next;
    	while (p != NULL) {
    		if (p->key == key) {
    			p->value = value;
    			adjust(p);
    			return;
    		}
    		p = p->next;
    	}
        //insert new item into use queue
    	item *t = new item;
    	t->key = key;
    	t->value = value;
    	t->next = head->next;
    	t->prev = head;
    	head->next->prev = t;
    	head->next = t;
        //insert new item into hash table
        p = hash[key % HASH_SIZE];
        while (p->hash_next != NULL) 
            p = p->hash_next;
        p->hash_next = t;
        t->hash_prev = p;

        count++;
        //remove if full
    	if (count > capacity) {
    		count--;
    		p = tail->prev;
    		p->prev->next = tail;
    		tail->prev = p->prev;
            p->hash_prev->hash_next = p->hash_next;
            if (p->hash_next != NULL) {
                p->hash_next->hash_prev = p->hash_prev;
            }
    		delete(p);
    	}

    }
};
int main() {
	LRUCache cache(2);
	cache.set(2, 1);
	cache.set(2, 2);
    cout<<cache.get(2)<<endl;
	cache.set(1, 1);
	cache.set(4, 1);
	cout<<cache.get(2)<<endl;
	return 0;
}