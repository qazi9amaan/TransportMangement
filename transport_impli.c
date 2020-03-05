#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "transport.h"



void write_into_database(int data)
{
  database = fopen("userdata.txt", "a");
  fprintf(database, "%d", data);
  fprintf(database, "\n");
  fclose(database);
}

// Function returing a graph of all the routes between the stops,
// Inputs are the routes and the number of routes.
GRAPH* create_graph(EDGE edges[],int n)
{
  unsigned i;
  GRAPH *graph = (GRAPH*)malloc(sizeof(GRAPH));
//assigning all the stops initially to null
  for(i=0;i<MAX_VERTICES;i++)
    graph->head[i]=NULL;
//assigning the edge between the source and destination for each stop
  for(i=0;i<n;i++)
  {
    int src = edges[i].src;
    int dest = edges[i].dest;

    NODE* newnode= (NODE*)malloc(sizeof(NODE));
    newnode->dest = dest;
 //assigning the edge between the source and destination
    newnode->next=graph->head[src];
    graph->head[src]=newnode;
  }
  return graph;
}

// Function printing the graph of all the routes between the stops,
// Input is the GRAPH containing the College/ Starting STOP.
void printGraph(GRAPH* graph)
{
	int i;
	for (i = 0; i < MAX_VERTICES; i++)
	{
		// print current vertex and all ts neighbors
		NODE* ptr = graph->head[i];
		while (ptr != NULL)
		{
			printf("(%d -> %d)\t", i, ptr->dest);
			ptr = ptr->next;
		}

		printf("\n");
	}
}

// Function returing a bus having Number of seats = MAX_SEATS and Capacity
BUS *create_bus (void)
{
    //allocating the memory for the bus
    BUS *p_node;
    if ((p_node = (BUS*)malloc (sizeof (BUS))) != NULL)
        p_node ->capacity = MAX_SEATS;
        p_node->seat = NULL;
    return p_node;
}

// A function returing a flag when the bus is FULL/ No Availability
// Input are all the buses and the UserInput busname.
short checkBusAvailabitily(BUS *A, BUS *B, BUS* C, BUS* D, BUS* E, char ini, int srn, int stop)
{

  SEAT* temp;
  char check;
  //checking capacity of the bus
  switch (ini) {
    case 'A':   if(A->capacity == 0)
                {
                  system("cls");
                  printf("Sorry! This bus is already full\n");
                  return 0;
                }
                else
                {
                  //if bus is available insert the user to the beginning of the double linked list and return the flag
                  printf("....................................................................\n");
                  printf("The bus is avaliable at this moment! Do you want to complete your booking(y/n)\t");
                  scanf(" %c", &check);
                  if(check == 'y' || check == 'Y')
                  {
                    insertBegining(&A,srn,stop);
                    return 1;
                  }
                  else{
                    printf("Your booking has been cleared!\n");
                    return 0;
                  }


                }
                break;

    case 'B': if(B->capacity == 0)
                {
                  system("cls");
                  printf("Sorry! This bus is already full\n");
                  return 0;
                }
                else
                {
                  //if bus is available insert the user to the beginning of the double linked list and return the flag
                  printf("....................................................................\n");
                  printf("The bus is avaliable at this moment! Do you want to complete your booking(y/n)\t");
                  scanf(" %c", &check);
                  if(check == 'y' || check == 'Y')
                  {
                    insertBegining(&A,srn,stop);
                    return 1;
                  }
                  else{
                    printf("Your booking has been cleared!\n");
                    return 0;
                  }


                }
                break;

    case 'C': if(C->capacity == 0)
                {
                  system("cls");
                  printf("Sorry! This bus is already full\n");
                  return 0;
                }
                else
                {
                  //if bus is available insert the user to the beginning of the double linked list and return the flag
                  printf("....................................................................\n");
                  printf("The bus is avaliable at this moment! Do you want to complete your booking(y/n)\t");
                  scanf(" %c", &check);
                  if(check == 'y' || check == 'Y')
                  {
                    insertBegining(&A,srn,stop);
                    return 1;
                  }
                  else{
                    printf("Your booking has been cleared!\n");
                    return 0;
                  }


                }
                break;
    case 'D': if(D->capacity == 0)
                {
                  system("cls");
                              printf("Sorry! This bus is already full\n");
                              return 0;
                            }
                else
                {
                  //if bus is available insert the user to the beginning of the double linked list and return the flag
                  printf("....................................................................\n");
                  printf("The bus is avaliable at this moment! Do you want to complete your booking(y/n)\t");
                  scanf(" %c", &check);
                  if(check == 'y' || check == 'Y')
                  {
                    insertBegining(&A,srn,stop);
                    return 1;
                  }
                  else{
                    printf("Your booking has been cleared!\n");
                    return 0;
                  }


                }
                break;

  case 'E': if(E->capacity == 0)
                {system("cls");
                                          printf("Sorry! This bus is already full\n");
                                          return 0;
                                        }
                else
                {
                  //if bus is available insert the user to the beginning of the double linked list and return the flag
                  printf("....................................................................\n");
                  printf("The bus is avaliable at this moment! Do you want to complete your booking(y/n)\t");
                  scanf(" %c", &check);
                  if(check == 'y' || check == 'Y')
                  {
                    insertBegining(&A,srn,stop);
                    return 1;
                  }
                  else{
                    printf("Your booking has been cleared!\n");
                    return 0;
                  }


                }
                break;
  }



}

