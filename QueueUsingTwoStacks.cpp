#include <bits/stdc++.h>
using namespace std;

class makeQueue {
public:

    stack<int> s1;
    stack<int> s2;


    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            s2.pop();
        }
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            return s2.top();
        }
        return -1;
    }
};

int main() {
    int q;
    cin >> q;

    makeQueue queue;

    while (q--) {
        int query;
        cin >> query;

        if (query == 1) {
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if (query == 2) {
            queue.dequeue();
        } else if (query == 3) {
            cout << queue.front() << endl;
        }
    }

    return 0;
}
