// 二叉树节点模板类
#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p)? p->height : -1)
typedef enum {RB_RED, RB_BLACK} RBColor;

template<typename T> struct BinNode {
    T data;
    BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
    int height;
    int npl;
    RBColor color;

    BinNode() : 
        parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr, int h = 0, int npl = 1, RBColor = RB_RED) :
        data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
    
    int size();
    BinNodePosi(T) insertAsLC(T const&);
    BinNodePosi(T) insertASRC(T const&);
    BinNodePosi(T) succ();
    template<typename VST> void travLevel(VST&);
    template<typename VST> void travPre(VST&);
    template<typename VST> void travIn(VST&);
    template<typename VST> void travPost(VST&);

    bool operator< (BinNode const& bn) { return data < bn.data; }
    bool operator== (BinNode const& bn) { return data == bn.data; }
}

// BinNode状态与性质的判断
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))

// 与BinNode具有特定关系的节点及指针
#define sibling(p) /*兄弟*/ 
    (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)
#define uncle(x) 
    (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
#define FromParentTo(x)
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))

// 插入孩子节点
template<typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e) 
{ return lc = new BinNode(e, this); }
template<typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e) 
{ return rc = new BinNode(e, this); }

