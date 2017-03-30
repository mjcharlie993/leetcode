DFS：思想是从一个顶点V0开始，沿着一条路一直走到底，如果发现不能到达目标解，那就返回到上一个节点，然后从另一条路开始走到底，这种尽量往深处走的概念即是深度优先的概念。
DFS适合此类题目：给定初始状态跟目标状态，要求判断从初始状态到目标状态是否有解。
/** 
 * DFS核心伪代码 
 * 前置条件是visit数组全部设置成false 
 * @param n 当前开始搜索的节点 
 * @param d 当前到达的深度，也即是路径长度 
 * @return 是否有解 
 */  

bool DFS(Node n, int d) {
    if (d == 4) 
        return true;
    for (Node nextNode, int n) {
        if (!visit[nextNode]) {
            visit[nextNode] = true;
            if (DFS(nextNode, d + 1) {
                return true;
            }
        visit[nextNode] = false;
        }
    }
    return false;
}