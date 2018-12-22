#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../App3_lab/Heap.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestHeap
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_Contains_True)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) heap->insert(i);
			for (int i : arrayForTree) Assert::IsTrue(heap->contains(i));

		}

		TEST_METHOD(Test_Contains_False)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) heap->insert(i);
			Assert::IsFalse(heap->contains(22));
			for (int i : arrayForTree) Assert::IsTrue(heap->contains(i));
		}

		TEST_METHOD(Test_Contains_Empty)
		{
			Heap *heap = new Heap();
			Assert::IsFalse(heap->contains(22));
		}


		TEST_METHOD(Test_Insert_True)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) heap->insert(i);
			heap->insert(10);
			std::vector<int> WaitedArr;

			WaitedArr.push_back(30);
			WaitedArr.push_back(18);
			WaitedArr.push_back(13);
			WaitedArr.push_back(10);
			WaitedArr.push_back(6);
			WaitedArr.push_back(3);
			WaitedArr.push_back(11);
			WaitedArr.push_back(2);
			WaitedArr.push_back(9);

			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Insert_TrueEmpty)
		{
			Heap *heap = new Heap();
			int arrayForTree[5];
			for (int i : arrayForTree) heap->insert(i);
			heap->insert(10);
			std::vector<int> WaitedArr;

			WaitedArr.push_back(10);

			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Insert_newRoot)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(40);
			WaitedArr.push_back(30);
			WaitedArr.push_back(18);
			WaitedArr.push_back(13);
			WaitedArr.push_back(9);
			WaitedArr.push_back(6);
			WaitedArr.push_back(3);
			WaitedArr.push_back(11);
			WaitedArr.push_back(2);

			heap->insert(40);

			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));


		}


		TEST_METHOD(Test_Remove)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(18);
			WaitedArr.push_back(13);
			WaitedArr.push_back(9);
			WaitedArr.push_back(6);
			WaitedArr.push_back(3);
			WaitedArr.push_back(2);

			heap->remove(11);

			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));

		}

		TEST_METHOD(Test_Remove_Empty)
		{

			Heap *heap = new Heap();
			int arrayForTree[5];

			std::vector<int> WaitedArr;


			heap->remove(11);


			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));

		}

		TEST_METHOD(Test_Remove_OneElem)
		{

			Heap *heap = new Heap();
			int arrayForTree[] = { 6 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;

			heap->remove(6);

			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));

		}

		TEST_METHOD(Test_Remove_twoExecuteElem)
		{

			Heap *heap = new Heap();
			int arrayForTree[] = { 1,2,7,10,20,30,7 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(30);
			WaitedArr.push_back(20);
			WaitedArr.push_back(10);
			WaitedArr.push_back(2);
			WaitedArr.push_back(1);


			heap->remove(7);
			heap->remove(7);

			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));


		}


		TEST_METHOD(Test_Remove_Root)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 7,3,4,12,9,40,14,20 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(20);
			WaitedArr.push_back(14);
			WaitedArr.push_back(9);
			WaitedArr.push_back(7);
			WaitedArr.push_back(3);
			WaitedArr.push_back(12);
			WaitedArr.push_back(4);

			heap->remove(heap->getRootKey());

			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));


		}

		TEST_METHOD(Test_Bft_Iterator)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(30);
			WaitedArr.push_back(18);
			WaitedArr.push_back(13);
			WaitedArr.push_back(9);
			WaitedArr.push_back(6);
			WaitedArr.push_back(3);
			WaitedArr.push_back(11);
			WaitedArr.push_back(2);
			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Bft_Iterator_OneElem)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 30 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(30);
			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Bft_Iterator_Empty)
		{
			Heap *heap = new Heap();
			std::vector<int> WaitedArr;
			std::vector<int> RealArr;
			for (auto tmp = heap->createBft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Equals_True)
		{
			Heap *heap = new Heap();
			std::vector<int> RealArr;
			RealArr.push_back(1);
			RealArr.push_back(2);
			RealArr.push_back(3);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(1);
			WaitedArr.push_back(2);
			WaitedArr.push_back(3);
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Equals_False)
		{
			Heap *heap = new Heap();
			std::vector<int> RealArr;
			RealArr.push_back(1);
			RealArr.push_back(2);
			RealArr.push_back(3);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(1);
			WaitedArr.push_back(2);
			Assert::IsFalse(heap->Equals(WaitedArr, RealArr));
		}

		TEST_METHOD(Test_Equals_Empty)
		{
			Heap *heap = new Heap();
			std::vector<int> RealArr;
			std::vector<int> WaitedArr;
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_TreeSort)
		{
			Heap *heap = new Heap();
			heap->insert(10);
			heap->insert(0);
			heap->putRootLeftKey(20);
			heap->TreeSort(heap->getRootLeft());
			Assert::AreEqual(20, heap->getRootKey());
		}

		TEST_METHOD(Test_TreeSort_False)
		{
			Heap *heap = new Heap();
			heap->insert(10);
			heap->insert(0);
			heap->putRootLeftKey(20);
			heap->TreeSort(heap->getRootLeft());
			Assert::AreEqual(10, heap->getRootLeftKey());
		}
		TEST_METHOD(Test_Dft_Iterator)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(2);
			WaitedArr.push_back(9);
			WaitedArr.push_back(18);
			WaitedArr.push_back(6);
			WaitedArr.push_back(30);
			WaitedArr.push_back(3);
			WaitedArr.push_back(13);
			WaitedArr.push_back(11);
			std::vector<int> RealArr;
			for (auto tmp = heap->createDft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Dft_Iterator_OneElem)
		{
			Heap *heap = new Heap();
			int arrayForTree[] = { 30 };
			for (int i : arrayForTree) heap->insert(i);
			std::vector<int> WaitedArr;
			WaitedArr.push_back(30);
			std::vector<int> RealArr;
			for (auto tmp = heap->createDft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

		TEST_METHOD(Test_Dft_Iterator_Empty)
		{
			Heap *heap = new Heap();
			std::vector<int> WaitedArr;
			std::vector<int> RealArr;
			for (auto tmp = heap->createDft_Iterator(); tmp->has_next(); tmp->next())
				RealArr.push_back(tmp->current());
			Assert::IsTrue(heap->Equals(RealArr, WaitedArr));
		}

	};
}