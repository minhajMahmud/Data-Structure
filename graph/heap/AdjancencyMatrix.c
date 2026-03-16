#include <stdio.h>
int main()
{
    int no_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &no_vertices);
    // Initialize adjacency matrix
    int adj[no_vertices][no_vertices];
    for (int i = 0; i < no_vertices; i++)
    {
        for (int j = 0; j < no_vertices; j++)
        {
            adj[i][j] = 0;
        }
    }
    // Read edges until both source and destination are -1
    int source, destination;
    do
    {
        printf("Enter the edge (source, destination): ");
        scanf("%d %d", &source, &destination);

        // Check for valid input within range
        if (source < 0 || source >= no_vertices || destination < 0 || destination >= no_vertices)
        {
            printf("Invalid vertex: Please enter values between 0 and %d.\n", no_vertices - 1);
            continue;
        }
        // Set edges for both directions in an undirected graph
        adj[source][destination] = 1;
        adj[destination][source] = 1;
    } while (source != -1 && destination != -1);
    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < no_vertices; i++)
    {
        for (int j = 0; j < no_vertices; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
