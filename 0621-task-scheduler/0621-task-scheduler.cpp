class Solution
{
public:
    int leastInterval(std::vector<char>& tasks, int n)
    {
        std::vector<int> count(26, 0); // Initialize count array with 26 zeros
        
        // Count the occurrences of each task
        for (char task : tasks)
        {
            count[task - 'A']++;
        }
        
        // Sort the tasks by frequency
        std::sort(count.begin(), count.end(), std::greater<int>());
        
        int maxFrequency = count[0]; // Get the maximum frequency
        
        int idleSlots = (maxFrequency - 1) * n; // Calculate the available idle slots
        
        // Fill the idle slots with the remaining tasks
        for (int i = 1; i < count.size() && idleSlots > 0; i++)
        {
            idleSlots -= std::min(maxFrequency - 1, count[i]);
        }
        
        idleSlots = std::max(0, idleSlots); // Make sure idleSlots is not negative
        
        return tasks.size() + idleSlots; // Return the total number of intervals required
    }
};