# LinkedList Library for ESP32 Arduino C++

A template class that implements a doubly linked list data structure for the ESP32 Arduino C++ environment.

**Features**

- Stores elements of any data type (template class)
- Provides methods for adding, removing, and accessing elements
- Includes methods for sorting, reversing, and clearing the list
- Provides a size method for getting the number of elements in the list
- Provides operator overload for accessing elements using the array operator
- Provides methods for adding and removing elements from the front and back of the list
- Includes a destructor to automatically clear the list when the object goes out of scope

**Usage**

*To use the LinkedList class, include the header file in your project and create an object of the class.*

```c++
#include "ESP_LinkedList.h"

ESP_LinkedList<int> myList;
```

**Adding Elements**

*Elements can be added to the list using the add method, which adds the element to the end of the list, or the add method with an index parameter, which adds the element at a specific index in the list.*

```c++
myList.add(5);
myList.add(2, 10);
```

*You can also use push_back method as an alias for the add method.*

```c++
myList.push_back(7);
```

**Removing Elements**

*Elements can be removed from the list using the remove method with an index parameter, which removes the element at the specified index in the list.*

```c++
myList.remove(1);
```

*You can also use pop_back method to remove the last element of the list and pop_front to remove the first element of the list. These two methods will return the removed element by value*

```c++
myList.pop_back();
myList.pop_front();
```

**Accessing Elements**

*Elements can be accessed using the get method with an index parameter, which returns the element at the specified index in the list.*

```c++
int element = myList.get(2);
```

*You can also use the array operator to access elements in the list.*

```c++
int element = myList[2];
```

**Other Methods**

- The clear method can be used to remove all elements from the list.
- The size method returns the number of elements in the list.
- The contains method checks if the list contains a specific element.
- The indexOf method finds the index of a specific element in the list.
- The reverse method reverses the order of the elements in the list.
- The sort method sorts the elements in the list in ascending order based on the comparison operator '>'.
Example

```c++
#include "ESP_LinkedList.h"

ESP_LinkedList<int> myList;

void setup() {
    myList.push_back(5);
    myList.push_back(2);
    myList.push_back(7);
    myList.push_back(3);
    myList.sort();
    for (int i = 0; i < myList.size(); i++) {
        Serial.println(myList[i]);
    }
}
```


*This one header library created because there was no working open source solution for a
  linked list library which does not conflict with EspAsyncWebserver's String linked list.*
  
*It supports any kind of data since it uses templates.*

**EXAMPLES ARE NOT TESTED FOR NOW!!**
