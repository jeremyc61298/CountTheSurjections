#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;

unsigned long long calcNI(unsigned long long n, unsigned long long i)
{
	unsigned long long result;
	if (i == 0 || n == 0 || i == n)
	{
		result = 1;
	}
	else if (0 < i && i < n)
	{
		result = calcNI(n - 1, i - 1) + calcNI(n - 1, i);
	}

	return result;
}

unsigned long long S(unsigned long long m, unsigned long long n)
{
	unsigned long long result;
	if (n == 1)
	{
		result = 1;
	}
	else if (m < n)
	{
		result = 0;
	}
	else if (m == n)
	{
		result = m;
		for (int i = 1; i < m; i++)
		{
			result *= i;
		}
	}
	else if(n > 1 && m > n)
	{
		unsigned long long expn = 1, sum = 0, I = 1;
		// Calculate the exponent
		for (int i = 0; i < m; i++)
		{
			expn *= n;
		}

		// Calculate the second half of the equation
		for (int i = 0; i < n - 1; i++)
		{
			sum += calcNI(n, I) * S(m, I);
		}
		
		result = expn - sum;
	}

	return result;
}

void main()
{
	ifstream fin("surjections.in");
	ofstream fout("surjections.out");
	unsigned long long m, n, ans;

	fin >> m >> n;

	while (m != 0 && n != 0)
	{
		ans = S(m, n);
		// Output the answer to the file
		fout << "S(" << m << ", " << n << ") = " << ans << endl;
		fin >> m >> n;
	}
}