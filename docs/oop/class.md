# OOP czp

# Others

## 内存空间分配new和delete

- new和delete可以直接用于内存空间分配或者是释放
  - `int k = new int;`表示在空间中分配了一个int类型的k
  - `delete k;`表示将k所在的内存空间释放
- 当new和delete用于数组的内存空间
  - `int *k = new int[size];`表示在内存空间中分配一个有size个int元素的数组空间，并将首指针赋值给k
  - `delete []k;`表示将k数组所在的内存空间内容释放