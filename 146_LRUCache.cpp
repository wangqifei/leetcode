// 146 LRU Cache
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// Hide Tags Data Structure


class LRUCache{
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(m_mp.find(key) == m_mp.end()) return -1;
        m_list.splice(m_list.begin(), m_list, m_mp[key]);
        m_mp[key] = m_list.begin();
        return m_mp[key]->second;
    }
    
    void set(int key, int value) {
        if(m_mp.count(key)) {
            m_mp[key]->second = value;
            m_list.splice(m_list.begin(), m_list, m_mp[key]);
            m_mp[key] = m_list.begin();
        }
        else {
            if(m_list.size() == m_capacity) {
                int back_key = m_list.back().first;
                m_list.pop_back();
                m_mp.erase(back_key);
            }
            m_list.push_front(make_pair(key, value));
            m_mp.insert(make_pair(key, m_list.begin()));
        }
    }
private:
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int,int>>::iterator> m_mp;
    int m_capacity;
};