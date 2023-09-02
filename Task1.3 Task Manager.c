#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tasks[100001][101];
int countTasks;

void addingTask(){
    
    if( countTasks >= 100001 ){
        printf( "\n Max number of tasks have been reached\n" );
        return;
    }
    
    printf( "\nEnter task description: " );

    scanf( "%s", tasks[countTasks]);

    countTasks++;

    printf( "\nTask added successfully!\n" );

}

void taskView(){

    printf( "\nCurrent Tasks:" );

    for(int i=0; i<countTasks; i++){

        printf( "\nTask ID: %d", i+1 );
        printf( "\nDescription: %s\n", tasks[i] );

    }

}

void taskRemove(){

    printf( "\nEnter task ID to remove: " );
    int id; scanf( "%d", &id );

    if( id > countTasks ){
        printf( "\nInvalid ID " );
        return;
    }

    for(int i=id-1; i<countTasks; i++){
        strcpy(tasks[i],tasks[i+1]);
    }
    countTasks--;
    
    printf( "\nTask removed successfully!\n" );
    
}


int main()
{
    //View to User welcome message and the task manager
    printf( "\n\n\t\t_Welcome User_\nMinions Task Manager\n1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit" );

    //Selection progress
    printf( "\nSelect an option: " );
    int selectionNo;
    scanf( "%d", &selectionNo );
    countTasks = 0;

    while(1)
    {
        switch( selectionNo )
        {

        case 1:
            addingTask();
            break;
        case 2:
            taskView();
            break;
        case 3:
            taskRemove();
            break;
        case 4:
            printf( "\nExiting Minions Task Manager. Have a great day!" );
            exit(0);
            break;
        default:
            printf( "Not Valid Option" );
        }
        printf( "\nSelect an option: " );
        scanf( "%d", &selectionNo );
    }

    return 0;
}
