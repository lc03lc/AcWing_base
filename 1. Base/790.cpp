#include <iostream>
double node = 0.0000001;

void cal(double f)
{
    if (f < 0)
    {
        printf("-");
        f = -f;
    }
    double l, r;
    if (f > 1)
    {
        l = 0 - node, r = f + node;
    }
    else
    {
        l = 0 - node, r = 1 + node;
    }
    
    while (l + node < r)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > f)
        {
            r = mid;
        }
        else if (mid * mid * mid < f)
        {
            l = mid;
        }
        else
        {
            printf("%.6f", r);
            break;
        }
    }
    printf("%.6f", r);
}

int main()
{
    double f;
    scanf("%lf", &f);
    cal(f);
}