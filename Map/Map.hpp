#ifndef __MAP_HPP__
#define __MAP_HPP__

    #define __DEBUG__ 0
    #include <iostream>
    #include <string>

    class mapNotInitialized{};
    class notAllowed{};

    struct list_s
    {
    private:
        list_s* l_ptr_next;
        std::string name;
        int current_value;

        friend struct list_s_root;
        friend class MapCSen;
        friend class MapCnSen;

    public:
        list_s(std::string, int);
        operator int();
        list_s& operator=(int value);
        list_s& operator=(const list_s& value);
    };

    struct list_s_root
    {
    private:
        list_s* l_ptr_first;
        //bool l_isEmpty(list_s_root* root);
        friend class MapCSen;
        friend class MapCnSen;
    public:
        list_s_root();
        ~list_s_root();
    };

    class MapCSen
    {
        list_s_root* l_ptr_root;

        void l_add(std::string name, int value);
        list_s* l_find(std::string name);

    public:
        MapCSen();
        MapCSen(MapCSen& src);
        ~MapCSen();
        virtual list_s& operator[](std::string name);
        friend std::ostream& operator<<(std::ostream& input, list_s& right);

        friend class MapCnSen;
    };

    class MapCnSen : MapCSen
    {
    public:
        void operator=(const MapCSen&);
        list_s& operator[](std::string name) override;
        std::string& tolower(std::string& name);
    };

#endif /*__MAP_HPP__*/
