在 C++中，对于 vector 的访问效率比较：

`for (int& x:a){}` 通常比 `for (int i=0;i<n;i++){ a[i] }` 略微高效，原因是：

1. 范围 for 循环使用迭代器，避免了索引计算
2. 使用引用(`int&`)避免了值复制
3. 编译器可以更好地优化范围 for 循环

不过，实际差异通常很小，尤其是在现代编译器优化下。如果性能关键，可以使用`-O2`或`-O3`优化级别编译并比较两种方法。
