#include <stdio.h>

#define DAYS 7

float get_sum_of_temperatures(float temp[])
{
    float sum;
    for (int i = 0; i < DAYS; i++)
    {
        printf("Digite a Temperatura do dia %d: ", i+1);
        scanf("%f", &temp[i]);
        sum += temp[i];
    }
    return sum;
}

float calculate_medium(float sum)
{
    return (float) sum / DAYS;
}

int get_above_average(float temp[], float medium)
{
    int count = 0;
    for (int i = 0; i < DAYS; i++)
        if (temp[i] > medium)
            count++;
    return count;
}

int main()
{
    float temperatures[DAYS];

    float some = get_some_of_temperatures(temperatures);
    float medium = calculate_medium(some);
    printf("Media: %.2f\n", medium);

    int above_average = get_above_average(temperatures, medium);
    printf("Quantidade de dias acima da media: %d\n", above_average);
    return 0;
}
