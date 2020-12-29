/*
 * stack.h
 */
 
typedef struct ratNum_tag {

	int *numerator;
	int *denominator;
} ratNum;

typedef struct stack_elt_tag {

	struct ratNum_tag *number;
	struct stack_elt_tag *next;
} stack_elt;

typedef struct {
	stack_elt *top, *bottom;
} stack;

void init_stack (stack *st);
void add_int_to_top (stack *st, int numer);
void add_num_to_top (stack *st, int numer, int denom);
void remove_num_from_top (stack *st);
void delete_all_entries (stack *st);
void print_stack (stack *st);
void print_top (stack *st);
int gcd (int a, int b);
void simplify (ratNum *number);
void duplicate_top (stack *st);
void multiply_and_replace (stack *st);
void add_and_replace (stack *st);
void subtract_and_replace (stack *st);
void divide_and_replace (stack *st);
void swap_top_two (stack *st);
