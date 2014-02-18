#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

#include "tube.h"

/* internal helper function which allocates a dynamic 2D array */
/*START OF FUNCTION allocate_2D_array*/
char **allocate_2D_array(int rows, int columns) {
	char **m = new char *[rows];
	assert(m);
	for (int r=0; r<rows; r++) {
		m[r] = new char[columns];
		assert(m[r]);
	}
	return m;
}
/* END OF FUNCTION allocate_2D_arra*/


/* internal helper function which deallocates a dynamic 2D array */
/*START OF FUNCTION deallocate_2D_array*/
void deallocate_2D_array(char **m, int rows) {
	for (int r=0; r<rows; r++)
		delete [] m[r];
	delete [] m;
}
/* END OF FUNCTION deallocate_2D_array*/


/* internal helper function which gets the dimensions of a map */
/*START OF FUNCTION get_map_dimensions*/
bool get_map_dimensions(const char *filename, int &height, int &width) {
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
/* END OF FUNCTION get_map_dimensions*/


/* pre-supplied function to load a tube map from a file*/
/*START OF FUNCTION load_map*/
char **load_map(const char *filename, int &height, int &width) {

	bool success = get_map_dimensions(filename, height, width);
  
	if (!success)
		return NULL;

	char **m = allocate_2D_array(height, width);
  
	ifstream input(filename);

	char line[512];
	char space[] = " ";

	for (int r = 0; r<height; r++) {
		input.getline(line, 512);
		strcpy(m[r], line);
		while ( (int) strlen(m[r]) < width )
			strcat(m[r], space);
	}
  
	return m;
}
/* END OF FUNCTION load_map*/


/* pre-supplied function to print the tube map */
/*START OF FUNCTION print_map*/
void print_map(char **m, int height, int width) {
	cout << setw(2) << " " << " ";
	for (int c=0; c<width; c++)
		if (c && (c % 10) == 0) 
			cout << c/10;
		else
			cout << " ";
	cout << endl;

	cout << setw(2) << " " << " ";
	for (int c=0; c<width; c++)
		cout << (c % 10);
	cout << endl;

	for (int r=0; r<height; r++) {
		cout << setw(2) << r << " ";    
		for (int c=0; c<width; c++) 
			cout << m[r][c];
		cout << endl;
	}
}
/* END OF FUNCTION print_map*/


/* pre-supplied helper function to report the errors encountered in Question 3 */
/*START OF FUNCTION */
const char *error_description(int code) {
	switch(code) {
	case ERROR_START_STATION_INVALID: 
		return "Start station invalid"; //1
	case ERROR_ROUTE_ENDPOINT_IS_NOT_STATION:
		return "Route endpoint is not a station"; //2
	case ERROR_LINE_HOPPING_BETWEEN_STATIONS:
		return "Line hopping between stations not possible"; //3
	case ERROR_BACKTRACKING_BETWEEN_STATIONS:
		return "Backtracking along line between stations not possible"; //4
	case ERROR_INVALID_DIRECTION:
		return "Invalid direction"; //5
	case ERROR_OFF_TRACK:
		return "Route goes off track"; //6
	case ERROR_OUT_OF_BOUNDS:
		return "Route goes off map"; //7
	case ERROR_UNKNOWN_ERROR:
		return "Unknown error happened during route verification. Please contact coder!"; //8
	}
	return "Unknown error. Please contact coder!"; //8
}
/* END OF FUNCTION*/


/*presupplied helper function for converting string to direction enum */
/*START OF FUNCTION*/
Direction string_to_direction(const char *token) {
	const char *strings[] = {"N", "S", "W", "E", "NE", "NW", "SE", "SW"};
	for (int n=0; n<8; n++) {
		if (!strcmp(token, strings[n])) 
			return (Direction) n;
	}
	return INVALID_DIRECTION;
}
/* END OF FUNCTION*/

/*ex 1 function */
/*START OF FUNCTION get_symbol_position*/
bool get_symbol_position(char** map, int height, int width, char target, int& r, int& c)
{
	r = -1 ;
	c = -1 ;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width ; j++)
			if(map[i][j] == target)
				{
					r = i;
					c = j;
					return 1;
				}
	return 0;
}
/* END OF FUNCTION*/


/*ex2 function*/
/*START OF FUNCTION get_symbol_for_station_or_line*/
char get_symbol_for_station_or_line(char* tube)
{
	char symbol = ' ';
	char file_name[2][20] = {{"lines.txt"}, {"stations.txt"}};
	char temp;
	if((temp = get_symbol_for_name(tube, file_name[0])) != ' ')
		{
			symbol = temp; 
			return symbol;
		}
	else if((temp = get_symbol_for_name(tube, file_name[1])) != ' ')
		{
			symbol = temp;
			return symbol; 
		}
	else return symbol;
}
/*END OF FUNCTION get_symbol_for_station_or_line*/

/*this function is for exercise 2 and 3 both to call it by parsing different filenames. */
/*START OF FUNCTION get_symbol_for_station_or_line*/
char get_symbol_for_name(char* tube, char* file_name)
{
	char symbol = ' ';
	ifstream input(file_name);
	while(!input.eof())
		{
			char input_name[100] = "";
			char temp[100] = "";
			input.get(symbol);
			input.ignore(1);
			input.getline(input_name,100);
			strcpy(temp,tube);
			if(!strcmp(input_name, temp))
				{
					input.close();
					return symbol;
				}
			symbol = ' ';
		}
	input.close();
	return symbol;
}