// A function to verify the details of a indiviual booking
// Input are all the buses and the UserInput busname.
void verifydetails(BUS *A , BUS* B, BUS *C, BUS* D, BUS* E, char bname)
{
  int srn;
  char opt;
  printf("Please Provide SRN:\t");
  scanf("%d",&srn );

  printf(" s -> Show Booking\n d -> delete Booking\n e -> edit Booking \n>>");
  scanf(" %c", &opt);


    switch (opt)
    {
      case 'e':         //edit the booking details search for user inside the bus
                        switch (bname)
                         {
                           //search user in the bus according to the user SRN
                           case 'A':  searchUserIn(A,srn);
                                    break;
                           case 'B':  searchUserIn(B,srn);
                                    break;
                           case 'C':  searchUserIn(C,srn);
                                    break;
                           case 'D':  searchUserIn(D,srn);
                                    break;
                           case 'E':  searchUserIn(E,srn);
                                   break;
                    }
                    break;
      case 'd' :
                        //delete the booking details search for user inside the bus
                        switch (bname) {
                        case 'A':  deleteUserIn(A,srn);
                                    break;

                        case 'B':  deleteUserIn(B,srn);
                                    break;

                        case 'C':  deleteUserIn(C,srn);
                                    break;

                        case 'D':  deleteUserIn(D,srn);
                                    break;

                        case 'E':  deleteUserIn(E,srn);
                                    break;
                    }
                    break;
        case 's' : //show the booking details search for user inside the bus
                          switch (bname) {
                                      case 'A':  ShowBooking(A,srn);
                                                  break;

                                      case 'B':  ShowBooking(B,srn);
                                                  break;

                                      case 'C':  ShowBooking(C,srn);
                                                  break;

                                      case 'D':  ShowBooking(D,srn);
                                                  break;

                                      case 'E':  ShowBooking(E,srn);
                                                  break;
                                  }
                          break;

    }


}

int check_in_database(int srn)
{


      char srn_str[20];
      itoa(srn,srn_str,10);

      int line_num = 1;
      int find_result = 0;
      char data[30];

      database = fopen("userdata.txt","r");
      while(fgets(data, 512, database) != NULL)
       {
        if((strstr(data, srn_str) != NULL))
        {
          find_result++;
        }
        line_num++;
      }
        fclose(database);
      if(find_result == 0) {
      return 0;
      }
      else{
        return 1;
      }

}

