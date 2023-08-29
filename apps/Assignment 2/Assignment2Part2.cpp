#include <iostream>

template<typename T>
class Array{
    int size = 1;
    T *arr = new T[size];

public:
    Array(size_t size){
        this->size = size;
        arr = new T[size];
    }


    ~Array(){
        delete [] arr;
        arr = nullptr;
    }


  T &at(int index) {
    if (index < 0 || index > Size()) {
			std::cerr << "Vector: index out of bounds on access" << std::endl;
			exit(1);
		}
		else {
			return arr[index];
		}
  }

  int Size() {
    return size;
  }


  void traverse() {
		for (int i = 0; i < this->size; i++) {
			std::cout << arr[i] << std::endl;
		}
		std::cout << std::endl;
  }

	bool operator==(Array& other) const {
		if (other.Size() != this->size) {
			return false;
		}
		else {
			for (int i = 0; i < this->size; i++) {
				if (arr[i] != other.at(i)) {
					return false;
				}
			}
		}
		return true;
	};

  T& operator[](int i) {
    if ((i < 0) || (i >= Size())) {
      std::cerr << std::endl << "Vector index out of bounds" << std::endl;
    }
    return at(i);
  }

	Array& operator=(Array& source) {
		// Do a self check.
		if (this == &source)
		{
			return *this;
		}
		// Reset self
		delete[] arr;
		arr = new T[1];
		this->size = 1;
		for (int i = 0; i < source.size(); i++) {
			source[i] = arr[i];
		}
		return *this;
	}
};

int main(){
    Array<int> arr(5);

    for (int i = 0; i < arr.Size(); i++){
        arr[i] = i;
    }

    arr.traverse();

    Array<int> arr2 = arr;
    arr2.traverse();

    bool isSame = arr == arr2;
    std::cout << isSame << std::endl;
}
