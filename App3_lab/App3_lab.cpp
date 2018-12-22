#include "stdafx.h"
#include "Heap.h"
#include <stdexcept>
#include <iostream>


using namespace std;

int main() {
	Heap *heap = new Heap();
	int arrayForTree[7] = { 70, 12, 3, 8, 11,4, 2};
	for (int i = 0; i < 7;i++) 
		heap->insert(arrayForTree[i]);
	heap->print();
	heap->remove(8);
	cout << "remove "<<8;
	cout << endl<<endl<<endl;
	heap->print();



	system("pause");
}