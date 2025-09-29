#include <iostream>
#include "TDLList.h"

using namespace std;

int main() {
        int choice;
        int item;

        DLList<int>* DL = new DLList<int>();
        Node<int>* x; // Because templates are resolved at compile time, not runtime; so you neeed to say which data type right here, you can't say T and let the program figure out, because that would be at runtime.

        do {
                cout << "-----------------------" << endl;
                        DL->traverse();

                        cout << "-----------------------" << endl;
                        cout << "1 - Insert at head" << endl;
                        cout << "2 - Insert at tail" << endl;
                        cout << "3 - Delete at head" << endl;
                        cout << "4 - Delete at tail" << endl;
                        cout << "5 - Traverse" << endl;
                        cout << "6 - Exit" << endl;

                        cout << "Enter your choice: ";
                        cin >> choice;
                cout << "-----------------------" << endl;

                switch(choice) {
                        case 1: cout << "Enter data item (integer) to be inserted: ";
                                cin >> item;
                                x = new Node<int>;
                                x->data = item;
                                x->next = nullptr;
                                x->prev = nullptr;
                                DL->insertHead(x);
                                break;
                        case 2: cout << "Enter data item (integer) to be inserted at the tail: ";
                                cin >> item;
                                x = new Node<int>;
                                x->data = item;
                                x->next = nullptr;
                                x->prev = nullptr;
                                DL->insertTail(x);
                                break;
                        case 3: DL->delHead();
                                break;
                        case 4: DL->delTail();
                                break;
                        case 5:
                                DL->traverse();
                                break;
                        case 6: break;
                        default: cout << "Enter a valid choice" << endl;
                        break;
                }
        }
        while (choice != 6);

        delete DL;
        return 0;
}
