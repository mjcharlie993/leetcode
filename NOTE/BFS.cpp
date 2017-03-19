BFS strategy: 越早被访问到的顶点，其邻边越优先被选用
BFS process： 反复从波峰集中找到最早被访问到顶点v，若其邻居均已访问到，则将其逐出波峰集，；否则，随意选出一个尚未访问到的邻居，并将其加入到波峰集
波峰集：在所有已访问到的顶点中，仍有邻居尚未访问者

实现代码
template <typename Tv, typename Te>    // 广度优先搜索BFS算法（全图）
void Graph<Tv, Te>::bfs(int s) {       // assert: 0 <= s < n
    reset(); int clock = 0;int v = s;  // 初始化
    do // 逐一检查所有顶点
        if (UNDISCOVERED == status(v)) // 一旦遇到尚未发现的顶点
            BFS(v, clock);             // 即从该顶点出发启动一次BFS
    while (s != (v = (++v % n)));      // 按序号检查，故不漏不重
}

template<typename Tv, typename Te>                           // 广度优先搜索BFS算法（单个连通域）
void Graph<Tv, Te>::BFS(int v, int& clock) {                 // assert: 0 <= v < n
    Queue<int> Q;                                            // 引入辅助队列
    status(v) = DISCOVERED; Q.enqueue(v);                    // 初始化顶点
    while (!Q.empty()) {                                     // 在Q变空之前，不断
        int v = Q.dequeue(); dTIme(v) = ++clock;             // 取出队首顶点v
        for (int u = firstNbr(v); -1 < u; u = nextNbr(v, n)) // 枚举v的所有邻居u
        if (UNDISCOVERED == status(u)) {                     // 若u尚未被发现，则
            status(u) = DISCOVERED; Q.enqueue(u);            // 发现该顶点
            type(v, u) = TREE; parent(u) = v;                // 引入树边拓展支撑树
        } else {                                             // 若u已被发现，或者甚至已访问完毕，则
            type(v, u) = CROSS;                              // 将（v,u）归类于跨边
        }
    status(v) = VISITED;                                     // 至此，当前顶点访问完毕
    }
}


//Source: http://poj.org/problem?id=3984
/**
 * 广度优先搜索
 * @param: Vs 起点
 * @param: Vd 终点
 */
bool BFS(Node& Vs, Node& Vd) {
    queue<Node> Q;
    Node Vn, Vw;
    int i;

    // 用于标记颜色当visit[i][j] == true时，说明节点访问过，也就是黑色
    bool visit[MAXL][MAXL];

    // 四个方向
    int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // 初始状态将起点放入队列Q
    Q.push(Vs);
    visit[Vs.x][Vs.y] = true; // 设置节点已经访问过了

    while (!Q.empty()) {// 队列不为空，继续搜索！
        // 取出队列的头Vn
        Vn = Q.front();
        // 从队列中移除
        Q.pop();

        for (i = 0; i < 4; ++i) {
            Vw = Node(Vn.x + dir[i][0], Vn.y + dir[i][1]); // 计算相邻节点
            if (Vw == Vd) { // 找到终点了
                // 把路径记录，这里没给出解法
                return true;
            }

            if (isValid(Vw) && !visit[Vw.x][Vw.y]) {
                // Vw是一个合法的节点并且为白色节点
                Q.push(Vw); // 加入队列Q
                visit[Vw.x][Vw.y] = true; // 设置节点颜色
            }
        }
    }
    return false; // 无解
}

