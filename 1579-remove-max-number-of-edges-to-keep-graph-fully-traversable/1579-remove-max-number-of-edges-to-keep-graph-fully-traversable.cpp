class Solution
{
    public:
#define d(x) cout << #x << " " << x << endl;
    vector<int> parent_a;
    vector<int> parent_b;
    void DSU(int n)
    {
        parent_a.resize(n + 1);
        parent_b.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent_a[i] = i;
            parent_b[i] = i;
        }
    }
    int find_parent_a(int k)
    {
        if (parent_a[k] == k) return k;
        return parent_a[k] = find_parent_a(parent_a[k]);
    }
    int find_parent_b(int k)
    {
        if (parent_b[k] == k) return k;
        return parent_b[k] = find_parent_b(parent_b[k]);
    }
    void merge_a(int u, int v)
    {
        int pu = find_parent_a(u);
        int pv = find_parent_a(v);
        if (pu == pv) return;
        parent_a[pu] = pv;
    }

    void merge_b(int u, int v)
    {
        int pu = find_parent_b(u);
        int pv = find_parent_b(v);
        if (pu == pv) return;
        parent_b[pu] = pv;
    }
   	// bool static comparator(vector<int>&a, vector<int>&b)
   	// {
   	//     return a[0] > b[0];
   	// }
    int maxNumEdgesToRemove(        int n,
        vector<vector < int>> &edges)
    {
        DSU(n);
        int answer = 0;
        sort(edges.rbegin(), edges.rend());
       	// cout<<find_parent_a(1)<<endl;
        for (auto &edge: edges)
        {
            int type = edge[0],
                u = edge[1],
                v = edge[2];
           	// cout<<type<<endl;
            if (type == 1)
            {
                if (find_parent_a(u) == find_parent_a(v))
                {
                    answer++;
                }
                else
                {
                    merge_a(u, v);
                }
            }
            else if (type == 2)
            {
               	// cout<<"at type 3"<<endl;
                if (find_parent_b(u) == find_parent_b(v))
                {
                    answer++;
                   	// cout<<u<<" "<<v<<endl;
                }
                else
                {
                   	// cout<<"hi"<<endl;
                    merge_b(u, v);
                }
            }
            else
            {
                if (find_parent_a(u) == find_parent_a(v))
                {
                    answer++;
                }
                else
                {
                    merge_a(u, v);
                    merge_b(u, v);
                   	// d(u);
                   	// d(v);
                   	// d(find_parent_a(u));
                   	// d(find_parent_a(v));
                   	// d(find_parent_b(u));
                   	// d(find_parent_b(v));
                   	// cout<<"merged "<<u<<" "<<v<<endl;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (find_parent_a(i) != find_parent_a(i + 1)) return -1;
        }
        for (int i = 1; i < n; i++)
        {
            if (find_parent_b(i) != find_parent_b(i + 1)) return -1;
        }
       	// int a1 = parent_a[0];
       	// for(auto it : parent_a)
       	// {
       	//     if(it != a1)return -1;
       	// }
       	// a1 = parent_b[0];
       	// for(auto it : parent_b)
       	// {
       	//     if(it != a1)return -1;
       	// }
        return answer;
    }
};