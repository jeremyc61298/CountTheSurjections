#include <fstream>

using std::ifstream;
using std::ofstream;

void S(unsigned long long &m, unsigned long long &n)
{

}

void main()
{
	ifstream fin("surjections.in");
	ofstream fout("surjections.out");
	unsigned long long m, n;

	fin >> m >> n;

	while (m != 0 && n != 0)
	{
		S(m, n);
		fin >> m >> n;
	}
}