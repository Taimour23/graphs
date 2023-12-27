#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<climits>
using namespace std;

class Graph {
    int** adjacencyMatrix;
    int size;
    int num;
    int* vertices;
public:
    Graph(int s) {
        num = 0;
        size = s;
        vertices = new int[size];
        adjacencyMatrix = new int* [size];
        for (int i = 0; i < size; i++) {
            adjacencyMatrix[i] = new int[size];
            vertices[i] = i;
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }
        
    }
    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 2; i >= 0; i--) {
            for (int j = 0; j < size; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void bfstraversal(int startingnode) {
        bool* visited = new bool[size];
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
        int* queue = new int[size], current;
        int front = -1, rear = -1;
        queue[++rear] = --startingnode;
        while (front != rear) {
            current = queue[++front];
            cout << 1+current << "  ";
            visited[current] = true;
            for (int i = 0; i < size; i++) {
                if (adjacencyMatrix[current][i]==1 && !visited[i]) {
                    if (rear < size - 1) {
                        visited[i] = true;
                        queue[++rear] = i;
                    }
                }
            }
        }
        cout << endl;
        delete[] visited;
        delete[] queue;
    }
    void bfstraversalforshortestdistancebetween2nodes(int startingnode,int endingnode) {
        bool check = false;;
        bool* visited = new bool[size]; 
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
        int* queue = new int[size], current;
        int front = -1, rear = -1;
        queue[++rear] = startingnode;
        while (front != rear) {
            //check = false;
            current = queue[++front];
            cout << current << "  ";
            visited[current-1] = true;
            if (adjacencyMatrix[current-1][endingnode-1] != 0) {
                cout << endingnode << endl;
                check = true;
            }
            if (check != true) {
                for (int i = 0; i < size; i++) {
                    if (adjacencyMatrix[current-1][i] == 1 && !visited[i]) {
                        if (rear < size - 1) {
                            visited[i] = true;
                            queue[++rear] = i+1;
                        }
                    }
                }
            }
        }

        cout << endl;
        delete[] visited;
        delete[] queue;
    }
    void primsalgorithem(int startingnode) {
        bool* visited = new bool[size];
        int* array = new int[size];
        int* parent = new int[size];

        for (int i = 0; i < size; i++) {
            visited[i] = false;
            array[i] = INT_MAX;
            parent[i] = -1;
        }

        int index = --startingnode;
        array[index] = 0;

        while (!empty(visited)) {
            int u = extractmin(array, visited);
            visited[u] = true;
            //   cout << u + 1 << "  ";
            for (int i = 0; i < size; i++) {
                if (adjacencyMatrix[u][i] && !visited[i] && adjacencyMatrix[u][i] < array[i]) {
                    parent[i] = u;
                    array[i] = adjacencyMatrix[u][i];
                }
            }
        }

        cout << "Minimum Spanning Tree (MST) using Prim's algorithm:" << endl;
        for (int i = 0; i < size; i++) {
            if (parent[i] != -1) {
                cout << parent[i] + 1 << " - " << i + 1 << " : " << adjacencyMatrix[parent[i]][i] << endl;
            }
        }

        delete[] visited;
        delete[] array;
        delete[] parent;
    }

    int bfstraversalforfindinglevelofnode(int node) {
      int startingnode = 1;
        bool* visited = new bool[size];
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
        int* queue = new int[size], current;
        int front = -1, rear = -1;
        queue[++rear] = --startingnode;
        while (front != rear) {
            //check = false;
            current = queue[++front];
          //  cout << 1 + current << "  ";
            visited[current] = true;
            for (int i = 0; i < size; i++) {
                if (adjacencyMatrix[current][i] == 1 && !visited[i]) {
                    if (rear < size - 1) {
                        visited[i] = true;
                        queue[++rear] = i;
                    }
                }
            }
        }
        if (node<size) {
            if (visited[node] == true) {
                return ((node +1)/ 2);
            }
        }
        else {
            return -1;
        }
        cout << endl;
        delete[] visited;
        delete[] queue;
    }
    void print(char** temp) {
        for (int i = 14; i >= 0; i--) {
            for (int j = 0; j < 15; j++) {
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }
    }
    int getindex(int data) {
        for (int i = 0; i < size; i++) {
            if (vertices[i] == data) {
                return i;
            }
        }
    }
    void dfs(int start) {
        int node = 0;
        int* stack = new int[size];
        bool* visited = new bool[size];
        for (int i = 0; i < size; i++) {
            stack[i] = 0;
            visited[i] = false;
        }
        int index = getindex(start);
        cout << start<<"  ";
        int secondindex = -1;
        visited[index] = true;
        for (int i = 0; i < size; i++) {
            if (adjacencyMatrix[index][i] != 0) {
                if (secondindex < size - 1) {
                    stack[++secondindex] = vertices[index];
                    node = vertices[i];
                    break;
                }
            }
        }
        while (secondindex != -1) {
            index = getindex(node);
            if (visited[index]) {
                node = stack[secondindex--];
                index = getindex(node);
            }
            if (!visited[index]) {
                cout << node << "  ";
            }
            visited[index] = true;
            for (int i = 0; i < size; i++) {
                if (adjacencyMatrix[index][i] != 0 && !visited[i]) {
                    if (secondindex < size - 1) {
                        stack[++secondindex] = vertices[index];
                        node = vertices[i];
                        break;
                    }
                }
            }
        }
    }
    bool empty(bool* vis) {
        for (int i = 0; i < size; i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
    int findMinDistanceNode(const int* dis, const int* stack, int index) {
        int minDist = INT_MAX;
        int minDistNode = -1;

        for (int i = 0; i <= index; ++i) {
            int node = stack[i];
            if (dis[node] < minDist) {
                minDist = dis[node];
                minDistNode = node;
            }
        }

        return minDistNode;
    }
    bool stackcheck(int node ,int* stack) {
        
        for (int i = 0; i < size; i++) {
            if (stack[i] == node) {
                return true;
            }
        }
        return false;
    }
    int extractmin(int* arr, bool* visit) {
        int min = INT_MAX;
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] < min && !visit[i]) {
                min = arr[i];
                index = i;
            }
        }
        return index;
    }
    int getCost(int innitial, int next) {
        if (next == innitial + 1 || next == innitial + 2) {
            return 2;
        }
        else {
            return 3;
        }

    }
    void dijkstraAlgorithm(int startingNode) {
        bool* visited = new bool[size];
        int* array = new int[size];
        int* parent = new int[size];

        for (int i = 0; i < size; i++) {
            visited[i] = false;
            array[i] = INT_MAX;
            parent[i] = -1;
        }


        int index = --startingNode;
        array[index] = 0;

        while (!empty(visited)) {
            int u = extractmin(array, visited);
            visited[u] = true;
            cout << u + 1 << "  ";
            for (int i = 0; i < size; i++) {
                if (adjacencyMatrix[u][i] != 0 && !visited[i] && array[u] + adjacencyMatrix[u][i] < array[i]) {
                    array[i] = adjacencyMatrix[u][i] + array[u];
                    parent[i] = u;
                }
            }
        }

        cout << "Minimum Spanning Tree (MST) using dijextra algorithm:" << endl;
        for (int i = 0; i < size; i++) {
            if (parent[i] != -1) {
                cout << parent[i] + 1 << " - " << i + 1 << " : " << adjacencyMatrix[parent[i]][i] << endl;
            }
        }
        cout << endl;
        delete[] visited;
        delete[] array;
        // ... (rest of your code)
    }
    void readAdjacencyMatrixFromFile(const string& filename) {
        ifstream file;
        file.open(filename);
        //char line;
        if (!file.is_open()) {
            cerr << "Error: Unable to open the file.\n";
            return;
        }

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                file >> adjacencyMatrix[i][j];
            }
        }
        file.close();
    }
    void addEdge(int node1, int node2, int weight) {
        adjacencyMatrix[node1][node2] = weight;
        //if (node1 >= 1 && node1 <= size && node2 >= 1 && node2 <= size) {
            // Assuming the graph is undirected, if it's directed, you might want to set the reverse edge as well.
           // adjacencyMatrix[node2 - 1][node1 - 1] = weight;
       // }
       /* else {
            cerr << "Invalid node indices.\n";
        }*/
    }
};
int main() {
    int choice, node1 = 0, node2 = 0, weight = 0, startingNode = 0, graphSize = 4;
    Graph graph(graphSize);
    do {
        cout << "\nMenu:\n1. Display Adjacency Matrix\n2. Add Edge\n3. BFS Traversal\n4. DFS Traversal\n5. Dijkstra's Algorithm\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            graph.displayAdjacencyMatrix();
            break;
        case 2:
            cout << "Enter the nodes and weight for the edge (node1 node2 weight): ";
            cin >> node1 >> node2 >> weight;
            graph.addEdge(node1, node2, weight);
            break;
        case 3:
            int end;
            cout << "Enter the starting node for BFS: ";
            cin >> startingNode;
            cout << "Enter the ending node: ";
            cin >> end;
            cout << "BFS Traversal starting from node " << startingNode << ": ";
            graph.bfstraversalforshortestdistancebetween2nodes(startingNode, end);
            break;
        case 4:
            cout << "Enter the starting node for DFS: ";
            cin >> startingNode;
            cout << "DFS Traversal starting from node " << startingNode << ": ";
            graph.dfs(startingNode);
            cout << endl;
            break;
        case 5:
            cout << "Enter the starting node for Dijkstra's Algorithm: ";
            cin >> startingNode;
            graph.dijkstraAlgorithm(startingNode);
            break;
        case 6:
            cout << "Exiting program.\n";
            exit(1);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);
    return 0;
}
