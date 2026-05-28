

Pasted text(13).txt
Document
GIVE ONE BY ONE

Let’s start with Lab 1 & Lab 2 – Problem 1 one by one.
The problem is based on Stack Data Structure. 


Problem Summary
A parking garage has:

Only 1 lane

Maximum 10 cars

One entrance and exit

If a car in the middle wants to leave:

Cars in front are temporarily removed

Target car leaves

Other cars are restored back in same order

You must:

Handle Arrival (A) and Departure (D)

Print messages

Count how many times a car was moved

Logic Used
We use:

Main Stack → Parking garage

Temporary Stack → To move blocking cars

Example
Suppose garage is:

Top -> KA04
       KA03
       KA02
       KA01
If KA02 wants to leave:

Remove KA04

Remove KA03

Remove KA02

Put back KA03

Put back KA04

Moved count of KA02 = 2

Complete C Program
#include <stdio.h>
#include <string.h>

#define MAX 10

struct Car
{
    char plate[20];
    int moveCount;
};

struct Car garage[MAX];
int top = -1;

void arrival(char num[])
{
    if(top == MAX - 1)
    {
        printf("Garage Full! Car %s cannot enter.\n", num);
        return;
    }

    top++;

    strcpy(garage[top].plate, num);
    garage[top].moveCount = 0;

    printf("Car %s arrived and parked.\n", num);
}

void departure(char num[])
{
    if(top == -1)
    {
        printf("Garage Empty!\n");
        return;
    }

    struct Car temp[MAX];
    int tempTop = -1;
    int found = 0;

    while(top != -1)
    {
        if(strcmp(garage[top].plate, num) == 0)
        {
            found = 1;

            printf("Car %s departed.\n", num);
            printf("It was moved %d times.\n",
                   garage[top].moveCount);

            top--;
            break;
        }
        else
        {
            garage[top].moveCount++;

            temp[++tempTop] = garage[top];
            top--;
        }
    }

    if(!found)
    {
        printf("Car %s not found.\n", num);
    }

    while(tempTop != -1)
    {
        garage[++top] = temp[tempTop--];
    }
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Garage Empty\n");
        return;
    }

    printf("\nCars in Garage:\n");

    for(i = top; i >= 0; i--)
    {
        printf("%s (Moved %d times)\n",
               garage[i].plate,
               garage[i].moveCount);
    }
}

