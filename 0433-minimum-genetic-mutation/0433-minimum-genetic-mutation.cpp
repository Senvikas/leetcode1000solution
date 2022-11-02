class Solution
{
    public:
        int minMutation(string start, string end, vector<string> &bank)
        {
           	//if end and start are same 
            if (start == end)
                return 0;
            unordered_set<string> isValid;
            unordered_set<string> visited;
            unordered_set<char> Givenchar;

            for (auto &str: bank)
                isValid.insert(str);

            Givenchar.insert('A');
            Givenchar.insert('C');
            Givenchar.insert('G');
            Givenchar.insert('T');

           	//using BFS
            queue<string> q;
            q.push(start);
            visited.insert(start);
            int count = 0;

            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    string s = q.front();
                    q.pop();
                    for (int i = 0; i < 8; i++)
                    {
                        for (char c: Givenchar)
                        {
                            string newstring = s;
                            newstring[i] = c;
                            if (visited.find(newstring) == visited.end() && isValid.find(newstring) != isValid.end())
                            {
                                if (end == newstring)
                                    return count + 1;
                                visited.insert(newstring);
                                q.push(newstring);
                            }
                        }
                    }
                }
                count++;
            }
            return -1;
        }
};