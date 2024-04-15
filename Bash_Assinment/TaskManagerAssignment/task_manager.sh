#!/bin/bash

#######################################Functions used###########################################
    AddTask()
    {
        echo "Enter the task Name:"
        read taskname

        echo "Enter task details:"
        read taskdetails

    #add the user task details to the file
        echo $taskname    >> tasks.txt
        echo $taskdetails >> tasks.txt
        echo "Mark:"      >> tasks.txt
    }
    ViewTask()
    {
        cat tasks.txt
        echo ""
    }
    MarkTask()
    {
        echo "Please enter the task name to mark"

        read task_name_to_be_marked
    #search for the task name in tasks.txt and then pipeline it to awk to extract the line number only
    #but we need to change the seperator to : becase the line number is right before the :
    #then print the value of that first data before the seperator : and assign the value of the 
    #printed data to linenumber
        linenumber=$(grep -n -i "$task_name_to_be_marked" tasks.txt | awk -F: '{print $1}')
        linenumber2=$((linenumber+1))
        linenumber3=$((linenumber+2))

        # cat specific lines starting from where the user input was found in the tasks file
        firstline=$(sed -n ${linenumber}p tasks.txt)
        secondline=$( sed -n ${linenumber2}p tasks.txt)
        thirdline=$( sed -n ${linenumber3}p tasks.txt)

        if [ -z "$linenumber" ]; then
        echo "Task not found"
        else
            #task found then we  edit the "Mark" line in place
            if   [ "$firstline"  == "Mark:" ]; then 
            # the -i is to save the changes to the file and the * is to replace the entire line
                sed -i "${linenumber}s/.*/Mark:Done/" tasks.txt
                echo 'Task Marked'
            elif [ "$secondline" == "Mark:" ]; then
                sed -i "${linenumber2}s/.*/Mark:Done/" tasks.txt
                echo 'Task Marked'
            elif [ "$thirdline"  == "Mark:" ]; then
                sed -i "${linenumber3}s/.*/Mark:Done/" tasks.txt
                echo 'Task Marked'
            fi
        fi
    }

    DeleteTask()
    {
        echo "Please enter the task name to delete"

        read task_name_to_be_deleted

        linenumber=$(grep -n -i "$task_name_to_be_deleted" tasks.txt | awk -F: '{print $1}')
        linenumber2=$((linenumber+1))
        linenumber3=$((linenumber+2))

        # cat specific lines starting from where the user input was found in the tasks file
        firstline=$(sed -n ${linenumber}p tasks.txt)
        secondline=$( sed -n ${linenumber2}p tasks.txt)
        thirdline=$( sed -n ${linenumber3}p tasks.txt)

        if [ -z "$linenumber" ]; then
        echo "Task not found"
        else
        #delete the 3 lines representing the task and inform the user
            sed -i "${linenumber3} d" tasks.txt
            sed -i "${linenumber2} d" tasks.txt
            sed -i "${linenumber} d" tasks.txt
            echo 'Task Deleted'
        fi
    }
#######################################Functions used########################################### 

    
    
    
#########################################start of program######################################

#check is a task file exists or not and if not create one
    if [ -f tasks.txt ]; then
        echo 'Tasks file detected...     '
    else
        echo 'Creating a new tasks file !'
        touch tasks.txt   
    fi

    echo "1-Add tasks  2-view tasks 3-Mark tasks 4-Delete tasks"
    read UserInput

    case $UserInput in
    1) AddTask;;
 
    2) ViewTask;;
 
    3) MarkTask;;
     
    4) DeleteTask;;
 
    *) echo "invalid input";;

    esac
#########################################End of program######################################