int main()
{
    int choice;
    char num[20];

    while(1)
    {
        printf("\n1. Arrival");
        printf("\n2. Departure");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Car Number: ");
                scanf("%s", num);

                arrival(num);
                break;

            case 2:
                printf("Enter Car Number: ");
                scanf("%s", num);

                departure(num);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
Sample Output
1. Arrival
2. Departure
3. Display
4. Exit
Enter choice: 1

Enter Car Number: KA01
Car KA01 arrived and parked.

Enter choice: 1
Enter Car Number: KA02
Car KA02 arrived and parked.

Enter choice: 1
Enter Car Number: KA03
Car KA03 arrived and parked.

Enter choice: 3

Cars in Garage:
KA03 (Moved 0 times)
KA02 (Moved 0 times)
KA01 (Moved 0 times)

Enter choice: 2
Enter Car Number: KA01

Car KA01 departed.
It was moved 2 times.
Time Complexity
Arrival
Only one push operation:

O
(
1
)
O(1)
Departure
May need to move all cars:

O
(
n
)
O(n)
where n = number of cars

Important Viva Questions
Why Stack is used?
Because parking follows LIFO (Last In First Out).

Why temporary stack is needed?
To temporarily store blocking cars while removing the target car.

Maximum capacity?
10 cars.

Which data structure principle is used?
LIFO principle.

Next I can explain:

Line-by-line code explanation

Algorithm

Flowchart

Dry run

Lab 3 Problem 2

Send:

NEXT

when ready.


NEXT

Now let’s move to Lab 3 – Problem 2 (Computer System Simulation using Queue). 


Problem Summary
A computer can process:

Only one transaction at a time

Users arrive at different times

Each user has:

User ID

Starting time

Multiple transaction durations

System follows:

FCFS (First Come First Serve)
FCFS (First Come First Serve)
You must:

Simulate execution

Print transaction start/end times

Calculate average waiting time

Real-Life Understanding
Suppose:

User	Arrival Time	Transactions
U1	0	5, 3
U2	2	4
Meaning:

U1 arrives at time 0

Transaction1 = 5 sec

Transaction2 = 3 sec

U2 arrives at time 2

Transaction1 = 4 sec

Since only one process runs at a time:

Others must wait in queue

Data Structure Used
We use:

Queue

FCFS Scheduling

Complete C Program
#include <stdio.h>

struct User
{
    int id;
    int arrival;
    int transCount;
    int duration[10];
};

int main()
{
    int n, i, j;

    struct User u[10];

    int currentTime = 0;
    int totalWaiting = 0;
    int totalTransactions = 0;

    printf("Enter number of users: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter User ID: ");
        scanf("%d", &u[i].id);

        printf("Enter arrival time: ");
        scanf("%d", &u[i].arrival);

        printf("Enter number of transactions: ");
        scanf("%d", &u[i].transCount);

        printf("Enter transaction durations:\n");

        for(j = 0; j < u[i].transCount; j++)
        {
            scanf("%d", &u[i].duration[j]);
        }
    }

    printf("\n--- Simulation Start ---\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < u[i].transCount; j++)
        {
            int requestTime;

            if(j == 0)
                requestTime = u[i].arrival;
            else
                requestTime = currentTime;

            if(currentTime < requestTime)
            {
                currentTime = requestTime;
            }

            int waiting = currentTime - requestTime;

            totalWaiting += waiting;
            totalTransactions++;

            printf("\nUser %d Transaction %d START at time %d",
                   u[i].id, j + 1, currentTime);

            currentTime += u[i].duration[j];

            printf("\nUser %d Transaction %d END at time %d\n",
                   u[i].id, j + 1, currentTime);
        }
    }

    printf("\nAverage Waiting Time = %.2f seconds\n",
           (float)totalWaiting / totalTransactions);

    return 0;
}
Sample Input
Enter number of users: 2

Enter User ID: 1
Enter arrival time: 0
Enter number of transactions: 2
Enter transaction durations:
5 3

Enter User ID: 2
Enter arrival time: 2
Enter number of transactions: 1
Enter transaction durations:
4
Step-by-Step Execution
User 1 Transaction 1
Arrival = 0

Starts at:

0
0
Duration = 5

Ends at:

0
+
5
=
5
0+5=5
User 1 Transaction 2
Previous transaction ended at 5

Starts at:

5
5
Duration = 3

Ends at:

5
+
3
=
8
5+3=8
User 2 Transaction 1
Arrived at time 2

But CPU free at time 8

Waiting time:

8
−
2
=
6
8−2=6
Starts at:

8
8
Ends at:

8
+
4
=
12
8+4=12
Output
--- Simulation Start ---

User 1 Transaction 1 START at time 0
User 1 Transaction 1 END at time 5

User 1 Transaction 2 START at time 5
User 1 Transaction 2 END at time 8

User 2 Transaction 1 START at time 8
User 2 Transaction 1 END at time 12

Average Waiting Time = 2.00 seconds
Formula Used
Waiting Time
Waiting Time
=
Start Time
−
Request Time
Waiting Time=Start Time−Request Time
Average Waiting Time
Average Waiting Time
=
Total Waiting Time
Total Transactions
Average Waiting Time= 
Total Transactions
Total Waiting Time
​
 
Time Complexity
If:

n = users

m = transactions

Then:

O
(
m
)
O(m)
because every transaction is processed once.

Important Viva Questions
Which scheduling algorithm is used?
FCFS (First Come First Serve)

Which data structure is suitable?
Queue

Why queue?
Because transactions are processed in arrival order.

Can two transactions execute simultaneously?
No.

Only one transaction at a time.

What is waiting time?
Time between request and actual execution.

What is turnaround time?
Completion Time
−
Arrival Time
Completion Time−Arrival Time
Next we can do:

Lab 4 Problem 3
(Factory Simulation)

OR line-by-line explanation of this code

Send:

NEXT


NEXT

Now let’s move to Lab 4 – Problem 3 (Factory Simulation). 


Problem Summary
A factory produces items in 2 stages:

Assembly

Polishing

Conditions:

10 workers

Only 1 polishing machine initially

Worker cannot start next item until polishing is finished

If machine busy → worker waits

You must compute:

Average waiting time per item

For:

1 polishing machine

2 polishing machines

3 polishing machines

Important Concepts
Uniform Distribution
Assembly time:

100
 to 
300
 seconds
100 to 300 seconds
Means any value between 100–300 can occur equally.

We generate using:

rand() % 201 + 100
because:

300
−
100
+
1
=
201
300−100+1=201
Normal Distribution
Polishing time:

Mean = 20 sec

Standard deviation = 7 sec

Values below 5 are discarded.

For simplicity in C lab programs,
many colleges approximate using:

rand() % 21 + 10
which gives values around 10–30.

Main Idea of Simulation
Each worker:

Assembles item

Waits if machine busy

Polishes item

Starts next item

We track:

machine availability

waiting times

Simplified C Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORKERS 10
#define ITEMS 20

int main()
{
    int machines, i;

    srand(time(0));

    for(machines = 1; machines <= 3; machines++)
    {
        int machineFree[3] = {0};

        float totalWaiting = 0;

        printf("\n===== %d POLISHING MACHINE(S) =====\n",
               machines);

        for(i = 0; i < ITEMS; i++)
        {
            int assemblyTime;
            int polishingTime;

            int finishAssembly;

            int selectedMachine = 0;

            int waiting = 0;

            assemblyTime = rand() % 201 + 100;

            polishingTime = rand() % 21 + 10;

            finishAssembly = assemblyTime;

            for(int j = 1; j < machines; j++)
            {
                if(machineFree[j] < machineFree[selectedMachine])
                {
                    selectedMachine = j;
                }
            }

            if(machineFree[selectedMachine] > finishAssembly)
            {
                waiting =
                machineFree[selectedMachine]
                - finishAssembly;
            }

            totalWaiting += waiting;

            machineFree[selectedMachine] =
            finishAssembly
            + waiting
            + polishingTime;

            printf("\nItem %d", i + 1);

            printf("\nAssembly Time = %d",
                   assemblyTime);

            printf("\nPolishing Time = %d",
                   polishingTime);

            printf("\nWaiting Time = %d\n",
                   waiting);
        }

        printf("\nAverage Waiting Time = %.2f seconds\n",
               totalWaiting / ITEMS);
    }

    return 0;
}
What This Program Does
Step 1
Generate assembly time:

assemblyTime = rand() % 201 + 100;
Range:

100
→
300
100→300
Step 2
Generate polishing time:

polishingTime = rand() % 21 + 10;
Approximate range:

10
→
30
10→30
Step 3
Find free polishing machine

if(machineFree[j] < machineFree[selectedMachine])
Choose earliest available machine.

Step 4
Calculate waiting time

If machine busy:

Waiting
=
Machine Free Time
−
Assembly Finish Time
Waiting=Machine Free Time−Assembly Finish Time
Step 5
Update machine busy time

machineFree[selectedMachine]
=
finishAssembly
+ waiting
+ polishingTime;
Sample Output
===== 1 POLISHING MACHINE(S) =====

Item 1
Assembly Time = 210
Polishing Time = 18
Waiting Time = 0

Item 2
Assembly Time = 140
Polishing Time = 21
Waiting Time = 88

Average Waiting Time = 56.20 seconds
Observation
As machines increase:

Machines	Waiting Time
1	High
2	Medium
3	Low
Because more machines reduce queue length.

Data Structures Used
Mostly:

Arrays

Simulation logic

Queue concept internally

Time Complexity
If:

n = items

m = machines

Then:

O
(
n
×
m
)
O(n×m)
Important Viva Questions
What is simulation?
Imitating a real-world system using program logic.

Why random numbers used?
To simulate real-life varying times.

Why waiting occurs?
Because polishing machines are limited.

Which machine is selected?
Earliest available machine.

Effect of increasing machines?
Waiting time decreases.

What type of queue is followed?
FCFS.

Next is:

Lab 5 & Lab 6 – Josephus Problem
(Soldiers elimination circle problem)

Very important and frequently asked.

Send:

NEXT


NEXT

Now let’s move to the famous:

Lab 5 & Lab 6 – Problem 4
Josephus Problem (Soldier Elimination Problem) 

This is one of the most important circular linked list problems.

Problem Summary
Soldiers stand in a circle

A number n is chosen

Starting from one soldier:

Count clockwise

Every nth soldier is eliminated

Process continues until only one survives

The last soldier escapes.

Example Given
Soldiers:

A B C D E
n = 3

Elimination Process
Start from A

Count:

A(1) B(2) C(3)
C eliminated.

Remaining:

A B D E
Now start from D

Count:

D(1) E(2) A(3)
A eliminated.

Remaining:

B D E
Continue:

B(1) D(2) E(3)
E eliminated.

Remaining:

B D
Count:

B(1) D(2) B(3)
B eliminated.

Survivor
D survives
Data Structure Used
Circular Linked List
Because:

Last node connects to first node

Circular movement needed

Structure of Node
struct Node
{
    char name[20];
    struct Node *next;
};
Complete C Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];
    struct Node *next;
};

