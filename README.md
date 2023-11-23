# TaskTrackerC
TaskTracker but in C hehe 


`gcc -Wall -Wextra -g -o test main.c list.c data.c`

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind-out.txt \
         ./test
