#include <stdlib.h>
#include "MathHelper.h"
#include "Agent.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	/*for (int i = 0; i != 5; i++)
		cout << MathHelper::RandomNumberClamped() << endl;*/
	Agent* test = new Agent();

	test->tick();

	system("pause");
}