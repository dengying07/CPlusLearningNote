#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include "maze.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

/* helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* helper function for internal use only which gets the dimensions of a maze */
bool get_maze_dimensions(const char *filename, int &height, int &width) {
  char line[512];
  
  ifstream input(filename);

  height = width = 0;

  input.getline(line,512);  
  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);  
  }

  if (height > 0)
    return true;
  return false;
}

/* pre-supplied function to load a maze from a file*/
char **load_maze(const char *filename, int &height, int &width) {

  bool success = get_maze_dimensions(filename, height, width);
  
  if (!success)
    return NULL;

  char **m = allocate_2D_array(height, width);
  
  ifstream input(filename);

  char line[512];

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
  }
  
  return m;
}

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width) {
  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0) 
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(4) << r << " ";    
    for (int c=0; c<width; c++) 
      cout << m[r][c];
    cout << endl;
  }
}

/*exercise 1*/
// r -- height -- maze[r][c]
bool find_marker(char ch,char** maze,int height,int width,int& row,int& column){
    for(int i=0; i<width; i++ ){
        for(int j=0; j<height; j++){
            if(maze[j][i] == ch){
                row = j;
                column = i;
                return true;
            }
        }
    }
    return false;
    return true;
}

/*exercise 2*/
bool valid_solution(char* path, char** maze, int height, int width){
    int r,c;
    if(!find_marker('>',maze, height, width, r, c))
        return false;
    for(int i=0; path[i]!= '\0'; i++){
        switch(path[i]){
        case 'E':c++;break;
        case 'W':c--;break;
        case 'N':r--;break;
        case 'S':r++;break;
        }
        if(maze[r][c]!= ' '){
            if(maze[r][c] == 'X' && path[i+1] == '\0'){
                return true;
            }
            return false;
        }
    }
    return false;
}

/*exercise 3*/
//bool gone_before(int r,int c,int gone[][2]);
//void put_in_gone(int r, int c, int gone[][2]);
//bool recursive_find(char** maze,int height,int width,int& r,int& c,char start, char end,int gone[][2],char* path);
bool gone_before(int r,int c,int** gone){
    for(int i=0; i<1000;i++){
        if(gone[i][0] == r && gone[i][1] == c){
            return true;
        }
        if(gone[i][0] == -1){
            return false;
        }
    }
    return false;
}

void put_in_gone(int r, int c, int** gone){
    int i=0;
    for(i = 0; i<1000;i++){
        if(gone[i][0]== -1){
            break;
        }
    }
    gone[i][0] = r; gone[i][1] = c;
}
bool recursive_find(char** maze,int height,int width,int r,int c,char start, char end,int** gone,char* path){
    if(maze[r][c] == end){
        return true;
    }
    cout << "test " << r << "  " << c << " ^ ";
    if(r >= height || c>= width || r<0 || c<0){
        return false;
    }
    if(maze[r][c]!= ' ' && maze[r][c]!= start && maze[r][c] != end){
        return false;
    }
    put_in_gone(r,c,gone);
    strcat (path,"E");
    if(path[strlen(path)-2] != 'W' &&recursive_find(maze,height,width,r,c+1,start,end,gone,path) && !gone_before(r,c+1,gone)){
        return true;
    }
    strcat (path,"S");
    if(path[strlen(path)-2] != 'N' &&recursive_find(maze,height,width,r+1,c,start,end,gone,path) && !gone_before(r+1,c,gone)){
        return true;
    }
    strcat (path,"W");
    if(path[strlen(path)-2] != 'E' &&recursive_find(maze,height,width,r,c-1,start,end,gone,path) && !gone_before(r,c-1,gone)){
        return true;
    }
    strcat (path,"N");
    if(path[strlen(path)-2] != 'S' && recursive_find(maze,height,width,r-1,c,start,end,gone,path) && !gone_before(r-1,c,gone)){
        return true;
    }
}



char* find_path(char** maze, int height, int width, char start, char end){
    int gone[1000][2] = {-1};
    int r,c,end_r,end_c;
    static char path[512] = "";
    if(!find_marker(start,maze,height,width,r,c)){
        return "no solution";
    }
    if(!find_marker(end,maze,height,width,end_r,end_c)){
        return "no solution";
    }
    if(recursive_find(maze,height,width,r,c,start,end,gone,path)){
        return path;
    }
    return "no solution";
}
