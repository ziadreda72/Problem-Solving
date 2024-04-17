class RandomizedSet {
public:
    RandomizedSet() {
        // The constructor will be empty
        // to solve this problem in O(1) average time we can use
        // a hash map data structure to hold insertion and deletion
        // in O(1) average time.
        // We also need a vector to implement GetRandom function in O(1) time
        // this can be done if we know the index of the element to be removed
        // instead of removing the element in O(n) time, we can swap this element
        // with the back of the vector then pop back in O(1)
        // The variable n indicates the size of the vector
    }
    
    bool insert(int val) { // O(1) average
        if (mp.count(val)) {
            // The input is already exists we will do nothing
            // just return false as the problem statement says
            return false;
        }
        // If we get here this means the element doesn't exist
        // we will insert to the map [key , value] = [val , n]
        // where n indicates the index of the new value in the vector
        // then we increment n
        mp[val] = n++;
        vals.push_back(val);
        return true;
    }
    
    bool remove(int val) { // O(1)
        if (mp.count(val)) {
            // The input already exists, we need to remove it and
            // do the swap operation we discussed before
            int i = mp[val];
            mp.erase(mp.find(val));
            if (i == n - 1) {
                // This means the element to be removed is already the back
            } else {
                // don't forget to change the index of the back in the hash map
                mp[vals.back()] = i;
                vals[i] = vals.back();
            }
            vals.pop_back();
            n--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // Just need to use built-in function rand
        // rand() % n will give us a random index between 0 and n - 1
        // with equal probability
        return vals[rand() % n];
    }

private:
    unordered_map < int , int > mp;
    vector < int > vals;
    int n = 0;    
};

/*
Time: O(1)
Space: O(n)
*/
