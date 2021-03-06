// Zagrajmy_w_Chinczyka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Cube
{
public:
	char direction;
	int value;
public:
	void setValues(char, int);
};

void Cube::setValues(char d, int v)
{
	direction = d;
	value = v;
}


class RotateCube
{
	char rotate;

public:
	void setRotationValue(char);
	void rotateCube(Cube c[6])
	{
		switch (rotate)
		{
		case 'N':
		case 'n':
			rotation('N', c);
			break;
		case 'S':
		case 's':
			rotation('S', c);
			break;
		case 'E':
		case 'e':
			rotation('E', c);
			break;
		case 'W':
		case 'w':
			rotation('W', c);
			break;
		}
	}
private:
	void rotation(char r, Cube c[6])
	{
		if (r == 'N')
		{
			for (int i = 0; i < 6; i++)
			{
				if (c[i].direction == 'T')
				{
					c[i].direction = 'N';
				}
				else if (c[i].direction == 'N')
				{
					c[i].direction = 'B';
				}
				else if (c[i].direction == 'B')
				{
					c[i].direction = 'S';
				}
				else if (c[i].direction == 'S')
				{
					c[i].direction = 'T';
				}
			}
		}
		else if (r == 'S')
		{
			for (int i = 0; i < 6; i++)
			{
				if (c[i].direction == 'T')
				{
					c[i].direction = 'S';
				}
				else if (c[i].direction == 'N')
				{
					c[i].direction = 'T';
				}
				else if (c[i].direction == 'B')
				{
					c[i].direction = 'N';
				}
				else if (c[i].direction == 'S')
				{
					c[i].direction = 'B';
				}
			}
		}
		else if (r == 'E')
		{
			for (int i = 0; i < 6; i++)
			{
				if (c[i].direction == 'T')
				{
					c[i].direction = 'E';
				}
				else if (c[i].direction == 'E')
				{
					c[i].direction = 'B';
				}
				else if (c[i].direction == 'B')
				{
					c[i].direction = 'W';
				}
				else if (c[i].direction == 'W')
				{
					c[i].direction = 'T';
				}
			}
		}
		if (r == 'W')
		{
			for (int i = 0; i < 6; i++)
			{
				if (c[i].direction == 'T')
				{
					c[i].direction = 'W';
				}
				else if (c[i].direction == 'E')
				{
					c[i].direction = 'T';
				}
				else if (c[i].direction == 'B')
				{
					c[i].direction = 'E';
				}
				else if (c[i].direction == 'W')
				{
					c[i].direction = 'B';
				}
			}
		}
	}
};

void RotateCube::setRotationValue(char r)
{
	rotate = r;
}


int main()
{
	string rotation_values;
	RotateCube rotateCube;
	Cube cube[6];
	int output = 1;

	cube[0].setValues('T', 1);
	cube[1].setValues('N', 2);
	cube[2].setValues('W', 3);
	cube[3].setValues('E', 4);
	cube[4].setValues('S', 5);
	cube[5].setValues('B', 6);


	cout << "Podaj wejście: ";
	getline(cin, rotation_values);
	if (!rotation_values.empty())
	{
		for (int i = 0; i < rotation_values.length(); i++)
		{
			rotateCube.setRotationValue(rotation_values[i]);
			rotateCube.rotateCube(cube);
		}
		for (int i = 0; i < 6; i++)
		{
			if (cube[i].direction == 'T')
			{
				output = cube[i].value;
				break;
			}
		}
	}
	cout << output;
	cout << endl;
	system("pause");
	return 0;
}
