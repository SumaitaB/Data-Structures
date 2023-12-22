#include<iostream>
#include<vector>
#include<iomanip>
#include<windows.h>
using namespace std;

void display(vector<int> T){
    for (int i = 0; i < T.size(); i++){
        if (i > 0) cout << ' ';
        cout << T[i];
    } cout << endl;
}

int main(){
    CONSOLE_SCREEN_BUFFER_INFO n;
    int CONSOLE_WIDTH;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &n);
    CONSOLE_WIDTH = n.srWindow.Right - n.srWindow.Left+1;

    string line = "IMPLEMENTATION OF QUEUE";
    if (line.size() % 2 == 0) line += " ";
    cout << setw(CONSOLE_WIDTH/2 + line.size()/2) << right << line << endl;

    cout << "1. Type 1 <space> 'value' to push an item into the queue.\n";
    cout << "2. Type 2 to pop the first item.\n";
    cout << "3. Press CTRL + Z then hit ENTER to terminate the program.\n";

    vector<int> S; int cmd, input;

    while (cin >> cmd){
        if (cmd == 1){
            cin >> input;
            if (S.size() >= 100000) cout << "Error: Overflow\n";
            S.push_back(input);
            cout << "Current condition of the queue is:\n";
            display(S);
        }

        else if (cmd == 2){
            if (S.empty()) cout << "Error: Underflow. The queue is already empty.\n";
            else{
                cout << "Popped out the item " << S[0] << endl;
                S.erase(S.begin());

                if (S.empty()) cout << "Currently, the queue is empty.\n";
                else{
                    cout << "Current condition of the queue is:\n";
                    display(S);
                }
            }
        }
    }

    return 0;
}