int checkforStop(int stop){
  int stops[]={1,2,3};
  int n = sizeof(stops)/sizeof(stops[0]);
  int i =0;
  for ( i = 0; i < n; i++) {
    if(stops[i]!=0)
    {
      if(stops[i] == stop)
        return 1;
    }}
    return 0;
}
// A function returning a filled seat inside a bus with particular User details
// Input is the User chosen bus.
SEAT* create_seat(BUS **z,int srn,int stop)
{

  //allocate memory for each seat with user input
    SEAT* temp =(SEAT*)malloc(1*sizeof(SEAT));
    temp->prev = NULL;
    temp->next = NULL;

    temp->srn = srn;
    printf("The bus is being booked in the name of\t:" );
    scanf("%s", temp->name);
    temp->stop = stop;
    temp->seat_no = ((*z)->capacity);
    write_into_database(srn);
    system("cls");
    printf("\nThankyou! Your booking is done!\n");
    return temp;
}

// A function to add seats as a queue insdie the doublelinked list structure BUS;
// Input is the user chosen bus.
void insertBegining(BUS **z,int srn , int stop)
{
  SEAT *head = (*z)->seat;
  SEAT *temp;
  //decreasing the available seats of the bus
  ((*z)->capacity)--;
    //if bus is empty insert at beginning
    if (head == NULL)
    {
        (*z)->seat = create_seat(z,srn,stop);


    }
    else
    {   //inserting the seat details inside the bus at the end
        temp = create_seat(z,srn,stop);
        temp->next = head;
        head->prev = temp;
        (*z)->seat = temp;

    }

}

// A function to print the Users who booked a seat inside a Bus;
// Input is the admin chosen bus.
void displayList(BUS *z)
{
  SEAT* head = z->seat;
//if bus is empty
  if(head == NULL)
    printf("Empty\n" );
  while(head)
  {
    printf("%s\n",head->name );
    head = head->next;
  }

}


// A function to delete the seat details inside a Bus;
// Input are the bus in which holds the user and the srn.
void deleteUserIn(BUS* bus, int srn)
{
  SEAT*head = bus->seat;
    int pos = 0;
     SEAT *pre_node;
     //if bus = empty
     if(head==NULL) {
        printf("EMPTY");
        return;
     }

     // if the user is siting at the first place and there are other people in the bus
     if(head->srn == srn) {
        if(head->next != NULL) {
           head->next->prev = NULL;
           head = head->next;
           bus->seat= head;
           printf("Removed the Person\n");
           //increase the capacity
           bus->capacity++;

           return;
        } else {
          //if only the one person insdie the bus
           head = NULL;
           bus->seat= NULL;
           printf("Removed the Person\n");
            bus->capacity++;
           return;
        }
     }
     // if user not found
     else if(head->srn != srn && head->next == NULL) {
        printf("%d not found in the bus\n", srn);
        return;
     }

     SEAT* current = head;
     //search the user insdie the bus while its not the end of list o ruser is found
     while(current->next != NULL && current->srn != srn) {
        pre_node = current;
        current = current->next;
     }

     //if user found delete him
     if(current->srn == srn) {
        pre_node->next = pre_node->next->next;

        if(pre_node->next != NULL) {          // link back
           pre_node->next->prev = pre_node;
        }

        printf("Successfully! deleted!\n");
        bus->capacity++;
        free(current);
     } else
        printf("%d not found in the list.", srn);

        fclose(fopen("userdata.txt", "w"));
}

// A function to show the seat details inside a Bus;
// Input are the bus in which holds the user and the srn.
void ShowBooking(BUS* bus, int srn)
{
  SEAT* head = bus->seat;

//searching for user SRN inside the bus booking

  while(head!= NULL)
  {//if found show the details
    if(head->srn == srn)
    {

      printf("Your Details Are : \n\n");

      printf(" Name\t %s\n" ,head->name);
      printf(" SRN\t %d\n" ,head->srn);
      printf(" STOP\t %d\n",head->stop );

    }
    head = head->next;
  }
}

// A function to search and change the seat details inside a Bus;
// Input are the bus in which holds the user and the srn.
void searchUserIn(BUS* bus, int srn)
{
  SEAT* head = bus->seat;

//searching for user SRN inside the bus booking
  while(head!= NULL)
  {
    // if found show and edit the details
    if(head->srn == srn)
    {
      //show details
      printf("Your Details Are : \n\n");
      printf(" Name\t %s\n" ,head->name);
      printf(" SRN\tPES2201800 %d\n" ,head->srn);
      printf(" STOP\t %d\n",head->stop );
      printf(" BUS\t %c\n" ,bus);

      //edit details
      printf("Please Enter Name\t" );
      scanf("%s", head->name);
      printf("Please Enter Stop\t" );
      scanf("%d",&head->stop);

    }
    head = head->next;
  }
}

