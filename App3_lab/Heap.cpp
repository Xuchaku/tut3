#include "stdafx.h"
#include "Heap.h";
#include "iterator.h";
#include <iostream>
#include <vector>
using namespace std;

Iterator * Heap::createDft_Iterator() {
	return new Dft_Iterator(root);
}


void Heap::Dft_Iterator::next() {
	Node *back = currentNodes->back();
	currentNodes->pop_back();

	if (back = back->right) {
		currentNodes->push_back(back);
		while (back = back->left)
			currentNodes->push_back(back);
	}
}

int Heap::Dft_Iterator::current() {
	return currentNodes->back()->key;
}

bool Heap::Dft_Iterator::has_next() {
	return !currentNodes->isEmpty();
}


Iterator * Heap::createBft_Iterator()
{
	return new Bft_Iterator(root);
}



void Heap::Bft_Iterator::next() {
	Node* current = currentNodes->front();
	currentNodes->pop_front();
	if (current->left) currentNodes->push_back(current->left);
	if (current->right) currentNodes->push_back(current->right);
}

int Heap::Bft_Iterator::current() {
	return currentNodes->front()->key;
}

bool Heap::Bft_Iterator::has_next() {
	return	!currentNodes->isEmpty();
}
void Heap::insert(int newElem)
{
	Node *elem = new Node;
	elem->key = newElem;
	if (root == nullptr)
	{
		root = elem;
		prevlast = last;
		last = elem;
	}
	else
	{
		Node *current = last;
		while ((current->parent != nullptr) && (current == current->parent->right))
			current = current->parent;

		if (current->parent != nullptr)
		{
			if (current->parent->right != nullptr)
			{
				current = current->parent->right;
				while (current->left != nullptr)
					current = current->left;
			}

			else {
				current->parent->right = elem;
				prevlast = last;
				last = elem;
				elem->parent = current->parent;
				elem->left = nullptr;
				elem->right = nullptr;
				TreeSort(last);
				return;
			}
		}
		else

		{
			while (current->left != nullptr)
				current = current->left;
		}

		if (current->left == nullptr)
		{
			current->left = elem;
			prevlast = last;
			last = current->left;
		}
		

		elem->parent = current;
		elem->left = nullptr;
		elem->right = nullptr;
	}
	TreeSort(last);
}


void Heap::removeHelp(int value, Node *node)
{
	if (!root)return;
	if (root && !root->left && !root->right) { root = nullptr; }
	else {
		if (node->left != nullptr && node->key != value)
		{
			removeHelp(value, node->left);
		}
		if (node->right != nullptr &&node->key != value)
		{

			removeHelp(value, node->right);
		}

		if (node != nullptr && node->key == value)
		{


			node->key = last->key;
			Node *help = node->right;
			Node *help1 = node->left;

			TreeSort(help);
			TreeSort(help1);
			if (last == last->parent->left)
				last->parent->left = nullptr;
			if (last == last->parent->right)
				last->parent->right = nullptr;
			TreeSort(prevlast);
			last = prevlast;
		}
	}
}

void Heap::remove(int value)
{
	removeHelp(value, root);
}





bool Heap::Equals(vector<int> bigger, vector<int> smaller)
{
	int issame = 0;

	for (auto c : bigger)
	{
		for (auto d : smaller)
		{
			if (c == d)
			{
				++issame;
			}
		}
	}
	if (issame >= smaller.size())
		return true;
	else return false;
}

void Heap::TreeSort(Node *elem)
{
	while (elem && (elem->parent != nullptr) && (elem->key > elem->parent->key))
	{
		int temp = elem->key;

		if (elem->key > elem->parent->key)
		{
			elem->key = elem->parent->key;
			elem->parent->key = temp;
		}
		elem = elem->parent;
	}
}



bool Heap::containsHelp(Node* node, int found)
{
	if (node == nullptr) return false;
	if (node->key == found) {
		return true;
	}
	else if (node->left == nullptr && node->right == nullptr && node->key != found) {
		return  false;
	}
	else {
		bool va1 = false;
		bool va2 = false;
		if (node->left != nullptr) {
			va1 = containsHelp(node->left, found);
		}
		if (node->right != nullptr) {
			va2 = containsHelp(node->right, found);
		}
		return va1 || va2;
	}

}

bool Heap::contains(int found)
{
	return containsHelp(root, found);
}

void Heap::List::push_front(Node*elem)
{
	if (size == 0) {
		add_first(elem);
	}
	else {
		elem->next = head;
		head = elem;
	}
	size++;
}


void Heap::List::pop_back()
{
	if (size == 0) return;

	if (size == 1) {
	
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node * current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		
		tail = current;
	}
	size--;
}

void Heap::List::pop_front()
{
	if (size == 0) return;

	if (size == 1) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node * current = head->next;

		head = current;
	}
	size--;
}


void Heap::List::add_first(Heap::Node*elem)
{
	head = elem;
	tail = head;
}

bool Heap::List::isEmpty()
{
	if (size == 0)return true;
	else return false;

}

Heap::Node * Heap::List::back()
{
	if (tail)return tail;
	else return nullptr;
}


Heap::Node * Heap::List::front()
{
	return head;
}


void Heap::List::push_back(Node*elem)
{
	if (size == 0) {
		add_first(elem);
	}
	else {
		tail->next = elem;
		tail = tail->next;
	}
	size++;
}
void Heap::printHelp(Node *node, size_t level) {
	if (node)
	{
		printHelp(node->right, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->key << endl;
		printHelp(node->left, level + 1);
	}
}


void Heap::print()
{
	printHelp(root, 1);
}



Heap::Node * Heap::getRoot()
{
	return root;
}

int Heap::getRootKey()
{
	return root->key;

}

Heap::Node * Heap::getRootLeft()
{
	return root->left;
}

int Heap::getRootLeftKey()
{
	return root->left->key;
}

void Heap::putRootLeftKey(int elem)
{
	root->left->key = elem;
}


