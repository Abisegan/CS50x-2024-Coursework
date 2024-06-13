int check_digits(int number)
{
    int n = 1;
    int digits=0;

    int x = 10;
    do
    {

        n = number / x;
        digits++;
        x = x * 10;

    }
    while(n <= 0);
    return digits;
}
