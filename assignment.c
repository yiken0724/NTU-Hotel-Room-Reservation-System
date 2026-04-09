/*custom header*/
#include <stdio.h>
#include <string.h>

	/*end_edit*/
	/*edit*/
/* Write your code here */

int main()
{
    int choice, roomID[5] = {1,2,3,4,5};
    int status[5]= {0,0,0,0,0};
    char customerName[5][50] = {"0","0","0","0","0"};
    

//funtion definition: listOccupiedRooms()
    void listOccupiedRooms()
    {
        int i; //variable declaration
    
        if ((status[0] == 0) && (status[1] == 0) && (status[2] == 0) && (status[3] == 0) && (status[4] == 0))
        {
            printf("The hotel is empty\n");
        }
        else
            for (i=0; i<=4; i++)
            {
                if (status[i]!=0)
                {
                    printf("roomID: %d\n", roomID[i]);
                    printf("customer name: %s\n", customerName[i]);
                }
            }
    }
    
//function definition: prompt_user_input()
    int prompt_user_input()
    {
        int dummy_var;
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &dummy_var);
        
        if ((dummy_var < 1) || (dummy_var > 5))
            dummy_var = prompt_user_input() + 1;
        return (dummy_var - 1);
    }
    
//funtion definition: assignRoom()
    void assignRoom()
    {
        int assign_room_id; 
        char customer_name[50], *p; //variable declaration

        if ((status[0] == 1) && (status[1] == 1) && (status[2] == 1) && (status[3] == 1) && (status[4] == 1))
            printf("The hotel is full\n");
        else
        {
            assign_room_id = prompt_user_input();
            
            if (status[assign_room_id]!=0)
            {
                printf("Occupied! Enter another roomID\n");
                assignRoom(); //restart the whole function
            }
            else
            { 
                printf("Enter customer name:\n");
                fgetc(stdin);
                fgets(customer_name, 30, stdin); //get input
                
                if ( p=strchr(customer_name, '\n')) //convert to char string
                    *p = '\0';
                
                //assign status and name of customer
                strcpy(customerName[assign_room_id], customer_name);
                status[assign_room_id] = 1;
                printf("The room has been assigned successfully\n");
            }
        }
    }
    
//funtion definition: removeRoom()
    void removeRoom()
    {
        int remove_room_id; //variable declaration
        
        if ((status[0] == 0) && (status[1] == 0) && (status[2] == 0) && (status[3] == 0) && (status[4] == 0))
          printf("All the rooms are empty\n"); 
          
        else
        {
            remove_room_id = prompt_user_input(); //prompt user to input 
            if (status[remove_room_id] == 0)
            {
                printf("Empty! Enter another roomID for removal\n");
                removeRoom(); //restart the whole funtion
            }
            else if (status[remove_room_id]==1)
            {
                //remove status and name of customer
                status[remove_room_id] = 0;
                strcpy(customerName[remove_room_id], "0"); 
                printf("Removal is successful\n");
            }
        }
    }
    
//funtion definition: findCustomer()    
    int findCustomer()
    {
        int j;
        char find_name[50], *p ; //variable declaration
        
        printf("Enter customer name:\n");
        fgetc(stdin);
        fgets(find_name, 50, stdin); //get input
        if (p=strchr(find_name,'\n')) //change to char string
            *p = '\0'; 

        for (j=0; j<=4; j++)
        {
            if (strcasecmp(find_name,customerName[j]) == 0)
            {
                printf("The target customer name is found\n");
                printf("roomID: %d\n", roomID[j]);
                printf("customer name: %s\n", customerName[j]);
                return 0;
            }
        }
        
        printf("The target customer name is not found\n");
    }


//menu NTU Hotel Room Reservation Program
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");
    
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("listOccupiedRooms():\n");
                listOccupiedRooms();
                break;
            case 2:
                printf("assignRoom():\n");
                assignRoom();
                break;
            case 3:
                printf("removeRoom():\n");
                removeRoom();
                break;
            case 4:
                printf("findCustomer():\n");
                findCustomer();
                break;
            default:
                continue;
        }
        
    } while (choice != 5);
    
}

	/*end_edit*/

