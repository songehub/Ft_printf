#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar(('-'));
		ft_putchar(('2'));
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar(('-'));
		n = -n;
		ft_putnbr((n));
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	else
		ft_putchar((n + 48));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	i++;
	}
}

void ft_type(char c, char const *str, ...)
{

	// ft_putstr(va_arg(arg, char *));     //Es igiual a decir:   ft_putstr("mundo");	
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start (arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')	//significa que recibio una cadena
			{
				ft_putstr(va_arg(arg, char *));
			}
			if (str[i + 1] == 'i')	//significa que recibio un entero
			{
				ft_putnbr(va_arg(arg, int));
			}
		i++;
		count++;
		}
		else
		{
			ft_putchar(str[i]);
		}
	i++;
	count++;
	}
	va_end (arg);
	return (i);
}


int main (void)
{
void *ptr = "como estas";
void *ptr2 = "Esto%i proban%";
int i = 2;

ft_printf("Hola %s, %s %i", ptr, ptr2, i);
printf("\n");

   printf("Hola %s, %s %i", ptr, ptr2, i);
printf("\n");


/*
printf("Hola Mundo\n");
ft_printf("Hola Mundo\n");

printf("%c\n", 'f');			// %c Imprime un solo carácter.
ft_printf("%c\n", 'f');

printf("%s\n", s1);				// %s Imprime una string (como se define por defecto en C).
ft_printf("%s\n", s1);

printf("%p\n", ptr)				// %p El puntero void * dado como argumento se imprime en formato hexadecimal.
ft_printf("%p\n", ptr);

printf("%d\n", 5.2);			// %d Imprime un número decimal (base 10).
ft_printf("%d\n", '4,5');

printf("%i\n", 7);				// %i Imprime un entero en base 10.
ft_printf("%i\n", 7);

printf("%u\n", -3);				// %u Imprime un número decimal (base 10) sin signo.
ft_printf("%u\n", 3,7);

printf("%x\n", 28);				// %x Imprime un número hexadecimal (base 16) en minúsculas.
ft_printf("%x\n", 18);

printf("%X\n", 28);				// %X Imprime un número hexadecimal (base 16) en mayúsculas.
ft_printf("%X\n", 18);

printf("%%\n");					// % % para imprimir el símbolo del porcentaje
ft_printf("%%\n");

*/

return(0);
}

/*

%c	Imprime el carácter ASCII correspondiente
%d, %i	Conversión decimal con signo de un entero
%x, %X	Conversión hexadecimal sin signo
%p	Dirección de memoria (puntero)
%e, %E	Conversión a coma flotante con signo en notación científica
%f, %F	Conversión a coma flotante con signo, usando punto decimal
%g, %G	Conversión a coma flotante, usando la notación que requiera menor espacio
%o	Conversión octal sin signo de un entero
%u	Conversión decimal sin signo de un entero
%s	Cadena de caracteres (terminada en '\0')
%%	Imprime el símbolo %

\" comilla doble
\\ barra invertida
\a alerta (BEL)
\b retroceso
\c no produce ninguna salida
\e escape
\f form feed
\n nueva línea
\r retorno de carro
\t tabulador horizontal
\v tabulador vertical
\NNNN byte con valor octal NNN (1 a 3 dígitos)
\xHH byte con valor hexadecimal HH (1 a 2 dígitos)
\uHHHH Carácter Unicode (ISO/IEC 10646) con valor hexadecimal HHHH (4 dígitos)
\UHHHHHH Carácter Unicode con valor hexadecimal HHHHHHHH (8 dígitos)

%% un único %
%b ARGUMENTO como una cadena con escapes '\' interpretados,
	excepto que los escapes octales son de la forma \0 o \0NNN
%q ARGUMENTO se imprime en un formato que puede ser reutilizado como entrada del shell, 
	escapando los caracteres no imprimibles con la sintaxis POSIX propuesta $''.
	y todas las especificaciones de formato C que terminan con uno de diouxXfeEgGcs, 
	con ARGUMENTOS convertidos al tipo apropiado primero.  Se manejan los anchos de variable.

n$	Se reemplaza “n” por un número para cambiar el orden en el que se procesan los argumentos. 
	Por ejemplo %3$d se refiere al tercer argumento independientemente del lugar que ocupa en la cadena de formato.
	
Numero	Rellena con espacios (o con ceros, ver siguiente flag) a la izquierda hasta el valor del número.
0	Se rellena con ceros a la izquierda hasta el valor dado por el flag anterior. Por ejemplo “%03d” imprime un número justificado con ceros hasta tres dígitos.
+	Imprimir el signo de un número
-	Justifica el campo a la izquierda (por defecto ya hemos dicho que se justifica a la derecha)
#	Formato alternativo. Para reales se dejan ceros al final y se imprime siempre la coma. Para números que no están en base 10, se añade un prefijo denotando la base.

número	Tamaño del ancho del campo donde se imprimirá el valor.
*	Igual que el caso anterior, pero el número a utilizar se pasa como parámetro justo antes del valor. Por ejemplo printf("%*d", 5, 10) imprime el número 10, pero con un ancho de cinco dígitos (es decir, rellenará con 3 espacios en blanco a la izquierda).
Precision	Descripción
número	Tamaño de la parte decimal para números reales. Número de caracteres a imprimir para cadenas de texto
*	Igual que el caso anterior, pero el número a utilizar se pasa como parámetro justo antes del valor. Por ejemplo printf("%.*s", 3, "abcdef") imprime “abc”.

hh	Convertir variable de tipo char a entero e imprimir
h	Convertir variable de tipo short a entero e imprimir
l	Para enteros, se espera una variable de tipo long.
ll	Para enteros, se espera una variable de tipo long long.
L	Para reales, se espera una variable de tipo long double.
z	Para enteros, se espera un argumento de tipo size_t.

*/