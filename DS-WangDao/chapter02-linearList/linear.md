#### 线性表是一种逻辑结构，表示元素之间一对一的相邻关系。顺序表和链表是指存储结构。

#### 线性表的基本操作：
- InitList(*L):初始化表，构造一个空的线性表
- Length(L):返回线性表L的长度，即L中元素的个数
- ListInsert(*L,i,e):插入，在表L的第i个位置插入元素e
- ListDelete(*L ,i, *e):删除，删除表L的第i个位置的元素，并用e返回删除元素的值
- PrintList(L):遍历表，按顺序输出线性表的所有元素值
- IsEmpty(L):判空，若L为空表，返回true，否则返回false
- IsFull(L):判满，若L为满表，返回true，否则返回false
- DestroyList(*L):销毁，销毁线性表并释放内存空间


