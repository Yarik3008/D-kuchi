#include "pch.h"
#include "../D-kuchi/D-heap.h"

TEST(DHeap, can_insert_element)
{
	Dheap<int> h;
	h.insert(10);
	ASSERT_EQ(10, h[0]);
}

TEST(DHeap, can_extract_max_element)
{
	Dheap<double> h;
	h.insert(20.0);
	h.insert(30.0);
	ASSERT_EQ(30, h.extractMax());
}

TEST(DHeap, can_change_priority_up)
{
	Dheap<int> h;
	h.insert(25);
	h.insert(35);
	h.changePriority(1, 40);
	ASSERT_EQ(40, h[0]);
}

TEST(DHeap, can_change_priority_down)
{
	Dheap<int> h;
	h.insert(50);
	h.insert(60);
	h.changePriority(1, 45);
	ASSERT_EQ(60, h[0]);
}

TEST(DHeap, can_get_max_element)
{
	Dheap<int> h;
	h.insert(70);
	h.insert(80);
	ASSERT_EQ(80, h.getMax());
}

TEST(DHeap, can_remove_element)
{
	Dheap<int> h;

	h.insert(90);
	h.insert(100);
	h.remove(1);
	ASSERT_EQ(90, h[0]);
}

TEST(DHeap, can_shift_up_element)
{
	Dheap<int> h;
	h.insert(110);
	h[2] = 120;
	h.shiftUp(2);
	ASSERT_EQ(120, h[0]);
}

TEST(DHeap, can_shift_down_element)
{
	Dheap<int> h;
	h.insert(130);
	h.changePriority(1, 140);
	h.shiftDown(0);
	ASSERT_EQ(140, h[0]);
}

TEST(DHeap, can_return_correct_parent)
{
	Dheap<int> h;
	ASSERT_EQ(2, h.parent(5));
}

TEST(DHeap, can_return_correct_left_child)
{
	Dheap<int> h;
	ASSERT_EQ(9, h.leftChild(4));
}