#include <stdio.h>
#include <string.h>

struct test1
{
	char x1;
	short x2;
	float x3;
	char x4;
};

#pragma pack(1)
struct test2
{
	char x1;
	short x2;
	float x3;
	char x4;
};
#pragma pack()

#pragma pack(8)
struct test3
{
	char x1;
	short x2;
	float x3;
	char x4;
};
#pragma pack()

#pragma pack(1)
struct test4
{
	char x1;
	short x2;
	float x3;
	long long x4;
};
#pragma pack()

int main(int argc, char *argv[])
{
	{
		struct test1 *p = 0;
		printf("struct test1 length:%d, offset: %p, %p, %p, %p\n", sizeof(*p),
				(void *)&p->x1, (void *)&p->x2, (void *)&p->x3, (void *)&p->x4);
	}

	{
		struct test2 *p = 0;
		printf("struct test2 length:%d, offset: %p, %p, %p, %p\n", sizeof(*p),
				(void *)&p->x1, (void *)&p->x2, (void *)&p->x3, (void *)&p->x4);
	}

	{
		struct test3 *p = 0;
		printf("struct test3 length:%d, offset: %p, %p, %p, %p\n", sizeof(*p),
				(void *)&p->x1, (void *)&p->x2, (void *)&p->x3, (void *)&p->x4);
	}
	{
		struct test4 *p = 0;
		printf("struct test4 length:%d, offset: %p, %p, %p, %p\n", sizeof(*p),
				(void *)&p->x1, (void *)&p->x2, (void *)&p->x3, (void *)&p->x4);
	}
}
