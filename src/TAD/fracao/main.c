#include <stdio.h>
#include "fraction.h"

int main() {
    Fraction *f1 = create_fraction(3, 4);
    Fraction *f2 = create_fraction(1, 2);

    printf("Fração 1: %d/%d\n", get_numerator(f1), get_denominator(f1));
    printf("Fração 2: %d/%d\n", get_numerator(f2), get_denominator(f2));

    Fraction *soma = add_fraction(f1, f2);

    printf("Fração soma: %d/%d\n", get_numerator(soma), get_denominator(soma));

    printf("Fração 2 em decimal: %.2f\n", convert_to_decimal(f2));

    free_fraction(f1);
    free_fraction(f2);
    free_fraction(soma);

    return 0;
}