// A function that returns a flag when the bus is filled;
// Input are all the bus and the user input bus.
int withdraw_buses(BUS *bus, BUS *A , BUS* B, BUS *C, BUS* D, BUS* E)
{
// checking for input bus and printing the bus name
  if (bus==A) {
    printf("A\t");
  }
  else if (bus==B) {
    printf("B\t");
  }
  else if (bus==C) {
    printf("C\t");
  }
  else if (bus==D) {
    printf("D\t");
  }
  else if (bus==E) {
    printf("E\t");

  }
  //if bus is available returning the flag 1
  if(bus->capacity == 0)
  {
    printf("%d\t Ready to go\n",bus->capacity);
    return 1;
  }
  else
  {
    //if not available return the flag 0
    printf("%d\t Boarding Bus\n",bus->capacity);
    return 0;
  }

}

// A function that checks whether users insidethe BUS reached the stop;
// Input are the bus and the current Stop.
void check_people_reached(BUS* z,int dest)
{
  SEAT* head = z->seat;
  //if capacity of bus=maximum seats return
  if(z->capacity== MAX_SEATS)
    return;

  while(head)
  {
    //delete the user  if current stop is user's stop
    if(head->stop == dest)
    {

      printf("%s\n",head->name);
      deleteUserIn(z, head->srn);
    }
    //if capacity = maximum seats break the loop
    if(z->capacity== MAX_SEATS)
    {
      break;
      return;
    }
    if(head->stop == -1)
    {
      free(head);
    }


    head = head->next;
  }

}

// A function that returns a flag whether user wants to see at each stop how many
// users are still in the bus ,input is the current Bus.
int driver_options(BUS* bus)
{
  char opt;
  printf("\nDRIVER'S MENU\n");
  printf("...........................................\n");
  printf(" d-> dont show menu c->Continue Journey\n v->View Members ");
  printf("\n...........................................\n>>");
  scanf(" %c",&opt);
  switch (opt) {
    case 'c': printf("\nContinuing Trip\n");
              system("cls");
              return 1;
              break;
    case 'v': system("cls");
              displayList(bus);
              printf("\nContinuing Trip\n");
              return 1;
              break;
    case 'd': return 0;
              break;

  }
}

// A function that starts the Journey, traverses the bus on the routes
// input are the bus and the route structure
void start_journey(BUS *bus,GRAPH* graph)
{
  printf("\n ");
  //while seats are available inside the bus
      SEAT*head = bus->seat;
      int pos = 0;
      SEAT *pre_node;
      //if bus = empty
      if(head==NULL) {
        printf("EMPTY");
        return;
      }
      while(head)
      {
        if(head->stop ==-1 || head->name == NULL)
        {
          printf("Sorry the stops of some of the students are not valid.\n");
          return;
        }
        head = head->next;
      }

  while(bus->capacity != MAX_SEATS)
  {
    int i;
    int flag =1;

    printf("Show drivers menu (1/0) \t");
    scanf("%d",&flag );
    if(flag)
    {
      //show the driver menu
        flag = driver_options(bus);

    }

    //for all the stops traverse the roots
  	for (i = 0; i < MAX_VERTICES; i++)
  	{
  		// print current stop and all its neighbors
  		NODE* ptr = graph->head[i];
  		while (ptr != NULL)
  		{
  			//printf("(%d -> %d)\t", i, ptr->dest);
        if(bus->capacity== MAX_SEATS)
          break;
        printf("\n...............................\n");
        printf("Current Stop %d\n", ptr->dest);
        printf("\n");
        //check the number of people reached their stop
        check_people_reached(bus,ptr->dest);
        if(flag)
        {
          //show the driver menu
            flag = driver_options(bus);

        }
        printf("\n\n");

  			ptr = ptr->next;

  		}
  		printf("\n");

      //if seats available = maximum break teh
      if(bus->capacity== MAX_SEATS)
        break;

  	}
  }
}
