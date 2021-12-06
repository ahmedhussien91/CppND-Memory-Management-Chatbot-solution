#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // copy constructor
    ChatBot(ChatBot & other) {
        std::cout << "ChatBot copy constructor";
        _image = new wxBitmap(*other._image);
        _chatLogic = nullptr;
        _rootNode = nullptr;
    } 
    // move constructor
    ChatBot(ChatBot && other) {
        std::cout << "ChatBot move constructor";
        _image = other._image;
        _currentNode = other._currentNode;
        _rootNode = other._rootNode;
        _chatLogic = other._chatLogic;
        other._image = nullptr;
        other._currentNode = nullptr;
        other._rootNode = nullptr;
        other._chatLogic = nullptr;
    }
    ChatBot & operator = ( ChatBot & other){
        std::cout << "ChatBot copy assignment operator";
        if (&other == this)
            return *this;
        delete _image;
        _image = new wxBitmap(*other._image);
    };
    ChatBot& operator = (ChatBot && other){
        std::cout << "ChatBot move assignment operator";
        if (&other == this)
            return *this;
        delete _image;
        _image = other._image;
        _currentNode = other._currentNode;
        _rootNode = other._rootNode;
        _chatLogic = other._chatLogic;
        other._image = nullptr;
        other._currentNode = nullptr;
        other._rootNode = nullptr;
        other._chatLogic = nullptr;
    };


    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
