#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	char input[1001] = "hCkGJ5M3VuF02psUJtUypbLaWM8zHsUxnUURYiAl46axNsFJ6NjJFHZSG9vzaoCyJ7IZD06gVYFQAGdpFXp0YpMW7BzzUWVeyF6SoaDVjWrlTxEWehYFtdwEnsYuWBy86cIDJIhAxhGLj7LVmMaRD4hyx9Z56pG0lHsjCoUouy6LjSPajyWhEp7GZ9mVqHJuMSUE0S2kMiRaKnNo74XGWv4jGdEaLsBb9uraidNSW6vAHTxdkdmli0HUY70OwsQnWlcTru3JKs7330jBQ59GS1s2ESsYqYsewtfrPzfRBeKSutf5Q1aXuN6YmkdnM2yskCFf8tWTUJYhdervq4OJEoVq7LkCwRi6MMNHykEykfyiI86A2MiiqItjOpui99FVhnU6S9HSeYEt0SLhRNP7vGNNg8UW19kPmzKxIWBJ7WdxfZ9UbNZmrtVapslBTpQT1bsork4sPTfdgwQ3wqTbkpTgiPrT3MZjtRW5DOanIDqRkCGfbgVZrCGulIBOd9qmBPJgLHIH94J94NzXEjZNxZiLicaoOe1FEHsMYANudsbWDQUXw7sKChkVVJHsWYPUon3VsGT5RpNDbDslBkPgDmZkDIEVtlQIYyrh937pU3yYq1qifFqXlYRFkEnkY9n73t1vr77eFHIMMSSB9oND4137zCL5EOtUjLJNrxqauO3SfhX75pc5Cu42OmF9qwi4mRGxsqHYLigaSzBKzmBtkm0WGZ2spI2Tu6TC5cpj4epMzFlRFodZrw0QCIF0IXOxrkBQSwl4H5MTQGSThByrrfNdZZ4qFWRZjAzlW2pPA1JimGTkAyAUCFlvEZyGEGP2bhLf1SaFDLJAyM8S1SXmWcgmjE76HWaFnMTZj5oYWl4qsP1qZ5cM1pm2Yeo6ndYwSWfnNZOaIOk3CJ5nhSNzX2fN5N0G8JL7IOk08jHTFG2jICKosIH2xw6nm3yfKtWbM41BZV9a0BGmBE2VU5QnhXyTuZBKZ0v9SKGh2XCs";
	map<char,int> a;
	map<char,int>::iterator it;
	int max = 0;
	char maxchar;
	for(int i = 0; i < strlen(input); i ++)
	{
		a[input[i]]++;
	}
	for(it=a.begin(); it!=a.end(); it++)
	{
		if(it->second > max)
		{
			max = it->second;
			maxchar = it->first;
		}
	}
	cout << maxchar << " " << max;
	while(1){}
	return 0;
}
