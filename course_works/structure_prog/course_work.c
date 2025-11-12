#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_POWER 100
#define EPSILON 1.e-10

typedef struct monomial
{
    double coefficient;
    int power;
} monomial;

typedef struct polynomial
{
    monomial nomos[100]; /*nomos - часть*/
    int counted_nomos;
    int max_power;
} polynomial;

typedef struct interval
{
    double left_border;
    double right_border;
} interval;

int read_interval(interval *borders);

int read_coefficient(char *cursor, double *temp_coefficient);

int input_converter(char *src, polynomial *equation);

int calculate_result(double **result, polynomial *equation, interval *borders);

double get_y(polynomial *poly, double x);

polynomial *get_derivative(polynomial *poly);

double binary_search(polynomial *poly, double left_border, double right_border);

double *get_result(polynomial *poly, double left_border, double right_border, int *counter);

void copy_polynomial(polynomial *poly_src, polynomial *poly_dest);

void print_menu()
{
    printf("------------------------------\n"

           "\tMenu\n"
           "\t1.Add interval\n"
           "\t2.Add polynomial\n"
           "\t3.Delete data\n"
           "\t4.View result\n"
           "\t0.Exit\n"
           "------------------------------\n\n");
}

int main()
{
    int counted_answers = 0;
    // double *answer = NULL;
    int program_mode = 0;
    interval find_in;
    polynomial equation;
    char input_str[200];
    int i;
    double *final_result;
    for (i = 0; i < 200; i++)
    {
        input_str[i] = 0;
    }
    
    for (i = 0; i < MAX_POWER; i++)
    {
        equation.nomos[i].coefficient = 0.0;
        equation.nomos[i].power = 0;
    }
    print_menu();
    scanf("%d", &program_mode);
    while (program_mode != 0)
    {
        switch (program_mode)
        {
        case 1:
            scanf("%*[^\n]");
            printf("Enter the interval using space between borders:\n");
            if (read_interval(&find_in) != 0)
            {
                printf("Entered interval is not valid!\n");
            }
            else
            {
                printf("Entered interval is:\n");
                printf("%lf %lf\n", find_in.left_border, find_in.right_border);
            }
            // printf("%e", EPSILON);
            break;

        case 2:
            scanf("%*[^\n]");
            scanf("%s", input_str);
            equation.counted_nomos = input_converter(input_str, &equation);
            break;
        case 3:
            for (i = 0; i < MAX_POWER; i++)
            {
                equation.nomos[i].coefficient = 0.0;
                equation.nomos[i].power = 0;
            }
            equation.counted_nomos = 0;
            equation.max_power = 0;
            break;
        case 4:
            for (i = 0; i < equation.counted_nomos; i++)
            {
                printf("%lfx^%d\n", equation.nomos[i].coefficient, equation.nomos[i].power);
            }
            printf("\n");

            // counted_answers = calculate_result(&answer, &equation, &find_in);

            // for (i = 0; i < counted_answers; i++)
            // {
            //     printf("%lf ", answer[i]);
            // }

            // // printf("%lf\n", get_y(&equation, 1));
            // printf("\nNOT HERE\n");
            // printf("\n\n%lf - result of binary search\n", binary_search(&equation,find_in.left_border, find_in.right_border));
            // printf("\nMAYBE HERE\n");
            final_result = get_result(&equation, find_in.left_border, find_in.right_border, &counted_answers);
            for (i = 0; i < (int)sizeof(final_result); i++)
            {
                printf("%lf\n", final_result[i]);
            }

            // printf("%lf",*get_result(&equation, find_in.left_border, find_in.right_border, &counted_answers));

            break;
        }

        print_menu();
        scanf("%d", &program_mode);
        scanf( "%*[^\n]" );
    }
    return 0;
}

int read_interval(interval *inter)
{
    int flag = 0;
    scanf("%lf %lf", &inter->left_border, &inter->right_border);
    if (inter->left_border > inter->right_border)
    {
        flag = 1;
    }
    scanf( "%*[^\n]" );
    return flag;
}

