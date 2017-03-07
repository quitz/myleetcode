bst问题：
解决此类问题时，一定要牢记递归，因为树的结构一样，处理完root节点，依次处理left 和 right 节点，要应用树的这种性质，lc450，删除bst中的一个节点就用到了。

map unordered_map
map keep their elements ordered, implemented by red-black tree. unordered_map use more memory, implemented by hash table.

c++ file operation
ifstream for read, ofstream for write.
ifstream f(filename.c_str()) or ifstream("test.txt"), it only accepts const char* variable.