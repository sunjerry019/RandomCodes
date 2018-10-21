#include "lightson.h"

class Fe
{
	private:
	unsigned long int length;
	long int *values;
	
	public:
	
	Fe()
	{
		length = 0;
		values = new long int[0];
	}
	
	Fe(unsigned long int n)
	{
		unsigned long int i;
		length = n;
		values = new long int[n];
		for (i = n; i--; )
		{
			values[i] = 0;
		}
	}
	
	~Fe()
	{
		delete [] values;
	}
	
	void add_one(unsigned long int i)
	{
		while (i < length)
		{
			values[i]++;
			i += i ^ i & i - 1;
		}
	}
	
	void add(unsigned long int i, long int v)
	{
		while (i < length)
		{
			values[i] += v;
			i += i ^ i & i - 1;
		}
	}
	
	long int find_before(unsigned long int i)
	{
		long int result = 0;
		while (i)
		{
			result += values[i];
			i &= i - 1;
		}
		return result;
	}
};

int n_floors, n_units, time = 500001;
int floor_last_changed[100000];
int unit_last_changed[100000];
Fe turned_on(500002);
Fe turned_off(500002);

void flat(int N, int M)
{
	n_floors = N;
	n_units = M;
}

void setFloor(int N, bool S)
{
	floor_last_changed[N] = --time << 1 | (int)S;
}

void setUnit(int M, bool S)
{	
	if (unit_last_changed[M])
	{
		(unit_last_changed[M] & 1 ? turned_on : turned_off).add(unit_last_changed[M] >> 1, -1);
	}
	unit_last_changed[M] = --time << 1 | (int)S;
	(S ? turned_on : turned_off).add_one(time);
}

int countLights(int N)
{
	if (floor_last_changed[N] & 1)
	{
		return n_units - turned_off.find_before(floor_last_changed[N] >> 1);
	}
	else if (floor_last_changed[N])
	{
		return turned_on.find_before(floor_last_changed[N] >> 1);
	}
	else
	{
		return turned_on.find_before(500001);
	}
}
