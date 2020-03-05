#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "transport.h"


int main()
{
system("cls");
  //the routes between the stops
  EDGE routes[]= {
    { 0, 1 },  { 0, 2 }, { 1, 2 }, { 2, 3 }, { 3,0 }
  };
  //  the available stops

  int stops[]={1,2,3};
  //number of the edges
  int n = sizeof(routes)/sizeof(routes[0]);
  //creating the graph of all teh routes
  GRAPH *graph = create_graph(routes,n);

  //Buses available
  BUS *A, *B, *C ,*D ,*E;
  char opt;
  char busname;


  // creating the buses
  A = create_bus();
  B = create_bus();
  C = create_bus();
  D = create_bus();
  E = create_bus();

  printf("\n");
  printf("...........................................\n");
  printf("Disclamer : \n1. To book the seat inside the buses check Availability First!\n");
  printf("2. To start the journey of the bus, it should be filled first\n");
  printf("3. To check your booking details, please go to My Booking\n");
  printf("4. To Login as admin, username : admin  password : admin\n");
  printf("5. To quit anytime press q\n");
  printf("\n...........................................\n");

  printf("STUDENTS TRANSPORT MANAGEMENT SYSTEM ");
  printf("\n");
  printf("...........................................\n");
  printf(" s -> Start Journey\n c -> Check Seat Availability\n b -> My Booking\n a -> admin Login\n q -> quit");
  printf("\n...........................................\n>>");
  scanf(" %c",&opt );


  while(1)
  {

      char buslist;
      char username[NAME_LEN];
      char password[NAME_LEN];
      int flag =0;
      // exit the program
      if(opt == 'q' || opt == 'Q')
      { fclose(fopen("userdata.txt", "w"));
        break;
      }
      // admin section
      if (opt == 'a' || opt == 'A')
      {
        system("cls");
        // check for admin details
        printf("Please provide username \t");
        scanf("%s",&username );
        printf("Please provide password \t");
        scanf("%s",&password );
        printf("Please wait! Validating Details\n");

        //if admin
        if(!strcmp(username,"admin")&& !strcmp(password,"admin"))
        {
          printf("Access Granted!\n");
          flag = 1;
        }
        else
        {
          printf("Access Denied!\n");
          flag = 0;
        }

        // if admin
        if(flag)
        {
          int opt;
          int srn;
          printf("...........................................\n");
          printf(" 1. -> Show Stops\n 2. -> Display Routes\n 3. -> Display Passengers\n 4. -> Staticts\n 5. -> remove passenger\n");
          printf("\n...........................................\n>>");

          scanf("%d",&opt);

          switch (opt) {
            case 1:   system("cls");
                      printf(" Displaying Bus Stops\n\n");
                      //printing the available stops
                      int n = sizeof(stops)/sizeof(stops[0]);
                      int i =0;
                      for ( i = 0; i < n; i++) {
                        if(stops[i]!=0)
                        {
                          printf("%d\t", stops[i]);
                        }


                      }
                        printf("\n" );
                      break;
            case 2:   system("cls");
                      printf(" Displaying Bus Routes\n");
                      printGraph(graph);
                      break;

            case 3:     system("cls");
                        printf(" Display Bus List\n A , B , C , D , E\t>>");
                        scanf(" %c",&buslist );
                          switch (buslist) {
                          case 'A': displayList(A);
                                    break;
                          case 'B': displayList(B);
                                    break;
                          case 'C': displayList(C);
                                    break;
                          case 'D': displayList(D);
                                    break;
                          case 'E': displayList(E);
                                  break;
                                }
                                break;

            case 4:       // Displaying the bus Staticts
                          system("cls");
                          printf("\n");
                          printf("A\t%d\tCollege\n",A->capacity);
                          printf("B\t%d\tCollege\n",B->capacity);
                          printf("C\t%d\tCollege\n",C->capacity);
                          printf("D\t%d\tCollege\n",D->capacity);
                          printf("E\t%d\tCollege\n",E->capacity);
                          break;

            case 5:       //searching for user inside the bus
                            system("cls");
                            printf("Please Provide the Bus Number? A B C D E\t>>>");
                            scanf(" %c",&busname );
                            verifydetails(A,B,C,D,E,busname);
                            break;


            default:
                            printf("Please check it again, inavlid input");

          }

        }

      }

      switch (opt)
      {
        case 'c':   // checking bus availabilty
                    system("cls");
                    printf("Please fill the following details to verify!\n");
                      printf("....................................................................\n");
                    printf("Please Enter SRN\tPES2201800" );
                    int srn;
                    scanf("%d", &srn);

                    if(srn>999 || srn == -1)
                    {
                      system("cls");
                      printf("Please enter a valid SRN\n" );

                      break;
                    }
                    else
                    {
                        if(!check_in_database(srn))
                        {
                          //printing available stops
                          printf("Availabile Stops\t" );
                          for (int  i = 0; i < n-1; i++) {
                            if(stops[i]==0)
                            {
                              printf("College(%d)\t", stops[i]);
                            }
                            else
                            {
                              printf("%d\t", stops[i]);
                            }
                          }
                          printf("\n");

                          int stop ;
                          printf("Which is your Stop?\t" );
                          scanf("%d",&stop);
                          if(!checkforStop(stop))
                          {
                            system("cls");
                            printf("Sorry %d Stop not available\n",stop );
                            break;
                          }
                          else
                          {

                            printf("Which bus? A B C D E \t");
                            scanf(" %c",&busname );
                            if(!(busname == 'A' ||busname == 'B' ||busname == 'C' ||busname == 'D' ||busname == 'D' ||busname == 'E'))
                            {
                              system("cls");
                              printf("\nIncorrect inputs, please be careful!");

                              break;
                            }
                            printf("\n");
                            checkBusAvailabitily(A,B,C,D,E,busname,srn,stop);
                            break;
                          }
                        }
                        else
                        {
                          system("cls");
                          printf("Already booked! Please Modify \n" );
                          break;
                        }
                    }
                    break;

        case 'b':   //Checking the details of the user in te bus
                    system("cls");
                    printf("Welcome back\n");
                    printf("Please Enter Your Bus Number?A B C D E\t>>>");
                    scanf(" %c",&busname );
                    verifydetails(A,B,C,D,E,busname);
                    break;

        case 's':   //starting the journey
                    system("cls");
                    printf("\nStarting Journey\nChecking Buses\n");
                    printf("Bus\t Capacity\t State\n");
                      // if all the BUSES is completely filled start journey
                      if(withdraw_buses(A,A,B,C,D,E))
                      {
                        //starting the journey for bus A
                          start_journey(A,graph);
                          fclose(fopen("userdata.txt", "w"));
                      };
                      if(withdraw_buses(B,A,B,C,D,E))
                      {
                        //starting the journey for bus B
                          start_journey(B,graph);
                          fclose(fopen("userdata.txt", "w"));
                      };
                      if(withdraw_buses(C,A,B,C,D,E))
                      {
                        //starting the journey for bus C
                        start_journey(C,graph);
                        fclose(fopen("userdata.txt", "w"));
                      };
                      if(withdraw_buses(D,A,B,C,D,E))
                      {
                        //starting the journey for bus D

                        start_journey(D,graph);
                        fclose(fopen("userdata.txt", "w"));
                      };
                      if(withdraw_buses(E,A,B,C,D,E))
                      {
                        //starting the journey for bus E
                        start_journey(E,graph);
                        fclose(fopen("userdata.txt", "w"));
                      };

                    break;
      default:
                  printf("Thankyou check again!\n");
                    }



      printf("\n");
      printf("...........................................\n");
      printf(" s -> Start Journey\n c -> Check Seat Availability\n b -> My Booking\n a -> admin Login\n q -> quit");
      printf("\n...........................................\n>>");
      scanf(" %c",&opt );

  }


fclose(fopen("userdata.txt", "w"));
}
