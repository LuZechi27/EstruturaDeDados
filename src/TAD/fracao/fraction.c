#include <stdlib.h>
#include "fraction.h"

typedef struct fraction {
    int numerator, denominator;
} Fraction;

Fraction *create_fraction( int numerator, int denominator ) {
    Fraction *f = (Fraction*) malloc(sizeof(Fraction));
    
    if (f != NULL) {
        f->numerator = numerator;
        f->denominator = denominator;
    }
    return f;
}

Fraction *add_fraction(Fraction *f1, Fraction *f2) {
    int numerator = (f1->numerator * f2->denominator) + (f2->numerator * f1->denominator);
    int denominator = f1->denominator * f2->denominator;
    return create_fraction(numerator, denominator);
}

float convert_to_decimal(Fraction *f) {
    return (float) f->numerator / f->denominator;
}

int get_numerator(Fraction *f) {
    return f->numerator;
}

int get_denominator(Fraction *f) {
    return f->denominator;
}

void free_fraction(Fraction *f) {
    free(f);
}
