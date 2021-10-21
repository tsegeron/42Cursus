void    ft_putchar (char c);

void rush51 (int l) // для условия 5:1 - строка
{
    ft_putchar('A'); //выводим А
    while (l > 2) // L изначально равна X, в этом примере Х=5
    {
        ft_putchar('B'); // выводим В
        l--; // Уменьшаем L на 1
    }
    ft_putchar('A'); // Выводим А
}// итог: АВВВА

void rush15 (int h) // для условия 1:5 - столбик
{
    ft_putchar('A'); // выводим А
    ft_putchar('\n'); // перенос строки
    while (h > 2) // H изначально равна Y, в этом примере Y=5
    {
        ft_putchar('B');
        ft_putchar('\n');
        h--;
    }
    ft_putchar('C');
}

void rush1__1 (int l, int h, int x) // для промежуточных строк
{
    while (h > 2)
    {
        ft_putchar('B');
        while (l > 2)
        {
            ft_putchar(' ');
            l--;
        }
        ft_putchar('B');
        ft_putchar('\n');
        l = x;
        h--; // промежуточные строки
    }
}

void rushLastStr (int l) // для последней строки
{
    ft_putchar('C');
    while (l > 2)
    {
        ft_putchar('B');
        l--;
    }
    ft_putchar('C'); //последняя строка
}

void rush(int x, int y)
{
    int l;
    int h;
    
    l = x;
    h = y; // вводим новые переменные, чотобы X и Y не менялись
    if ((l == 1) && (h == 1)) // условие для 1:1
        ft_putchar('A'); // функция на вывод А, см выше
    else if ((l > 1) && (h == 1)) // условие для 5:1
        rush51(l); // функция на вывод строки, см выше
    else if ((l == 1) && (h > 1)) // условие для 1:5
        rush15(h); // функция на вывод столбца, см выше
    else if ((l > 1) && (h > 1)) // условие для 5:5
    {
        rush51(l); // вывод первой строки
        ft_putchar('\n'); // переход на след строку после первой
        l = x; // заново приравниваем l к x, тк в rush51(l) менялось его значение (2 строки назад)
        rush1__1(l, h, x); // вывод промежуточных строк
        l = x;
        h = y; // заново приравниваем L к X и H к Y, тк в rush1__1(l,h,x) менялось его значение (2 строки назад)
        rushLastStr (l); // вывод последней строки
    }
}