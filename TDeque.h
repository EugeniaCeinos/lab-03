#ifndef TDEQUE_H
#define TDEQUE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
        public:
                T data;
                Node<T>* next;
                Node<T>* prev;
};

template <typename T>
class Deque {
        private:
                Node<T>* head;
                Node<T>* tail;
		int size;
        public: 
                Deque() {
                        head = nullptr;
                        tail = nullptr;
			size = 0;
                }


                void EnqueueAtHead(Node<T>* x) {
                        if (head == nullptr) {
                                head = tail = x;  // head and tail are pointers so they store the address of x
                                x->prev = nullptr;
                                x->next = nullptr;
                        }
                        else {
                                x->next = head;
                                x->prev = nullptr;
                                head->prev = x;   // old head(node) points to the current head, because head holds the address of the old head
                                head = x;   // update head
                        }
			size++;
                }


		void DequeueFromHead() {
                        if (head == nullptr) {
                                cout << "The Doubly-Linked List is empty" << endl;
                                return;
                        }
                        Node<T>* temp = head; // outside if statement so in both cases temp is deleted afterwards.
                        if (head == tail) {
                                head = tail = nullptr;
                        }
                        else {
                                head = head->next;  // update head to next in line.
                                head->prev = nullptr;
                        }
                         delete temp;
			 size--;
                }


                void EnqueueAtTail(Node<T>* x) {
                        if (tail == nullptr) {
                                head = tail = x;  // if the list is empty just add the new node, which head and tail will be pointing to
                                x->next = nullptr;
                                x->prev = nullptr;
                        }
                        else {
                                x->next = nullptr;
                                x->prev = tail;
                                tail->next = x; // old tail which is the address of the last node will now point to the new tail, which is the node x just added.
                                tail = x;
                        }
			size++;
                }


                void DequeueFromTail() {
                        if (tail == nullptr) {
                                cout << "The Doubly-Linked List is empty" << endl;
                                return;
                        }
                        Node<T>* temp = tail;
                        if (head == tail) {
                                head = tail = nullptr;
                        }
                        else {
                                tail = tail->prev;
                                tail->next = nullptr;
                        }

                        delete temp;
			size--;
                }


		void getSize() {
			cout << "The size of the Deque is " << size << endl;;
		}	

		void isEmpty() {
			if (head == nullptr) {
				cout << "The Deque is empty" << endl;
			}
			else {
				cout << "The Deque is not empty" << endl;
			}
		}

                void display() {
                        if (head == nullptr) {
                                cout << "The Doubly Linked List is empty" << endl;
                        }
                        else {
                                Node<T>* curr = head;
                                while (curr != nullptr) {
                                        cout << "[" << curr->data << "] ";
                                        curr = curr->next;
                                }
                                cout << endl;
                        }
                }


                ~Deque() {
                        Node<T>* curr = head;
                        while (curr != nullptr) {
                                Node<T>* temp = curr;
                                curr = curr->next;
                                delete temp;
                        }
                }
};


#endif
