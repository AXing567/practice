#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct Node
{
    int x1, y1;
    int x2, y2;
};
vector<Node> q;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    q.push_back({a, b, c, d});
    cin >> a >> b >> c >> d;
    q.push_back({a, b, c, d});
    cin >> a >> b >> c >> d;
    q.push_back({a, b, c, d});

    bool x = false;
    if (q[1].x1 <= q[0].x1 && q[1].y1 <= q[0].y1 && q[1].x2 >= q[0].x2 && q[1].y2 >= q[0].y2)
        x = true;
    if (q[2].x1 <= q[0].x1 && q[2].y1 <= q[0].y1 && q[2].x2 >= q[0].x2 && q[2].y2 >= q[0].y2)
        x = true;

    if (q[1].x1 <= q[0].x1 && q[1].x2 >= q[0].x1 && q[1].y1 <= q[0].y1 && q[1].y2 >= q[0].y2)
        if (q[1].x2 >= q[2].x1 && q[2].x2 >= q[0].x2 && q[2].y1 <= q[0].y1 && q[2].y2 >= q[0].y2)
            x = true;
    if (q[2].x1 <= q[0].x1 && q[2].x2 >= q[0].x1 && q[2].y1 <= q[0].y1 && q[2].y2 >= q[0].y2)
        if (q[2].x2 >= q[1].x1 && q[1].x2 >= q[0].x2 && q[1].y1 <= q[0].y1 && q[1].y2 >= q[0].y2)
            x = true;   



    if (q[1].x1 <= q[0].x1 && q[1].x2 >= q[0].x2 && q[1].y2 >= q[0].y2 && q[1].y1 <= q[0].y2)
        if (q[1].y1 <= q[2].y2 && q[2].y1 <= q[0].y1 && q[2].x1 <= q[0].x1 && q[2].x2 >= q[0].x2)
            x = true;
    if (q[2].x1 <= q[0].x1 && q[2].x2 >= q[0].x2 && q[2].y2 >= q[0].y2 && q[2].y1 <= q[0].y2)
        if (q[2].y1 <= q[1].y2 && q[1].y1 <= q[0].y1 && q[1].x1 <= q[0].x1 && q[1].x2 >= q[0].x2)
            x = true;

    if (x)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;


    return 0;
}/*
1 1 4 4
1 1 4 4
999 999 9999 9999 
NO

2 2 7 7 
3 1 8 8
1 1 3 7
NO

2 2 7 7
1 5 8 8
1 1 8 5
NO


*/