int read_coefficient(char *cursor, double *temp_coefficient)
{
    int result = 0;

    if ('0' <= *cursor && *cursor <= '9')
    {
        sscanf(cursor, "%lf%n", temp_coefficient, &result); /*считываем из курсора число double и кол-во считанных символов записываем в result*/
        fflush(stdin);
    }
    cursor += result;
    if (*cursor == '*')
    {
        result++;
    }

    return result;
}

int input_converter(char *src, polynomial *equation)
{
    if (src == NULL || equation == NULL)
    {
        return -1;
    }
    int counted_terms = 0;
    char line[MAX_POWER];
    strncpy(line, src, MAX_POWER - 1);
    line[MAX_POWER - 1] = '\0';
    char *cursor = line;
    double sign = 1;
    double temp_coeff = 0, temp_degree = 0;
    monomial temp_monomial = {0.0, 0};
    int flag = 0;
    int is_have_num = 1;
    int pow_quantity = 0;
    int max_power = 1;
    while (*cursor != '\0')
    {

        is_have_num = 1;
        temp_monomial.coefficient = 0.0;
        temp_monomial.power = 1;
        sign = 1;
        while (*cursor == ' ')
        {
            cursor++;
        }

        if (*cursor == '+')
        {
            cursor++; /*можно оптимизировать*/
        }
        else if (*cursor == '-')
        {
            sign = -1;
            cursor++; /*можно оптимизировать*/
        }

        while (*cursor == ' ')
        {
            cursor++;
        }

        int counted_digit = 0;
        counted_digit = read_coefficient(cursor, &temp_coeff);

        // printf("%lf %d\n", temp_coeff, counted_digit);

        if (counted_digit <= 1)
        {
            is_have_num = 0;
            if (counted_digit>0)
            {
                cursor += counted_digit;
            }
        }

        else
        {
            cursor += counted_digit;
        }

        while (*cursor == ' ')
        {
            cursor++;
        }

        
        if (*cursor == 'X' || *cursor == 'x')
        {
            if (is_have_num == 0)
            {
                temp_coeff = 1;
            }
            
            cursor++;
        }
        else
        {
            temp_monomial.power = 0;
        }

        // printf("ERROR 6\n");
        // printf("%lf", temp_coeff);

        temp_monomial.coefficient = temp_coeff * sign;

        while (*cursor == ' ')
        {
            cursor++;
        }

        if (*cursor == '^')
        {       
            cursor++;

            while (*cursor == ' ')
            {
                cursor++;
            }

            if ('0' <= *cursor && *cursor <= '9')
            {
                sscanf(cursor, "%lf%n", &temp_degree, &pow_quantity); /*считываем из курсора число double и кол-во считанных символов записываем в result*/
                cursor += pow_quantity;
                temp_monomial.power = temp_degree;
                // printf("%d", pow_quantity);
            }
        }

        while (*cursor == ' ')
        {
            cursor++;
        }

        if (flag == 0)
        {
            equation->nomos[counted_terms].coefficient = temp_monomial.coefficient;
            equation->nomos[counted_terms].power = temp_monomial.power;
            counted_terms++;
            if (temp_monomial.power > max_power)
            {
                max_power = temp_monomial.power;
            }
        }
        while (*cursor == ' ')
        {
            cursor++;
        }
    }
    equation->max_power = max_power;
    return counted_terms;
}

int calculate_result(double **result, polynomial *equation, interval *borders)
{
    if (*result != NULL)
    {
        free(*result);
        *result = NULL;
    }
    *result = calloc(10,sizeof(double));
    int counter = 0;
    double temp_result = 0.0;
    if (equation->max_power == 1)
    {
        if (equation->nomos[1].coefficient == 0)
        {
            temp_result = (equation->nomos[1].coefficient * (-1));
            if (temp_result > borders->left_border && temp_result < borders->right_border)
            {
                *result[0] = temp_result;
            }
            counter += 1;

 
        }
        else
        {
            temp_result = (equation->nomos[1].coefficient * (-1) / equation->nomos[0].coefficient);
            if (temp_result > borders->left_border && temp_result < borders->right_border)
            {
                *result[0] = temp_result;
            }
            counter += 1;
        }
        
        // printf("WAR %lf",result[0]);
    }
    return counter;
}

