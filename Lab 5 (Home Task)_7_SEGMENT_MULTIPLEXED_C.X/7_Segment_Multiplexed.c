#include <xc.h>

void num2dig(int);
int sevenSeg(int);
void display();
void delay();

int dig[3];
unsigned int code[3];

int main()
{
    unsigned char mainCount = 0;
    TRISB = TRISD = 0;
    PORTB = PORTD = 0;
    while (1)
    {
        if (mainCount > 255)
            mainCount = 0;
        num2dig(mainCount);
        mainCount++;
        for (int i = 0; i < 3; i++)
            code[i] = sevenSeg(dig[i]);
        display();
    }
    return 0;
}

void num2dig(int num)
{
    int k = 0;
    while (num > 0)
    {
        dig[k] = num % 10;
        num /= 10;
        k++;
    }
}

int sevenSeg(int num)
{
    switch (num)
    {
    case 0:
        return 0x3F;
        break;
    case 1:
        return 0x06;
        break;
    case 2:
        return 0x5B;
        break;
    case 3:
        return 0x4F;
        break;
    case 4:
        return 0x66;
        break;
    case 5:
        return 0x6D;
        break;
    case 6:
        return 0x7D;
        break;
    case 7:
        return 0x07;
        break;
    case 8:
        return 0x7F;
        break;
    case 9:
        return 0x6F;
        break;
    }
    return 0;
}

void display()
{
    int count = 0;
    while (count <= 100)
    {
        PORTB = code[0];
        PORTDbits.RD0 = 1;
        delay();
        PORTB = code[1];
        PORTDbits.RD1 = 1;
        delay();
        PORTB = code[2];
        PORTDbits.RD2 = 1;
        delay();
        count++;
    }
}

void delay()
{
    for (int j = 0; j <= 12; j++)
    {
    }
    PORTB = PORTD = 0;
}