struct Node *createNode(char name[])
{
    struct Node *newNode;

    newNode =
    (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);

    newNode->next = NULL;

    return newNode;
}

int main()
{
    int n, total, i;

    char name[20];

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;

    printf("Enter number of soldiers: ");
    scanf("%d", &total);

    printf("Enter value of n: ");
    scanf("%d", &n);

    for(i = 0; i < total; i++)
    {
        printf("Enter soldier name: ");
        scanf("%s", name);

        newNode = createNode(name);

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;

    struct Node *ptr = head;
    struct Node *prev = temp;

    printf("\nElimination Order:\n");

    while(ptr->next != ptr)
    {
        for(i = 1; i < n; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        printf("%s eliminated\n", ptr->name);

        prev->next = ptr->next;

        free(ptr);

        ptr = prev->next;
    }

    printf("\nSoldier who escapes: %s\n",
           ptr->name);

    free(ptr);

    return 0;
}
Dry Run
Suppose:

n = 3
Soldiers:

A B C D E
Initial Circle
A → B → C → D → E
↑               ↓
← ← ← ← ← ← ← ←
First Elimination
Count 3:

A B C
C removed.

Second Elimination
Start from D:

D E A
A removed.

Third Elimination
B D E
E removed.

Fourth Elimination
B D B
B removed.

Survivor
D
Sample Output
Enter number of soldiers: 5
Enter value of n: 3

Enter soldier name:
A
B
C
D
E

Elimination Order:
C eliminated
A eliminated
E eliminated
B eliminated

Soldier who escapes: D
Important Logic
Circular Connection
temp->next = head;
Makes linked list circular.

Traversing n Times
for(i = 1; i < n; i++)
Moves pointer to nth soldier.

Removing Node
prev->next = ptr->next;
Skips eliminated node.

Time Complexity
If:

N = soldiers

Then:

O
(
N
2
)
O(N 
2
 )
because for each elimination we may traverse many nodes.

Important Viva Questions
Which data structure is best?
Circular Linked List.

Why circular linked list?
Because counting repeats continuously in circle.

What is Josephus Problem?
Repeated elimination in circular order until one survives.

Why use dynamic memory allocation?
Number of soldiers may vary.

Difference between linear and circular linked list?
In circular:

last node points to first node

In linear:

last node points to NULL

What happens if n = 1?
Every current soldier gets eliminated immediately in order.

Next:

Lab 7 & Lab 8 – Modified Josephus Problem
(Each eliminated person's chosen number becomes next count)

Send:

NEXT


NEXT

Now let’s move to:

Lab 7 & Lab 8 – Problem 5
Modified Josephus Problem 

This is an advanced version of the Josephus Problem.

Problem Summary
People stand in a circle.

Each person chooses:

A name

A positive integer

Rules:

Start from first person

Initial count = given number

Eliminate nth person

The eliminated person’s chosen number becomes next count

Continue until one remains

Example Given
Person	Number
A	3
B	4
C	6
D	2
E	7
Initial count:

n
=
2
n=2
Elimination Process
Round 1
Start from A

Count 2:

A(1) B(2)
B eliminated.

Next count becomes:

4
4
Round 2
Start from C

Count 4:

C(1) D(2) E(3) A(4)
A eliminated.

Next count becomes:

3
3
Round 3
Start from C

Count 3:

C(1) D(2) E(3)
E eliminated.

Next count:

7
7
Round 4
Remaining:

C D
Count 7:

C D C D C D C
C eliminated.

Survivor
D survives
Data Structure Used
Circular Linked List
Because:

Repeated circular traversal needed

Dynamic deletion required

Node Structure
struct Node
{
    char name[20];
    int num;
    struct Node *next;
};
Complete C Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];
    int num;
    struct Node *next;
};

struct Node* createNode(char name[], int num)
{
    struct Node *newNode;

    newNode =
    (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);

    newNode->num = num;

    newNode->next = NULL;

    return newNode;
}

int main()
{
    int total, i, count;

    char name[20];
    int num;

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;

    printf("Enter number of people: ");
    scanf("%d", &total);

    for(i = 0; i < total; i++)
    {
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter chosen number: ");
        scanf("%d", &num);

        newNode = createNode(name, num);

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;

    printf("Enter initial count: ");
    scanf("%d", &count);

    struct Node *ptr = head;
    struct Node *prev = temp;

    printf("\nElimination Order:\n");

    while(ptr->next != ptr)
    {
        for(i = 1; i < count; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        printf("%s eliminated\n", ptr->name);

        count = ptr->num;

        prev->next = ptr->next;

        free(ptr);

        ptr = prev->next;
    }

    printf("\nLast remaining person: %s\n",
           ptr->name);

    free(ptr);

    return 0;
}
Dry Run
Input:

A 3
B 4
C 6
D 2
E 7
Initial count:

2
First Elimination
Count 2:

A B
B removed.

New count:

4
Second Elimination
C D E A
A removed.

New count:

3
Third Elimination
C D E
E removed.

New count:

7
Fourth Elimination
C D C D C D C
C removed.

Survivor
D
Sample Output
Enter number of people: 5

Enter name:
A
Enter chosen number:
3

Enter name:
B
Enter chosen number:
4

Enter name:
C
Enter chosen number:
6

Enter name:
D
Enter chosen number:
2

Enter name:
E
Enter chosen number:
7

Enter initial count: 2

Elimination Order:
B eliminated
A eliminated
E eliminated
C eliminated

Last remaining person: D
Important Logic
Updating Count
count = ptr->num;
The eliminated person’s chosen number becomes next count.

Circular Movement
ptr = ptr->next;
Moves around the circle continuously.

Node Deletion
prev->next = ptr->next;
Removes node from circle.

Time Complexity
If:

N = number of people

Then:

O
(
N
2
)
O(N 
2
 )
because multiple circular traversals occur.

Important Viva Questions
Which data structure is used?
Circular Linked List.

Difference from normal Josephus problem?
In normal Josephus:

count remains fixed

In modified version:

eliminated person's number becomes next count

Why linked list instead of array?
Deletion is easier in linked list.

Why circular linked list?
Traversal repeats continuously in circular order.

What happens if count becomes very large?
Counting wraps around circle repeatedly.

Next:

Lab 9 & Lab 10 – Tournament Tree & Tournament Sort
This includes:

Priority Queue

Tournament Tree

Selection Sort using Tournament

Send:

NEXT


NEXT

Now let’s move to:

Lab 9 & Lab 10 – Problem 6
Tournament Tree & Tournament Sort 

This topic is very important for:

Priority Queue

Heap-like structures

Selection Sorting

Tree-based comparisons

What is a Tournament Tree?
A tournament tree is a:

Complete Binary Tree
where:

Leaf nodes contain elements

Every parent stores the larger value among children

Just like a sports tournament winner.

Example
Suppose elements are:

5 8 3 10
Tournament Tree:

          10
         /  \
        8    10
       / \   / \
      5  8  3 10
Explanation:

8 wins between 5 and 8

10 wins between 3 and 10

10 wins overall

Root contains maximum element.

Applications
Used in:

Priority Queue

Tournament Sort

Selection algorithms

PART (a)
pqinsert(t, n, elt)
Insert a new element into tournament.

Idea
Add element at leaf

Compare upward

Update winners

Simple Insert Algorithm
void pqinsert(int t[], int *n, int elt)
{
    int i;

    t[*n] = elt;

    i = *n;

    while(i > 0)
    {
        int parent = (i - 1) / 2;

        if(t[parent] < t[i])
        {
            int temp = t[parent];
            t[parent] = t[i];
            t[i] = temp;
        }

        i = parent;
    }

    (*n)++;
}
PART (b)
pqmaxdelete(t, n)
Delete maximum element.

Since root stores maximum:

remove root

replace with dummy value

adjust tree

Algorithm
int pqmaxdelete(int t[], int *n)
{
    int max = t[0];

    t[0] = t[*n - 1];

    (*n)--;

    int i = 0;

    while(1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int largest = i;

        if(left < *n && t[left] > t[largest])
        {
            largest = left;
        }

        if(right < *n && t[right] > t[largest])
        {
            largest = right;
        }

        if(largest == i)
            break;

        int temp = t[i];
        t[i] = t[largest];
        t[largest] = temp;

        i = largest;
    }

    return max;
}
PART (c)
Simplification using Pointer
Instead of storing actual values:

store pointer/index to winner leaf

Advantages:

less copying

faster updates

memory efficient

PART (d)
Tournament Sort Program
Tournament Sort:

Build tournament tree

Repeatedly delete max

Store sorted elements

Complete C Program
#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void tournamentSort(int arr[], int n)
{
    int i;

    for(i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for(i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    tournamentSort(arr, n);

    printf("\nSorted Elements:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
Dry Run
Input:

8 3 10 5
Step 1 — Build Tournament
        10
       /  \
      8   10
Maximum = 10

Step 2 — Remove Maximum
Remaining:

8 5 3
Step 3 — Repeat
Sorted order becomes:

3 5 8 10
Sample Output
Enter number of elements: 4

Enter elements:
8 3 10 5

Sorted Elements:
3 5 8 10
Important Concepts
Tournament Tree vs Heap
Tournament Tree	Heap
Winner propagation	Parent ordering
Used in tournament sort	Used in heap sort
Root stores winner	Root stores max/min
Why complete binary tree?
Efficient storage using arrays.

Heap Formula
For node i:

Left child:

2
i
+
1
2i+1
Right child:

2
i
+
2
2i+2
Parent:

i
−
1
2
2
i−1
​
 
Time Complexity
Insert
O
(
log
⁡
n
)
O(logn)
Delete Max
O
(
log
⁡
n
)
O(logn)
Tournament Sort
O
(
n
log
⁡
n
)
O(nlogn)
Important Viva Questions
What is tournament tree?
Binary tree storing winners of comparisons.

Why root stores maximum?
Each parent stores larger child recursively.

What is tournament sort?
Sorting using repeated winner selection.

Difference between heap sort and tournament sort?
Heap sort uses heap property.
Tournament sort uses winner tree concept.

Why array representation used?
Efficient memory usage.

Advantage of tournament tree?
Fast repeated maximum/minimum selection.

Next:

Lab 11 & Lab 12 – Army Camp Mountain Problem
(Binary Tree based simulation)

Send:

NEXT


NEXT

Now let’s move to:

Lab 11 & Lab 12 – Problem 7
Army Camp Mountain Problem 

This problem is based on:

Binary Tree
and includes:

Tree creation

Level-wise traversal

Counting nodes

Subtree checking

Very important for viva.

Problem Summary
Army creates camps on 2 mountains:

MP1

MP2

Rules:

Camps built from summit to base

Minimum distance = 30 meters

Every camp has:

2 child/base camps

Each camp contains:

2 Havildars

1 Subedar

1 Captain/Lieutenant

One Major per level

You must compute:

Total camps

Total personnel

Officer counts

Food camps needed

Whether one mountain is subset of another

Main Data Structure
Binary Tree
Because:

Every camp has maximum 2 child camps

Structure becomes:

          Summit
         /      \
     Camp       Camp
    /   \       /   \
 Camp Camp   Camp Camp
Assumption Used
Every:

30 meters creates next level

Suppose:

Height = 120m
Then levels:

120
/
30
=
4
120/30=4
Binary Tree Formation
Level-wise:

Level	Camps
0	1
1	2
2	4
3	8
Total:

1
+
2
+
4
+
8
=
15
1+2+4+8=15
Formula
Total camps in binary tree:

2
0
+
2
1
+
2
2
+
⋯
+
2
(
n
−
1
)
=
2
n
−
1
2 
0
 +2 
1
 +2 
2
 +⋯+2 
(n−1)
 =2 
n
 −1

where:

n = levels

Personnel Per Camp
Each camp:

Officer	Count
Havildar	2
Subedar	1
Captain/Lieutenant	1
Total:

4
 officers per camp
4 officers per camp
Plus:

1 Major per level

Complete C Program
#include <stdio.h>
#include <math.h>

int totalCamps(int levels)
{
    return pow(2, levels) - 1;
}

int main()
{
    int h1, h2;

    int levels1, levels2;

    int camps1, camps2;

    int personnel1, personnel2;

    int major1, major2;

    printf("Enter height of MP1: ");
    scanf("%d", &h1);

    printf("Enter height of MP2: ");
    scanf("%d", &h2);

    levels1 = h1 / 30;
    levels2 = h2 / 30;

    camps1 = totalCamps(levels1);
    camps2 = totalCamps(levels2);

    major1 = levels1;
    major2 = levels2;

    personnel1 = camps1 * 4 + major1;
    personnel2 = camps2 * 4 + major2;

    printf("\n===== MP1 DETAILS =====\n");

    printf("Levels: %d\n", levels1);

    printf("Total Camps: %d\n", camps1);

    printf("Total Personnel: %d\n",
           personnel1);

    printf("Havildars: %d\n",
           camps1 * 2);

    printf("Subedars: %d\n",
           camps1);

    printf("Captains/Lieutenants: %d\n",
           camps1);

    printf("Majors: %d\n",
           major1);

    printf("Food Camps Needed: %d\n",
           camps1);

    printf("\n===== MP2 DETAILS =====\n");

    printf("Levels: %d\n", levels2);

    printf("Total Camps: %d\n", camps2);

    printf("Total Personnel: %d\n",
           personnel2);

    printf("Havildars: %d\n",
           camps2 * 2);

    printf("Subedars: %d\n",
           camps2);

    printf("Captains/Lieutenants: %d\n",
           camps2);

    printf("Majors: %d\n",
           major2);

    printf("Food Camps Needed: %d\n",
           camps2);

    if(camps1 == camps2)
    {
        printf("\nMP1 and MP2 are identical.\n");
    }
    else if(camps1 < camps2)
    {
        printf("\nMP1 is subset of MP2.\n");
    }
    else
    {
        printf("\nMP2 is subset of MP1.\n");
    }

    return 0;
}
Dry Run
Suppose:

MP1 Height = 120
MP2 Height = 90
Step 1 — Find Levels
For MP1:

120
/
30
=
4
120/30=4
For MP2:

90
/
30
=
3
90/30=3
Step 2 — Find Total Camps
For MP1:

2
4
−
1
=
15
2 
4
 −1=15

For MP2:

2
3
−
1
=
7
2 
3
 −1=7

Step 3 — Personnel
Each camp:

4 officers

For MP1:

15
×
4
+
4
=
64
15×4+4=64
For MP2:

7
×
4
+
3
=
31
7×4+3=31
Sample Output
Enter height of MP1: 120
Enter height of MP2: 90

===== MP1 DETAILS =====
Levels: 4
Total Camps: 15
Total Personnel: 64
Havildars: 30
Subedars: 15
Captains/Lieutenants: 15
Majors: 4
Food Camps Needed: 15

===== MP2 DETAILS =====
Levels: 3
Total Camps: 7
Total Personnel: 31
Havildars: 14
Subedars: 7
Captains/Lieutenants: 7
Majors: 3
Food Camps Needed: 7

MP2 is subset of MP1.
Important Concepts
Why Binary Tree?
Each camp controls:

left base camp

right base camp

Exactly like binary tree children.

Why powers of 2 used?
Binary tree doubles nodes each level.

Formula Used
Total nodes in complete binary tree:

2
n
−
1
2 
n
 −1

Time Complexity
All calculations:

O
(
1
)
O(1)
because direct formulas used.

Important Viva Questions
Which data structure is used?
Binary Tree.

Why binary tree?
Each camp has two subordinate camps.

Why powers of 2 appear?
Each level doubles number of camps.

Formula for total nodes?
2
n
−
1
2 
n
 −1

What is complete binary tree?
All levels fully filled except possibly last.

What is subset checking here?
Comparing camp structures/sizes of mountains.

Next and final:

Lab 13 & Lab 14 – Graph Related Problem
This usually includes:

BFS

DFS

Graph representation

Adjacency Matrix/List

Send:

NEXT


NEXT

Now let’s move to the final topic:

Lab 13 & Lab 14 – Graph Related Problems 

This lab generally covers:

Graph Representation

BFS

DFS

Adjacency Matrix

Adjacency List

Traversal Algorithms

These are extremely important in DAA and Data Structures.

What is a Graph?
A graph consists of:

Vertices (Nodes)

Edges (Connections)

Mathematically:

G
=
(
V
,
E
)
G=(V,E)
where:

V
V = set of vertices

E
E = set of edges

Example Graph
      A
     / \
    B   C
    |   |
    D---E
Vertices:

A B C D E
Edges:

AB AC BD CE DE
Types of Graph
Type	Meaning
Directed Graph	Edges have direction
Undirected Graph	No direction
Weighted Graph	Edges contain weights
Cyclic Graph	Contains cycle
Acyclic Graph	No cycle
Directed Graph
A directed graph has arrows.

Example:

A → B
↓
C
Edge direction matters.

Graph Representation
Two common methods:

1. Adjacency Matrix
Matrix representation.

Example:

    A B C
A   0 1 1
B   1 0 0
C   1 0 0
Meaning:

A connected to B and C

2. Adjacency List
Each node stores neighbors.

Example:

A → B → C
B → A
C → A
Breadth First Search (BFS)
BFS visits:

level by level

Uses:

Queue
BFS Example
Graph:

A → B → C
|       |
D ------E
Start from A.

Traversal:

A B D C E
BFS Algorithm
Start node visited

Insert into queue

Remove front node

Visit neighbors

Repeat

BFS C Program
#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front > rear;
}

int main()
{
    int n, i, j;

    int graph[10][10];

    int visited[10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    enqueue(start);

    visited[start] = 1;

    printf("\nBFS Traversal:\n");

    while(!isEmpty())
    {
        int node = dequeue();

        printf("%d ", node);

        for(i = 0; i < n; i++)
        {
            if(graph[node][i] == 1 &&
               visited[i] == 0)
            {
                enqueue(i);

                visited[i] = 1;
            }
        }
    }

    return 0;
}
DFS (Depth First Search)
DFS visits:

deeply first

then backtracks

Uses:

Stack / Recursion
DFS Example
Graph:

A → B → D
|
C → E
DFS from A:

A B D C E
DFS Algorithm
Visit node

Mark visited

Go deeper recursively

Backtrack

DFS C Program
#include <stdio.h>

int graph[10][10];

int visited[10];

int n;

void DFS(int node)
{
    int i;

    printf("%d ", node);

    visited[node] = 1;

    for(i = 0; i < n; i++)
    {
        if(graph[node][i] == 1 &&
           visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");

    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");

    scanf("%d", &start);

    printf("\nDFS Traversal:\n");

    DFS(start);

    return 0;
}
Difference Between BFS and DFS
BFS	DFS
Queue used	Stack/Recursion used
Level-wise traversal	Depth-wise traversal
Finds shortest path	Does not guarantee shortest
More memory	Less memory
FIFO	LIFO
Time Complexity
For graph with:

V = vertices

E = edges

Both BFS and DFS:

O
(
V
+
E
)
O(V+E)
Important Graph Terms
Degree
Number of edges connected to node.

Path
Sequence of connected vertices.

Cycle
Path starting and ending at same vertex.

Connected Graph
Every node reachable.

Spanning Tree
Tree connecting all vertices without cycles.

Important Viva Questions
Which data structure is used in BFS?
Queue.

Which data structure is used in DFS?
Stack or Recursion.

Which traversal finds shortest path?
BFS.

Why DFS uses recursion?
Recursive calls behave like stack.

Difference between tree and graph?
Tree has no cycle.
Graph may contain cycles.

Maximum edges in complete graph?
For undirected graph:

n
(
n
−
1
)
2
2
n(n−1)
​
 

Complete Lab Topics Finished
Covered:

Parking Garage Stack

Computer Simulation Queue

Factory Simulation

Josephus Problem

Modified Josephus

Tournament Tree

Army Camp Binary Tree

Graph BFS & DFS


