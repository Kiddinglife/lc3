main()
{
	int i; char *s;

	for (s = "bfnrtvx"; *s; s++)
		printf("%c = 0x%x\n", *s, backslash(*s));
	sf();
	sg();
	sh();
	for (i = 0x1000; i&0x7000; i += 0x1000)
		big(i);
	limit();
	return 0;
}

char backslash_c(char c)
{
	switch (c) {
	case 'b':
		return '\b';
	case 'f':
		return '\f';
	case 'n':
		return '\n';
	case 'r':
		return '\r';
	case 't':
		return '\t';
	case 'v':
		return '\v';
	}
	return c;
}

backslash(c)
{
	switch (c) {
	case 'b':
		return '\b';
	case 'f':
		return '\f';
	case 'n':
		return '\n';
	case 'r':
		return '\r';
	case 't':
		return '\t';
	case 'v':
		return '\v';
	}
	return c;
}

sf_c() {
	char i, x = 0, y;

	printf("f:\n");
	for (i = 0; i <= 20; i++) {
		y = i;
		switch (i) {
		case 1: x = i; break;
		case 2: x = i; break;
		case 7: x = i; break;
		case 8: x = i; break;
		case 9: x = i; break;
		case 16: x = i; break;
		case 17: x = i; break;
		case 18: x = i; break;
		case 19: x = i; break;
		case 20: x = i; break;
		}
		printf("x = %d\n", x);
	}
}

sf() {
	int i, x = 0, y;

	printf("f:\n");
	for (i = 0; i <= 20; i++) {
		y = i;
		switch (i) {
		case 1: x = i; break;
		case 2: x = i; break;
		case 7: x = i; break;
		case 8: x = i; break;
		case 9: x = i; break;
		case 16: x = i; break;
		case 17: x = i; break;
		case 18: x = i; break;
		case 19: x = i; break;
		case 20: x = i; break;
		}
		printf("x = %d\n", x);
	}
}

sg() {
	int i;

	printf("g:\n");
	for (i = 1; i <= 10; i++)
		switch (i) {
		case 1: case 2: printf("1 %d\n", i); break;
		case 3: case 4: case 5: printf("2 %d\n", i); break;
		case 6: case 7: case 8: printf("3 %d\n", i);
		default:
			printf("d %d\n", i); break;
		case 1001: case 1002: case 1003: case 1004:
			printf("5 %d\n", i); break;
		case 3001: case 3002: case 3003: case 3004:
			printf("6 %d\n", i); break;
	}
}

sh()
{
	int i, n=0;

	printf("h:\n");
	for (i = 1; i <= 500; i++)
		switch (i) {
		default: n++; continue;
		case 128: printf("i = %d\n", i); break;
		case 16: printf("i = %d\n", i); break;
		case 8: printf("i = %d\n", i); break;
		case 120: printf("i = %d\n", i); break;
		case 280: printf("i = %d\n", i); break;
		case 264: printf("i = %d\n", i); break;
		case 248: printf("i = %d\n", i); break;
		case 272: printf("i = %d\n", i); break;
		case 304: printf("i = %d\n", i); break;
		case 296: printf("i = %d\n", i); break;
		case 288: printf("i = %d\n", i); break;
		case 312: printf("i = %d\n", i); break;
		}
	printf("%d defaults\n", n);
}

big(x) int x; {
	switch(x&0x6000){
	case -1:
	case -2:
	case 0x0000:
		printf("x = 0x%x (0)\n", x); break;
	case 0x2000:
		printf("x = 0x%x (2)\n", x); break;
	case 0x4000:
		printf("x = 0x%x (4)\n", x); break;
	default:
		printf("x = 0x%x (default)\n", x); break;
	}
}

#define INT_MIN -32000
#define INT_MAX 32000

limit() {
	int i;

	for (i = INT_MIN; i <= INT_MIN+5; i++)
		switch (i) {
		case INT_MIN:	printf("0\n"); break;
		case INT_MIN+1:	printf("1\n"); break;
		case INT_MIN+2:	printf("2\n"); break;
		case INT_MIN+3:	printf("3\n"); break;
		case INT_MIN+4:	printf("4\n"); break;
		default:	printf("5\n"); break;
		}
	for (i = INT_MAX; i >= INT_MAX-5; i--)
		switch (i) {
		case INT_MAX:	printf("0\n"); break;
		case INT_MAX-1:	printf("1\n"); break;
		case INT_MAX-2:	printf("2\n"); break;
		case INT_MAX-3:	printf("3\n"); break;
		case INT_MAX-4:	printf("4\n"); break;
		default:	printf("5\n"); break;
		}
}
