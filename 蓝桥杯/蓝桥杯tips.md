赛前总结
1. 首先先看数据范围，确定算法时间复杂度 -> O(N ^ 2) O(N ^ log(N)) 
	- 如果是 15 - 20这种，绝对是dfs
	- 如果是 100 - 500 这种，绝对动态规划
	- 如果 1000 - 5000 这种，动态规划，或者 N ^ 2 * log(N) 算法
	- 如果 10000，N ^ 2
	- 如果 100000， N ^ log(N)
	- 如果 1e7 ~ 1e9, N
	- 如果 > 1e9, 多半是数学方法
2. '#define ll long long' 一定要记得
	- 如果你不确定会不会爆 int， 直接开 long long, 不然15分…… [15届国BC++ 5.数三角](https://www.lanqiao.cn/problems/17107/learning/)
	- 当然你开了long long 也可能会爆，这时候开 unsigned long long，但是一般来说，ll 爆了，ull 也差不了多少了。这是要十分小心和注意，例如 [15届国BC++ 2.双子数](https://www.lanqiao.cn/problems/17105/learning/)
3. 数据精度
	- 主要是 double 小数这方面的， 要十分注意，如果能够整除，尽量整除，例如 [8届省BC++ 3.承压计算](https://www.lanqiao.cn/paper/4103/result/?backPath=%2Fcup%2F)
	- 如果确实无法整除，那就尽可能保留高精度，例如 [12届省BC++ 3.直线](https://www.lanqiao.cn/problems/1449/learning/)
4. 蓝桥杯OJ系统
	- 在笔者刷题过程中遇到一些编译报错问题。
	- struct data{……} 本地dev-cpp可以正常运行，但是蓝桥杯官网OJ会报错，猜测data是其内部关键词，所以，尽可能用不那么像关键词的词，例如 info，或者 Data
	- 关于 输入 cin。 笔者刷题过程中，遇到一个前所未闻错误原因。我的输入写在 solve（）方法中，main（）中调用 solve ， 但是蓝桥杯的输出结果会包含样例。在我将cin 放置 main 中后，就通过了……，我后来没试验过，但是还是请注意。
5. 关于数组初始化问题
	- 个人建议，显式初始化数组，用vector,不要用 int*.
	- int arr[N]; memset(arr,1,sizeof(arr)); 这个是错误的，memset 会将每一个字节初始化为1，但是 int 四个字节啊，当初始化为 0，-1时，是没问题的。如果时char类型，memset是可以用的。
	- 但是vector在初始化时明显方便许多。
	- vector<int> arr(N,1); arr.assign(N + 1, -1);
6. dfs
	- 有时候dfs可以通过剪枝和记忆化搜索的方式，通过动态规划的题目，例如 
	- [13届省BC++ 9.李白打酒加强版](https://www.lanqiao.cn/problems/2114/learning/)
	- [12届省BC++ 7.砝码称重](https://www.lanqiao.cn/problems/1447/learning/)
	- 建议各位看一下左程云老师的课 dfs -> dp 讲解的十分精妙

目前先到这里吧，祝大家都能有个好成绩。