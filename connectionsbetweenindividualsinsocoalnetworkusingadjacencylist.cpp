//#include<iostream>
//using namespace std;
//
//struct node {
//    char connection;
//    node* next;
//    node(char c) {
//        connection = c;
//        next = nullptr;
//    }
//};
//
//class adjacencylist {
//    static const int size = 8;
//    node* list[size];
//    char* vertices;
//
//public:
//    adjacencylist(char* ver) {
//        for (int i = 0; i < size; i++) {
//            list[i] = nullptr;
//        }
//        vertices = new char[size];
//        for (int i = 0; i < size; i++) {
//            vertices[i] = ver[i];
//        }
//    }
//
//    void makeedge(char ch1, char ch2) {
//        for (int i = 0; i < size; i++) {
//            if (vertices[i] == ch1) {
//                insert(ch2, i);
//            }
//        }
//    }
//
//    void insert(char ch2, int i) {
//        node* newnode = new node(ch2);
//        if (list[i] == nullptr) {
//            list[i] = newnode;
//        }
//        else {
//            newnode->next = list[i];
//            list[i] = newnode;
//        }
//    }
//
//    int findconnections() {
//        int max = 0, previous = 0;
//        int count = 0;
//        for (int i = 0; i < size; i++) {
//            count = 0;
//            node* current = list[i];
//            while (current != nullptr) {
//                count++;
//                current = current->next;
//            }
//            if (count > previous) {
//                max = i;
//                previous = count;
//            }
//        }
//        return max;
//    }
//    bool bip
//};
//
//int main() {
//    char vertices[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
//    adjacencylist graph(vertices);
//    int maxNode;
//    int choice;
//    char ch1, ch2;
//
//    do {
//        cout << "\nMenu:\n";
//        cout << "1. Make Edge\n";
//        cout << "2. Find Node with Maximum Connections\n";
//        cout << "3. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter the vertices for the edge (e.g., AB):  and p to stop";
//            cin >> ch1 >> ch2;
//            while (ch1 != 'P') {
//                graph.makeedge(ch1, ch2);
//                cin >> ch1 >> ch2;
//            }
//            break;
//
//        case 2:
//            maxNode = graph.findconnections();
//            cout << "Node with Maximum Connections: " << vertices[maxNode] << endl;
//            break;
//
//        case 3:
//            cout << "Exiting program.\n";
//            exit(0);
//            break;
//
//        default:
//            cout << "Invalid choice. Please try again.\n";
//        }
//
//    } while (true);
//
//    return 0;
//}
