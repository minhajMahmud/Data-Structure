#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
} List;

typedef struct Graph
{
    int num_vertices;
    List *adj_lists;
} Graph;
Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Graph *initializeGraph(int num_vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adj_lists = malloc(sizeof(List) * num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        graph->adj_lists[i].head = NULL;
    }
    return graph;
}
void addEdge(Graph *graph, int source, int destination)
{
    Node *newNode = createNode(destination);

    // Add node to the source's adjacency list
    newNode->next = graph->adj_lists[source].head;
    graph->adj_lists[source].head = newNode;

    // For undirected graphs, add edge in the opposite direction as well
    newNode = createNode(source);
    newNode->next = graph->adj_lists[destination].head;
    graph->adj_lists[destination].head = newNode;
}

// Prints the adjacency list representation of the graph
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        printf("Vertex %d: ", i);
        Node *temp = graph->adj_lists[i].head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int num_vertices, source, destination;

    // Get number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    // Initialize graph
    Graph *graph = initializeGraph(num_vertices);

    // Read edges until both source and destination are -1
    do
    {
        printf("Enter the edge (source, destination): ");
        scanf("%d %d", &source, &destination);

        // Check for valid input within range
        if (source < 0 || source >= num_vertices || destination < 0 || destination >= num_vertices)
        {
            printf("Invalid vertex: Please enter values between 0 and %d.\n", num_vertices - 1);
            continue;
        }

        // Add edge between source and destination
        addEdge(graph, source, destination);
    } while (source != -1 && destination != -1);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    return 0;
}
