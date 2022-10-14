#include <stdio.h>

void ChargeRefills(int y[],int l[],int n,int Capacity)
{
    int current=0,last=0,i;
    printf("\nStops:{%c",current+65);//prints the starting point of the journey
    while(current<(n-1))
    {
        last=current;
        i=0;
        while(current<(n-1))//It calculates whether that gas is sufficient to go futher and comeback to the before
        {.                  // station in case the next gas station doesn't work.
            if((y[current+1]-y[last])<=(Capacity-l[i]))
               { 
                current+=1;
                i++;
                   
               }
            else break;
        }

        if(current==last)
            return;
        if(current<(n-1))
        {
            printf(" %c",current+65);//prints the gas station stops to refill the tank.
        }
    }
    printf(" %c}",current+65);//prints the ending point of the journey.
}

void main()
{
    int i,n,Capacity;
    printf("\n***Electric Car Traveler Problem CPSC 535-01 by Spandhana and Vyshnavi***\n");
    printf("\nEnter the capacity of car in miles: ");
    scanf("%d",&Capacity);
    printf("\nEnter number of cities between starting and ending point: ");
    scanf("%d",&n);
    n=n+2;
    int l[n];
    char city[n];
    l[0]=0;
    for(i=1;i<n;i++)
    {
        printf("\nEnter the Distance from %c stop to %c stop: ",i-1+65,i+65);
        scanf("%d",&l[i]);
    }
    int y[n];
    y[0]=0;
    for(i=1;i<n;i++)
    {
        y[i]=l[i]+y[i-1];//calculates the total distance from starting position to each gas station.
    }
    ChargeRefills(y,l,n,Capacity);
}
