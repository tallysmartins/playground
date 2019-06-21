#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
	int n, M, removed;

	// Two queues one of MIN and one of MAX
	priority_queue<int, vector<int>, greater<int> > qmin;
	priority_queue<int> qmax;

	cin >> n >> M;
	int st, last, tmp, cap = 0;
	while(n--) {
		cin  >> st;
		// while the student is in the capacity range insert and increase capacity
		// print 0 to represent that no one was removed and go to the next student
		// use a MAX heap to pop greater values first when needed and minimize the
		// amount of students that must be dropped
		if ((cap + st) <= M) {
			qmax.push(st);
			cap += st;
			cout << 0 << " ";
			continue;

		// if the capacity is overloaded we have to count how many students were removed
		}else {
			removed=0;

			// while capacity plus the current student is beyond the limit M, remove
			// a student and save him in the qmin to be restored later and also
			// decrease the total capacity
			tmp = cap;
			while(cap + st > M) {
				last = qmax.top(); qmax.pop();
				cap -= last;
				qmin.push(last);
				removed++;
			}
			// print the amount of students removed and restore the queue and
			// the capacity of previously removed students
			cout << removed << " ";
			while(removed--) {
				last = qmin.top(); qmin.pop();
				qmax.push(last);
			}
			// also insert the current student and add its capacity to the system
			// we can do this before, but here we can be a lil faster in the worst
			// case with just one sort pass
			qmax.push(st);
			cap=tmp + st;
		}

	}
	cout << endl;

	return 0;
}
