cmake_minimum_required(VERSION 3.31)
project(DSA C)

set(CMAKE_C_STANDARD 11)

add_executable(Stack 01.Stack/main.c
        01.Stack/stack.c
        01.Stack/stack.h)

add_executable(Queue 02.Queue/main.c
        02.Queue/queue.c
        02.Queue/queue.h
)

add_executable(CircularQueue 03.CircularQueue/main.c
        03.CircularQueue/circularQueue.c
        03.CircularQueue/circularQueue.h)

add_executable(SinglyLinkedList 04.SinglyLinkedList/main.c
        04.SinglyLinkedList/linkedList.c
        04.SinglyLinkedList/linkedList.h)


add_executable(DoublyLinkedList 05.DoublyLinkedList/main.c
        05.DoublyLinkedList/doublyLinkedList.c
        05.DoublyLinkedList/doublyLinkedList.h)

add_executable(PriorityQueue 06.PriorityQueue/main.c
        06.PriorityQueue/priority_queue.c
        06.PriorityQueue/priority_queue.h)

add_executable(TreeTraversal 07.TreeTraversal/main.c
        07.TreeTraversal/tree_traversal.c
        07.TreeTraversal/tree_traversal.h)

add_executable(BinarySearchTree 08.BinarySearchTree/main.c
        08.BinarySearchTree/binary_search_tree.c
        08.BinarySearchTree/binary_search_tree.h)


add_executable(HashTable 09.HashTable/main.c
        09.HashTable/hast_table.c
        09.HashTable/hast_table.h)

add_executable(DynamicList 10.DynamicList/main.c
        10.DynamicList/dynamic_list.c
        10.DynamicList/dynamic_list.h)
