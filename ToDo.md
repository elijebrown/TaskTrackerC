<!-- 1. verify and improve init task and init list
    - malloc error handling for reliability -->
<!-- 1. cleanupData, cleanupList functions needed. Memory Leaks!!! -->
1. remove by id function
    - faster and preferred method of removing task
1. build parser
    - readAll
    - Write (aka overwrite/save function)
    - (maybe) append
2. print task
3. print task list


## future ideas: 
1. parent/child tasks (subdirectories)
	- a main task (let's say a class)
		- can contain subtasks (like a specific project in that class)
		-tracking time of the project also adds to the main task time
		tracking time of the parent task only adds to parent task and its parent, not its children. 
	- shows this relation similar to directories when you printTasks
	
	
## different menu modes:
- menu mode: prints menu upon every loop iteration
- quiet mode: input h for help with all commands, prints nothing to terminal upon new iteration
1. launch program in either mode with command line argument, allow user to switch modes in program. 
