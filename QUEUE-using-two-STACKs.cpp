
#include <iostream>
#include <stack>

using namespace std;

class QUEUE {
public:
    stack<int> FORWARD, BACKWARD;

    int front() {
        if (!FORWARD.empty()){
            BACKWARD.push(FORWARD.top());
            FORWARD.pop();
        }
        return BACKWARD.top();
    }

    int back() {
        return FORWARD.top();
    }

    void enqueue(int n) {
        FORWARD.push(n);
    }

    void dequeue() {
        if (!FORWARD.empty()){
            BACKWARD.push(FORWARD.top());
            FORWARD.pop();
        }
        BACKWARD.pop();
    }
};

int main() {
    int q; cin >> q;
    QUEUE Q;

    while (q--) {
        int type; cin >> type;
        if (type == 1){
            int x; cin >> x; Q.enqueue(x);
        } else if (type == 3) cout << Q.front() << endl;
        else Q.dequeue();
    }

    return 0;
}
