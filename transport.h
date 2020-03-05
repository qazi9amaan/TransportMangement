#include <stdio.h>


//NAME_LEN for username length.
#define NAME_LEN 25
//MAX_VERTICES for maximum stops.
#define MAX_VERTICES 4
//MAX_VERTICES for maximum seats in a bus.
#define MAX_SEATS 2

// FILE TO SAVE USERS
FILE *database;


// A SEAT structure to define the details of a person occupying a seat.
typedef struct seat_details
{
    char name [NAME_LEN];
    int srn;
    int stop;
    int seat_no;
    struct seat_details *next;
    struct seat_details *prev;
} SEAT;

// A BUS Structure to define the details of a bus having capacity(Availability) and the seats.
typedef struct bus_details
{
    SEAT *seat;
    int capacity;
} BUS;

// A EDGE structure to define the particular route between different stops.
typedef struct edge
{
  int src, dest;
}EDGE;

// A NODE Structure to define the Adjacency List of all the stops.
typedef struct graph_node
{
  int dest;
  struct graph_node*next;
}NODE;

// A GRAPH Structure to define the graph of all the routes between the stops.
typedef struct graph
{
  NODE* head[MAX_VERTICES];
}GRAPH;

// Function returing a graph of all the routes between the stops,
// Inputs are the routes and the number of routes.
GRAPH* create_graph(EDGE*,int );


// Function printing the graph of all the routes between the stops,
// Input is the GRAPH containing the College/ Starting STOP.
void printGraph(GRAPH* );

// Function returing a bus having Number of seats = MAX_SEATS and Capacity
BUS *create_bus (void);

// A function returing a flag when the bus is FULL/ No Availability
// Input are all the buses and the UserInput busname.
short checkBusAvailabitily(BUS *, BUS *, BUS* , BUS* , BUS* , char ,int,int);

// A function to verify the details of a indiviual booking
// Input are all the buses and the UserInput busname.
void verifydetails(BUS * , BUS* , BUS *, BUS*, BUS*, char);

// A function returning a filled seat inside a bus with particular User details
// Input is the User chosen bus.
SEAT* create_seat(BUS **,int , int);

// A function to add seats as a queue insdie the doublelinked list structure BUS;
// Input is the user chosen bus.
void insertBegining(BUS **,int ,int);

// A function to print the Users who booked a seat inside a Bus;
// Input is the admin chosen bus.
void displayList(BUS *);

// A function to delete the seat details inside a Bus;
// Input are the bus in which holds the user and the srn.
void deleteUserIn(BUS* , int );

// A function to show the seat details inside a Bus;
// Input are the bus in which holds the user and the srn.
void ShowBooking(BUS* , int );

// A function to search and change the seat details inside a Bus;
// Input are the bus in which holds the user and the srn.
void searchUserIn(BUS* , int );

// A function that returns a flag when the bus is filled;
// Input are all the bus and the user input bus.
int withdraw_buses(BUS *, BUS * , BUS* , BUS *, BUS* , BUS* );

// A function that checks whether users insidethe BUS reached the stop;
// Input are the bus and the current Stop.
void check_people_reached(BUS* ,int );

// A function that returns a flag whether user wants to see at each stop how many
// users are still in the bus ,input is the current Bus.
int driver_options(BUS* );

//Function to write users into database;
void write_into_database(int);
//Function to check whether data is in database or not
int check_in_database(int );

// A function that starts the Journey, traverses the bus on the routes
// input are the bus and the route structure
void start_journey(BUS *,GRAPH* );

int checkforStop(int);
