class MyHashMap {
private:
    static const int SIZE = 1000; // number of buckets
    vector<list<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE);
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        // check if key exists
        for (auto &p : buckets[idx]) {
            if (p.first == key) {
                p.second = value; // update
                return;
            }
        }

        // insert new
        buckets[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);

        for (auto &p : buckets[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);

        buckets[idx].remove_if([&](pair<int,int> &p) {
            return p.first == key;
        });
    }
};