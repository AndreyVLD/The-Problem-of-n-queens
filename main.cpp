#include <iostream>
using namespace std;
int x[100], k, n, as, es;
void valid(int x[], int k, int& es)
{
	int i;
	es = 1;
	for (i = 1; i <= k - 1; i++)
		if (x[i] == x[k] || abs(x[k] - x[i]) == k - i)
			es = 0;

}
void succ(int x[], int k, int& as)
{
	if (x[k] < n)
	{
		x[k]++;
		as = 1;
	}
	else
		as = 0;
}
void afis(int x[], int k)
{
	int i;
	for (i = 1; i <= k; i++)
		cout << x[i] << " ";
	cout << endl;
}
int main()
{
	cout << "The number of queens & size of the chessboard = "; cin >> n;
	k = 1;
	x[k] = 0;
	while (k > 0)
	{
		do
		{
			succ(x, k, as);
			if (as)
				valid(x, k, es);
		} while (as && !es);
		if (as)
		{
			if (k == n)
				afis(x, k);
			else
			{
				k++;
				x[k] = 0;
			}
		}
		else
			k--;
	}
}

