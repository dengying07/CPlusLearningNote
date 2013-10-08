#ifndef EX2_H
#define EX2_H
int print_preliminary_message ();
void input_table_specifications(int &this_lower, int &this_upper, int &this_step);
int print_message_echoing_input(int lower, int upper, int step);
int print_table(int lower, int upper, int step);
double celsius_of(int fahr);
double absolute_value_of(int fahr);
#endif
