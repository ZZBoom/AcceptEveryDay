/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class NodeImpl : public Node{
public:
    NodeImpl() = default;
    NodeImpl(const std::vector<std::string> &input) : temp(input) {

    }
    int evaluate() const {
        std::stack<int> sta;
        for (const auto &str : temp) {
            if (str[0] == '+') {
                assert(sta.size() >= 2);
                auto x = sta.top(); sta.pop();
                auto y = sta.top(); sta.pop();
                sta.push(x + y);
            } else if (str[0] == '-') {
                assert(sta.size() >= 2);
                auto x = sta.top(); sta.pop();
                auto y = sta.top(); sta.pop();
                sta.push(y - x);
            } else if (str[0] == '*') {
                assert(sta.size() >= 2);
                auto x = sta.top(); sta.pop();
                auto y = sta.top(); sta.pop();
                sta.push(x * y);
            } else if (str[0] == '/') {
                assert(sta.size() >= 2);
                auto x = sta.top(); sta.pop();
                auto y = sta.top(); sta.pop();
                sta.push(y / x);
            } else {
                auto x = std::stoi(str);
                sta.push(x);
            }
        }
        return sta.top();
    }
private:
    std::vector<std::string> temp;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        return new NodeImpl(postfix);
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
