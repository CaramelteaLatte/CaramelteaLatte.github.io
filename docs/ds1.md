## DS1
### Algorithm Analysis
input, output, definiteness确定性（每条指令都是清晰的没有歧义的）, finiteness有限性（经过一定的代码这个算法一定会停下来terminate）, effectiveness（基本的->可行的,足够基本）
- 与程序不同program，程序可以一直跑下去（比如做任务规划）
- 算法可以有多种描述方式，实际的编程语言，自然语言，伪代码。不一定要具体实现才能分析

### Selection Sort选择排序
自然语言：find the smallest from the unsorted and place it next in the sorted lists

### what to analysis
- Machine and complier-dependent run times
  - run times由机器和编译器决定->太抽象
- Time and space complexities时间空间复杂度，和machine and compliers无关
  - 我们假设：指令都是单线程运行的；每条指令都是简单的，都只占据一个  时间单位；整数的规模是有限的且我们有无限内存
  
### 复杂度计算
- 声明的复杂度：0；每条赋值的复杂度：1；每条判断的复杂度：1；判断分支：计算所有情况中复杂度较大者；return返回的复杂度：1
- 递归的复杂度：如T(n) = T(n-1) + 2解得T(n) = 2n + 2
- 循环的复杂度：注意退出循环的 时候还有一次判断但不运行
  - 总执行次数 = n+1+n*(循环体中语句执行次数)
  ```
  void  add ( int  a[ ][ MAX_SIZE ], 
                   int  b[ ][ MAX_SIZE ], 
                   int  c[ ][ MAX_SIZE ],
                   int  rows,  int  cols )
  {
    int  i,  j ;//声明复杂度无
    for ( i = 0; i < rows; i++ )//对于该循环体，复杂度为rows+1+rows(i的内部)
          for ( j = 0; j < cols; j++ )//对于i的内部，复杂度为cols+1+cols(j的内部)
                c[ i ][ j ] = a[ i ][ j ] + b[ i ][ j ];//j的内部=1
  }
  ```
- ![](1.png)

## Tree

- 一个 node 的 degree 是这个 node 的 child 个数，一棵树的 degree 是这棵树里面所有 node 的 degree 的最大值。
- 从节点 n<sub>1</sub>, n<sub>k</sub> 的路径定义为一个一个序列，这条路径是唯一的。
- deep：从跟到该节点唯一路径的长度
- height：从该节点到一片树叶的最长路径的长度

### binary tree

对每一个二叉树：
- 深度 k 的二叉树最多有 2<sup>k</sup> - 1 个节点
- 对任何非空二叉树有 n<sub>0</sub> = n<sub>2</sub> + 1

- preorder
```c
void preorder(tree* tree){
  if(tree){
    visit(tree);
    for(each child of the tree) preorder(child);
  }
}
```
- postorder
```c
void postorder(tree* tree){
  if(tree){
    for(each child in the tree) postorder(child);
    visit(tree);
  }
}
```
- levelorder
```c
void leveorder(tree* tree){
  enqueue(tree);
  while(queue is not empty){
    visit(T = dequeue());
    for(eaach child in the tree) enqueue(child);
  }
}
```
- inorder
```c
void inorder(tree* tree){
  if(tree){
    inorder(tree->left);
    visit(tree->element);
    inorder(tree->right);
  }
}
```

#### Thread binary tree 线索二叉树

![Alt text](image-4.png)

#### Binary serach tree 二叉搜索树

- 所有节点 element 不相同
- 左子树的 element < element < 右子树的 element

### stack

对于我们来说只有pop，push的操作，只有头结点可见

struct里面，总容量（用于判断），目前容量，头结点

### Heap



## Sort

### ShellSort

```c
//希尔排序
void ShellSort(SqList *L)
{
    int i, j, increment = L->last;
    do
    {
        increment = increment / 3 + 1;
        for (i = increment + 1; i <= L->last; i++)
        {
            if (L->arr[i] < L->arr[i - increment])
            {
                L->arr[0] = L->arr[i];
                for (j = i - increment; j > 0 && L->arr[0] < L->arr[j]; j -= increment)
                    L->arr[j + increment] = L->arr[j];
                L->arr[j + increment] = L->arr[0];
            }
        }
 
    } while (increment > 1);
}
```
希尔排序交换不相邻的数据对数组进行局部排序，最终用插入排序将局部有序的数组排序。

最初我们选择增量gap=length/2, 循环时gap=gap/2, 最后运行至gap=1。

### QuickSort

```c
void quick_sort(int *num,int l,int r){
	//如果小于等于1个数据元素·直接返回结束快排函数 r为数组元素总个数
	if(l+1>=r){
		return ;
	}
	int first=l,last=r-1,key=num[first];
	while(first<last){
		while(first<last&&num[last]>=key){
			--last;
		}
		//如果值小于 key分界值 交换 
		num[first]=num[last];
		while(first<last&&num[first]<key){
			++first;
		}
		//如果值大于key分界值 交换 
		num[last]=num[first];
	}
	num[first]=key;
	//递归左右部分进行快排 
	quick_sort(num,l,first);
	quick_sort(num,first+1,r);
}
```
以first为区间左端，以last为区间右端，以key作为基准值。

这里key取num[last]:（说明了last的位置可以被覆盖）

key和区间左端比较，如果左端 <key（符合条件），则区间左端右移；如果左端 >=key（不符合条件），则将区间左端放到last的位置上去。

key和区间右端比较，如果右端 >key（符合条件），则区间右端左移；如果右端 <=key（不符合条件），则将区间右端放到first的位置上去。

当区间左右端重合时一轮排序结束，重合位置就是key应当被放置的位置。

对这个位置的左右两个子段进行相同的操作，直到子段内元素个数为1，说明整个数列已经完全有序。

注意，如果是key取num[first]，（说明first的位置可以被覆盖），那么key的比较应当从区间右端开始，再左端，再往复循环。

## Search

### Hashing

二分查找树时间复杂度NlogN建树+logN查找，对于大数据来说太慢，而hash对于大量的数据，查找复杂度一直是O(1).（无冲突）

hash: 知道key找到index，由key映射index。(函数)

- collision：一个key查找到了两个index。
- overflow：溢出，桶放满了。
- 当一行只有1个桶的时候，overflow和collision同时发生。

**hash：选择合适的bucket和slot大小+设计key映射index的函数+桶排序+一个桶内链表**

#### 如何构造一个哈希函数

ascii 码，平方取中法（但是我感觉这个很随意吧）

#### 如何处理一次 collision

- 线性寻址open addressing：当这个位置冲突了就往后寻址，直到找到空的格子放进去
  - 平方探测： 
    - size = 4k + 3 且 size 是素数，平方探测可以探测到整个空间
  - 双散列double hashing
![Alt text](image-3.png)
以H2为步长往后移，
  - rehashing
    - 影响（装填因子）arpha = identifier density = total number of identifiers in ht[ ] / total number of distinct possible values for x. 已占有空间除以全部空间
    - 当 arpha 在范围 [0.5,0.85] 的时候必须要使用rehashing（在一个更大的空间里面重开hash）
    - 重开，空间范围要扩大，扩大的空间是原来的空间乘2然后往上取最近一个素数
    - 重开是在第一次hash之后的小数组基础上进行的，不在小数组内的数字按照原数组里面的顺序取
  - seperate chaining
    - 复杂度不再是 O（1）
    - 