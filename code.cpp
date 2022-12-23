#include <iostream>

using namespace std;

int main()
{

	int bits, bit1, bit2, subtrahend, limit, carry = 1, carry1 = 0, minuend,print,printh;
	cout << "enter bits" << endl;
	cin >> bits;
	limit = bits;
	bit1 = bits;
	bit2 = bits;
	print = bits;
	printh = bits;
	cout << "enter minuend" << endl;
	cin >> minuend;
	cout << "enter subtrahend" << endl;
	cin >> subtrahend;
	

	//number separation of minuend
	int* bitminu = new int[bit1];
	for (int i = 0; i < limit; ++i)
	{
		bit1--;
		bitminu[bit1] = minuend % 10;
		minuend = minuend / 10;
	}

	//minuend print
	/*for (int i = 0; i < limit; ++i)
	{
		cout << bitminu[i];
	}

	cout << " is minuend" << endl;*/


	//number separation of subtrahend
	int* bitsubtra = new int[bits];
	for (int i = 0; i < limit; ++i)
	{
		bits--;
		bitsubtra[bits] = subtrahend % 10;
		subtrahend = subtrahend / 10;
	}



	////subtrahend print
	//for (int i = 0; i < limit; ++i)
	//{
	//	cout << bitsubtra[i];
	//}
	//cout << " is subtrahend" << endl;

	//cout << endl;

	//1's complement calculate
	for (int i = limit - 1; i >= 0; --i)
	{
		if (1 == bitsubtra[i])
		{
			bitsubtra[i] = 0;
		}
		else
		{
			bitsubtra[i] = 1;
		}
	}
	cout << endl;

	//1's complement print
	/*for (int i = 0; i < limit; ++i)
	{
		cout << bitsubtra[i];
	}*/




	//2's complement	calculate
	for (int i = limit - 1; i >= 0; --i && carry != 0)
	{
		bitsubtra[i] = bitsubtra[i] + carry;
		if (0 == bitsubtra[i])
		{
			bitsubtra[i] = 0;
			carry = 0;
		}
		else if (1 == bitsubtra[i])
		{
			bitsubtra[i] = 1;
			carry = 0;
		}
		else if (2 == bitsubtra[i])
		{
			bitsubtra[i] = 0;
			carry = 1;

		}
		else if (3 == bitsubtra[i])
		{
			bitsubtra[i] = 1;
			carry = 1;

		}
	}




	cout << endl;

	////2's complement print
	//for (int i = 0; i < limit; ++i)
	//{
	//	cout << bitsubtra[i];
	//}

	//cout << endl;

	//summation
	int* sum = new int[bit2];
	int* carryprint = new int[print];
	for (int i = limit - 1; i >= 0; --i)
	{
		sum[i] = bitsubtra[i] + bitminu[i] + carry1;
		if (0 == sum[i])
		{
			sum[i] = 0;
			carry1 = 0;
		}
		else if (1 == sum[i])
		{
			sum[i] = 1;
			carry1 = 0;
		}
		else if (2 == sum[i])
		{
			sum[i] = 0;
			carry1 = 1;

		}
		else if (3 == sum[i])
		{
			sum[i] = 1;
			carry1 = 1;
		}
		carryprint[i] = carry1;
	}

	////sum print
	//for (int i = 0; i < limit; ++i)
	//{
	//	cout << sum[i];
	//}

	//cout << " is sum"<<endl;
	

	system("cls");



	//carry print
	for (int i = 1; i < print; ++i)
	{
		--printh;
		cout << carryprint[printh] << " ";
	}
	cout << "0 CARRY" << endl;

	//minuend print
	for (int i = 0; i < print; ++i)
	{
		cout <<bitminu[i] << " ";
	}
	cout << "MINUEND" << endl;

	//subtrahend print
	for (int i = 0; i < print; ++i)
	{
		cout << bitsubtra[i] << " ";
	}
	cout << "SUBTRAHEND" << endl;

	//------ print
	for (int i = 0; i < print; ++i)
	{
		cout << "--";
	}
	cout << endl;

	//sum print
	for (int i = 0; i < print; ++i)
	{
		cout << sum[i] << " ";
	}
	cout << "SUM" << endl;




	//dynamic array deletion
	bitsubtra = NULL;
	bitminu = NULL;
	sum = NULL;
	carryprint = NULL;
	delete[] bitsubtra;
	delete[] bitminu;
	delete[] sum;
	delete[] carryprint;

	system("pause>0");


	
}