double get_y(polynomial *poly, double x)
{
    double result = 0.0;
    int i = 0;
    if (poly == NULL)
    {
        return -1;
    }

    for (i = 0; i < poly->counted_nomos; i++)
    {   
        result += poly->nomos[i].coefficient * pow(x, poly->nomos[i].power);
    }

    return result;
}

void copy_polynomial(polynomial *poly_src, polynomial *poly_dest)
{
    int i = 0;
    for (i = 0; i < poly_src->counted_nomos; i++)
    {
        poly_dest->nomos[i].coefficient = poly_src->nomos[i].coefficient;
        poly_dest->nomos[i].power = poly_src->nomos[i].power;
    }
}

polynomial *get_derivative(polynomial *poly)
{
    polynomial *result = calloc(sizeof(1), sizeof(polynomial));
    int i = 0;
    result->counted_nomos = poly->counted_nomos;
    for (i = 0; i < poly->counted_nomos; i++)
    {
        if (poly->nomos[i].power == 0)
        {
            result->nomos[i].coefficient = 0.0;
            result->counted_nomos = poly->counted_nomos-1;
        }
        else
        {
            result->nomos[i].coefficient = poly->nomos[i].coefficient * poly->nomos[i].power;
            result->nomos[i].power = poly->nomos[i].power-1;
        }
    }
    result->max_power = poly->max_power - 1;
    return result;
}

double binary_search(polynomial *poly, double left_border, double right_border)
{
    double dot = get_y(poly, (left_border + right_border)/2);
    double lboundary = get_y(poly, left_border);
    double rboundary = get_y(poly, right_border);
    while(!(dot > -EPSILON && dot < EPSILON))
    {
        if (lboundary < rboundary) /*функция возрастает*/
        {
            if(dot > EPSILON)
            {
                right_border = (left_border + right_border)/2;
            }
            else
            {
                left_border = (left_border + right_border)/2;
            }
        }
        else
        {
            if(dot > EPSILON)
            {
                left_border = (left_border + right_border)/2;
            }
            else
            {
                right_border = (left_border + right_border)/2;
            }
        }
        dot = get_y(poly, (left_border + right_border)/2);
    }
   
    return ((left_border + right_border)/2);
}

double *get_result(polynomial *poly, double left_border, double right_border, int *counter)
{
    double *result = malloc(poly->max_power*sizeof(double));
    *counter = 0;

    if (poly->nomos->power == 1)
    {
        if ((poly->counted_nomos == 2) && (poly->nomos[1].coefficient != 0))
        {
            *result = ((poly->nomos[1].coefficient)*(-1)) / poly->nomos[0].coefficient;

            if (!(*result >= left_border && *result <= right_border))
            {
                free(result);
                result = NULL;
            }
            else
            {
                *counter += 1; 
            }
        }
        else
        {
            *result = 0;

            if (*result >= left_border && *result <= right_border)
            {
                *counter += 1;
            }
        }
    }
    else
    {
        int i;
        int roots_counter = 0;
        polynomial *derivative = get_derivative(poly);
        double *temp_result = get_result(derivative, left_border, right_border, &roots_counter);
        double *res_with_boundaries = malloc((roots_counter+2)*sizeof(polynomial));
        for (i = 0; i < roots_counter; i++)
        {
            res_with_boundaries[i+1] = temp_result[i];
        }
        res_with_boundaries[0] = left_border;
        res_with_boundaries[roots_counter + 1] = right_border;
        if (temp_result != 0)
        {
            free(temp_result);
        }
        free(derivative);
        for (i=0; i < roots_counter+1; i++)
        {
            if (((get_y(poly, res_with_boundaries[i])) < 0 && (get_y(poly, res_with_boundaries[i+1])) >= 0) || ((get_y(poly, res_with_boundaries[i])) >= 0 && (get_y(poly, res_with_boundaries[i+1])) < 0))
            {
                result[*counter] = binary_search(poly, res_with_boundaries[i], res_with_boundaries[i+1]);
                *counter += 1;
            }
        }
    }
    return result;
}