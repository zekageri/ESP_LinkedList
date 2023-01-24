# ESP_LinkedList
**ESP_AsyncWebserver compatible LinkedList implementation.**

*This one header library created because there was no working open source solution for a
  linked list library which does not conflict with EspAsyncWebserver's String linked list.*
  
*It supports any kind of data since it uses templates.*
 
**For now it supports the following methods**
- add(T data);
- add(int index, T data);
- remove(int index);
- clear();
- size();
- get(int index);
- T operator[](int index);
- contains(T data);
- indexOf(T data);
- reverse();
- sort();
- pop_back();
