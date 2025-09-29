#include <iostream>
#include "TDeque.h"

using namespace std;

int main() {
        int choice;
        int item;

        Deque<int>* D = new Deque<int>();
        Node<int>* x; // Because templates are resolved at compile time, not runtime; so you neeed to say which data type right here, you can't say T and let the program figure out, because that would be at runtime.

        do {
                cout << "-----------------------" << endl;
                        D->display();

                        cout << "-----------------------" << endl;
                        cout << "1 - Enqueue at head" << endl;
                        cout << "2 - Dequeue from head" << endl;
                        cout << "3 - Enqueue at tail" << endl;
                        cout << "4 - Dequeue from tail" << endl;
                        cout << "5 - Get size" << endl;
                        cout << "6 - Check if the Deque is empty" << endl;
			cout << "7 - Display Deque" << endl;
			cout << "8 - Exit" << endl;

                        cout << "Enter your choice: ";
                        cin >> choice;
                cout << "-----------------------" << endl;

                switch(choice) {
                        case 1: 
				cout << "Enter data item (integer) to be enqueued at the head: ";
                                cin >> item;
                                x = new Node<int>;
                                x->data = item;
                                x->next = nullptr;
                                x->prev = nullptr;
                                D->EnqueueAtHead(x);
                                break;

                        case 2: 
				D->DequeueFromHead();
                                break;

                        case 3: 
				cout << "Enter data item (integer) to be enqueued at the tail: ";
                                cin >> item;
                                x = new Node<int>;
                                x->data = item;
                                x->next = nullptr;
                                x->prev = nullptr;
                                D->EnqueueAtTail(x);
                                break;

                        case 4: 
				D->DequeueFromTail();
                                break;

                        case 5: 
				D->getSize();
                                break;

                        case 6: 
				D->isEmpty();
				break;

			case 7:
				D->display();
				break;

			case 8:
				break;
                        default: cout << "Enter a valid choice" << endl;
                        break;
                }
        }
        while (choice != 8);

        delete D;
        return 0;
}
