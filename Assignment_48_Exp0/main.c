#include <stdio.h>
#include <math.h>
long long int f1(long long int n)
{
	return (n);
}
double f2(long long int n)
{
	return log2(log2(n));
}
double f3(long long int n)
{
	return log2(n);
}
double f4(long long int n)
{
	double ans = log2(n);
	ans = sqrt(ans);
	return ans;
}
double f5(long long int n)
{
	return (log2(n)*log2(n));
}
double f6(long long int n)
{
	return pow(2,log2(n));
}
double f7(long long int n)
{
	return n*log2(n);
}
double f8(long long int n)
{
	return pow(n,1/log2(n));
}
double f9(long long int n)
{
	double root_of_two = sqrt(2);
	return pow(root_of_two,log2(n));
} 
double f10(long long int n)
{
	double power = 2*log2(n);
	power = pow(power,0.5);
	return pow(2,power);
}
long long int factorial(int n)
{
	if(n == 0) return 1;
	return n * factorial(n-1);
}
int main()
{
	printf("n\tn\tln(ln(n))\tln(n)\t\troot(lg(n))\t(lg(n))^2\t2^(ln n)\tn*ln(n)\t\tn^1/lg(n)\troot(2)^ln(n)\t2^(root(2*log(n)))\n");
	for(long long int i = 0 ; i <= 100 ; i++)
	{
		printf("%lld\t%lld\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t\t%.2lf\t\t%.2lf",i,f1(i),f2(i),f3(i),f4(i),f5(i),f6(i),f7(i),f8(i),f9(i),f10(i));
		printf("\n");
	}

	printf("\n\n");
	printf("n\tn\tln(ln(n))\tln(n)\t\troot(lg(n))\t(lg(n))^2\t2^(ln n)\tn*ln(n)\t\tn^(ln(ln(n)))\troot(2)^ln(n)\t2^(root(2*log(n)))\n");
	for(int j = 1 ; j < 21; j++)
	{
		long long int i = factorial(j);
		printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf",j,f2(i),f3(i),f4(i),f5(i),f6(i),f7(i),f8(i),f9(i),f10(i));
		printf("\n");
	}

}
