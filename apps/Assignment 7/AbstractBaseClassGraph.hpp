
class GraphBase{
    public:
    virtual void addEdge(int v1, int v2) = 0;
    virtual void removeEdge(int v1, int v2) = 0;
    virtual bool isEdge(int v1, int v2) = 0;
    virtual void display() = 0;
    virtual int getNumVertices() = 0;
    virtual int getNumEdges() = 0;
};

