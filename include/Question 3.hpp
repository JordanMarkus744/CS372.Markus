#include <cassert>

template <class RecordType>
class Table {
public:
    static const std::size_t CAPACITY = 4096;

    Table() : used(0) {
        for (std::size_t i = 0; i < CAPACITY; ++i) {
            data[i].key = NEVERUSED;
        }
    }

    void insert(const RecordType &entry) {
        bool alreadyPresent;
        std::size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);

        if (!alreadyPresent) {
            assert(size() < CAPACITY);
            index = hash(entry.key);

            int count = 1;
            while (!isVacant(index)) {
                index = quadProbe(index, count);
                count++;
            }

            ++used;
        }

        data[index] = entry;
    }

    void remove(int key) {
        bool found;
        std::size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }

    bool isPresent(int key) const {
        bool isFound;
        std::size_t index;
        findIndex(key, isFound, index);
        return isFound;
    }

    void find(int key, bool &found, RecordType &result) const {
        std::size_t index;
        findIndex(key, found, index);

        if (found) {
            result = data[index];
        }
    }

    std::size_t size() const { return used; }

private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    std::size_t used;

    std::size_t hash(int key) const {
        return (key % CAPACITY);
    }

    std::size_t nextIndex(std::size_t index) const {
        return (index + 1) % CAPACITY;
    }

    void findIndex(int key, bool &found, std::size_t &index) const {
        std::size_t count = 0;
        index = hash(key);

        while ((count < CAPACITY) && (!neverUsed(index)) && (data[index].key != key)) {
            ++count;
            index = quadProbe(index, count);
        }

        found = (data[index].key == key);
    }

    std::size_t quadProbe(std::size_t index, int count) const {
        return (index + (count * count)) % CAPACITY;
    }

    bool neverUsed(std::size_t index) const { return (data[index].key == NEVERUSED); }
    bool isVacant(std::size_t index) const { return (data[index].key == PREVIOUSLYUSED); }
};