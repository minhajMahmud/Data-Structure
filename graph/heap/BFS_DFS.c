#include <stdio.h>

#define MAX 5 // Replace with desired maximum number of vertices

void breadth_first_search(int adj[][MAX], int visited[], int start)
{
  int queue[MAX], rear = 0, front = 0, i, k;

  // Initialize visited array
  for (k = 0; k < MAX; k++)
  {
    visited[k] = 0;
  }

  // Enqueue starting vertex and mark visited
  queue[rear++] = start;
  visited[start] = 1;

  while (rear > front)
  {
    // Dequeue current vertex
    start = queue[front++];
    printf("%c ", start + 65); // Assuming vertices are represented by characters A-Z

    // Explore and enqueue unvisited neighbors
    for (i = 0; i < MAX; i++)
    {
      if (adj[start][i] == 1 && visited[i] == 0)
      {
        queue[rear++] = i;
        visited[i] = 1;
      }
    }
  }
}

void depth_first_search(int adj[][MAX], int visited[], int start)
{
  int stack[MAX], top = -1, i, k;

  // Initialize visited array
  for (k = 0; k < MAX; k++)
  {
    visited[k] = 0;
  }

  // Push starting vertex
  stack[++top] = start;
  // Mark visited after pushing as DFS may go back and visit again

  visited[start] = 1;

  while (top != -1)
  {
    // Pop current vertex
    start = stack[top--];
    printf("%c ", start + 65);

    // Explore and push unvisited neighbors
    for (i = 0; i < MAX; i++)
    {
      if (adj[start][i] == 1 && visited[i] == 0)
      {
        stack[++top] = i;
        visited[i] = 1;
      }
    }
  }
}

int main()
{
  int visited[MAX] = {0};
  int adj[MAX][MAX], i, j;
  int option, size;
  do
  {
    printf("\n 1. Enter values in graph");
    printf("\n 2. BFS Traversal");
    printf("\n 3. DFS Traversal");
    printf("\n 4. Exit");
    printf("\n\n Enter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("\n Enter the adjacency matrix:\n");
      for (i = 0; i < MAX; i++)
      {
        for (j = 0; j < MAX; j++)
        {
          scanf("%d", &adj[i][j]);
        }
      }
      break;
    case 2:
      printf("BFS Traversal: ");
      breadth_first_search(adj, visited, 0); // Assuming starting vertex is 0
      printf("\n");
      break;
    case 3:
      printf("DFS Traversal: ");
      depth_first_search(adj, visited, 0); // Assuming starting vertex is 0
      printf("\n");
      break;
    case 4:
      printf("\n Exiting...\n");
      break;
    default:
      printf("\n Invalid option. Please enter again.\n");
      break;
    }
  } while (option != 4);

  return 0;
}
