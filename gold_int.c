/*
 * finding the nth fibonacci number in logarithmic time
 * using fast exponentiation on golden integers aka Z[φ]
 */

#include <stdio.h>
#include <stdlib.h>

struct gold_int {
	int a,b;
	// aφ + b
};
typedef struct gold_int gint;

gint new_gint(int a, int b)
{
	gint g;
	g.a = a;
	g.b = b;
	return g;
}

gint add_gints(gint A, gint B)
{
	return new_gint(
		A.a + B.a,
		A.b + B.b
	);

	// (aφ + b) + (xφ + y)
	// = (a+x)φ + (b+y)
			
}
gint mult_gints(gint A, gint B)
{
	// φ^2 = φ + 1
	// (aφ + b)(xφ + y)
	// = axφ^2 + (bx + ay)φ + by
	// = ax*(φ+1) + (bx + ay)φ + by
	// = (ax + bx + ay)φ + (ax + by)
	return new_gint(
		A.a*B.a + A.b*B.a + A.a*B.b,
		A.a*B.a + A.b*B.b
	);
}
gint power(gint g, int p)
{
	//fast powering with squaring
	gint res = new_gint(0,1);
	while(p > 0)
	{
		if(p & 1) res = mult_gints(res,g);
		p >>= 1;
		g = mult_gints(g,g);
	}
	return res;
}
void print_gint(gint g)
{
	printf("%dφ + %d\n",g.a,g.b);
}

int nthfib(int n)
{
	//φ^n = Fib(n)*φ + Fib(n-1);
	gint phi_to_n = power(new_gint(1,0),n);
	return phi_to_n.a;
}


int main()
{
	for(int i=0; i<25; i++)
		printf("%d\n",nthfib(i));
}
