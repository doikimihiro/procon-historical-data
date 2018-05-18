//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2664
//���j�I���t�@�C���h�؁@�×~�@
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#define MAX_N 5001
int par[MAX_N], r[MAX_N];//rank


void init(int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		r[i] = 0;
		par[i] = i;
	}
}

int root(int x)
{
	if (par[x] == x)
	{
		return x;
	}
	else
	{
		return par[x] = root(par[x]);
	}
}

bool same(int x, int y)
{
	return  root(x) == root(y);

}

void unite(int x, int y)
{
	x = root(x);
	y = root(y);
	if (x == y)
	{
		return;
	}
	if (r[x] < r[y])
	{
		par[x] = y;
	}
	else if (r[x]>r[y])
	{
		par[y] = x;
	}
	else if (r[x] == r[y])
	{
		par[x] = y;
		r[y]++;
	}

}
struct _cost {
	string material;
	int material_number;
	int material_cost;
	bool operator<(const _cost& other)const {
		return material_cost < other.material_cost;
	}
};



int main()
{
	int n;//�ޗ��̐� ���j�I���t�@�C���h�؂̒��_�̐�
	cin >> n;
	init(n);
	vector<_cost>v(n);//�ޗ��ƃR�X�g�̑Ή����Ǘ�
	for (int i = 0; i < n; i++)
	{
		_cost c;
		string str;
		cin >> str;
		c.material = str;
		c.material_number = i;
		int cost;
		cin >> cost;
		c.material_cost = cost;
		v[i] = c;

	}
	sort(v.begin(), v.end());//�ޗ���cost���������ɕ��בւ���
	int m;
	cin >> m;//���@�̎�� �ӂ̐�
	vector<vector<int>>edge(m,vector<int>(2));
	for (int i = 0; i < m; i++)
	{
		string str1;
		cin >> str1;
		
		
			for (int j = 0; j < n; j++)
			{
				if (str1 == v[j].material)
				{
					edge[i][0] = v[j].material_number;
		  		}
			}
		
		
		string str2;
		cin >> str2;

		for (int j = 0; j < n; j++)
		{
			if (str2 == v[j].material)
			{
				edge[i][1] = v[j].material_number;
			}
		}

		
	}
	

	for (int i = 0; i < m; i++)
	{
		unite(edge[i][0], edge[i][1]);
	}

	vector<int>check(n,0);//�e���_�̎����I�ȃR�X�g���Ǘ�����
	vector<bool>ok(n, false);//�×~�@�Ȃ̂ň��A�b�v�f�[�g���ꂽ��I���@������`�F�b�N����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (same(v[i].material_number, j)&&(ok[j]==false))
			{
				check[j] = v[i].material_cost;
				ok[j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += check[i];
	}
	cout << ans << endl;

	return 0;
}