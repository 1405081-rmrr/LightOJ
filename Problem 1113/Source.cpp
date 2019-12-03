// Bismillahir Rahmanir Rahim
// Nafis Chowdhury
// LightOJ #1113
// Discover the Web
// Problem statement- http://lightoj.com/volume_showproblem.php?problem=1113
// Main.cpp


#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	stack <string> forward;
	stack <string> backward;

	string userInput, url, current;
	current = "http://www.lightoj.com/";

	int testCases;
	cin >> testCases;

	for (int i = 1; i <= testCases; i++)
	{
		cout << "Case " << i << ": " << endl;

		while (cin >> userInput)
		{
			if (userInput == "VISIT")
			{
				cin >> url;
				cout << url << endl;
				backward.push(current);
				current = url;
				while (!forward.empty())
					forward.pop();
			}
			else if (userInput == "BACK" && !backward.empty())
			{
				forward.push(current);
				current = backward.top();
				backward.pop();
				cout << current << endl;
			}
			else if (userInput == "FORWARD" && !forward.empty())
			{
				backward.push(current);
				current = forward.top();
				forward.pop();
				cout << current << endl;
			}
			else if (userInput == "QUIT")
			{
				break;
			}
			else if(forward.empty() || backward.empty())
			{
				cout << "Ignored" << endl;
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}