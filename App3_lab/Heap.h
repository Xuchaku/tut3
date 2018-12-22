#pragma once
#include "stdafx.h"
#include "iterator.h"
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;
class Heap {
private:
	class Node {
	public:
		int key;
		Node* left, *right, *parent, *next;
		Node(int key = 0, Node * left = nullptr, Node* right = nullptr, Node* parent = nullptr, Node* next = nullptr) {
			this->key = key;
			this->left = left;
			this->right = right;
			this->parent = parent;
			this->next = next;
		}
		~Node() {
			if (right) delete right;
			if (left) delete left;
		}
	};
//Для тестирования перенести след. методы в public

	Node* getRoot();
	Node* getRootLeft();
	bool Equals(vector<int> bigger, vector<int>smaller);
	int getRootLeftKey();
	bool containsHelp(Node* node, int found);
	void putRootLeftKey(int);
	void printHelp(Node *node, size_t);
	int getRootKey();
	void TreeSort(Node *elem);
	

	
	void removeHelp(int value, Node * node);
	

	class List {
	public:
		int size;
		Node * head;
		Node * tail;
		List(int size = 0, Node * head = nullptr, Node * tail = nullptr) {
			this->size = size;
			this->head = head;
			this->tail = tail;
		}
		~List() {}
		void add_first(Node * elem);

		bool isEmpty();
		Node* back();
		Node* front();
		void push_back(Node * elem); 
		void push_front(Node * elem); 
		void pop_back();
		void pop_front(); 

	};

	class Bft_Iterator : public Iterator {
		List * currentNodes = new List;
		
	public:
		Bft_Iterator(Heap::Node *root) {
			if (root)
				currentNodes->push_back(root);
		}
		void next();
		int current();
		bool has_next();
	};

	class Dft_Iterator : public Iterator {
		List * currentNodes = new List;
	
	public:
		Dft_Iterator(Node *root) {
			if (root) {
				Node *current = root;
				currentNodes->push_back(root);
				while (current = current->left)
					currentNodes->push_back(current);
			}
		}
		void next();
		int current();
		bool has_next();
	};
	Node* root;
	Node* last;
	Node* prevlast;

	public:


	void print();
	void remove(int value);
	bool contains(int);
	void insert(int);
//


	
	Heap(Node*root = nullptr, Node*last = nullptr) {
		this->root = root;
		this->last = last;
	}
	~Heap()
	{
		delete root;
	}
	Iterator *createDft_Iterator();
	Iterator *createBft_Iterator();
	
	
};
