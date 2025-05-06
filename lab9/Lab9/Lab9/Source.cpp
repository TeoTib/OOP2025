#include <iostream>
using namespace std;

template <typename A, typename B>
class Map
{
private:
    struct Entry {
        A key;
        B value;
    };

    Entry* entries;
    int size;
    int capacity;

    int findIndex(const A& key)
    {
        for (int i = 0; i < size; i++)
            if (entries[i].key == key)
                return i;
        return -1;
    }
public:
    Map(){
        capacity = 10;
        entries = new Entry[capacity];
        size = 0;
    }
    ~Map()
    {
        delete[] entries;
    }
    
    B& operator[](const A& key)
    {
        int index = findIndex(key);
        if (index != -1)
            return entries[index].value;
        entries[size].key = key;
        entries[size].value = {};  // default-initialize
        ++size;
        return entries[size - 1].value;
    }

    class Iterator {
    private:
        Entry* current;
        int index;

    public:
        Iterator(Entry* ptr, int idx) : current(ptr), index(idx) {}

        // Dereference pt [key, value, index]
        auto operator*() const {
            return tuple<A, B, int>{current->key, current->value, index};
        }

        // Prefix increment
        Iterator& operator++() {
            ++current;
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    Iterator begin() {
        return Iterator(entries, 0);
    }
    Iterator end() {
        return Iterator(entries + size, size);
    }

    void Set(const A& key, const B& value)
    {
        int index = findIndex(key);
        if (index != -1)
            entries[index].value = value;
        else
        {
            //adaugam
            entries[size].key = key;
            entries[size].value = value;
            ++size;
        }
    }
    bool Get(const A& key, B& value)
    {
        int index = findIndex(key);
        if (index != -1)
        {
            value = entries[index].value;
            return true;
        }
        else return false;
    }
    int Count()
    {
        return size;
    }
    void Clear()
    {
        delete[] entries;
        entries = nullptr;
        size = 0;
        capacity = 0;
    }
    bool Delete(const A& key)
    {
        int index = findIndex(key);
        if (index != -1)
        {
            for (int i = index; i < size - 1; i++)
            {
                entries[i].key = entries[i + 1].key;
                entries[i].value = entries[i + 1].value;
            }
            size--;
            return true;
        }
        return false;
    }
    bool Includes(const Map<A, B>& map) //verific daca map se afla in this
    {
        bool verificare = true;
        for (int i = 0; i < map.size; i++)
        {
            int index = findIndex(map.entries[i].key);
            if (index==-1)
                verificare = false;
        }
        return verificare;
    }
};


int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Set(20, "macanache");
    cout << m[20]<<endl;
    const char* test;
    cout << m.Get(20, test) << " " << test << endl;
    cout << m.Count() << endl;
    m.Delete(20);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    Map<int, const char*> m2;
    m2[10] = "C++";
    cout << m.Includes(m2);
    return 0;
}