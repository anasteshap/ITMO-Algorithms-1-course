#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct item {
    int x, y;
    int dist = -1;
    int canIGO;
    string direction;
} S, T;

queue<item> Q;
vector<vector<item>> maze;

void smth(item cur, item tmp) {
    if (cur.dist == -1 && cur.canIGO) { // если не пройдена и можно двигаться
        cur.dist = maze[tmp.x][tmp.y].dist + 1; // увеличение длины пути на 1

        if (cur.x == tmp.x - 1) { // если идем вверх
            cur.direction = maze[tmp.x][tmp.y].direction + "U";
        } else if (cur.x == tmp.x + 1) { // вниз
            cur.direction = maze[tmp.x][tmp.y].direction + "D";
        } else if (cur.y == tmp.y - 1) {
            cur.direction = maze[tmp.x][tmp.y].direction + "L";
        } else if (cur.y == tmp.y + 1) {
            cur.direction = maze[tmp.x][tmp.y].direction + "R";
        }

        maze[cur.x][cur.y] = cur; // данныe из cur засовываем в ячейку из лабиринтика
        Q.push(cur);
    }
}

void BST() {
    Q.push(S);
    maze[S.x][S.y].dist = 0;
    item cur;

    while (!Q.empty()) {
        item tmp = Q.front(); // ячейка, из которой сейчас шагаем

        cur = maze[tmp.x - 1][tmp.y]; // вверх
        smth(cur, tmp);
/*        if (cur.dist == -1 && cur.canIGO) {
            maze[tmp.x - 1][tmp.y].dist = maze[tmp.x][tmp.y].dist + 1;
            Q.push(maze[tmp.x - 1][tmp.y]);
        }*/

        cur = maze[tmp.x + 1][tmp.y]; // вниз
        smth(cur, tmp);

        cur = maze[tmp.x][tmp.y - 1]; // влево
        smth(cur, tmp);

        cur = maze[tmp.x][tmp.y + 1]; // вправо
        smth(cur, tmp);

        Q.pop();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    char a;
    cin >> n >> m;
    maze.resize(n + 2, vector<item> (m + 2));

    for (int i = 0; i < n + 2; i++) {
        maze[i][0].canIGO = maze[i][m + 1].canIGO = 0;
    } // стенки лабиринта слева и справа

    for (int i = 0; i < m + 2; i++) {
        maze[0][i].canIGO = maze[n + 1][i].canIGO = 0;
    } // стенки лабиринта снизу и сверху

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            cin >> a;
            maze[i][j].x = i;
            maze[i][j].y = j;

            if (a == '.') {
                maze[i][j].canIGO = 1;
            }
            else if (a == '#') {
                maze[i][j].canIGO = 0;
            }
            else if (a == 'S') {
                maze[i][j].canIGO = 1;
                S = maze[i][j];
            }
            else if (a == 'T') {
                maze[i][j].canIGO = 1;
                T = maze[i][j];
            }
        }
    }

    BST();
    if (maze[T.x][T.y].direction.length() == 0) {
        cout << -1;
    } else {
        cout << maze[T.x][T.y].dist << '\n' << maze[T.x][T.y].direction << '\n';
    }

    return 0;
}
