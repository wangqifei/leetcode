#include <iostream>
#include <queue>
using namespace::std;

int main(int argc, char const *argv[])
{
	priority_queue<int, vector<int>, greater<int> > q;
	q.push(1);
	q.push(2);
	q.push(2);
	q.push(3);
	while(q.empty() == false)
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}