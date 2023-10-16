#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define infinity 9999
#define MAX 20
int Graph[MAX][MAX];
 void dijkstra(int G[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], dis[MAX], pred[MAX];
    int visited[MAX], count, mindis, next, i, j;
     if(start>=13)
    {
    	printf("\nEnter a Valid House Number");
    
	}
	else if(start==10 || start==11 || start==12)
	{ 
		printf("\nPlot Number %d is Hospital",start);
		printf("\nEnter a house number");
	}
	else
	{
		
	  printf("\nSearching Nearest Hospital And Shortest Path To Given Location.....\n");
    // pred[] stores the predecessor of each node ,count gives the number of nodes seen so far
    // creating the cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = G[i][j];
    // initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++)
    {
        dis[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    //to check if house number exceeds 12
    /*
    if(start>13)
    {
    	printf("Enter a valid house number");
	}*/
    dis[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindis = infinity;
        // next node will give the node at minimum distance
        for (i = 0; i < n; i++)
            if (dis[i] < mindis && !visited[i])
            {
                mindis = dis[i];
                next = i;
            }
        // checking if a better path exists through next node
        visited[next] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindis + cost[next][i] < dis[i])
                {
                    dis[i] = mindis + cost[next][i];
                    pred[i] = next;
                }
        count++;
    }
    // printing the path and distance of each hospital
    int minindex = 10;
    for (i = 10; i < n; i++)
    {
        if (i != start)
        {
            printf("\nDistance of house to the hospital at plot number %d = %d metres",i,dis[i]);
            if (dis[minindex] > dis[i])
            {
                minindex = i;
            }

            printf("\nPath to hospital = %d", i);
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != start);
            printf("\n");
        }
    }
   

    printf("\n-------------------------------------------------------------------------------\n");
    printf("\nNearest hospital is at plot number : %d", minindex);
    printf("\nDistance for nearest hospital : %d metres", dis[minindex]);
    printf("\nPath of nearest hospital : %d", minindex);
    j = minindex;
    do
    {
        j = pred[j];
        printf("<-%d", j);
    } while (j != start);
     printf("\n-------------------------------------------------------------------------------\n\n");
}
     
}
void menu(){

    int  i, j, n, u, p;
    n = 13;
    while (1)
    {

        printf("\nSelect a Operation\n1.Search the Hospital\n2.EXIT\nPlease Enter a Option:");
        scanf("%d", &p);
        if (p == 1)
        {
            printf("Enter the House Number :");
            scanf("%d", &u);
            dijkstra(Graph,n,u);
            printf("\n");
        }
        else if (p == 2)
        {

            printf("\nTHANK YOU FOR USING THIS APPLICATION...");
            exit(0);
        }
        else
        {
            printf("Please Enter a Valid Option\n");
        }
    }

}

void printGraph(){


    printf("                 NEAREST HOSPITAL PATH FINDER                                  \n");
    printf("-------------------------------------------------------------------------------\n");

    printf("                          CITY MAP                          \n");

    printf("\n             ______10m________________________");
    printf("\n            |                                 | ");
    printf("\n            |                                 | ");
    printf("\n         __(1)_____50m______(H1(10))___50m___(2)");
    printf("\n        |   |      __________| |              ||__");
    printf("\n        |   |     40m         _|30m           |   |");
    printf("\n        |   |     |           | _____20m______|   |");
    printf("\n        |   |60m  |           ||              _20m|");
    printf("\n        |   |     |           ||              |    ");
    printf("\n        |   |____(3)___10m___(4)____20m__(H2(11))--------|");
    printf("\n     70m|      __||           ||            | |          | ");
    printf("\n        |   10m|  |        30m||         40m| |          | ");
    printf("\n        |      |  |10m______  ||10m________ | |20m       |");
    printf("\n        |_____(5)           | |           | |   |__      | ");
    printf("\n              ||            | |           | |      |     | ");
    printf("\n              ||____10m____(H3(12))__10m__(6)_10m_(7)    |");
    printf("\n              |              |            ||_     ||     |65m");
    printf("\n              | 20m       40m|      ______|  |    ||     | ");
    printf("\n              |____(8)_______|     | __30m___|    ||     |");
    printf("\n              |     | |            | |  ______40m_||     |");
    printf("\n              |     | |______20m___| |  |  ________|     |");
    printf("\n              |  30m|      __________|  |  |        _____| ");
    printf("\n              |     |     | ____________|  |        | ");
    printf("\n              |     |     ||            10m|      __|");
    printf("\n              |     |____(9)             |        |");
    printf("\n          70m |__________||              |        | ");
    printf("\n                          |_____________(0)_______|");
    printf("\n                               25m               ");
    printf("\n\n");
    printf("-------------------------------------------------------------------------------\n");
}
 int main()
 {
 	    //file handling
        FILE* input_file = fopen("InputGraph.txt","r");
 		int i,j;
 		for( i=0;i<13;i++)
 		{
 			for( j=0;j<13;j++)
 			{
 				fscanf(input_file,"%d",&Graph[i][j]);
			 }
		 }
		 fclose(input_file);
		 printGraph();
		 menu();
		 return 0;
 }
