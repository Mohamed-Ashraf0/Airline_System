#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <string>


class Entity {
    protected:
    std::string id;
public:
    virtual ~Entity() = default;
    virtual const std::string &getId() const =0;
    virtual void setId(const std::string &id)=0;
    virtual void displayInfo()const=0;
};

#endif