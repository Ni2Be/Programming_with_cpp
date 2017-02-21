#include <iostream>

/*
linked list excaples see git TH/algorithmik
*/

void to_lower(char* ch);
char* strdub(const char* ch);
char* findx(const char* str, const char* x);

void reserve_infinit_space();


int main()
{
	char *cha = new char(sizeof(char) * 10);
	cha[0] = 'k'; cha[1] = 'G'; cha[2] = '?'; cha[3] = 'R'; cha[4] = 'k'; cha[5] = 'M';
	cha[6] = 'T'; cha[7] = 'f'; cha[8] = '#'; cha[9] = 0;
	to_lower(cha);

	std::cout << std::endl;

	char* foo = strdub("Hallo!");
	to_lower(foo);


	std::cout << std::endl;
	std::cout << findx("you'll never find", "ind");

	//reserve_infinit_space();

	std::cout << std::endl;
	char ch;
	std::cin >> ch;
}


void to_lower(char* ch)
{
	int i = 0;
	while (ch[i] != 0)
	{
		if (ch[i] >= 65 && ch[i] <= 90)
			ch[i] += 32;
		std::cout << ch[i];
		i++;
	}
}

char* strdub(const char* ch)
{
	int i = 0;
	while (ch[i] != 0)
	{
		i++;
	}
	char *str = new char(sizeof(char) * i);
	i = 0;
	while (ch[i] != 0)
	{
		str[i] = ch[i];
		i++;
	}
	str[i] = 0;
	return str;
}


char* findx(const char* str, const char* x)
{
	int str_size = 0;
	while (str[str_size++] != 0);
	int x_size = 0;
	while (x[x_size++] != 0);
	x_size -= 1;

	int front = 0;
	while (front < str_size - x_size)
	{
		if (str[front] == x[0])
		{
			for (int i = 0; i < x_size; i++)
			{
				if (str[front + i] != x[i])
				{
					break;
				}
				if (i == 0)
				{
					return "yes!";
				}
			}
		}
		front++;
	}
	return "no!";
}


void reserve_infinit_space()
{
	while (1)
	{
		int *p = new int(sizeof(int) * 1000);
	}
}