队列方法的可优化项

因为队列是先进先出的,从左往右. 对从右往左的情况, 需要reverse方法. O(N)的时间复杂度



要对奇数层,从左往右;偶数层, 从右往左. 可以用两个双端队列/或者两个栈.


相当于以空间换时间