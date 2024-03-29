
// class RandomizedSet {
// private:
//     unordered_set<int>::iterator nextRand;
//     unordered_set<int> randomGen;
// public:
//     /** Initialize your data structure here. */
//     RandomizedSet() {
//         nextRand = randomGen.end();
//     }
    
//     /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//     bool insert(int val) {
//         if (randomGen.count(val) > 0) {
//             return false;   
//         }
//         randomGen.insert(val);
//         return true;
//     }
    
//     /** Removes a value from the set. Returns true if the set contained the specified element. */
//     bool remove(int val) {
//         auto i = randomGen.find(val);
        
//         if (i == randomGen.end()) {
//             return false;
//         } else if ((nextRand != randomGen.end()) && (*i == *nextRand)) {
//             nextRand++;
//         }
        
//         randomGen.erase(val);
//         return true;
//     }
    
//     /** Get a random element from the set. */
//     int getRandom() {
//         int rand;
//         if (nextRand == randomGen.end()) {
//             nextRand = randomGen.begin();
//         }
        
//         rand = *nextRand;
//         nextRand++;
//         return rand;
//     }
// };
class RandomizedSet {
	// Thanks to Bhalerao-2002
private:
    // array vector
    vector<int> a;
     // Unordered Map does searching, insertion & deletion of element in average O(1) time
    unordered_map<int,int> m;
public:
    RandomizedSet() {
    // No need to initialise a & m as they are initialised automatically
	// to 0 as and when their container size increases.
    }
    //Insert
    bool insert(int val) {
        if(m.find(val)!=m.end())
	        // If val is not already present in the map, find() function  
	        // returns an iterator(m.end()) pointing to next memory location  
            // of the last element of the map. Otherwise, find() returns an iterator 
            // pointing to val which was already present in the map.  
            return false;
        else{
            a.push_back(val);  
            m[val]=a.size()-1; 
            return true;
        }
    }
    
    //Remove
    bool remove(int val) {
        if(m.find(val)==m.end()) // val not present in the array vector
            return false;
        else{
	        // val present in the array vector
            int last=a.back();  // back() fetches last element of the array vector
            a[m[val]]=a.back(); // m[val] locates the index of val in the array vector.     
            a.pop_back();	   
            m[last]=m[val];	     
            m.erase(val);	    // Delete the val entry from map
            return true;
        }
    }
    
    /** Get a random element from the array vector */
    int getRandom() {
        return a[rand()%a.size()];
    }
};