/*this is the function to check for err 2 and 3: find the symbol of give r,c; check stations.txt for matches */
/*START OF FUNCTION get_station_by_position*/
bool get_station_by_position(char** map, int r, int c, char* station_name)
{
	char file_name[20] = "stations.txt";
	ifstream input(file_name);
	char position_content = map[r][c];
	while(!input.eof())
		{
			char temp = ' ';
			input.get(temp);
			input.ignore(1);
			input.getline(station_name, 30);
			if(position_content == temp) 
				return 1;
		}
	return 0;
}
/* END OF FUNCTION get_station_by_position*/

/*helper function for ex3: put the string of directions into an 2 dimension array for seperate operation*/
/*START OF FUNCTION seperate_route_direction */
void seperate_route_direction(char route[], char** direction, int &number_of_move)
{
	int i = 0;
	for (char *dir = route ;*dir != '\0'; dir++)
		{
			if( *dir == ',')
				{
					direction[number_of_move++][i] = '\0';
					i = 0;
				}
			else
				direction[number_of_move][i++] = *dir; //assign the pointed char to the array.
		}
}
/* END OF FUNCTION seperate_route_direction */

/* helper function for ex3: do the direction switch in a seperate function */
/* START OF FUNCTION direction_switch*/
void direction_switch(char direction[], int &current_height, int &current_width)
{
	switch ( string_to_direction(direction) ) 
		{
		case 0 : {current_height--; break;}
		case 1 : {current_height++; break;}
		case 2 : {current_width--; break;}
		case 3 : {current_width++; break;}
		case 4 : {current_height--; current_width++; break;}
		case 5 : {current_height--; current_width--; break;}
		case 6 : {current_height++; current_width++; break;}
		case 7 : {current_height++; current_width--; break;}
		}
}
/*END OF FUNCTION direction_switch*/

/* question 3 function to determine if a provided route is valid */
/* START OF FUNCTION validate_route*/
int validate_route(char** map, int height, int width, char station[], char route[], char destination[])
{
	// int dir_int,r,c,last_r,last_c,before_last_r,before_last_c;
	char** direction = new char *[100];
	for( int i = 0; i < 100; i++)
		direction[i] = new char[3];
	for (int i = 0 ; i < 100 ; i ++) //initialize the array to be exactly empty before giving values
		for (int j = 0 ; j < 3 ; j ++)
			direction [i][j] = '\0';

	int count_for_interchange = 0;
	int number_of_move = 0;
	seperate_route_direction(route, direction, number_of_move);

	/*check for err 1:*/
	if (get_symbol_for_name(station, "stations.txt") == ' ')
		return -1;
  
	int start_width, start_height;
	get_symbol_position(map, height, width, get_symbol_for_name(station, "stations.txt"), start_height, start_width);

	/*prepared values for checking err 3 and 4*/
	int last_height = start_height; int before_last_height = start_height;
	int last_width = start_width; int before_last_width = start_width;
	int current_height = start_height; int current_width = start_width;
  
	/* a for loop for all the movements */
	for ( int k = 0; k <= number_of_move; k++)
		{
			/*prepare for err 3 and 4 checking: record down position for the last two operations.*/
			before_last_height = last_height;
			before_last_width = last_width; 
			last_height = current_height;
			last_width = current_width;
			char symbol_record_last = map[last_height][last_width];
    
			direction_switch(direction[k], current_height, current_width);// call for function to change height and width according to direction

			/*check for err 5: invalid direction. as a result of switch in helper function*/
			if ( string_to_direction(direction[k]) > 7 || string_to_direction(direction[k]) < 0)
				return -5;
			

			/*check for err 7: off map*/
			if(current_height > height || current_height < 0 || current_width > width || current_width < 0)
				return -7;
   
			/*check for err 6: route off track*/
			if (map[current_height][current_width] == ' ') 
				return -6;
 
			/*check for err 4: backtracking*/
			if(current_height == before_last_height && current_width == before_last_width) 
				return -4;
     
			/*check for err 3:line hopping*/
			char current_name[30], last_name[30]; 
			strcpy(current_name, "");
			strcpy(last_name, "");
			if (map[current_height][current_width] != symbol_record_last)
				if(!get_station_by_position(map,current_height, current_width, current_name) && !get_station_by_position(map, last_height, last_width, last_name) )
					return -3;
             
			/*to find the situation of an interchange*/
			char station_name[30];
			strcpy(station_name, "");
			if((map[current_height][current_width] != map[before_last_height][before_last_width] ) && get_station_by_position(map, last_height, last_width, station_name) && (before_last_height != last_height || before_last_width != last_width))
				count_for_interchange++;
		}
 
	/*check for err 2: end point not a station*/
	char station_name[30]; 
	strcpy(station_name,"");
	if (get_station_by_position(map, current_height, current_width, station_name)) //the case of a valid search
		{
			strcpy(destination, station_name);
			return count_for_interchange;
		}
	else return -2;

	/*if none of the error check matches and unknown error and the search is not valid, return default code*/
	return -8; 
}
/* END OF FUNCTION validate_route*/
