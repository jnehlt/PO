#include "Map.hpp"

/* struct list_s_root public methods */
list_s_root::list_s_root():
    l_ptr_first(nullptr)    //Cxx11
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif
}

list_s_root::~list_s_root()
{
    list_s* temp = l_ptr_first;

    while(temp)
    {
        list_s* temp2 = temp;
        temp = temp->l_ptr_next;
        delete temp2;
    }
}

/* struct list_s public methots */
list_s::list_s(std::string name, int value):
    name(name), current_value(value), l_ptr_next(nullptr)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif
}

list_s& list_s::operator=(int value)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    this->current_value = value;
    return *this;
}

list_s& list_s::operator=(const list_s& value)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    this->current_value = value.current_value;
    return *this;
}

list_s::operator int()
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    return this->current_value;
}

/* class MapCSen private methods */
void MapCSen::l_add(std::string name, int value)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    if(l_ptr_root == nullptr){
        throw mapNotInitialized();
    }

    list_s* _new = new list_s(name, value);
    _new->l_ptr_next = l_ptr_root->l_ptr_first;
    l_ptr_root->l_ptr_first = _new;
    return;
}

list_s* MapCSen::l_find(std::string name)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    if(l_ptr_root == nullptr){
        throw mapNotInitialized();
    }
    if(l_ptr_root->l_ptr_first == nullptr)
    {
        #if __DEBUG__
            std::cout << "Empty list\n";
        #endif
        return nullptr;
    }

    list_s* temp = l_ptr_root->l_ptr_first;
    while(temp)
    {
        if(!temp->name.compare(name))
        {
            #if __DEBUG__
                std::cout << "Entry found.\n";
            #endif

            break;
        }
        temp = temp->l_ptr_next;
    }
    return temp;
}

/* class MapCSen public methods */
MapCSen::MapCSen()
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    l_ptr_root = new list_s_root;

    #if __DEBUG__
        std::cout << "l_ptr_root:ADDR    =     " << l_ptr_root << std::endl;
        std::cout << "l_ptr_root->first:ADDR = " << l_ptr_root->l_ptr_first << std::endl;
    #endif
}

MapCSen::MapCSen(MapCSen& src)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    list_s* src2 = src.l_ptr_root->l_ptr_first;
    this->l_ptr_root = new list_s_root();

    #if __DEBUG__
        std::cout << "l_ptr_root:ADDR    =     " << l_ptr_root << std::endl;
        std::cout << "l_ptr_root->first:ADDR = " << l_ptr_root->l_ptr_first << std::endl;
    #endif

    while(src2)
    {
        list_s* temp = new list_s(src2->name, src2->current_value);
        temp->l_ptr_next = l_ptr_root->l_ptr_first;
        l_ptr_root->l_ptr_first = temp;
        src2 = src2->l_ptr_next;
    }
}

MapCSen::~MapCSen()
{
  delete l_ptr_root;
}

list_s& MapCSen::operator[](std::string name)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    list_s* temp = l_find(name);
    if(temp == nullptr)
    {
        list_s* _new = new list_s(name, 0);
        _new->l_ptr_next = l_ptr_root->l_ptr_first;
        l_ptr_root->l_ptr_first = _new;
        return *_new;
    }
    return *temp;
}

std::ostream& operator<<(std::ostream& out, list_s& right)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
        std::cout << "object Map addr: " << &right << std::endl;
    #endif

    out << (int)right;
    return out;
}

/* MapCnSen methods */
void MapCnSen::operator=(const MapCSen&)
{
    throw notAllowed();
}

list_s& MapCnSen::operator[](std::string name)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    std::string newname = tolower(name);

    list_s* temp = l_find(newname);
    if(temp == nullptr)
    {
        list_s* _new = new list_s(newname, 0);
        _new->l_ptr_next = l_ptr_root->l_ptr_first;
        l_ptr_root->l_ptr_first = _new;
        return *_new;
    }
    return *temp;
}

std::string& MapCnSen::tolower(std::string& name)
{
    #if __DEBUG__
        std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;
    #endif

    int iterator = name.length();
    while(iterator--)
        if(name[iterator] >=65 && name[iterator] <= 90)
            name[iterator] += 32;
    return name;
}
