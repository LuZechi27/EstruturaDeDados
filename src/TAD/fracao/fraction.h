typedef struct fraction Fraction;

Fraction *create_fraction(int numerator, int denominator);
Fraction *add_fraction(Fraction *f1, Fraction *f2);
float convert_to_decimal(Fraction *f);
int get_numerator(Fraction *f);
int get_denominator(Fraction *f);
void free_fraction(Fraction *f);
