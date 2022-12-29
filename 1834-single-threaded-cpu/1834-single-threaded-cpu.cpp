class Solution
{
   	// time for processing, index
    typedef pair<int, int> T;
    public:
        vector<int> getOrder(vector<vector < int>> &arr)
        {
            priority_queue<T, vector < T>, greater < >> q;	// min heap of tasks, sorted first by processing time then by index.
            long n = arr.size(), time = 0, i = 0;	// `time` is the current time, `i` is the read pointer
            for (int i = 0; i < n; ++i) arr[i].push_back(i);	// append the index to each task
            sort(begin(arr), end(arr));	// sort the input array so that we can take the tasks of small enqueueTime first
            vector<int> res;
            while (i < n || q.size())
            {
               	// stop the loop when we exhausted the input array and the tasks in the heap.
                if (q.empty())
                {
                    time = max(time, (long) arr[i][0]);	// nothing in the heap? try updating the current time using the processing time of the next task in array
                }
                while (i < n && time >= arr[i][0])
                {
                   	// push all the tasks in the array whose enqueueTime <= currentTime into the heap
                    q.emplace(arr[i][1], arr[i][2]);
                    ++i;
                }
                auto[pro, index] = q.top();
                q.pop();
                time += pro;	// handle this task and increase the current time by the processingTime
                res.push_back(index);
            }
            return res;
        }
};