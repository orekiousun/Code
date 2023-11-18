#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

enum NodeState {
    Success = 0,
    Failure = 1,
    Running = 2,
};

class BTNode {
public:
    virtual NodeState OnExecute() = 0;
};

class BTBranch : BTNode {
public:
    BTBranch() {
        children.reserve(8);
        currentIndex = 0;
    }
protected:
    vector<BTNode*> children;
    int currentIndex;

    virtual void Add(BTNode* node) {
        currentIndex++;
        if(currentIndex + 1 < children.size())
            children[currentIndex] = node;
        else
            children.push_back(node);
    }

    virtual void Add(vector<BTNode*> nodes) {
        for (auto node : nodes) {
            Add(node);
        }
    }
};

class Sequencer : BTBranch {
    NodeState OnExecute() override {
        NodeState childNode = children[currentIndex]->OnExecute();
        switch (childNode) {
        case Success:
            currentIndex++;
            if(currentIndex == children.size()) {
                currentIndex = 0;
            }
            return Success;
            break;
        case Failure:
            currentIndex = 0;
            return Failure;
            break;
        case Running:
            return Running;
            break;
        }
        return Success;
    }
};

class Selector : BTBranch {
public:
    NodeState OnExecute() override {
        NodeState childNode = children[currentIndex]->OnExecute();
        switch (childNode) {
        case Success:
            currentIndex = 0;
            return Success;
            break;
        case Failure:
            currentIndex++;
            if(currentIndex == children.size()) {
                currentIndex = 0;
            }
            return Failure;
            break;
        case Running:
            return Running;
            break;
        }
        return Success;
    }
};

class ActionBase : BTNode {

};

class ConditionBase : BTNode {

};

class RepeatNode : BTBranch {
public:
    bool isStop = false;
    NodeState OnExecute() override {
        auto childNode = children[currentIndex]->OnExecute();
        while (true) {
            switch (childNode) {
            case Running:
                return Running;
                break;
            default:
                currentIndex++;
                if(currentIndex == children.size()) {
                    currentIndex = 0;
                    return Success;
                }
                continue;
            }
        }
    }
};