/* You are pre-supplied with the functions below. Add your own 
   function prototypes to the end of this file. */
#ifndef MAZE_H
#define MAZE_H
/* helper functions to allocate and deallocate dynamic 2D arrays */
char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);

/* pre-supplied function to load a maze from a file */
char **load_maze(const char *filename, int &height, int &width);

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width);

/*exercise 1*/
bool find_marker(char ch,char** maze,int height,int width,int& row,int& column);

/*exercise 2*/
bool valid_solution(char* path, char** maze, int height, int width);

/*exercise 3*/
char* find_path(char** maze, int height, int width, char start, char end);

#endif //MAZE_H
