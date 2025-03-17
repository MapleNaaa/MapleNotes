ok，我现在想要实现一些基本功能，比如有一个容器，list
他需要以下功能。
1. 储存一些数据
2. read，write/motify
3. insert
4. remove
5. 能够count(size) / empty

这些功能构建了我们对这个list最基本的设想，也就是ADT(abstract data type)

主播主播，那你说的这些功能，arr就可以实现啊。
是的，但是还有些功能需要在arr的基础上进行增改,ADT就是我们修改的依据。

那么我们想想arr具体应该如何实现。
1. 储存数据。arr不必多说
2. read，write/motify 。 arr同样轻松搞定
3. insert
	1. 插入末尾的话，很轻松，没难度
	2. 在中间插入，那么应该后面的数据依次向后移动一位。
4. remove：操作类似于insert
5. int size = 0 初始化的时候，insert + 1  remove -1. size = 0 -> empty

诶主播主播，arr一开始就分配好空间了呀，会有一个初始的maxsize，如果insert的时候，已经满了怎么办？
那只能再一次开辟新数组，把旧数组的值一一复制到新数组中。一般默认新数组的空间是原来空间的两倍。

okok啊，
那么我们来看看时间复杂度啊。
1. O(1)
2. O(1)
3. 最坏O(n)
4. 最坏O(n)
5. O(1)
开辟新数组：包O(n)的老弟

主播主播，开辟新数组后，有部分空间没用到啊，这不纯纯浪费空间吗?还有更好的方法嘛？
有的有的，老弟。链表法了解一下？

数组的空间是连续存储空间，而链表是非连续的。

在介绍链表前，我们先定义一个struct
```
struct Node{
	int val;
	Node* next;
}
```

ok，那我这时候在来一个指针
```
Node* head = Null;
```

诶，同学是不是有点小想法了？

head 是一个Node类型指针，可以指向一块空间为Node的区域，这块区域里面，你说巧不巧，又有一个Node类型指针，那是不是可以指向另外一个Node区域？

这样是不是就串联起来了，各个数据之间？
有点类似于，你拿着知道一个门牌号，找到了对应的房屋，房屋里的人告诉你了第二个房子的门牌号，你又去找第二个，不断循环下去

ok，那我们来看看这个如何实现我们的ADT呢？
1. 储存数据。在val中储存。
2. read，write / motify 。从头节点一个个拿着门牌号去找
3. insert。简单啊，先找到对应的门牌号，改一下下一个门牌号即可
4. remove。同上
5. empty。头节点知不知道下一个门牌号。
6. 同arr

主播，这个是不是就没有空间浪费的问题了？
是的孩子。
这里的每一次insert，都是新开辟一个Node空间，随便开哪里，只要能够指到即可。不会有额外空间浪费。

那我们接着分析一下时间复杂度啊
1. O(n)
2. 最坏O(n)
3. 最坏O(n)
4. 最坏O(n)
5. O(1)
6. O(1)

其实比较下来，二者的差别也不是很大。各有各的优势。

说回链表法的空间占用。
Node* 占用8个字节，但是int只占用4个字节。相当于多花费了150%的空间储存。

当然，当Node里的其他数据占用多的时候，链表的优势就会展现。

ok，我简单写一下 链表的C++实现

```
struct Node{
	int val;
	Node* next;
}

Node* Head = NULL; // empty

Node* temp = new Node();
temp->val = 2;
temp->next = NULL;

Head = temp;

```

刚刚在链表中，很重要的一点就是找到门牌号对吧。那再写一下如何找门牌号
```
Node* temp = Head; // 假设Head后面有很多数据

while(temp->next != NULL){
	temp = temp->next;
}
temp->next // NULL，直接找到最后一家了

temp = Head; // 这次我要找到第5个
for(int i = 0 ; i < 5; i++){
	temp = temp->next;
}
temp->val // 这就是第5个所对应的值

```

那让我们来实现一下insert函数
```
void insert(int data,int n){
	if( n > size + 1 || n <= 0 ) return ;

	Node* temp = new Node();
	temp->val = data;
	temp->next = NULL;

	if(n == 1){
		temp->next = head;
		head = temp;
	}

	Node* ptr = head;
	for(int i = 0 ; i < n - 2 ; i++)
		ptr = ptr->next;
	// 此时ptr指向第n-1个值
	temp->next = ptr->next;
	ptr->next = temp;
	
}
```
这里有一个关键的理解。head代表的是第一个节点，执行一次后，ptr代表第二节点，所以要执行n-2后，代表n-1个节点。

那删除链表呢？其实也很简单了
```
void remove(int n){
	if(n > size || n <= 0 ) return ;

	Node* temp;

	if(n == 1){
		temp = head;
		head = head->next;
		free(temp) // 释放内存
		return;
	}

	Node* ptr = head;
	for(int i = 0; i < n - 2; i++)
		ptr = ptr->next;
	temp = ptr->next // ptr是第n-1个节点，ptr->next是第n个节点
	ptr->next = ptr->next->next;
	free(temp);
	return ;
}
```

那如何实现反转链表呢？
这一看其实就挺难受的。比较是单项链表，到了当前节点无法获取前面节点的内容。
如果直接暴力的话，O(n).

难点：如何在单次循环中，修改链接关系的同时，不遗漏后面的链接。

其实也很简单，三个变量即可，prev，cur，next
代码如下
```
void reverse(){
	Node* prev, cur, next;
	cur = head;
	prev = NULL;

	while(cur != NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}
```

主播主播，我听说循环的形式，似乎可以写成递归，主播你可以吗？
包的，主播什么实力你还不清楚嘛？

我们先来几个简单的例子入入门好吧
```
void printList(){
	Node* ptr = head;
	while(ptr != NULL){
		printf(ptr->data);
		ptr = ptr->next;
	}
	print("\n")
}
```
你看啊，在这段代码中，ptr值发生了改变。循环和递归执行的都是重复的代码
改写成递归形式
```
void printList(Node* p){
	if(ptr == NULL) return;
	printf(p->data);
	printList(p->next);
}
```

那翻转链表改成递归形式，似乎也可以从变量的角度入手
// 视频记录一下
```
void reverse(Node* cur,Node* prev){
	if(cur == NULL){
		head = prev;
		return ;
	} 
	reverse(cur->next,cur);
	cur->next = prev;
	prev = cur;
}
```

