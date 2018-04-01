#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;
int main()
{
	char c;
	while(1){ printf("%c", c = (unsigned char)(std::rand() % 256)); }
_getch();
return 0;
}