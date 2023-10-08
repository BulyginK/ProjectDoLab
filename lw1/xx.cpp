#include <cstdio>
#include <math.h>

int main()
{
    std::puts("`ax^2+bx+c=0:`");
    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);

    float D = b * b - 4 * a * c;
    std::printf("%f\n", D);
    if (D == 0)
    {
        float x1 = -b / (2 * a);
        std::printf("x1=x2=%f\n", x1);
    };
    if (D > 0)
    {
        float x1 = (-b + sqrt(D)) / (2 * a);
        float x2 = (-b - sqrt(D)) / (2 * a);
        std::printf("x1=%f, x2=%f\n", x1, x2);
    };
    if (D < 0)
    {
        std::printf("net korney");
    }
}