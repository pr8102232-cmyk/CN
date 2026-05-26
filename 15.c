#include <stdio.h>

#define N 4
#define MAX 1000

// Goal State
int goal[N][N] =
{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12},
    {13,14,15,0}
};

// Node Structure
struct Node
{
    int mat[N][N];

    int x, y;

    int cost;
    int level;

    int parent;
};

// Node storage
struct Node nodes[MAX];

int nodeCount = 0;

// Priority Queue
int pq[MAX];

int size = 0;

// Print Matrix
void printMatrix(int mat[N][N])
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(mat[i][j] == 0)
                printf("   ");
            else
                printf("%2d ", mat[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

// Copy Matrix
void copyMatrix(int source[N][N],
                int dest[N][N])
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}

// Heuristic Function
// Counts misplaced tiles
int calculateCost(int mat[N][N])
{
    int i, j;

    int count = 0;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(mat[i][j] != 0 &&
               mat[i][j] != goal[i][j])
            {
                count++;
            }
        }
    }

    return count;
}

// Check valid move
int isSafe(int x, int y)
{
    return (x >= 0 && x < N &&
            y >= 0 && y < N);
}

// Total Cost
int totalCost(int index)
{
    return nodes[index].cost +
           nodes[index].level;
}

// Insert into Heap
void push(int index)
{
    int i = size;

    pq[size++] = index;

    while(i > 0 &&
          totalCost(pq[(i - 1) / 2]) >
          totalCost(pq[i]))
    {
        int temp;

        temp = pq[i];

        pq[i] = pq[(i - 1) / 2];

        pq[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

// Remove Minimum Cost Node
int pop()
{
    int root;

    root = pq[0];

    pq[0] = pq[--size];

    int i = 0;

    while(1)
    {
        int left = 2 * i + 1;

        int right = 2 * i + 2;

        int smallest = i;

        if(left < size &&
           totalCost(pq[left]) <
           totalCost(pq[smallest]))
        {
            smallest = left;
        }

        if(right < size &&
           totalCost(pq[right]) <
           totalCost(pq[smallest]))
        {
            smallest = right;
        }

        if(smallest == i)
            break;

        int temp;

        temp = pq[i];

        pq[i] = pq[smallest];

        pq[smallest] = temp;

        i = smallest;
    }

    return root;
}

// Solve Puzzle
void solvePuzzle(int initial[N][N],
                 int x,
                 int y)
{
    int row[] = {-1, 1, 0, 0};

    int col[] = {0, 0, -1, 1};

    int i;

    // Create Root Node
    copyMatrix(initial,
               nodes[nodeCount].mat);

    nodes[nodeCount].x = x;

    nodes[nodeCount].y = y;

    nodes[nodeCount].level = 0;

    nodes[nodeCount].cost =
        calculateCost(initial);

    nodes[nodeCount].parent = -1;

    push(nodeCount);

    nodeCount++;

    while(size > 0)
    {
        int current;

        current = pop();

        // Print Current State
        printf("Step %d:\n\n",
               nodes[current].level);

        printMatrix(nodes[current].mat);

        // Goal Reached
        if(nodes[current].cost == 0)
        {
            printf("Goal State Reached\n");

            return;
        }

        // Generate Children
        for(i = 0; i < 4; i++)
        {
            int newX;

            int newY;

            newX = nodes[current].x +
                   row[i];

            newY = nodes[current].y +
                   col[i];

            if(isSafe(newX, newY))
            {
                // Copy Current Matrix
                copyMatrix(nodes[current].mat,
                           nodes[nodeCount].mat);

                // Swap Blank Tile
                int temp;

                temp =
                nodes[nodeCount].mat
                [nodes[current].x]
                [nodes[current].y];

                nodes[nodeCount].mat
                [nodes[current].x]
                [nodes[current].y]

                =
                nodes[nodeCount].mat
                [newX][newY];

                nodes[nodeCount].mat
                [newX][newY]

                = temp;

                // Fill Child Details
                nodes[nodeCount].x = newX;

                nodes[nodeCount].y = newY;

                nodes[nodeCount].level =
                    nodes[current].level + 1;

                nodes[nodeCount].cost =
                    calculateCost(
                    nodes[nodeCount].mat);

                nodes[nodeCount].parent =
                    current;

                // Insert Child
                push(nodeCount);

                nodeCount++;
            }
        }
    }
}

int main()
{
    int initial[N][N];

    int i, j;

    int x, y;

    printf("Enter initial puzzle:\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d",
                  &initial[i][j]);

            if(initial[i][j] == 0)
            {
                x = i;

                y = j;
            }
        }
    }

    solvePuzzle(initial, x, y);

    return 0;
}
