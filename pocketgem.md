#Pocket Gems
1.给一个数组，包含1到n，有的出现一次，有的出现两次，用constant space， O(n) time找出出现两次的数。不能排序 不能hash 想到异或 可是不知道有几个出现两次。。。

a: https://leetcode.com/problems/find-all-duplicates-in-an-array/?tab=Description 
思路：这题的关键是给定了数组值的范围1-n,可以把他的值作为index，相当于a[a[i]-1],如果有重复的值，那么flip一下值，判断遇到了多少次负数的值，就出现了多少个两次的元素

2.一组数范围在［0， n] 每个数都存在， 有的数出现一次， 有的数出现两次，输出所有出现两次的数 O(n) time, O(1) space
居然不是top K， 上来有点懵， 稳了一下问他说可不可以改变数组元素的位置， 说可以。 就尝试扫一遍， 没到array[i] != i 的时候就交换 array[i] 和array[array[i]]
知道相等。 最后所有array[i] != i的数就是重复的数。因为每次交换都会使一个位置出现array[i] ＝= i 的情况， 最多n 次交换 time O(n). 

a:

3.一个矩阵有0 和 1， 1的右边一定是1， 要找到整个矩阵最左边的1。 要求复杂度比O(mn) 好。 一开始naive了， 说每行binary search。 他问能不能更好。 才发现
从右上角第一个1开始往左找， 遇到0 往下找下一个1， 直到不能走了为止。 复杂度O(m + n)


4.convert a Ternary expression to a Binary tree structure?
把三元组转换成二叉树
