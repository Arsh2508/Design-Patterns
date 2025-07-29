#include <iostream>
#include <string>
#include <unordered_map>

class Message {
public:
    virtual std::string getText(const std::string& message) const = 0;
};

class PlainMessage : public Message {
public:
    std::string getText(const std::string& message) const override {
        return message;
    }
};

class BaseDecorator : public Message {
public:
    BaseDecorator(Message* msg_) : message{msg_} {}

    std::string getText(const std::string& msg) const override
    {
        return message->getText(msg);
    }
protected:
    Message* message;
};

class UpperCaseDecorator : public BaseDecorator {
public: 
    UpperCaseDecorator(Message* msg_) 
        : BaseDecorator(msg_)
    {}

    std::string getText(const std::string& msg) const override 
    {
        std::string res = message->getText(msg);
        for(int i = 0; i < msg.size(); ++i) {
            res[i] = std::toupper(msg[i]);
        }

        return res;
    }
};

class LowerCaseDecorator : public BaseDecorator {
public: 
    LowerCaseDecorator(Message* msg) 
        : BaseDecorator(msg)
    {}

    std::string getText(const std::string& msg) const override 
    {
        std::string res = message->getText(msg);
        for(int i = 0; i < msg.size(); ++i) {
            res[i] = std::tolower(msg[i]);
        }
        
        return res;
    }
};

class EncryptedMessageDecorator : public BaseDecorator {
public:
    EncryptedMessageDecorator(Message *msg, std::unordered_map<char, char>& mp)
        : BaseDecorator(msg), mp_{mp} {}

    std::string getText(const std::string& text) const override 
    {
        std::string res = text;
        for(int i = 0; i < res.size(); ++i){
            if(mp_.find(res[i]) != mp_.end()){
                res[i] = mp_.find(res[i])->second;
            }
        }

        return res;
    }

protected:
    std::unordered_map<char, char> mp_;
};


class DecryptedMessageDecorator : public BaseDecorator {
public:
    DecryptedMessageDecorator(Message *msg, std::unordered_map<char, char>& mp)
        : BaseDecorator(msg) 
    {
        for(const auto& [key, val] : mp){
            mp_[val] = key;
        }
        
    }

    std::string getText(const std::string& text) const override 
    {
        std::string res = text;
        for(int i = 0; i < res.size(); ++i){
            if(mp_.find(res[i]) != mp_.end()){
                res[i] = mp_.find(res[i])->second;
            }
        }
        
        return res;
    }

protected:
    std::unordered_map<char, char> mp_;
};

int main() {
    Message *message = new PlainMessage();

    message->getText("HelloWorld");

    std::unordered_map<char, char> cipher = {
        {'A','Q'}, {'B','W'}, {'C','E'}, {'D','R'}, {'E','T'}, {'F','Y'},
        {'G','U'}, {'H','I'}, {'I','O'}, {'J','P'}, {'K','A'}, {'L','S'},
        {'M','D'}, {'N','F'}, {'O','G'}, {'P','H'}, {'Q','J'}, {'R','K'},
        {'S','L'}, {'T','Z'}, {'U','X'}, {'V','C'}, {'W','V'}, {'X','B'},
        {'Y','N'}, {'Z','M'},
        // Lowercase letters
        {'a','q'}, {'b','w'}, {'c','e'}, {'d','r'}, {'e','t'}, {'f','y'},
        {'g','u'}, {'h','i'}, {'i','o'}, {'j','p'}, {'k','a'}, {'l','s'},
        {'m','d'}, {'n','f'}, {'o','g'}, {'p','h'}, {'q','j'}, {'r','k'},
        {'s','l'}, {'t','z'}, {'u','x'}, {'v','c'}, {'w','v'}, {'x','b'},
        {'y','n'}, {'z','m'}
    };



    Message* decorator1 = new LowerCaseDecorator(message);
    Message* decorator2 = new EncryptedMessageDecorator(message, cipher);
    Message* decorator3 = new DecryptedMessageDecorator(message, cipher);

    std::cout << decorator2->getText("Decorator Hello 1") << std::endl;
    std::cout << decorator3->getText("Decorator HElloWOrld 2") << std::endl;
    std::cout << decorator1->getText("HeLLO worlD") << std::endl;

    delete decorator1;
    delete decorator2;
    delete decorator3;
    delete message;

    return 0;
}

