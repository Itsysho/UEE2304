#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int INIT_X = 0;
int INIT_Y = 0;

namespace DS {
	int n, m;
	int sx, sy;
	int ex, ey;
	vector<vector<int>> maze;
	const int dx[] = {-1, 1, 0, 0};
	const int dy[] = {0, 0, -1, 1};

	struct Pt {
		int x, y;
		Pt(int x, int y): x(x), y(y) {}
	};

	void find_path(Pt prev, Pt curr, 
			stack<std::pair<Pt, Pt>> &visit, 
			stack<std::pair<Pt, Pt>> &back);

	void solve() {
		stack<std::pair<Pt, Pt>> visit;
		stack<std::pair<Pt, Pt>> back;

		visit.push(make_pair(Pt(sx, sy), Pt(sx, sy)));

		while (!visit.empty()) {
			auto e = visit.top();
			Pt curr = e.first;
			Pt prev = e.second;
			visit.pop();
			if (curr.x == -1 && curr.y == -1) {
				curr = back.top().first;
				prev = back.top().second;
				back.pop();
			}

			cout << curr.x << " " << curr.y << endl;
				
			maze[curr.x][curr.y] = 2;
			if (curr.x == ex && curr.y == ey)
				return;

			find_path(prev, curr, visit, back);
		}
	}

	void find_path(Pt prev, Pt curr,
			stack<std::pair<Pt, Pt>> &visit, 
			stack<std::pair<Pt, Pt>> &back) {
		for (int i = 3; i >= 0; i--) {
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];
			if (nx == prev.x && ny == prev.y)
				continue;
			if (maze[nx][ny] != 1) {
				back.push(make_pair(Pt(nx, ny), curr));
				visit.push(make_pair(Pt(-1, -1), curr));
			}
		}
	}

	void print_maze(ostream &fout) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				fout << maze[i][j] << " ";
			fout << endl;
		}
	}
}

int main () {
	ifstream fin("input.txt");
	ofstream fout("answer.txt");
	fin >> DS::n >> DS::m;
	fin >> DS::sx >> DS::sy;
	fin >> DS::ex >> DS::ey;

	for (int i = 0; i < DS::n; i++) {
		vector<int> row;
		for (int j = 0; j < DS::m; j++) {
			int x;
			fin >> x;
			row.push_back(x);
		}
		DS::maze.push_back(row);
	}

	DS::solve();
	DS::print_maze(fout);
	return 0;
}
